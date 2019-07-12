#include "SshClient.h"
#include "ui_SshClient.h"

SshClient::SshClient(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::SshClient();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

//重写构造函数，需要传入ip和端口号
SshClient::SshClient(QString serverIp, int Port, QWidget *parent) : QDialog(parent)
{
	ui = new Ui::SshClient();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	sshTcpClientSock = new QTcpSocket(this);

	connect(sshTcpClientSock, SIGNAL(connected()), this, SLOT(slotConnected()));//connect信号
	connect(sshTcpClientSock, SIGNAL(disconnected()), this, SLOT(slotDisconnect()));//disconnect信号,服务器断开的时候会触发
	connect(sshTcpClientSock, SIGNAL(readyRead()), this, SLOT(slotreadserver()));//readyRead信号，当有数据接收时发出
	connect(sshTcpClientSock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

	//与TCP服务器连接，连接成功后发出connected信号
	//connect_server();
	sshTcpClientSock->connectToHost(QHostAddress(serverIp), Port);//与tcp服务器连接，连接成功后发出connect信号
	//sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//与tcp服务器连接，连接成功后发出connect信号
	//connect(ui->SendpushButton, SIGNAL(clicked()), this, SLOT(send_data_to_server()));
	ui->textEdit_2->installEventFilter(this);
	
}

//重写构造函数，需要传入ip和端口号，输入文件，输出文件路劲
SshClient::SshClient(QString serverIp, int Port,QString inputpathFilename,QString outputPathFile, QWidget *parent) : QDialog(parent)
{
	ui = new Ui::SshClient();
	ui->setupUi(this);
	ui->groupBox->setVisible(false);
	ui->groupBox_2->setVisible(false);
	sshTcpClientSock = new QTcpSocket(this);
	filepathname = inputpathFilename;
	outputfilepath = outputPathFile;
	fileFlag = true;
	connect(sshTcpClientSock, SIGNAL(connected()), this, SLOT(slotConnected()));//connect信号
	connect(sshTcpClientSock, SIGNAL(disconnected()), this, SLOT(slotDisconnect()));//disconnect信号,服务器断开的时候会触发
	connect(sshTcpClientSock, SIGNAL(readyRead()), this, SLOT(slotreadserver()));//readyRead信号，当有数据接收时发出
	connect(sshTcpClientSock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

	//与TCP服务器连接，连接成功后发出connected信号
	//connect_server();
	sshTcpClientSock->connectToHost(QHostAddress(serverIp), Port);//与tcp服务器连接，连接成功后发出connect信号
																  //sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//与tcp服务器连接，连接成功后发出connect信号
																  //connect(ui->SendpushButton, SIGNAL(clicked()), this, SLOT(send_data_to_server()));
	ui->textEdit_2->installEventFilter(this);

}

//读服务器返回的字串
void SshClient::slotreadserver()
{
	QString displayServerMsg;
	QColor oldcolor = ui->textEdit->textColor();
	if (fileFlag)
	{
		fileFlag = false;
		QDateTime time1 = QDateTime::currentDateTime();
		qDebug() << "file time1:" << time1;
		send_file_to_server();
	}
	ui->textEdit->setTextColor(Qt::blue);
	ui->textEdit->append("(" + sshTcpClientSock->peerAddress().toString() + ")" + QTime::currentTime().toString() + ":");
	//ui->textEdit->append(sshTcpClientSock->readAll());
	displayServerMsg = sshTcpClientSock->readAll();
	ui->textEdit->append(displayServerMsg);
	//qDebug() << "displayServerMsg:" << displayServerMsg;
	if (displayServerMsg.contains("file transfer completed !"))
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << displayServerMsg;
		QMessageBox::information(this, "information", displayServerMsg);
		QDateTime time2 = QDateTime::currentDateTime();
		qDebug() << "file time2:" << time2;
		sshTcpClientSock->disconnectFromHost();
		sshTcpClientSock->waitForDisconnected();
	}
	ui->textEdit->setTextColor(oldcolor);
}

void SshClient::slotConnected()
{
	//客户端向服务器发出请求，如果服务器接收请求成功，会回复客户端请求成功
	QString msg = ("(" + sshTcpClientSock->localAddress().toString() + ")" + tr(" client request connect"));
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + sshTcpClientSock->localAddress().toString() + ")" + QTime::currentTime().toString() + ":\n" + tr(" client request connect").toLocal8Bit());
	int length = 0;
	if ((length = sshTcpClientSock->write(msg.toLatin1(), msg.length())) != msg.length())
	{
		return;
	}
}

//与服务器断开连接，断开连接后发出disconnect信号
void SshClient::slotDisconnect()
{
	QString msg = ("(" + sshTcpClientSock->localAddress().toString() + ")" + tr(" client request disconnect"));
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + sshTcpClientSock->localAddress().toString() + ")" + QTime::currentTime().toString() + ":\n" + tr(" server disconnect").toLocal8Bit());
	qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "disconnect:" << msg;
	int length = 0;
	if ((length = sshTcpClientSock->write(msg.toLatin1(), msg.length())) != msg.length())
	{
		return;
	}
}

void SshClient::connect_server()
{
	//192.168.79.128
	sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//与tcp服务器连接，连接成功后发出connect信号
}

//向服务器发送字串

void SshClient::send_data_to_server()
{
	QColor oldcolor = ui->textEdit->textColor();
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + sshTcpClientSock->localAddress().toString() + ")" + QTime::currentTime().toString() + ":\n" + ui->textEdit_2->toPlainText().toLocal8Bit());
	sshTcpClientSock->write(ui->textEdit_2->toPlainText().toLocal8Bit());
	ui->textEdit_2->clear();
	ui->textEdit->setTextColor(oldcolor);
}

//如果用户输入命令后，按回车键，会发送命令
bool SshClient::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == ui->textEdit_2)
	{
		if (event->type() == QEvent::KeyPress)
		{
			if (((QKeyEvent *)event)->key() == Qt::Key_Return)
			{

				send_data_to_server();
				return true;
			}
		}
	}
	return QWidget::eventFilter(watched, event);
}

//错误显示函数
void SshClient::displayError(QAbstractSocket::SocketError) //显示错误
{
	//qDebug() << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	//qDebug() << "(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + sshTcpClientSock->errorString();
	qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + sshTcpClientSock->errorString();
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + ":\n" + sshTcpClientSock->errorString());
	sshTcpClientSock->close();
	//ui->clientProgressBar->reset();
	//ui->clientStatusLabel->setText(tr("客户端就绪"));
	//ui->sendButton->setEnabled(true);
}

//向服务器发送文件
void SshClient::send_file_to_server()
{
	//QString filepathname = "C:/Users/Administrator/Desktop/test.txt";
	//filepathname是一个类的全局成员变量
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "filepathname:" << filepathname;
	QStringList filenamelist = filepathname.split("/");
	QString filename = filenamelist.at(filenamelist.length() - 1);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "client input filename:" << filename;
	QFile file(filepathname);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "open " << filepathname << " file is fail !";
		QMessageBox::about(this,"Error","Transferred file is invalid, file transfer failed!");
		return;
	}
	QStringList filecontainslist;
	//将文件名和输出文件路径发送到服务器
	QString msghead = "client input filename:" + filename + ":" +  outputfilepath + "\n";
	filecontainslist.append(msghead);
	while (!file.atEnd())
	{
		filecontainslist.append(file.readLine());
	}
	for (int i = 0; i < filecontainslist.length(); i++)
	{
		//在此将文件内容一行行传递给服务器
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "filecontain:" << filecontainslist.at(i);
		sshTcpClientSock->write(filecontainslist.at(i).toLocal8Bit());//toLocal8Bit
	}
}

//关闭事件,Tcp客户端断开的时候
void SshClient::closeEvent(QCloseEvent *event)
{
	this->close();
}

SshClient::~SshClient()
{
	delete ui;
}
