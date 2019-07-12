#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QWidget>
#include <QtNetwork>
#include <QFileDialog>
#include <QDir>
#include "ui_QtTcpClient.h"

class QtTcpClient : public QWidget
{
	Q_OBJECT

public:
	QtTcpClient(QWidget *parent = Q_NULLPTR);
	QtTcpClient(QString serverIP,int Port, QString inputFile, QString outputFile, QWidget *parent = Q_NULLPTR);
	~QtTcpClient();

private:
	Ui::QtTcpClient ui;

	QTcpSocket *tcpClient; 
	QFile *localFile;//Ҫ���͵��ļ�
	qint64 totalBytes;//�����ܴ�С
	qint64 bytesWritten;//�Ѿ��������ݴ�С
	qint64 bytesToWrite;//ʣ�����ݴ�С
	qint64 loadSize;//ÿ�η������ݴ�С
	QString fileName;//�����ļ�·��
	QString outputfilePath;//�����ļ�·��
	QByteArray outBlock;//���ݻ������������ÿ��Ҫ���͵�����

private slots:
	void send();//���ӷ�����
	void startTransfer();//�����ļ���С����Ϣ
	void updateClientProgress(qint64);//�������ݣ����½�����
	void displayError(QAbstractSocket::SocketError);//��ʾ����
	void openFile();//���ļ�
	void on_openButton_clicked();
	void on_sendButton_clicked();
};
