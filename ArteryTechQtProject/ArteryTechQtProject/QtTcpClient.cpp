#include "QtTcpClient.h"

QtTcpClient::QtTcpClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

//��д���캯��
QtTcpClient::QtTcpClient(QString serverIP,int Port, QString inputFile, QString outputFile,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	loadSize = 4 * 1024;
	totalBytes = 0;
	bytesWritten = 0;
	bytesToWrite = 0;
	tcpClient = new QTcpSocket(this);
	//send();
	//�����������ӳɹ�ʱ������connected()�źţ����ǿ�ʼ�����ļ�
	connect(tcpClient, SIGNAL(connected()), this, SLOT(startTransfer()));
	//�������ݷ��ͳɹ�ʱ�����Ǹ��½�����
	connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	//��ʼʹ���Ͱ�ť������
	//ui->sendButton->setEnabled(false);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" <<  "serverIP:" << serverIP << " Port:" << Port;

	fileName = inputFile;
	outputfilePath = outputFile;
	tcpClient->connectToHost(serverIP, Port);//����
}

void QtTcpClient::openFile()//���ļ�
{
	fileName = QFileDialog::getOpenFileName(this);
	/*
	if (!fileName.isEmpty())
	{
		ui->sendButton->setEnabled(true);
		ui->clientStatusLabel->setText(tr("���ļ�%1�ɹ�").arg(fileName));
	}
	*/
}

void QtTcpClient::send()//���ӵ���������ִ�з���
{
	//ui->sendButton->setEnabled(false);
	bytesWritten = 0;//��ʼ���ѷ����ֽ�Ϊ0
	//ui->clientStatusLabel->setText(tr("������.."));
	//tcpClient->connectToHost(ui->HostLineEdit->text(),ui->PortLineEdit->text().toInt());//����
	//���ӷ�����ip�Ͷ˿ں�
	tcpClient->connectToHost("192.168.0.121", 6666);//����
}

void QtTcpClient::startTransfer()//ʵ���ļ���С����Ϣ�ķ���
{
	//fileName = "C:/Users/Administrator/Desktop/lineEdit.txt"; 
	//fileName = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
	//qDebug() << "filename:" << fileName;
	localFile = new QFile(fileName);
	if (!localFile->open(QFile::ReadOnly))
	{
		//�ļ�����ʧ��
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "(" + tcpClient->localAddress().toString() + ")" + QTime::currentTime().toString() + fileName + " load fail !\n";
		return;
	}

	totalBytes = localFile->size();//�ļ��ܴ�С

	QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
	sendOut.setVersion(QDataStream::Qt_5_0);
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);

	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "currentFileName:"<<currentFileName;
	currentFileName = currentFileName + ":" + outputfilePath;
	//����д���ܴ�С��Ϣ�ռ䣬�ļ�����Ϣ��С�ռ䣬�ļ���
	sendOut << qint64(0) << qint64(0) << currentFileName;
	//�����ܴ�С���ļ�����С����Ϣ��ʵ���ļ���С���ܺ�
	totalBytes += outBlock.size();

	//����outBlock��ʼ����ʵ����Ϣ��������qint64�ռ�
	sendOut.device()->seek(0);
	sendOut << totalBytes << qint64(outBlock.size() - sizeof(qint64) * 2);

	//�������ݣ������㷢�������ݺ�ʣ�����ݵĴ�С
	bytesToWrite = totalBytes - tcpClient->write(outBlock);

	//ui->clientStatusLabel->setText(tr("������"));
	outBlock.resize(0);
}

//���½�������ʵ���ļ��Ĵ���
void QtTcpClient::updateClientProgress(qint64 numBytes)
{
	bytesWritten += (int)numBytes;//�Ѿ��������ݵĴ�С

	if (bytesToWrite > 0)//����Ѿ�����������
	{
		//ÿ�η���loadSize��С�����ݣ���������Ϊ4KB�����ʣ������ݲ���4KB���ͷ���ʣ�����ݵĴ�С
		outBlock = localFile->read(qMin(bytesToWrite, loadSize));
		//������һ�����ݺ�ʣ�����ݵĴ�С
		bytesToWrite -= (int)tcpClient->write(outBlock);
		outBlock.resize(0);//��շ��ͻ�����
	}
	else
	{
		localFile->close();//���û�з����κ����ݣ���ر��ļ�
	}

	//���½�����
	//ui->clientProgressBar->setMaximum(totalBytes);
	//ui->clientProgressBar->setValue(bytesWritten);

	if (bytesWritten == totalBytes)//�������
	{
		//ui->clientStatusLabel->setText(tr("�����ļ�%1�ɹ�").arg(fileName));
		localFile->close();
		tcpClient->close();
	}
}

//������ʾ����
void QtTcpClient::displayError(QAbstractSocket::SocketError) //��ʾ����
{
	qDebug() << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	tcpClient->close();
	//ui->clientProgressBar->reset();
	//ui->clientStatusLabel->setText(tr("�ͻ��˾���"));
	//ui->sendButton->setEnabled(true);
}

void QtTcpClient::on_openButton_clicked()//���ļ���ť
{
	openFile();
}

void QtTcpClient::on_sendButton_clicked()
{
	send();
}

QtTcpClient::~QtTcpClient()
{
}
