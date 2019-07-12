#include "QtTcpClient.h"

QtTcpClient::QtTcpClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

//重写构造函数
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
	//当服务器连接成功时，发出connected()信号，我们开始传送文件
	connect(tcpClient, SIGNAL(connected()), this, SLOT(startTransfer()));
	//当有数据发送成功时，我们更新进度条
	connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	//开始使发送按钮不可用
	//ui->sendButton->setEnabled(false);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" <<  "serverIP:" << serverIP << " Port:" << Port;

	fileName = inputFile;
	outputfilePath = outputFile;
	tcpClient->connectToHost(serverIP, Port);//连接
}

void QtTcpClient::openFile()//打开文件
{
	fileName = QFileDialog::getOpenFileName(this);
	/*
	if (!fileName.isEmpty())
	{
		ui->sendButton->setEnabled(true);
		ui->clientStatusLabel->setText(tr("打开文件%1成功").arg(fileName));
	}
	*/
}

void QtTcpClient::send()//连接到服务器，执行发送
{
	//ui->sendButton->setEnabled(false);
	bytesWritten = 0;//初始化已发送字节为0
	//ui->clientStatusLabel->setText(tr("连接中.."));
	//tcpClient->connectToHost(ui->HostLineEdit->text(),ui->PortLineEdit->text().toInt());//连接
	//连接服务器ip和端口号
	tcpClient->connectToHost("192.168.0.121", 6666);//连接
}

void QtTcpClient::startTransfer()//实现文件大小等信息的发送
{
	//fileName = "C:/Users/Administrator/Desktop/lineEdit.txt"; 
	//fileName = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
	//qDebug() << "filename:" << fileName;
	localFile = new QFile(fileName);
	if (!localFile->open(QFile::ReadOnly))
	{
		//文件加载失败
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "(" + tcpClient->localAddress().toString() + ")" + QTime::currentTime().toString() + fileName + " load fail !\n";
		return;
	}

	totalBytes = localFile->size();//文件总大小

	QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
	sendOut.setVersion(QDataStream::Qt_5_0);
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);

	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "currentFileName:"<<currentFileName;
	currentFileName = currentFileName + ":" + outputfilePath;
	//依次写入总大小信息空间，文件名信息大小空间，文件名
	sendOut << qint64(0) << qint64(0) << currentFileName;
	//这里总大小是文件名大小等信息和实际文件大小的总和
	totalBytes += outBlock.size();

	//返回outBlock开始，用实际信息代替两个qint64空间
	sendOut.device()->seek(0);
	sendOut << totalBytes << qint64(outBlock.size() - sizeof(qint64) * 2);

	//发送数据，并计算发送完数据后剩余数据的大小
	bytesToWrite = totalBytes - tcpClient->write(outBlock);

	//ui->clientStatusLabel->setText(tr("已连接"));
	outBlock.resize(0);
}

//更新进度条，实现文件的传送
void QtTcpClient::updateClientProgress(qint64 numBytes)
{
	bytesWritten += (int)numBytes;//已经发送数据的大小

	if (bytesToWrite > 0)//如果已经发送了数据
	{
		//每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
		outBlock = localFile->read(qMin(bytesToWrite, loadSize));
		//发送完一次数据后剩余数据的大小
		bytesToWrite -= (int)tcpClient->write(outBlock);
		outBlock.resize(0);//清空发送缓冲区
	}
	else
	{
		localFile->close();//如果没有发送任何数据，则关闭文件
	}

	//更新进度条
	//ui->clientProgressBar->setMaximum(totalBytes);
	//ui->clientProgressBar->setValue(bytesWritten);

	if (bytesWritten == totalBytes)//发送完毕
	{
		//ui->clientStatusLabel->setText(tr("发送文件%1成功").arg(fileName));
		localFile->close();
		tcpClient->close();
	}
}

//错误显示函数
void QtTcpClient::displayError(QAbstractSocket::SocketError) //显示错误
{
	qDebug() << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "QHostAddress::LocalHost :" << QHostAddress(QHostAddress::LocalHost).toString();
	tcpClient->close();
	//ui->clientProgressBar->reset();
	//ui->clientStatusLabel->setText(tr("客户端就绪"));
	//ui->sendButton->setEnabled(true);
}

void QtTcpClient::on_openButton_clicked()//打开文件按钮
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
