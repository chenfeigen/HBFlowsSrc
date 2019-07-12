#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include "ui_InstallationAlignment.h"

class InstallationAlignment : public QDialog
{
	Q_OBJECT

public:
	InstallationAlignment(QWidget *parent = Q_NULLPTR);
	~InstallationAlignment();

signals:
	void InstallAlignmentSignal(QString serialNumber);
private:
	Ui::InstallationAlignment ui;
	void SendInstallAlignmentSignal();
private slots:
	void PushButtonSlot();
};
