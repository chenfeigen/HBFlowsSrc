#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QPainter>
#include <QFile>
#include <QIODevice>
#include <QDialog>
#include <QDir>
#include <windows.h>
#include "EncryptedFileDialog.h"
#include "ui_RegisterInterface.h"

class RegisterInterface : public QDialog
{
	Q_OBJECT

public:
	RegisterInterface(QWidget *parent = Q_NULLPTR);
	~RegisterInterface();

private:
	Ui::RegisterInterface ui;
	void paintEvent(QPaintEvent *event);
	bool checkedRegisterUserInfo();
	bool SaveuserInfoFile();
	private slots:
	void ConfirmPushButtonSlot();
	void CancelPushButtonSlot();
};
