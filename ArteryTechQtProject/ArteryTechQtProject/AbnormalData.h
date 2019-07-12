#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include "ui_AbnormalData.h"

class AbnormalData : public QDialog
{
	Q_OBJECT

public:
	AbnormalData(QWidget *parent = Q_NULLPTR);
	AbnormalData(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~AbnormalData();

private:
	Ui::AbnormalData ui;
};
