#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include "SshClient.h"
#include "QtTcpClient.h"

namespace Ui { class TcpClientDialog; };

class TcpClientDialog : public QDialog
{
	Q_OBJECT

public:
	TcpClientDialog(QWidget *parent = Q_NULLPTR);
	~TcpClientDialog();

	void fileTcpClientUi();
	void sshTcpClientUi();

private:
	Ui::TcpClientDialog *ui;
	QString inputFilenamePath;

private slots:
	void connectcomputepushButtonSlots();
	void connectsshpushButtonSlots();
	void connectinputpushButtonSlots();

};
