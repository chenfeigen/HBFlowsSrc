#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QtWidgets/QMainWindow>
#include "ui_ArteryTechQtProject.h"
#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <qt>
#include <QMenu>
#include <QProcess>
#include <QWindow.h>
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <QDateTime>
#include <QMouseEvent>
#include <QTimer>
#include "QtArteryTechNonlinearSolverSetupUI.h"
#include "QtArteryTechPhysicsSetupUI.h"
#include "QtArteryTechOutputSetupUI.h"
#include "QtArteryTechOtherSetupsUI.h"
#include "QtArteryTechLinearSolverSetupUI.h"
#include "QtArteryTechTwoLevelPreconditionerUI.h"
#include "QtArteryTechPreconditionerSetupUI.h"
#include "QtArteryTechMeshSetup.h"
#include "QtArteryTechBoundarySetupUI.h"
#include "QtAeteryTechDocFille.h"
#include "TcpClientDialog.h"
#include "Help.h"
#include "HtmlCreatedWord.h"
#include "QtVtkDialog.h"
#include "AbnormalData.h"
#include "PuttyInformationDialog.h"
#include "userInformation.h"
#include "EncryptedFileDialog.h"
#include "GetCalculationResultsDialog.h"//获取计算结果头文件

class ArteryTechQtProject : public QMainWindow
{
	Q_OBJECT

public:
	ArteryTechQtProject(QWidget *parent = Q_NULLPTR);
	ArteryTechQtProject(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~ArteryTechQtProject();

protected:
	//鼠标事件
	void mousePressEvent(QMouseEvent *event);//按压事件
	void mouseReleaseEvent(QMouseEvent *event);//松开事件
	void mouseDoubleClickEvent(QMouseEvent *event);//双击事件
	void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
	void wheelEvent(QWheelEvent *event);//鼠标滚轮事件
	void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);
private:
	Ui::ArteryTechQtProjectClass ui;

	bool m_flag = false;
	bool m_saveOptionFlag = false;
	QString m_tmpFileName = NULL;
	uint m_startTime = 0;
	QString m_boundaryTypeText;

private:
	//load file 菜单和load file菜单下的action
	QMenu *loadFileMenu = NULL;
	QAction *actLoadPicture = NULL;
	QAction *actLoadDicomPicture = NULL;

	//slover菜单和solver菜单下的action
	QMenu *solverMenu = NULL;
	QAction *actLastInput = NULL;
	QAction *actMeshSetup = NULL;
	QAction *actBoundarySetup = NULL;
	QAction *actPhysicsSetup = NULL;
	QAction *actNonlinearSolverSetup = NULL;
	QAction *actLinearSolverSetup = NULL;
	QAction *actPreconditionerSetup = NULL;
	QAction *actTwoLevelPreconditioner = NULL;
	QAction *actOutputSetup = NULL;
	QAction *actOtherSetup = NULL;
	QAction *actSaveOption = NULL;
	QAction *actSaveCPR = NULL;//计算参数报告Action

	QMenu *HBFlowsHelpMenu = NULL;
	QAction *actHelp = NULL;

	QAction *actDivision = NULL;
	QAction *actGeomagic = NULL;
	QAction *actMesh = NULL;
	QAction *actCompute = NULL;
	QAction *actView = NULL;
	QAction *actExecutionscript = NULL;
	QAction *actPutty = NULL;
	QAction *actReport = NULL;
	QAction *actEncryptedFile = NULL;
	QAction *actGetResults = NULL;

	QProcess *processDivision = NULL;
	QProcess *processGeomagic = NULL;
	QProcess *processMesh = NULL;
	QProcess *processCompute = NULL;
	QProcess *processView = NULL;
	QProcess *processPutty = NULL;

	puttyInformation *m_puttyInfon = NULL;

	QtArteryTechMeshSetup *qtATMeshSetupDlg = NULL;
	QtArteryTechBoundarySetupUI *qtATBoundarysetupDlg = NULL;
	QtArteryTechPhysicsSetupUI *qtATPhysicsSetupDlg = NULL;
	QtArteryTechNonlinearSolverSetupUI *qtATNonlinearsolversetupDlg = NULL;
	QtArteryTechLinearSolverSetupUI *qtATLinearSolverSetupDlg = NULL;
	QtArteryTechPreconditionerSetupUI *qtATPreconditionerSetupDlg = NULL;
	QtArteryTechTwoLevelPreconditionerUI *qtATTwoLevelPreconditionerDlg = NULL;
	QtArteryTechOutputSetupUI *qtATOutputSetupDlg = NULL;
	QtArteryTechOtherSetupsUI *qtATOtherSetupsDlg = NULL;
	//QtPainEvent *qtPainEventDialog;
	Help *help;

	QProcess *process = new QProcess(this);
	QString UpperEncryption(QString pretext);
	QString UpperDecryption(QString pretext);
	QString XorEncryption(QString pretext);
	QString XorDecryption(QString pretext);
	QString ToUpperAndLower(QString src); // 大小写
	QString ToXOREncryptUncrypt(QString src, const QChar key); // 异或加解密(钥匙加解密)
	
	void InitUIdata();
	void MainUI();
	void SendBoundaryTypeToPhysicsSetup();

//将BoundaryType内容通过信号发送给qtATPhysicsSetupDlg
signals:
	void BoundaryTypeToPhysicsSetupSignal(QString boundaryType);
private slots:
	void ActOpenDicompictureSlot();
	void ActOpenpictureSlot();
	void ActOpenExeSlot();
	void ActLastInputSlot();
	void ActMeshSetupSlot();
	void ActBoundarySetupSlot();
	void ActPhysicsSetupSlot();
	void ActNonlinearSolverSetupSlot();
	void ActLinearSolverSetupSlot();
	void ActPreconditionerSetupSlot();
	void ActTwoLevelPreconditionerSlot();
	void ActOutputSetupSlot();
	void ActOtherSetupsSlot();
	void ActSaveOptionSlot();
	void ActViewSlot();
	void ActDivisionSlot();
	void ActGeomagicSlot();
	void ActMeshSlot();
	void ActComputeSlot();
	void ActExecutionscriptSlot();
	void ActOpenPuttySlot();
	void ActReportSlot();
	void ProcessError(QProcess::ProcessError error);
	//生成计算参数报告文件
	void ActSaveCPRSlot();
	//加密文件槽函数
	void ActEncryptedFileSlot();
	void ActGetResultsSlot();//获取计算结果槽函数
	//void landpushButtonSlots();//登录功能槽函数
	//void registerpushButtonSlots();//注册功能的槽函数
	void ActHelpSlot();
	//void pushButtonSlots();
	void  ActReportHtmlSlot();
	//void RetrievePasswordpushButtonSlots();//找回密码功能槽函数
	void GetPuttyInfoSignal(puttyInformation*);
	void TimeoutSlot();
	void GetBoundaryTypeSlot(QString boundaryTypeText);
};
