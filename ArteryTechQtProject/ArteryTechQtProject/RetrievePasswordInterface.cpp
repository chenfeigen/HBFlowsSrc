#include "RetrievePasswordInterface.h"

RetrievePasswordInterface::RetrievePasswordInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	//�����һأ�ͨ�����������һ�
	//this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	//this->setWindowTitle("HBFLows RetrievePassword");
	//this->setMaximumSize(418, 295);
	//this->setMinimumSize(418, 295);
	//ui.PasswordLabel->setVisible(false);
	//ui.PasswordLineEdit->setVisible(false);

	////�ź���ۺ���������
	//QObject::connect(ui.ConfirmPushButton,SIGNAL(clicked(bool)),this,SLOT(ConfirmPushButtonSlot()));
	//QObject::connect(ui.CancelPushButton,SIGNAL(clicked(bool)),this,SLOT(CancelPushButtonSlot()));

	//��ʾͨ�����̻�ȡ����
	this->setWindowTitle("�����һ�");
	ui.UsernameLabel->setVisible(false);
	ui.UsernameLineEdit->setVisible(false);
	ui.PasswordLabel->setVisible(false);
	ui.PasswordLineEdit->setVisible(false);
	ui.ConfirmPushButton->setVisible(false);
	ui.CancelPushButton->setVisible(false);
	ui.BackgroundLabel->setAlignment(Qt::AlignCenter);
	QString labelText = "���������룬����ϵHBFlows�����һ����룡\n���̵绰��057185165173";
	ui.BackgroundLabel->setText(labelText);

}

RetrievePasswordInterface::~RetrievePasswordInterface()
{
}

void RetrievePasswordInterface::paintEvent(QPaintEvent *event)
{
	//���ݴ��ڵĴ�С���Ʊ���ͼƬ
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

bool RetrievePasswordInterface::checkedRetPasswordUserInfo()
{
	QString userName = ui.UsernameLineEdit->text();
	if (userName == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Input account number cannot be empty, please re-enter!";
		QMessageBox::information(this, "��Ϣ:", "������˺Ų���Ϊ�գ����������룡");
		return false;
	}
	int userNamelength = userName.length();
	if (userNamelength <= 20)
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
				QMessageBox::information(this, "��Ϣ:", "�˺Ų��ܰ��������ֺ���ĸ����������ַ������������룡");
				return false;
			}
		}
	}
	else
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters,please re-enter!";
		QMessageBox::information(this, "��Ϣ:", "�˺ų��Ȳ��ܳ���30���ַ������������룡");
		return false;
	}
	return true;
}

void RetrievePasswordInterface::ConfirmPushButtonSlot()
{
	if (NULL == ui.UsernameLineEdit->text().trimmed())
	{
		QMessageBox::information(this, "��Ϣ:", "�˺Ų���Ϊ�գ����������룡");
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

//��������
QString RetrievePasswordInterface::findInfoFromUserInfo(QString str1)
{
	QString password =	NULL;
	QString filename = "userInfo.db";
	QFile file(filename);

	bool openStatus = file.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::warning(this, "����:", "�˺�û�б�ע�ᣬ���������룡.");
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
	QMessageBox::information(this, "��Ϣ:", "�˺����벻��ȷ�����������룡");
	return password;
}