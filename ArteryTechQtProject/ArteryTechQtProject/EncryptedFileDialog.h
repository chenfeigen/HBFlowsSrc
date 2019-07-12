#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")   
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include "ui_EncryptedFileDialog.h"

class EncryptedFileDialog : public QDialog
{
	Q_OBJECT

public:
	EncryptedFileDialog(QWidget *parent = Q_NULLPTR);
	~EncryptedFileDialog();

private:
	Ui::EncryptedFileDialog ui;

	private slots:
	void InputFilePushButtonSlot();//输入文件按钮槽函数
	void EncryptionPushButtonSlot();//加密按钮槽函数
	void DecryptionPushButtonSlot();//解密按钮槽函数
};
