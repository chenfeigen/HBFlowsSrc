#include "SshClient.h"
#include "ui_SshClient.h"

SshClient::SshClient(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::SshClient();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

//��д���캯������Ҫ����ip�Ͷ˿ں�
SshClient::SshClient(QString serverIp, int Port, QWidget *parent) : QDialog(parent)
{
	ui = new Ui::SshClient();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	sshTcpClientSock = new QTcpSocket(this);

	connect(sshTcpClientSock, SIGNAL(connected()), this, SLOT(slotConnected()));//connect�ź�
	connect(sshTcpClientSock, SIGNAL(disconnected()), this, SLOT(slotDisconnect()));//disconnect�ź�,�������Ͽ���ʱ��ᴥ��
	connect(sshTcpClientSock, SIGNAL(readyRead()), this, SLOT(slotreadserver()));//readyRead�źţ��������ݽ���ʱ����
	connect(sshTcpClientSock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

	//��TCP���������ӣ����ӳɹ��󷢳�connected�ź�
	//connect_server();
	sshTcpClientSock->connectToHost(QHostAddress(serverIp), Port);//��tcp���������ӣ����ӳɹ��󷢳�connect�ź�
	//sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//��tcp���������ӣ����ӳɹ��󷢳�connect�ź�
	//connect(ui->SendpushButton, SIGNAL(clicked()), this, SLOT(send_data_to_server()));
	ui->textEdit_2->installEventFilter(this);
	
}

//��д���캯������Ҫ����ip�Ͷ˿ںţ������ļ�������ļ�·��
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
	connect(sshTcpClientSock, SIGNAL(connected()), this, SLOT(slotConnected()));//connect�ź�
	connect(sshTcpClientSock, SIGNAL(disconnected()), this, SLOT(slotDisconnect()));//disconnect�ź�,�������Ͽ���ʱ��ᴥ��
	connect(sshTcpClientSock, SIGNAL(readyRead()), this, SLOT(slotreadserver()));//readyRead�źţ��������ݽ���ʱ����
	connect(sshTcpClientSock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

	//��TCP���������ӣ����ӳɹ��󷢳�connected�ź�
	//connect_server();
	sshTcpClientSock->connectToHost(QHostAddress(serverIp), Port);//��tcp���������ӣ����ӳɹ��󷢳�connect�ź�
																  //sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//��tcp���������ӣ����ӳɹ��󷢳�connect�ź�
																  //connect(ui->SendpushButton, SIGNAL(clicked()), this, SLOT(send_data_to_server()));
	ui->textEdit_2->installEventFilter(this);

}

//�����������ص��ִ�
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
	//�ͻ�����������������������������������ɹ�����ظ��ͻ�������ɹ�
	QString msg = ("(" + sshTcpClientSock->localAddress().toString() + ")" + tr(" client request connect"));
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + sshTcpClientSock->localAddress().toString() + ")" + QTime::currentTime().toString() + ":\n" + tr(" client request connect").toLocal8Bit());
	int length = 0;
	if ((length = sshTcpClientSock->write(msg.toLatin1(), msg.length())) != msg.length())
	{
		return;
	}
}

//��������Ͽ����ӣ��Ͽ����Ӻ󷢳�disconnect�ź�
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
	sshTcpClientSock->connectToHost(QHostAddress("192.168.0.121"), 5000);//��tcp���������ӣ����ӳɹ��󷢳�connect�ź�
}

//������������ִ�

void SshClient::send_data_to_server()
{
	QColor oldcolor = ui->textEdit->textColor();
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + sshTcpClientSock->localAddress().toString() + ")" + QTime::currentTime().toString() + ":\n" + ui->textEdit_2->toPlainText().toLocal8Bit());
	sshTcpClientSock->write(ui->textEdit_2->toPlainText().toLocal8Bit());
	ui->textEdit_2->clear();
	ui->textEdit->setTextColor(oldcolor);
}

//����û���������󣬰��س������ᷢ������
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

//������ʾ����
void SshClient::displayError(QAbstractSocket::SocketError) //��ʾ����
{
	//qDebug() << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	//qDebug() << "(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + sshTcpClientSock->errorString();
	qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + sshTcpClientSock->errorString();
	ui->textEdit->setTextColor(Qt::red);
	ui->textEdit->append("(" + QHostAddress(QHostAddress::LocalHost).toString() + ")" + QTime::currentTime().toString() + ":\n" + sshTcpClientSock->errorString());
	sshTcpClientSock->close();
	//ui->clientProgressBar->reset();
	//ui->clientStatusLabel->setText(tr("�ͻ��˾���"));
	//ui->sendButton->setEnabled(true);
}

//������������ļ�
void SshClient::send_file_to_server()
{
	//QString filepathname = "C:/Users/Administrator/Desktop/test.txt";
	//filepathname��һ�����ȫ�ֳ�Ա����
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
	//���ļ���������ļ�·�����͵�������
	QString msghead = "client input filename:" + filename + ":" +  outputfilepath + "\n";
	filecontainslist.append(msghead);
	while (!file.atEnd())
	{
		filecontainslist.append(file.readLine());
	}
	for (int i = 0; i < filecontainslist.length(); i++)
	{
		//�ڴ˽��ļ�����һ���д��ݸ�������
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "filecontain:" << filecontainslist.at(i);
		sshTcpClientSock->write(filecontainslist.at(i).toLocal8Bit());//toLocal8Bit
	}
}

//�ر��¼�,Tcp�ͻ��˶Ͽ���ʱ��
void SshClient::closeEvent(QCloseEvent *event)
{
	this->close();
}

SshClient::~SshClient()
{
	delete ui;
}
