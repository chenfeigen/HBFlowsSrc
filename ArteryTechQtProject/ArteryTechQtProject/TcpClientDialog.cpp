#include "TcpClientDialog.h"
#include "ui_TcpClientDialog.h"

TcpClientDialog::TcpClientDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::TcpClientDialog();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(605, 182);
	this->setMaximumSize(605, 182);
	//将用户名和密码的输入框隐藏起来
	ui->userNamelabel->setVisible(false);
	ui->userNamelineEdit->setVisible(false);
	ui->passWordlabel->setVisible(false);
	ui->passWordlineEdit->setVisible(false);

	ui->passWordlineEdit->setEchoMode(QLineEdit::Password);
	ui->iplineEdit->setText(tr("192.168.79.128"));
	ui->portlineEdit->setText(tr("5000"));
	ui->outputlineEdit->setText(tr("/tmp"));

	QObject::connect(ui->connectsshpushButton, SIGNAL(clicked(bool)), this, SLOT(connectsshpushButtonSlots()));
	QObject::connect(ui->connectcomputepushButton, SIGNAL(clicked(bool)), this, SLOT(connectcomputepushButtonSlots()));
	QObject::connect(ui->inputpushButton, SIGNAL(clicked(bool)), this, SLOT(connectinputpushButtonSlots()));
}

void TcpClientDialog::fileTcpClientUi()
{
	ui->connectsshpushButton->setVisible(false);
}

void TcpClientDialog::sshTcpClientUi()
{
	ui->inputlabel->setVisible(false);
	ui->inputfilelineEdit->setVisible(false);
	ui->inputpushButton->setVisible(false);
	ui->outputlabel->setVisible(false);
	ui->outputlineEdit->setVisible(false);
	ui->connectcomputepushButton->setVisible(false);
}

#if 1
//不带用户名和密码的连接
void TcpClientDialog::connectcomputepushButtonSlots()
{
	QString serverIP = ui->iplineEdit->text();
	int Port = ui->portlineEdit->text().toInt();
	QString inputFile = ui->inputfilelineEdit->text();
	QString outputFile = ui->outputlineEdit->text();
	//先判断输入的文件是否有效
	if (inputFile == NULL)
	{
		QMessageBox::information(this,"Error","Please enter the file to be transferred !");
		return;
	}
	//连接server 服务器
	//QtTcpClient *client = new QtTcpClient(serverIP, Port, inputFile, outputFile);
	SshClient *executionscriptClient = new SshClient(serverIP, Port, inputFile, outputFile, this);
	hide();
	//executionscriptClient->show();
	return;
}

void TcpClientDialog::connectsshpushButtonSlots()
{
	QString serverIP = ui->iplineEdit->text();
	int Port = ui->portlineEdit->text().toInt();
	SshClient *executionscriptClient = new SshClient(serverIP, Port, this);
	hide();
	executionscriptClient->show();
	return;
}
#endif

#if 0
//带用户名和密码的连接
void TcpClientDialog::connectcomputepushButtonSlots()
{
	QString userInfo;
	QStringList userInfoList;
	char readbuff[100] = { 0 };
	qint64 rlen;
	int flag = 0;

	//先判断是否输入了用户名和密码，并且用户名和密码是否输入正确
	QFile file("userInfo.db");
	bool ok = file.open(QIODevice::ReadOnly | QIODevice::Text);//只读打开文
	if (!ok)
	{
		QMessageBox::information(this, "info", "can not open user informationn file !");
		return;
	}
	while (!file.atEnd())
	{
		rlen = file.readLine(readbuff, 100);
		qDebug() << "read data:" << readbuff;
		userInfo = readbuff;
		userInfoList = userInfo.split("|");
		//判断界面上的用户名是否在文件中以存在//userNamelineEdit
		if (userInfoList[0].compare(ui->userNamelineEdit->text()) == 0)
		{
			file.close();
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		QString password = ui->passWordlineEdit->text();
		//判断密码是否正确
		if (userInfoList[1].trimmed().compare(password) == 0)
		{
			QString serverIP = ui->iplineEdit->text();
			int Port = ui->portlineEdit->text().toInt();
			QString inputFile = ui->inputfilelineEdit->text();
			QString outputFile = ui->outputlineEdit->text();
			//连接server 服务器
			//QtTcpClient *client = new QtTcpClient(serverIP, Port, inputFile, outputFile);
			SshClient *executionscriptClient = new SshClient(serverIP, Port, inputFile, outputFile, this);
			hide();
			//executionscriptClient->show();
			return;
		}
		else
		{
			QMessageBox::critical(this, "Error", "password input fail !");
			return;
		}

	}
	else
	{
		QMessageBox::critical(this, "Error", "userName input fail !");
		return;
	}
}

void TcpClientDialog::connectsshpushButtonSlots()
{
	QString userInfo;
	QStringList userInfoList;
	char readbuff[100] = { 0 };
	qint64 rlen;
	int flag = 0;
	//先判断是否输入了用户名和密码，并且用户名和密码是否输入正确
	QFile file("userInfo.db");
	bool ok = file.open(QIODevice::ReadOnly | QIODevice::Text);//只读打开文
	if (!ok)
	{
		QMessageBox::information(this, "info", "can not open user informationn file !");
		return;
	}
	while (!file.atEnd())
	{
		rlen = file.readLine(readbuff, 100);
		qDebug() << "read data:" << readbuff;
		userInfo = readbuff;
		userInfoList = userInfo.split("|");
		//判断界面上的用户名是否在文件中以存在//userNamelineEdit
		if (userInfoList[0].compare(ui->userNamelineEdit->text()) == 0)
		{
			file.close();
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		QString password = ui->passWordlineEdit->text();
		//判断密码是否正确
		if (userInfoList[1].trimmed().compare(password) == 0)
		{
			QString serverIP = ui->iplineEdit->text();
			int Port = ui->portlineEdit->text().toInt();
			SshClient *executionscriptClient = new SshClient(serverIP, Port, this);
			hide();
			executionscriptClient->show();
			return;
		}
		else
		{
			QMessageBox::critical(this, "Error", "password input fail !");
			return;
		}

	}
	else
	{
		QMessageBox::critical(this, "Error", "userName input fail !");
		return;
	}
}
#endif

void TcpClientDialog::connectinputpushButtonSlots()
{
	inputFilenamePath = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "inputFilenamePath:" << inputFilenamePath;
	if (NULL == inputFilenamePath)
	{
		QMessageBox::about(this, "information:", "please input a file ");
	}

	//将文件名设置在inputfilelineEdit上
	ui->inputfilelineEdit->setText(inputFilenamePath);
}

TcpClientDialog::~TcpClientDialog()
{
	delete ui;
}
