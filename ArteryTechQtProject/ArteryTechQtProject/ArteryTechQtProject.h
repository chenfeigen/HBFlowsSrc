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
#include "GetCalculationResultsDialog.h"//��ȡ������ͷ�ļ�
#include "VariableParametersDialog.h" //��ȡ�ɱ����ͷ�ļ�
#include "VerifyPassword.h"//��֤����ͷ�ļ�
#include "ComputingMultipleBP.h"//��������߽����

class ArteryTechQtProject : public QMainWindow
{
	Q_OBJECT

public:
	ArteryTechQtProject(QWidget *parent = Q_NULLPTR);
	ArteryTechQtProject(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~ArteryTechQtProject();

protected:
	//����¼�
	void mousePressEvent(QMouseEvent *event);//��ѹ�¼�
	void mouseReleaseEvent(QMouseEvent *event);//�ɿ��¼�
	void mouseDoubleClickEvent(QMouseEvent *event);//˫���¼�
	void mouseMoveEvent(QMouseEvent *event);//����ƶ��¼�
	void wheelEvent(QWheelEvent *event);//�������¼�
	void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);
private:
	Ui::ArteryTechQtProjectClass ui;

	bool m_flag = false;
	bool m_saveOptionFlag = false;
	QString m_tmpFileName = NULL;
	uint m_startTime = 0;
	QString m_boundaryTypeText;
	bool m_vpflag = false; //��ֹ/�����޸Ĺ̶�����
	QStringList m_variableParametersList;

private:
	//load file �˵���load file�˵��µ�action
	QMenu *loadFileMenu = NULL;
	QAction *actLoadPicture = NULL;
	QAction *actLoadDicomPicture = NULL;

	//slover�˵���solver�˵��µ�action
	QMenu *solverMenu = NULL;
	QAction *actLastInput = NULL;
	QAction *actVariableParameters = NULL;
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
	QAction *actVerifyPassword = NULL;//�޸ļ������

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
	QAction *actComputingMultipleBP = NULL;//��������߽����action

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
	VerifyPassword *verifyPassword = NULL;//��ֹ�޸Ĺ̶���������
	//QtPainEvent *qtPainEventDialog;
	Help *help = NULL;
	//ComputingMultipleBP *computingMultipleBP = NULL; //��������߽����

	QProcess *process = new QProcess(this);
	QString UpperEncryption(QString pretext);
	QString UpperDecryption(QString pretext);
	QString XorEncryption(QString pretext);
	QString XorDecryption(QString pretext);
	QString ToUpperAndLower(QString src); // ��Сд
	QString ToXOREncryptUncrypt(QString src, const QChar key); // ���ӽ���(Կ�׼ӽ���)
	
	void InitUIdata();
	void MainUI();
	void SendBoundaryTypeToPhysicsSetup();
	void SendVerifyPasswordStatu(bool flag);
	void SendVariableParameters(QStringList variableParametersList);
	void SendComputingMultipleBP(QStringList m_computingMultipleBPList);
	bool CreateOPTFile(QString fullFileName);//����option�ļ�
	void SendCreateOPTFile(bool creatStatus);//���ʹ���opt�ļ���״̬

//��BoundaryType����ͨ���źŷ��͸�qtATPhysicsSetupDlg
signals:
	void BoundaryTypeToPhysicsSetupSignal(QString boundaryType);//����BoundaryType��PhysicsSetup
	void VerifyPasswordStatu(bool flag);//��������/��ֹ�޸Ĺ̶������ı�־
	void VariableParametersSingnal(QStringList);//���Ϳɱ���������������
	void ComputingMultipleBPSignal(QStringList);//���ͼ���߽�����Ŀɱ���������������
	void CreateOPTFileSignal(bool status);

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
	void ActGetResultsSlot();//��ȡ�������ۺ���
	//void landpushButtonSlots();//��¼���ܲۺ���
	//void registerpushButtonSlots();//ע�Ṧ�ܵĲۺ���
	void ActHelpSlot();
	//void pushButtonSlots();
	void  ActReportHtmlSlot();
	//void RetrievePasswordpushButtonSlots();//�һ����빦�ܲۺ���
	void GetPuttyInfoSignal(puttyInformation*);
	void TimeoutSlot();
	void GetBoundaryTypeSlot(QString boundaryTypeText);//��ȡQtArteryTechBoundarySetupUI������boundaryType�Ĳ���
	void ActVariableParameters();
	void ActVerifyPasswordSlot();//��ֹ/�����޸Ĺ̶�����
	void GetPasswordStatuSlot(bool flag);//��ȡ����/��ֹ�Ի��������״̬
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//��ÿɱ�����źŲۺ���
	void GetComputingMultipleBPSignalSlot(QStringList ComputingMultipleBPList);//�����������߽�����ۺ���
	void ActComputingMultipleBPSlot();//��������߽�����ۺ���
};
