#include "RetrievePasswordInterface.h"

RetrievePasswordInterface::RetrievePasswordInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	//密码找回，通过界面密码找回
	//this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	//this->setWindowTitle("HBFLows RetrievePassword");
	//this->setMaximumSize(418, 295);
	//this->setMinimumSize(418, 295);
	//ui.PasswordLabel->setVisible(false);
	//ui.PasswordLineEdit->setVisible(false);

	////信号与槽函数的连接
	//QObject::connect(ui.ConfirmPushButton,SIGNAL(clicked(bool)),this,SLOT(ConfirmPushButtonSlot()));
	//QObject::connect(ui.CancelPushButton,SIGNAL(clicked(bool)),this,SLOT(CancelPushButtonSlot()));

	//提示通过厂商获取密码
	this->setWindowTitle("密码找回");
	ui.UsernameLabel->setVisible(false);
	ui.UsernameLineEdit->setVisible(false);
	ui.PasswordLabel->setVisible(false);
	ui.PasswordLineEdit->setVisible(false);
	ui.ConfirmPushButton->setVisible(false);
	ui.CancelPushButton->setVisible(false);
	ui.BackgroundLabel->setAlignment(Qt::AlignCenter);
	QString labelText = "如忘记密码，请联系HBFlows厂商找回密码！\n厂商电话：057185165173";
	ui.BackgroundLabel->setText(labelText);

}

RetrievePasswordInterface::~RetrievePasswordInterface()
{
}

void RetrievePasswordInterface::paintEvent(QPaintEvent *event)
{
	//根据窗口的大小绘制背景图片
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

bool RetrievePasswordInterface::checkedRetPasswordUserInfo()
{
	QString userName = ui.UsernameLineEdit->text();
	if (userName == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Input account number cannot be empty, please re-enter!";
		QMessageBox::information(this, "消息:", "输入的账号不能为空，请重新输入！");
		return false;
	}
	int userNamelength = userName.length();
	if (userNamelength <= 20)
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
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::information(this, "消息:", "账号不能包含除数字和字母以外的其他字符，请重新输入！");
				return false;
			}
		}
	}
	else
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters,please re-enter!";
		QMessageBox::information(this, "消息:", "账号长度不能超过30个字符，请重新输入！");
		return false;
	}
	return true;
}

void RetrievePasswordInterface::ConfirmPushButtonSlot()
{
	if (NULL == ui.UsernameLineEdit->text().trimmed())
	{
		QMessageBox::information(this, "消息:", "账号不能为空，请重新输入！");
		return;
	}
	bool checkStatus = checkedRetPasswordUserInfo();
	if (!checkStatus)
	{
		return;
	}
	QString username = ui.UsernameLineEdit->text().trimmed();
	QString findStr= findInfoFromUserInfo(username);
	if (NULL == findStr)
	{
		return;
	}
	else
	{
		ui.PasswordLineEdit->setText(findStr);
		ui.PasswordLabel->setVisible(true);
		ui.PasswordLineEdit->setVisible(true);
	}
}

void RetrievePasswordInterface::CancelPushButtonSlot()
{
	close();
}

//返回密码
QString RetrievePasswordInterface::findInfoFromUserInfo(QString str1)
{
	QString password =	NULL;
	QString filename = "userInfo.db";
	QFile file(filename);

	bool openStatus = file.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::warning(this, "警告:", "账号没有被注册，请重新输入！.");
		return password;
	}
	QString fileContent;
	QString username;
	while (!file.atEnd())
	{
		fileContent = file.readLine();
		if (NULL == fileContent.trimmed())
		{
			continue;
		}
		username = fileContent.split("|").at(0).trimmed();
		if (username.compare(str1.trimmed()) == 0)
		{

			password = fileContent.split("|").at(1).trimmed();
			return password;
		}
		else
		{
			continue;
		}
	}
	QMessageBox::information(this, "消息:", "账号输入不正确，请重新输入！");
	return password;
}