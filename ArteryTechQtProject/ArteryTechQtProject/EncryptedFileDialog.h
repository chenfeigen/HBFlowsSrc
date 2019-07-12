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
	void InputFilePushButtonSlot();//�����ļ���ť�ۺ���
	void EncryptionPushButtonSlot();//���ܰ�ť�ۺ���
	void DecryptionPushButtonSlot();//���ܰ�ť�ۺ���
};
