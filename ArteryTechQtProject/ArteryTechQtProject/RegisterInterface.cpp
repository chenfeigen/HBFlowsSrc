#include "RegisterInterface.h"

RegisterInterface::RegisterInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	this->setWindowTitle("用户注册");
	this->setMaximumSize(500, 300);
	this->setMinimumSize(500, 300);
	ui.PasswordLineEdit->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
	ui.PasswordLineEdit2->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点

	//信号与槽函数的连接
	QObject::connect(ui.ConfirmPushButton, SIGNAL(clicked(bool)), this, SLOT(ConfirmPushButtonSlot()));
	QObject::connect(ui.CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlot()));
}

RegisterInterface::~RegisterInterface()
{
}

void RegisterInterface::paintEvent(QPaintEvent *event)
{
	//根据窗口的大小绘制背景图片
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

void RegisterInterface::ConfirmPushButtonSlot()
{
	if (NULL == ui.UsernameLineEdit->text().trimmed())
	{
		QMessageBox::warning(this, "警告:", "账号不能为空，请重新输入！");
		return;
	}
	bool checkStatus = checkedRegisterUserInfo();
	if (!checkStatus)
	{
		return;
	}
	QString username = ui.UsernameLineEdit->text().trimmed();
	bool saveStatus = SaveuserInfoFile();
	if (NULL == saveStatus)
	{
		return;
	}
	else
	{
		QMessageBox::information(this,"消息:","恭喜您注册成功！");
		return;
	}
}

void RegisterInterface::CancelPushButtonSlot()
{
	close();
}

//检查注册界面输入的用户信息,checkedRegisterUserInfo()只对注册时用户输入的账号和密码是否有效进行检测
bool RegisterInterface::checkedRegisterUserInfo()
{
	QString userName = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	QString password2 = ui.PasswordLineEdit2->text().trimmed();
	if (userName == NULL)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The account entered at the time of registration cannot be empty, please re-enter!";
		QMessageBox::warning(this, "警告:", "注册账号输入不能为空，请重新输入！");
		return false;
	}
	if (password == NULL || password2 == NULL)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The password entered at the time of registration cannot be empty. Please re-enter it!";
		QMessageBox::warning(this, "警告:", "注册账号密码输入不能为空，请重新输入！");
		return false;
	}
	else if (password.compare(password2) != 0)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Two inconsistent passwords!";
		QMessageBox::warning(this, "警告:", "两次密码输入不一致，请重新输入!");
		return false;
	}

	if (userName.compare(password) == 0)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "注册账号时，账号和密码一致!";
		QMessageBox::warning(this, "警告:", "账号和密码不能一致，请重新输入！");
		return false;
	}

	if (password.length() < 8)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "警告:", "密码长度不能小于8位，请重新输入！");
		return false;
	}
	int userNamelength = userName.length();
	int passwordlength = password.length();
	if (userNamelength <= 20 && passwordlength <= 30)
	{
		//判断账号中是否存在特殊字符
		for (int i = 0; i < userNamelength; i++)
		{
			if ((userName[i] >= '0' && userName[i] <= '9') || (userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::warning(this, "警告:", "账号不能有除数字和字母以外的其他字符，请重新输入！");
				return false;
			}
		}
	}
	else
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!";
		QMessageBox::warning(this, "警告:", "账号长度不能超过20个字符，密码长度不能超过30个字符，请重新输入！");
		return false;
	}
	return true;
}

bool RegisterInterface::SaveuserInfoFile()
{
	QString fileUsername = NULL;
	QString filePassword = NULL;
	//用户信息保存文件
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo/userInfo.db");
	QString temporaryFile = "userInfo.db";
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	//步骤：1.先判断隐藏文件userInfo.db是否存在，如果不存在，则是第一次注册账号
	//2.文件在，先将文件解密，然后生成userInfo.db临时文件
	//3.一行行读取userInfo.db文件，判断注册的用户名是否存在
	//4.注册成功之后，需要将userInfo.db文件进行加密，然后生成userInfo.db隐藏文件，并且删除userInfo.db临时文件
	QFile userFile(qstrUserInfo);
	bool existStatus = userFile.exists(qstrUserInfo);
	if (!existStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "第一次注册账号！";
	}
	else
	{
		//先解密隐藏文件qstrUserInfo,得到零时文件temporaryFile
		bool ret = encryptedFileDialog->DecryptionFile(qstrUserInfo, temporaryFile);
		if (ret)
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << qstrUserInfo + "文件解密成功！";
		}
		else
		{
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << qstrUserInfo + "文件解密失败！";
			return false;
		}
	}
	QFile tmpFile(temporaryFile);
	bool ok = tmpFile.open(QIODevice::ReadWrite| QIODevice::Text);//读写打开文件
	if (!ok)
	{
		QMessageBox::information(this, "消息", "无法打开用户信息文件！");
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "can not open userInfo.db file !";
		return false;
	}
	QString username = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	QString fileContent = NULL;
	//QStringList outfileContentList;
	//先判断输入的用户名是不是在文件中已经存在，如果已经存在，则提示该用户名已经被注册
	while (!tmpFile.atEnd())
	{
		fileContent = tmpFile.readLine();
		qDebug() << "fileContent:" << fileContent;
		if (fileContent.trimmed() == NULL)
		{
			continue;
		}
		fileUsername = fileContent.split("|").at(0).trimmed();
		filePassword = fileContent.split("|").at(1).trimmed();
		//判断界面上的用户名是否在文件中以存在
		if (fileUsername.compare(username) == 0)
		{
			//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "This user has been registered. Please login.";
			QMessageBox::information(this, "消息：", "该用户已注册，请直接登录！.");
			tmpFile.close();
			return false;
		}
	}
	QString userInfoString = username + "|" + password + "\n";
	qDebug() << "userInfoString:" << userInfoString;
	//outfileContentList.append(userInfoString);
	tmpFile.write("\n");
	qint64 wlen = tmpFile.write(userInfoString.toStdString().c_str());
	//qint64 wlen = tmpFile.write(userInfoString.toStdString().c_str(), userInfoString.length());
	//qDebug() << "wlen:" << wlen << "userInfoString len:" << userInfoString.length();
	tmpFile.close();
	//将文件加密成隐藏文件
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "temporaryFile:" + temporaryFile;
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "qstrUserInfo:" + qstrUserInfo;
	//FILE_ATTRIBUTE_NORMAL
	SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_NORMAL);
	bool encryptionStatus = encryptedFileDialog->EncryptionFile(temporaryFile,qstrUserInfo);
	if (encryptionStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << temporaryFile + "文件加密成功！";
		remove(temporaryFile.toStdString().c_str());
		SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
		return true;
	}
	else//加密失败，说明注册的用户没有保存到用户信息文件中
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << temporaryFile + "文件加密失败！";
		QMessageBox::warning(this,"警告:","账号注册无法保存，请联系软件厂商\n厂商电话：057185165173");
		//remove(temporaryFile.toStdString().c_str());
		return false;
	}
	
}