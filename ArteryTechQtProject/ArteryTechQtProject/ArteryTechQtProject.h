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

class ArteryTechQtProject : public QMainWindow
{
	Q_OBJECT

public:
	ArteryTechQtProject(QWidget *parent = Q_NULLPTR);
	ArteryTechQtProject(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~ArteryTechQtProject();

protected:
	void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);
private:
	Ui::ArteryTechQtProjectClass ui;

	bool m_flag = false;
	bool m_saveOptionFlag = false;
	QString m_tmpFileName = NULL;

private:
	//load file �˵���load file�˵��µ�action
	QMenu *loadFileMenu = NULL;
	QAction *actLoadPicture = NULL;
	QAction *actLoadDicomPicture = NULL;

	//slover�˵���solver�˵��µ�action
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
	QAction *actSaveCPR = NULL;//�����������Action

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
	QString ToUpperAndLower(QString src); // ��Сд
	QString ToXOREncryptUncrypt(QString src, const QChar key); // ���ӽ���(Կ�׼ӽ���)
	
	void InitUIdata();
	void MainUI();

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
	//���ɼ�����������ļ�
	void ActSaveCPRSlot();
	//�����ļ��ۺ���
	void ActEncryptedFileSlot();

	//void landpushButtonSlots();//��¼���ܲۺ���
	//void registerpushButtonSlots();//ע�Ṧ�ܵĲۺ���
	void ActHelpSlot();
	//void pushButtonSlots();
	void  ActReportHtmlSlot();
	//void RetrievePasswordpushButtonSlots();//�һ����빦�ܲۺ���
	void GetPuttyInfoSignal(puttyInformation*);
};
