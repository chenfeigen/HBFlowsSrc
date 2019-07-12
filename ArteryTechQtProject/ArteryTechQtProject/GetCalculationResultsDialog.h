#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>

namespace Ui { class GetCalculationResultsDialog; };

class GetCalculationResultsDialog : public QDialog
{
	Q_OBJECT

public:
	GetCalculationResultsDialog(QWidget *parent = Q_NULLPTR);
	~GetCalculationResultsDialog();

private:
	Ui::GetCalculationResultsDialog *ui;
	private slots:
	void InputFilePushButtonSlot();//�����ļ���ť�ۺ���
	void GetResultPushButtonSlot();//��ȡ�����ť�ۺ���
	void SaveAspushButtonSlot();//���Ϊ�ۺ���
	void PrintPushButtonSlot();//��ӡ�ۺ���
};
