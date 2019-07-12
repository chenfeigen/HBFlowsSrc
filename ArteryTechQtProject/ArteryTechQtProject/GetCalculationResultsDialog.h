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
	void InputFilePushButtonSlot();//输入文件按钮槽函数
	void GetResultPushButtonSlot();//获取结果按钮槽函数
	void SaveAspushButtonSlot();//另存为槽函数
	void PrintPushButtonSlot();//打印槽函数
};
