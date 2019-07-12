#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QtNetwork>
#include <QColor>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QDateTime>
//#include "TcpClientDialog.h"

namespace Ui { class SshClient; };

class SshClient : public QDialog
{
	Q_OBJECT

public:
	SshClient(QWidget *parent = Q_NULLPTR);
	SshClient(QString serverIp, int Port, QWidget *parent = Q_NULLPTR);
	SshClient(QString serverIp, int Port, QString inputpathFilename, QString outputPathFile, QWidget *parent = Q_NULLPTR);
	~SshClient();

private:
	Ui::SshClient *ui;

	QTcpSocket *sshTcpClientSock;
	bool fileFlag = false;
	QString filepathname;
	QString outputfilepath;
	//TcpClientDialog *clientDialog;
	bool eventFilter(QObject *watched, QEvent *event);
	void connect_server();
	void closeEvent(QCloseEvent *event);


private slots:
	void slotConnected();
	void slotDisconnect();
	void slotreadserver();
	void send_data_to_server();
	void send_file_to_server();
	void displayError(QAbstractSocket::SocketError);//œ‘ æ¥ÌŒÛ

};
