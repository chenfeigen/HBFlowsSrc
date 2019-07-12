#include "RegisterInterface.h"

RegisterInterface::RegisterInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	this->setWindowTitle("HBFLows Register");
	this->setMaximumSize(418, 295);
	this->setMinimumSize(418, 295);

	//�ź���ۺ���������
	QObject::connect(ui.ConfirmPushButton, SIGNAL(clicked(bool)), this, SLOT(ConfirmPushButtonSlot()));
	QObject::connect(ui.CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlot()));
}

RegisterInterface::~RegisterInterface()
{
}

void RegisterInterface::paintEvent(QPaintEvent *event)
{
	//���ݴ��ڵĴ�С���Ʊ���ͼƬ
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

void RegisterInterface::ConfirmPushButtonSlot()
{
	if (NULL == ui.UsernameLineEdit->text().trimmed())
	{
		QMessageBox::information(this, "Message:", "Account cannot be empty, please re-enter!");
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
		QMessageBox::information(this,"Message:","Congratulations on the successful registration!");
		return;
	}
}

void RegisterInterface::CancelPushButtonSlot()
{
	close();
}

//���ע�����������û���Ϣ,checkedRegisterUserInfo()ֻ��ע��ʱ�û�������˺ź������Ƿ���Ч���м��
bool RegisterInterface::checkedRegisterUserInfo()
{
	QString userName = ui.UsernameLineEdit->text();
	QString password = ui.PasswordLineEdit->text();
	QString password2 = ui.PasswordLineEdit2->text();
	if (userName == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The account entered at the time of registration cannot be empty, please re-enter!";
		QMessageBox::information(this, "Message:", "The account entered at the time of registration cannot be empty, please re-enter!");
		return false;
	}
	if (password == NULL || password2 == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The password entered at the time of registration cannot be empty. Please re-enter it!";
		QMessageBox::information(this, "Message:", "The password entered at the time of registration cannot be empty. Please re-enter it!");
		return false;
	}
	else if (password.compare(password2) != 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Two inconsistent passwords!";
		QMessageBox::information(this, "Message:", "Two inconsistent passwords!");
		return false;
	}
	int userNamelength = userName.length();
	int passwordlength = password.length();
	if (userNamelength <= 20 && passwordlength <= 30)
	{
		//�ж��˺����Ƿ���������ַ�
		for (int i = 0; i < userNamelength; i++)
		{
			if ((userName[i] >= '0' && userName[i] <= '9') || (userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::information(this, "Message:", "Account cannot have special characters except numbers and characters. Please re-enter!");
				return false;
			}
		}
	}
	else
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!";
		QMessageBox::information(this, "Message:", "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!");
		return false;
	}
	return true;
}

bool RegisterInterface::SaveuserInfoFile()
{
	QString fileUsername = NULL;
	QString filePassword = NULL;

	QFile file("userInfo.db");
	bool ok = file.open(QIODevice::ReadWrite | QIODevice::Text);//��д���ļ�
	if (!ok)
	{
		QMessageBox::information(this, "infon", "can not open userInfo.db file !");
		//qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "can not open userInfo.db file !";
		return false;
	}
	QString username = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	QString fileContent = NULL;
	//���ж�������û����ǲ������ļ����Ѿ����ڣ�����Ѿ����ڣ�����ʾ���û����Ѿ���ע��
	while (!file.atEnd())
	{
		fileContent = file.readLine();
		if (fileContent.trimmed() == NULL)
		{
			continue;
		}
		fileUsername = fileContent.split("|").at(0).trimmed();
		filePassword = fileContent.split("|").at(1).trimmed();
		//�жϽ����ϵ��û����Ƿ����ļ����Դ���
		if (fileUsername.compare(username) == 0)
		{
			//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "This user has been registered. Please login.";
			QMessageBox::information(this, "infon", "This user has been registered. Please login.");
			file.close();
			return false;
		}
	}
	QString userInfoString = username + "|" + password + "\n";
	qint64 wlen = file.write(userInfoString.toStdString().c_str(), userInfoString.length());
	//qDebug() << "wlen:" << wlen << "userInfoString len:" << userInfoString.length();
	file.close();
	return true;
}