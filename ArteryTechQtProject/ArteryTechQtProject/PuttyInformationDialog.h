#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QFile>
#include <QIODevice>
#include "ui_PuttyInformationDialog.h"
#include "userInformation.h"

class PuttyInformationDialog : public QDialog
{
	Q_OBJECT

public:
	PuttyInformationDialog(QWidget *parent = Q_NULLPTR);
	~PuttyInformationDialog();

private:
	Ui::PuttyInformationDialog ui;
	puttyInformation *puttyInfon;
	void InitUI();
	void SendPuttyInfoSignal();
signals:
	void PuttyInfoSignal(puttyInformation *m_puttyInformation);//将PuttyInformationDialog界面上的信息发送到ArteryTechQtProject

	private slots:
	void ConfirmPushButtonSlot();
	void CancelPushButtonSlot();
};
