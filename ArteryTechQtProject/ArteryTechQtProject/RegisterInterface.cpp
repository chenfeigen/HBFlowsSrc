#include "RegisterInterface.h"

RegisterInterface::RegisterInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	this->setWindowTitle("�û�ע��");
	this->setMaximumSize(500, 300);
	this->setMinimumSize(500, 300);
	ui.PasswordLineEdit->setEchoMode(QLineEdit::Password);//�����ʱ�����ʾԲ��
	ui.PasswordLineEdit2->setEchoMode(QLineEdit::Password);//�����ʱ�����ʾԲ��

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
		QMessageBox::warning(this, "����:", "�˺Ų���Ϊ�գ����������룡");
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
		QMessageBox::information(this,"��Ϣ:","��ϲ��ע��ɹ���");
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
	QString userName = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	QString password2 = ui.PasswordLineEdit2->text().trimmed();
	if (userName == NULL)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The account entered at the time of registration cannot be empty, please re-enter!";
		QMessageBox::warning(this, "����:", "ע���˺����벻��Ϊ�գ����������룡");
		return false;
	}
	if (password == NULL || password2 == NULL)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The password entered at the time of registration cannot be empty. Please re-enter it!";
		QMessageBox::warning(this, "����:", "ע���˺��������벻��Ϊ�գ����������룡");
		return false;
	}
	else if (password.compare(password2) != 0)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Two inconsistent passwords!";
		QMessageBox::warning(this, "����:", "�����������벻һ�£�����������!");
		return false;
	}

	if (userName.compare(password) == 0)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ע���˺�ʱ���˺ź�����һ��!";
		QMessageBox::warning(this, "����:", "�˺ź����벻��һ�£����������룡");
		return false;
	}

	if (password.length() < 8)
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "����:", "���볤�Ȳ���С��8λ�����������룡");
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
				qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::warning(this, "����:", "�˺Ų����г����ֺ���ĸ����������ַ������������룡");
				return false;
			}
		}
	}
	else
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!";
		QMessageBox::warning(this, "����:", "�˺ų��Ȳ��ܳ���20���ַ������볤�Ȳ��ܳ���30���ַ������������룡");
		return false;
	}
	return true;
}

bool RegisterInterface::SaveuserInfoFile()
{
	QString fileUsername = NULL;
	QString filePassword = NULL;
	//�û���Ϣ�����ļ�
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo/userInfo.db");
	QString temporaryFile = "userInfo.db";
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	//���裺1.���ж������ļ�userInfo.db�Ƿ���ڣ���������ڣ����ǵ�һ��ע���˺�
	//2.�ļ��ڣ��Ƚ��ļ����ܣ�Ȼ������userInfo.db��ʱ�ļ�
	//3.һ���ж�ȡuserInfo.db�ļ����ж�ע����û����Ƿ����
	//4.ע��ɹ�֮����Ҫ��userInfo.db�ļ����м��ܣ�Ȼ������userInfo.db�����ļ�������ɾ��userInfo.db��ʱ�ļ�
	QFile userFile(qstrUserInfo);
	bool existStatus = userFile.exists(qstrUserInfo);
	if (!existStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��һ��ע���˺ţ�";
	}
	else
	{
		//�Ƚ��������ļ�qstrUserInfo,�õ���ʱ�ļ�temporaryFile
		bool ret = encryptedFileDialog->DecryptionFile(qstrUserInfo, temporaryFile);
		if (ret)
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << qstrUserInfo + "�ļ����ܳɹ���";
		}
		else
		{
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << qstrUserInfo + "�ļ�����ʧ�ܣ�";
			return false;
		}
	}
	QFile tmpFile(temporaryFile);
	bool ok = tmpFile.open(QIODevice::ReadWrite| QIODevice::Text);//��д���ļ�
	if (!ok)
	{
		QMessageBox::information(this, "��Ϣ", "�޷����û���Ϣ�ļ���");
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "can not open userInfo.db file !";
		return false;
	}
	QString username = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	QString fileContent = NULL;
	//QStringList outfileContentList;
	//���ж�������û����ǲ������ļ����Ѿ����ڣ�����Ѿ����ڣ�����ʾ���û����Ѿ���ע��
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
		//�жϽ����ϵ��û����Ƿ����ļ����Դ���
		if (fileUsername.compare(username) == 0)
		{
			//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "This user has been registered. Please login.";
			QMessageBox::information(this, "��Ϣ��", "���û���ע�ᣬ��ֱ�ӵ�¼��.");
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
	//���ļ����ܳ������ļ�
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "temporaryFile:" + temporaryFile;
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "qstrUserInfo:" + qstrUserInfo;
	//FILE_ATTRIBUTE_NORMAL
	SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_NORMAL);
	bool encryptionStatus = encryptedFileDialog->EncryptionFile(temporaryFile,qstrUserInfo);
	if (encryptionStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << temporaryFile + "�ļ����ܳɹ���";
		remove(temporaryFile.toStdString().c_str());
		SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
		return true;
	}
	else//����ʧ�ܣ�˵��ע����û�û�б��浽�û���Ϣ�ļ���
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << temporaryFile + "�ļ�����ʧ�ܣ�";
		QMessageBox::warning(this,"����:","�˺�ע���޷����棬����ϵ�������\n���̵绰��057185165173");
		//remove(temporaryFile.toStdString().c_str());
		return false;
	}
	
}