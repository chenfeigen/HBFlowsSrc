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
#include <QProcess>
#include "ui_LoginInterface.h"
#include "RegisterInterface.h"
#include "RetrievePasswordInterface.h"
#include "ArteryTechQtProject.h"
#include "InstallationAlignment.h"

class LoginInterface : public QDialog
{
	Q_OBJECT

public:
	LoginInterface(QWidget *parent = Q_NULLPTR);
	~LoginInterface();

private:
	Ui::LoginInterface ui;
	QProcess *process;
	InstallationAlignment *installationAlignment;
	void paintEvent(QPaintEvent *event);
	bool CheckedLoginUserInfo();
	bool FindInfoFromUserInfo(QString usernamePar, QString passwordPar);
	bool GetSerialNumber();
	bool SaveLicenseFile(QString serialNumber);
	private slots:
	//槽函数定义
	void RetPasswordPushButtonSlot();//找回密码槽函数
	void RegisterPushButtonSlot();//注册槽函数
	void LoginPushButtonSlot();//登录槽函数
	void GetInstallationAlignmentSlot(QString serialNumber);//首次安装正确之后的槽函数
};
