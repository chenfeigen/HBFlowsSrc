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
#include <windows.h>
#include "ui_LoginInterface.h"
#include "RegisterInterface.h"
#include "RetrievePasswordInterface.h"
#include "ArteryTechQtProject.h"
#include "InstallationAlignment.h"
#include "EncryptedFileDialog.h"

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
	int m_errorCount = 0;//�˺����������������

	void paintEvent(QPaintEvent *event);
	bool CheckedLoginUserInfo();
	int FindInfoFromUserInfo(QString usernamePar, QString passwordPar);
	bool GetSerialNumber();
	bool SaveLicenseFile(QString serialNumber);
	bool LockAccountsStatus(QString userNamePar);//У���˺���û�б�������
	void CreateLockFile();
	void SaveLockInfo();
	private slots:
	//�ۺ�������
	void RetPasswordPushButtonSlot();//�һ�����ۺ���
	void RegisterPushButtonSlot();//ע��ۺ���
	void LoginPushButtonSlot();//��¼�ۺ���
	void GetInstallationAlignmentSlot(QString serialNumber);//�״ΰ�װ��ȷ֮��Ĳۺ���
};
