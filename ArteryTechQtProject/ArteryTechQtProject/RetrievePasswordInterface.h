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
#include "ui_RetrievePasswordInterface.h"

class RetrievePasswordInterface : public QDialog
{
	Q_OBJECT

public:
	RetrievePasswordInterface(QWidget *parent = Q_NULLPTR);
	~RetrievePasswordInterface();

private:
	Ui::RetrievePasswordInterface ui;

	void paintEvent(QPaintEvent *event);
	bool checkedRetPasswordUserInfo();
	QString findInfoFromUserInfo(QString str1);
	private slots:
	void ConfirmPushButtonSlot();
	void CancelPushButtonSlot();
};
