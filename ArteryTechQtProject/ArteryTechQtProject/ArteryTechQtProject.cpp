#include "ArteryTechQtProject.h"
#include <QAxWidget>
#include <QAxObject>

ArteryTechQtProject::ArteryTechQtProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	//����Ĭ��Ϊ���
	this->setWindowState(Qt::WindowMaximized);

	this->setWindowTitle("CT�޴�Ѫ��������������ϵͳ");
	this->setWindowIcon(QIcon("images/ArteryTech.ico"));

	show();
	InitUIdata();
	MainUI();
	ui.label->setText(QString("<font color=#e9a96f;>����汾�ţ�01.00.00\n��������汾�ţ�01\nCopyright&#169; 2019 Artery All Rights Reserved.���ݰ�����Ƽ����޹�˾��Ȩ����</font>"));

	m_startTime = QDateTime::currentDateTime().toTime_t();
	//������ʱ��
	QTimer *timer = new QTimer(this);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(TimeoutSlot()));
	//�ź���ۺ�������
	QObject::connect(actHelp, SIGNAL(triggered(bool)), this, SLOT(ActHelpSlot()));
	//������ʱ��
	timer->start(1000);//1���Ӵ���һ��
}

ArteryTechQtProject::ArteryTechQtProject(QString tmpFileName, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	//����Ĭ��Ϊ���
	this->setWindowState(Qt::WindowMaximized);

	this->setWindowTitle("CT�޴�Ѫ��������������ϵͳ");
	this->setWindowIcon(QIcon("images/ArteryTech.ico"));
	m_startTime = QDateTime::currentDateTime().toTime_t();
	show();
	InitUIdata();
	MainUI();
	//ȥ��pushbutton�ı߿�
	ui.pushButton->setStyleSheet("border:none;");
	ui.label->setAlignment(Qt::AlignCenter);//����label��text��Ϣ������ʾ
	//ui.label->setText(QString("< font color=#e9a96f;>Copyright&#169; 2016</font>"));
	//QString str1 = "����汾�ţ�01.00.06\n��������汾�ţ�01\n";
	//ui.label->setText(str1 + QString("< font color=#e9a96f;>Copyright&#169; 2019 Artery All Rights Reserved.���ݰ�����Ƽ����޹�˾��Ȩ����</font>"));
	ui.label->setText(QString("< font color=#e9a96f;>����汾�ţ�01.00.00\n��������汾�ţ�01\nCopyright&#169; 2019 Artery All Rights Reserved.���ݰ�����Ƽ����޹�˾��Ȩ����</font>"));
	//ui.label->setText("����汾�ţ�01.00.06\n��������汾�ţ�01\nCopyright &copy 2019 Artery All Rights Reserved.���ݰ�����Ƽ����޹�˾��Ȩ����");
	//������ʱ��
	QTimer *timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(TimeoutSlot()));
	//�ź���ۺ�������
	QObject::connect(actHelp, SIGNAL(triggered(bool)), this, SLOT(ActHelpSlot()));
	//������ʱ��
	timer->start(1000);//1���Ӵ���һ��
}

//�����������г�ʼ��
void ArteryTechQtProject::InitUIdata()
{
	//��ʼ��QProcess����
	this->processDivision = new QProcess;
	this->processGeomagic = new QProcess;
	this->processMesh = new QProcess;
	this->processCompute = new QProcess;
	this->processView = new QProcess;
	this->processPutty = new QProcess;

	//��������QMenu���˵���
	this->loadFileMenu = new QMenu("��������");
	this->actLoadPicture = new QAction("����ͼ���ļ�");
	this->actLoadDicomPicture = new QAction("����CTAӰ��");
	this->loadFileMenu->addAction(actLoadPicture);
	this->loadFileMenu->addAction(actLoadDicomPicture);

	//slover�˵���solver�˵��µ�action
	this->solverMenu = new QMenu("�����");
	this->actLastInput = new QAction("�ϴ�����");
	this->actMeshSetup = new QAction("��������");
	this->actBoundarySetup = new QAction("�߽���������");
	this->actPhysicsSetup = new QAction("�����������");
	this->actNonlinearSolverSetup = new QAction("�������������������");
	this->actLinearSolverSetup = new QAction("�����������������");
	this->actPreconditionerSetup = new QAction("Ԥ�����㷨��������");
	this->actTwoLevelPreconditioner = new QAction("��ˮƽԤ�����������");
	this->actOutputSetup = new QAction("����������");
	this->actOtherSetup = new QAction("������������");
	this->actSaveOption = new QAction("��������");
	this->actSaveCPR = new QAction("�����������");
	this->solverMenu->addAction(actLastInput);
	this->solverMenu->addAction(actMeshSetup);
	this->solverMenu->addAction(actBoundarySetup);
	this->solverMenu->addAction(actPhysicsSetup);
	this->solverMenu->addAction(actNonlinearSolverSetup);
	this->solverMenu->addAction(actLinearSolverSetup);
	this->solverMenu->addAction(actPreconditionerSetup);
	this->solverMenu->addAction(actTwoLevelPreconditioner);
	this->solverMenu->addAction(actOutputSetup);
	this->solverMenu->addAction(actOtherSetup);
	//this->solverMenu->addAction(actSaveCPR);//��������������
	this->solverMenu->addAction(actSaveOption);

	this->qtATMeshSetupDlg = new QtArteryTechMeshSetup(m_tmpFileName,this);
	this->qtATBoundarysetupDlg = new QtArteryTechBoundarySetupUI(m_tmpFileName,this);
	QObject::connect(qtATBoundarysetupDlg,SIGNAL(BoundaryTypeSignal(QString)),this,SLOT(GetBoundaryTypeSlot(QString)));
	this->qtATPhysicsSetupDlg = new QtArteryTechPhysicsSetupUI(m_tmpFileName, this);
	QObject::connect(this, SIGNAL(BoundaryTypeToPhysicsSetupSignal(QString)), qtATPhysicsSetupDlg, SLOT(GetBoundaryTypeSlot(QString)));
	this->qtATNonlinearsolversetupDlg = new QtArteryTechNonlinearSolverSetupUI(m_tmpFileName, this);
	this->qtATLinearSolverSetupDlg = new QtArteryTechLinearSolverSetupUI(m_tmpFileName, this);
	this->qtATPreconditionerSetupDlg = new QtArteryTechPreconditionerSetupUI(m_tmpFileName, this);
	this->qtATTwoLevelPreconditionerDlg = new QtArteryTechTwoLevelPreconditionerUI(m_tmpFileName, this);
	this->qtATOutputSetupDlg = new QtArteryTechOutputSetupUI(m_tmpFileName, this);
	this->qtATOtherSetupsDlg = new QtArteryTechOtherSetupsUI(m_tmpFileName, this);

	//this->HBFlowsHelpMenu = new QMenu("����");
	this->actHelp = new QAction("����");
	//this->HBFlowsHelpMenu->addAction(actHelp);
	//ui.menuBar->addMenu(HBFlowsHelpMenu);
	ui.menuBar->addAction(this->actHelp);

	//��ʼ��Action
	this->actDivision = new QAction("ͼ��ָ�");
	this->actGeomagic = new QAction("�����޸�");
	this->actMesh = new QAction("��������");
	//this->actCompute = new QAction("Upload");
	this->actView = new QAction("���ӻ�");
	//�����ļ�
	this->actEncryptedFile = new QAction("�����ļ�");
	//this->actExecutionscript = new QAction("Job Submission");
	//this->actPutty = new QAction("Download");
	//this->actReport = new QAction("Report");
	//this->actGetResults = new QAction("��ȡ������");//��ȡ������

	this->help = new Help(this);
}

void ArteryTechQtProject::ActOpenDicompictureSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	QtVtkDialog *qtVtkDialog = new QtVtkDialog(this);
	//qtPainEventDialog = new QtPainEvent(this);
	qtVtkDialog->displyPicture3d();
	//setCentralWidget(qtPainEventDialogui);
	qtVtkDialog->move(250, 250);
	//qtVtkDialog->show();
}

void ArteryTechQtProject::ActOpenpictureSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	QtVtkDialog *qtVtkDialog = new QtVtkDialog(this);
	//qtPainEventDialog = new QtPainEvent(this);
	qtVtkDialog->openpicture();
	//setCentralWidget(qtPainEventDialogui);
	qtVtkDialog->move(250,250);
	//qtVtkDialog->show();
}

void ArteryTechQtProject::ActOpenExeSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	QProcess *process = new QProcess;
	QString Exefilepathname = QFileDialog::getOpenFileName(this, "open exe", QDir::currentPath()).trimmed();

	//QString Exefilename = "\"C:/Program Files/Geomagic/Geomagic Foundation 2014/Studio.exe\"";
	//����������ϼ������ţ����Դ�����ļ���·�����Ƕ����пո�������������пո񲻼��������ǲ��������򿪵�
	QString Exefilename = 0x22 + Exefilepathname + 0x22;
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Exefilename:" << Exefilename;
	process->start(Exefilename);
	//process->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

void ArteryTechQtProject::ActMeshSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATMeshSetupDlg = new QtArteryTechMeshSetup(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����MeshSetup����!";
	qtATMeshSetupDlg->show();
}

void ArteryTechQtProject::ActBoundarySetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATBoundarysetupDlg = new QtArteryTechBoundarySetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����BoundarySetup����!";
	qtATBoundarysetupDlg->show();
}

void ArteryTechQtProject::ActPhysicsSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATPhysicsSetupDlg = new QtArteryTechPhysicsSetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����BoundarySetup����!";
	SendBoundaryTypeToPhysicsSetup();
	qtATPhysicsSetupDlg->show();
}

void ArteryTechQtProject::ActNonlinearSolverSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATNonlinearsolversetupDlg = new QtArteryTechNonlinearSolverSetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����NonlinearSolverSetup����!";
	qtATNonlinearsolversetupDlg->show();
}

void ArteryTechQtProject::ActLinearSolverSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATLinearSolverSetupDlg = new QtArteryTechLinearSolverSetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����LinearSolverSetup����!";
	qtATLinearSolverSetupDlg->show();
}

void ArteryTechQtProject::ActPreconditionerSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATPreconditionerSetupDlg = new QtArteryTechPreconditionerSetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����PreconditionerSetup����!";
	qtATPreconditionerSetupDlg->show();
}

void ArteryTechQtProject::ActTwoLevelPreconditionerSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATTwoLevelPreconditionerDlg = new QtArteryTechTwoLevelPreconditionerUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����TwoLevelPreconditioner����!";
	qtATTwoLevelPreconditionerDlg->show();
}

void ArteryTechQtProject::ActOutputSetupSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATOutputSetupDlg = new QtArteryTechOutputSetupUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����OutputSetup����!";
	qtATOutputSetupDlg->show();
}

void ArteryTechQtProject::ActOtherSetupsSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//this->qtATOtherSetupsDlg = new QtArteryTechOtherSetupsUI(this);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����OtherSetup����!";
	qtATOtherSetupsDlg->show();
}

/*
functionname:actionModify_FinishActionSlots
param: void
return: void
function:����Modify Finish Action�Ĳۺ���������action��������ͻᴥ�����������
			�����Ĺ����ǽ�soloer�˵������е�����д�뵽�ļ�
*/
void ArteryTechQtProject::ActSaveOptionSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	QString filepathname = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), NULL);

	//qDebug() << "save file path name:" << filepathname;
	if (NULL == filepathname)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��ѡ������Ҫ������ļ�!";
		QMessageBox::information(this, "��Ϣ", "��ѡ����Ҫ������ļ�!");
		return;
	}
	else
	{
		QStringList fileContent;
		m_saveOptionFlag = true;
		QFile *file = new QFile(filepathname);
		bool existStatus = file->exists();
		if (existStatus)
		{
			//�ļ�������ɾ��
			file->remove();
		}
		//file->write(contenttext.toStdString().c_str(), contenttext.length() + 2);
		//���ν��˵������ϵ�����׷�ӵ�fileContent�б���
		if (NULL != this->qtATMeshSetupDlg)
			fileContent.append(this->qtATMeshSetupDlg->meshSetupDataList);
		if (NULL != this->qtATBoundarysetupDlg)
			fileContent.append(this->qtATBoundarysetupDlg->boundaryDataList);
		if (NULL != this->qtATPhysicsSetupDlg)
			fileContent.append(this->qtATPhysicsSetupDlg->physicsDataList);
		if (NULL != this->qtATNonlinearsolversetupDlg)
			fileContent.append(this->qtATNonlinearsolversetupDlg->nonlinearSolverDataList);
		if (NULL != this->qtATLinearSolverSetupDlg)
			fileContent.append(this->qtATLinearSolverSetupDlg->linearSolverDataList);
		if (NULL != this->qtATPreconditionerSetupDlg)
			fileContent.append(this->qtATPreconditionerSetupDlg->preconditionerDataList);
		if (NULL != this->qtATTwoLevelPreconditionerDlg)
			fileContent.append(this->qtATTwoLevelPreconditionerDlg->twoLPreconditionerDataList);
		if (NULL != this->qtATOutputSetupDlg)
			fileContent.append(this->qtATOutputSetupDlg->outputDataList);
		if (NULL != this->qtATOtherSetupsDlg)
			fileContent.append(this->qtATOtherSetupsDlg->otherDataList);
		if (0 != fileContent.length())
		{
			bool ok = file->open(QIODevice::Text | QIODevice::WriteOnly);
			if (!ok)
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong:!";
				QMessageBox::critical(this, "����", "�ļ���ʧ��");
				return;
			}
			for (size_t i = 0; i < fileContent.length(); i++)
			{
				//д�ļ�
				file->write(fileContent[i].toStdString().c_str(), fileContent[i].toStdString().length());
			}
			file->close();
		}
		else
		{
			QMessageBox::warning(this,"����:","������˵������������Ϊ��, ����һ�����ļ�!");
			bool ok = file->open(QIODevice::Text | QIODevice::WriteOnly);
			if (!ok)
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong:!";
				QMessageBox::critical(this, "����", "�ļ�����ʧ�ܣ�");
				return;
			}
			file->close();
		}
	}
}

//Mimics
void ArteryTechQtProject::ActDivisionSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//QString Exefilepathname = QFileDialog::getOpenFileName(this, "open exe", QDir::currentPath()).trimmed();
	//QString Exefilename = "\"C:/Program Files/Geomagic/Geomagic Foundation 2014/Studio.exe\"";
	//����������ϼ������ţ����Դ�����ļ���·�����Ƕ����пո�������������пո񲻼��������ǲ��������򿪵�
	//"D:\Program Files\Materialise\Mimics Research 21.0\MimicsResearch.exe"
	//QString Exefilename = "\"D:/work/Materialise/Mimics Research 21.0/MimicsResearch.exe\"";
	QString Exefilename = "\"D:/Program Files/Materialise/Mimics Research 21.0/MimicsResearch.exe\"";
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Exefilename:" << Exefilename;
	processDivision->start(Exefilename);
	//processDivision->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

//Geomagic
void ArteryTechQtProject::ActGeomagicSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//QString Exefilename = "\"D:/work/Geomagic/Studio.exe\"";
	//"D:\Program Files\Geomagic\Geomagic Foundation 2014\Studio.exe"
	QString Exefilename = "\"D:/Program Files/Geomagic/Geomagic Foundation 2014/Studio.exe\"";
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Exefilename:" << Exefilename;
	processGeomagic->start(Exefilename);
	//processGeomagic->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

//ansys
void ArteryTechQtProject::ActMeshSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//"D:\Program Files\ANSYS Inc\v145\icemcfd\win64_amd\bin\icemcfd.bat"
	//QString Exefilename = "\"D:/work/ANSYS Inc/v145/icemcfd/win64_amd/bin/icemcfd.bat\"";
	QString Exefilename = "\"D:/Program Files/ANSYS Inc/v145/icemcfd/win64_amd/bin/icemcfd.bat\"";
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Exefilename:" << Exefilename;
	processMesh->start(Exefilename);
	//processMesh->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

void ArteryTechQtProject::ActComputeSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	TcpClientDialog *clientDialog = new TcpClientDialog;
	clientDialog->fileTcpClientUi();
	clientDialog->show();
}

//paraview
void ArteryTechQtProject::ActViewSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//"D:\Program Files\ParaView 5.3.0-Qt5-OpenGL2-Windows-64bit\bin\paraview.exe"
	//QString Exefilename = "\"D:/work/ParaView 5.3.0/bin/paraview.exe\"";
	QString Exefilename = "\"D:/Program Files/ParaView 5.3.0-Qt5-OpenGL2-Windows-64bit/bin/paraview.exe\"";
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Exefilename:" << Exefilename;
	processCompute->start(Exefilename);
	//processCompute->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

void ArteryTechQtProject::ActExecutionscriptSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	TcpClientDialog *clientDialog = new TcpClientDialog;
	clientDialog->sshTcpClientUi();
	clientDialog->show();
}

//����QProcess��putty����
void ArteryTechQtProject::ActOpenPuttySlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	PuttyInformationDialog *puttyInformationDialog = new PuttyInformationDialog(this);
	QObject::connect(puttyInformationDialog,SIGNAL(PuttyInfoSignal(puttyInformation*)),this,SLOT(getPuttyInfoSignal(puttyInformation*)));
	puttyInformationDialog->show();
#if 0
	QString program = "D:/software/putty2186/putty64.exe";

	QStringList arguments;
	//arguments << "-pw" << "wang" << QString("%1@%2").arg("root").arg("192.168.0.121") << "22";
	arguments << "-pw" << "1234567" << QString("%1@%2").arg("cfg").arg("192.168.0.121") << "22";

	/*for (int i = 0; i < arguments.length(); i++)
	{
		qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "arguments[i]:" << arguments.at(i);
	}*/
	//QProcess *process = new QProcess(this);
	processPutty->setProcessChannelMode(QProcess::SeparateChannels);
	processPutty->setReadChannel(QProcess::StandardOutput);
	processPutty->start(program, arguments, QIODevice::ReadWrite);
	connect(processPutty, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
#endif
}

//���̴������з��غ���
void ArteryTechQtProject::ProcessError(QProcess::ProcessError error)
{
	switch (error)
	{
	case QProcess::FailedToStart:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ <<" LOG:" << "FailedToStart";
		QMessageBox::information(0, "��Ϣ", "��ʼʧ�ܣ�");
		break;
	case QProcess::Crashed:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Crashed";
		QMessageBox::information(0, "��Ϣ", "������");
		break;
	case QProcess::Timedout:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Timedout";
		QMessageBox::information(0, "��Ϣ", "��ʱ��");
		break;
	case QProcess::WriteError:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "WriteError";
		QMessageBox::information(0, "��Ϣ", "�������");
		break;
	case QProcess::ReadError:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ReadError";
		QMessageBox::information(0, "��Ϣ", "��ȡ����");
		break;
	case QProcess::UnknownError:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "UnknownError";
		QMessageBox::information(0, "��Ϣ", "δ֪����");
		break;
	default:
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "UnknownError";
		QMessageBox::information(0, "��Ϣ", "δ֪����");
		break;
	}

}

//�����˵�½��ť֮�󣬵�½����ֱ�����أ�Ȼ����ʾ�������
void ArteryTechQtProject::MainUI()
{
	//��Menu��ӵ�MenuBar��
	ui.menuBar->clear();
	ui.menuBar->addMenu(loadFileMenu);
	ui.menuBar->addMenu(solverMenu);
	//ui.menuBar->addMenu(HBFlowsHelpMenu);
	//��action��ӵ�mainToolBar
	ui.mainToolBar->addAction(actDivision);
	ui.mainToolBar->addAction(actGeomagic);
	ui.mainToolBar->addAction(actMesh);
	//ui.mainToolBar->addAction(actionCompute);
	ui.mainToolBar->addAction(actView);
	ui.mainToolBar->addAction(actHelp);
	//ui.mainToolBar->addAction(actionExecutionscript);
	//ui.mainToolBar->addAction(actionPutty);
	//ui.mainToolBar->addAction(actionReport);
	//ui.mainToolBar->addAction(actEncryptedFile);
	//ui.mainToolBar->addAction(actGetResults);//����ȡ������Action��ӵ�mainToolBar


	QObject::connect(actLoadPicture, SIGNAL(triggered(bool)), this, SLOT(ActOpenpictureSlot()));
	QObject::connect(actLoadDicomPicture, SIGNAL(triggered(bool)), this, SLOT(ActOpenDicompictureSlot()));
	QObject::connect(actLastInput, SIGNAL(triggered(bool)), this, SLOT(ActLastInputSlot()));
	QObject::connect(actMeshSetup, SIGNAL(triggered(bool)), this, SLOT(ActMeshSetupSlot()));
	QObject::connect(actBoundarySetup, SIGNAL(triggered(bool)), this, SLOT(ActBoundarySetupSlot()));
	QObject::connect(actPhysicsSetup, SIGNAL(triggered(bool)), this, SLOT(ActPhysicsSetupSlot()));
	QObject::connect(actNonlinearSolverSetup, SIGNAL(triggered(bool)), this, SLOT(ActNonlinearSolverSetupSlot()));
	QObject::connect(actLinearSolverSetup, SIGNAL(triggered(bool)), this, SLOT(ActLinearSolverSetupSlot()));
	QObject::connect(actPreconditionerSetup, SIGNAL(triggered(bool)), this, SLOT(ActPreconditionerSetupSlot()));
	QObject::connect(actTwoLevelPreconditioner, SIGNAL(triggered(bool)), this, SLOT(ActTwoLevelPreconditionerSlot()));
	QObject::connect(actOutputSetup, SIGNAL(triggered(bool)), this, SLOT(ActOutputSetupSlot()));
	QObject::connect(actOtherSetup, SIGNAL(triggered(bool)), this, SLOT(ActOtherSetupsSlot()));
	QObject::connect(actSaveOption, SIGNAL(triggered(bool)), this, SLOT(ActSaveOptionSlot()));
	QObject::connect(actDivision, SIGNAL(triggered(bool)), this, SLOT(ActDivisionSlot()));
	QObject::connect(actGeomagic, SIGNAL(triggered(bool)), this, SLOT(ActGeomagicSlot()));
	QObject::connect(actMesh, SIGNAL(triggered(bool)), this, SLOT(ActMeshSlot()));
	//QObject::connect(actionCompute, SIGNAL(triggered(bool)), this, SLOT(ActionComputeSlot()));
	QObject::connect(actView, SIGNAL(triggered(bool)), this, SLOT(ActViewSlot()));
	//QObject::connect(actionExecutionscript, SIGNAL(triggered(bool)), this, SLOT(ActionExecutionscriptSlot()));
	//QObject::connect(actionPutty, SIGNAL(triggered(bool)), this, SLOT(ActOpenPuttySlot()));
	//QObject::connect(actionReport, SIGNAL(triggered(bool)), this, SLOT(ActReportHtmlSlot()));
	//actionSaveCPR
	QObject::connect(actSaveCPR, SIGNAL(triggered(bool)), this, SLOT(ActSaveCPRSlot()));
	//actEncryptedFile
	QObject::connect(actEncryptedFile, SIGNAL(triggered(bool)), this, SLOT(ActEncryptedFileSlot()));//�����ļ�
	//QObject::connect(actGetResults, SIGNAL(triggered(bool)), this, SLOT(ActGetResultsSlot()));//�����ļ�

	return;
}

void ArteryTechQtProject::ActReportHtmlSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	HtmlCreatedWord *htmlCreatedWord = new HtmlCreatedWord(this);
}

//����Qt����doc �����ļ�,��Ҫʹ��.dotģ���ļ�
void ArteryTechQtProject::ActReportSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	//QMessageBox::about(this,"information","Report is clicked()");
	QAxWidget *word = new QAxWidget("Word.Application", this, Qt::MSWindowsOwnDC);
	word->setProperty("Visible", true);
	//get all documents
	QAxObject *documents = word->querySubObject("Documents");
	//build a tempetate with .dot file
	documents->dynamicCall("Add(QString)", QString::fromLocal8Bit("E:/template.dot"));
	//get the current actived document
	QAxObject *document = word->querySubObject("ActiveDocument");
	//template.dot�ļ���ǩ��ʾpic1,code1,pic2,pic3,pic4,pic5,pic6
	
	//pic6
	QString pic6 = "pic6";
	QAxObject *bookmark_pic6 = document->querySubObject("Bookmarks(QVariant)", pic6);
	if (!bookmark_pic6->isNull())
	{
		bookmark_pic6->dynamicCall("Select(void)");
		QAxObject *shapes6 = document->querySubObject("InlineShapes");
		shapes6->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture6.png");
	}

	//pic5
	QString pic5 = "pic5";
	QAxObject *bookmark_pic5 = document->querySubObject("Bookmarks(QVariant)", pic5);
	if (!bookmark_pic5->isNull())
	{
		bookmark_pic5->dynamicCall("Select(void)");
		QAxObject *shapes5 = document->querySubObject("InlineShapes");
		shapes5->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture5.png");
	}

	//pic4
	QString pic4 = "pic4";
	QAxObject *bookmark_pic4 = document->querySubObject("Bookmarks(QVariant)", pic4);
	if (!bookmark_pic4->isNull())
	{
		bookmark_pic4->dynamicCall("Select(void)");
		QAxObject *shapes4 = document->querySubObject("InlineShapes");
		shapes4->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture4.png");
	}
	
	//pic3
	QString pic3 = "pic3";
	QAxObject *bookmark_pic3 = document->querySubObject("Bookmarks(QVariant)", pic3);
	if (!bookmark_pic3->isNull())
	{
		bookmark_pic3->dynamicCall("Select(void)");
		QAxObject *shapes3 = document->querySubObject("InlineShapes");
		shapes3->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture3.png");
	}
	
	//pic2
	QString pic2 = "pic2";
	QAxObject *bookmark_pic2 = document->querySubObject("Bookmarks(QVariant)", pic2);
	if (!bookmark_pic2->isNull())
	{
		bookmark_pic2->dynamicCall("Select(void)");
		QAxObject *shapes2 = document->querySubObject("InlineShapes");
		shapes2->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture2.png");
	}

	//code2
	QString code2 = "code2";
	QAxObject *bookmark_code2 = document->querySubObject("Bookmarks(QVariant)", code2);
	QString code1Text2 = "    Absence ";
	if (!bookmark_code2->isNull())
	{
		bookmark_code2->dynamicCall("Select(void)");
		bookmark_code2->querySubObject("Range")->setProperty("Text", code1Text2);
	}
	
	//��ǩΪcode1
	QString code = "code1";
	QAxObject *bookmark_code = document->querySubObject("Bookmarks(QVariant)", code);
	QString code1Text = "code1";
	if (!bookmark_code->isNull())
	{
		bookmark_code->dynamicCall("Select(void)");
		bookmark_code->querySubObject("Range")->setProperty("Text", code1Text);
	}

	//��ǩΪpic1
	QString pic1 = "pic1";
	QAxObject *bookmark_pic = document->querySubObject("Bookmarks(QVariant)", pic1);
	if (!bookmark_pic->isNull())
	{
		bookmark_pic->dynamicCall("Select(void)");
		QAxObject *shapes = document->querySubObject("InlineShapes");
		shapes->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture1.png");
	}
#if 0
	QAxObject *bookmark_ndvi = document->querySubObject("Bookmarks(QVariant)", "ndvi");
	if (!bookmark_ndvi->isNull())
	{
		bookmark_ndvi->dynamicCall("Select(void)");
		bookmark_ndvi->querySubObject("Range")->setProperty("Text", "ndvi");
	}

	QAxObject *bookmark_ndvi2 = document->querySubObject("Bookmarks(QVariant)", "ndvi");
	if (!bookmark_ndvi2->isNull())
	{
		bookmark_ndvi2->dynamicCall("Select(void)");
		bookmark_ndvi2->querySubObject("Range")->setProperty("Text", "ndvi2");
	}

	QAxObject *bookmark_pic = document->querySubObject("Bookmarks(QVariant)", "pic");
	if (!bookmark_pic->isNull())
	{
		bookmark_pic->dynamicCall("Select(void)");
		QAxObject *shapes = document->querySubObject("InlineShapes");
		shapes->dynamicCall("AddPicture(Const QString&)", "F:\\CND.jpg");

	}
#endif
	document->dynamicCall("SaveAs (const QString&)", QString("E:/testword.doc"));
	document->dynamicCall("Close(boolean)", false);
	word->dynamicCall("Quit()");
}
#if 0

//����Qt����doc �����ļ�
void ArteryTechQtProject::actionReportSlots()
{
	//QMessageBox::about(this,"information","Report is clicked()");
	QAxWidget *word = new QAxWidget("Word.Application", this, Qt::MSWindowsOwnDC);
	word->setProperty("Visible", true);
	//get all documents
	QAxObject *documents = word->querySubObject("Documents");
	//build a tempetate with .dot file
	documents->dynamicCall("Add(QString)", QString::fromLocal8Bit("E:/template.dot"));
	//get the current actived document
	QAxObject *document = word->querySubObject("ActiveDocument");  
	//template.dot�ļ���ǩ��ʾpic1,code1,pic2,pic3,pic4,pic5,pic6
	//��ǩΪpic1
	QString pic1 = "pic1";
	QAxObject *bookmark_pic = document->querySubObject("Bookmarks(QVariant)", pic1);
	if (!bookmark_pic->isNull())
	{
		bookmark_pic->dynamicCall("Select(void)");
		QAxObject *shapes = document->querySubObject("InlineShapes");
		shapes->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture1.png");
	}
	//��ǩΪcode1
	QString code = "code1";
	QAxObject *bookmark_code = document->querySubObject("Bookmarks(QVariant)", code);
	QString code1Text = "    Absence of nitrate administration during cCTA acquisition may adversely affect the accuracy of the HeartFlow FFRCT Analysis. HeartFlow Analysis simulates maximal coronary hyperemia.Induction of coronary hyperemia commonly includes vasodilation of the epicardial coronary arteries via nitrate administration. Therefore, HeartFlow recommends following SCCT Guidelines for cCTA acquisition, which include the use of sublingual nitrates at the time of image acquisition.4 ";
	if (!bookmark_code->isNull())
	{
		bookmark_code->dynamicCall("Select(void)");
		bookmark_code->querySubObject("Range")->setProperty("Text", code1Text);
	}
	QString code2 = "code2";
	QAxObject *bookmark_code2 = document->querySubObject("Bookmarks(QVariant)", code2);
	QString code1Text2 = "    Absence ";
	if (!bookmark_code2->isNull())
	{
		bookmark_code2->dynamicCall("Select(void)");
		bookmark_code2->querySubObject("Range")->setProperty("Text", code1Text2);
	}
	//pic2
	QString pic2 = "pic2";
	QAxObject *bookmark_pic2 = document->querySubObject("Bookmarks(QVariant)", pic2);
	if (!bookmark_pic2->isNull())
	{
		bookmark_pic2->dynamicCall("Select(void)");
		QAxObject *shapes2 = document->querySubObject("InlineShapes");
		shapes2->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture2.png");
	}
	//pic3
	QString pic3 = "pic3";
	QAxObject *bookmark_pic3 = document->querySubObject("Bookmarks(QVariant)", pic3);
	if (!bookmark_pic3->isNull())
	{
		bookmark_pic3->dynamicCall("Select(void)");
		QAxObject *shapes3 = document->querySubObject("InlineShapes");
		shapes3->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture3.png");
	}
	//pic4
	QString pic4 = "pic4";
	QAxObject *bookmark_pic4 = document->querySubObject("Bookmarks(QVariant)", pic4);
	if (!bookmark_pic4->isNull())
	{
		bookmark_pic4->dynamicCall("Select(void)");
		QAxObject *shapes4 = document->querySubObject("InlineShapes");
		shapes4->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture4.png");
	}
	//pic5
	QString pic5 = "pic5";
	QAxObject *bookmark_pic5 = document->querySubObject("Bookmarks(QVariant)", pic5);
	if (!bookmark_pic5->isNull())
	{
		bookmark_pic5->dynamicCall("Select(void)");
		QAxObject *shapes5 = document->querySubObject("InlineShapes");
		shapes5->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture5.png");
	}
	//pic6
	QString pic6 = "pic6";
	QAxObject *bookmark_pic6 = document->querySubObject("Bookmarks(QVariant)", pic6);
	if (!bookmark_pic6->isNull())
	{
		bookmark_pic6->dynamicCall("Select(void)");
		QAxObject *shapes6 = document->querySubObject("InlineShapes");
		shapes6->dynamicCall("AddPicture(Const QString&)", "E:/wpicture/picture6.png");
	}
#if 0
	QAxObject *bookmark_ndvi = document->querySubObject("Bookmarks(QVariant)", "ndvi");
	if (!bookmark_ndvi->isNull())
	{
		bookmark_ndvi->dynamicCall("Select(void)");
		bookmark_ndvi->querySubObject("Range")->setProperty("Text", "ndvi");
	}

	QAxObject *bookmark_ndvi2 = document->querySubObject("Bookmarks(QVariant)", "ndvi");
	if (!bookmark_ndvi2->isNull())
	{
		bookmark_ndvi2->dynamicCall("Select(void)");
		bookmark_ndvi2->querySubObject("Range")->setProperty("Text", "ndvi2");
	}

	QAxObject *bookmark_pic = document->querySubObject("Bookmarks(QVariant)", "pic");
	if (!bookmark_pic->isNull())
	{
		bookmark_pic->dynamicCall("Select(void)");
		QAxObject *shapes = document->querySubObject("InlineShapes");
		shapes->dynamicCall("AddPicture(Const QString&)", "F:\\CND.jpg");

	}
#endif
	document->dynamicCall("SaveAs (const QString&)", QString("E:/testword.doc"));
	document->dynamicCall("Close(boolean)", false);
	word->dynamicCall("Quit()");
}
#endif
void ArteryTechQtProject::ActHelpSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	this->help->show();
}

//���ݴ��ڵĴ�С���Ʊ���ͼƬ
void ArteryTechQtProject::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, ui.centralWidget->width(), ui.centralWidget->height(), QPixmap("images/backgroundpicture.png"));
}

void ArteryTechQtProject::closeEvent(QCloseEvent *event)
{
	QString filepathname = "tmp.txt";
	if (m_saveOptionFlag)
	{
		//�����˳�
		QFile *file = new QFile(filepathname);
		bool fileExistStatus = file->exists();
		if (fileExistStatus)
		{
			file->remove();
		}
		close();
		return;
	}
 	

	//qDebug() << "save file path name:" << filepathname;
	if (NULL == filepathname)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Please select the save data file!";
		QMessageBox::critical(this, "����:", "��ѡ����Ҫ������ļ���");
		return;
	}
	else
	{
		QStringList fileContent;
		QFile *file = new QFile(filepathname);
		bool existStatus = file->exists();
		if (existStatus)
		{
			//�ļ�������ɾ��
			file->remove();
		}
		//file->write(contenttext.toStdString().c_str(), contenttext.length() + 2);
		//���ν��˵������ϵ�����׷�ӵ�fileContent�б���
		if(NULL != this->qtATMeshSetupDlg)
			fileContent.append(this->qtATMeshSetupDlg->meshSetupDataList);
		if (NULL != this->qtATBoundarysetupDlg)
			fileContent.append(this->qtATBoundarysetupDlg->boundaryDataList);
		if (NULL != this->qtATPhysicsSetupDlg)
			fileContent.append(this->qtATPhysicsSetupDlg->physicsDataList);
		if (NULL != this->qtATNonlinearsolversetupDlg)
			fileContent.append(this->qtATNonlinearsolversetupDlg->nonlinearSolverDataList);
		if (NULL != this->qtATLinearSolverSetupDlg)
			fileContent.append(this->qtATLinearSolverSetupDlg->linearSolverDataList);
		if (NULL != this->qtATPreconditionerSetupDlg)
			fileContent.append(this->qtATPreconditionerSetupDlg->preconditionerDataList);
		if (NULL != this->qtATTwoLevelPreconditionerDlg)
			fileContent.append(this->qtATTwoLevelPreconditionerDlg->twoLPreconditionerDataList);
		if (NULL != this->qtATOutputSetupDlg)
			fileContent.append(this->qtATOutputSetupDlg->outputDataList);
		if (NULL != this->qtATOtherSetupsDlg)
			fileContent.append(this->qtATOtherSetupsDlg->otherDataList);
		if (0 != fileContent.length())
		{
			bool ok = file->open(QIODevice::Text | QIODevice::WriteOnly);
			if (!ok)
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong:!";
				QMessageBox::critical(this, "����:", "�ļ���ʧ�ܣ�");
				return;
			}
			for (size_t i = 0; i < fileContent.length(); i++)
			{
				//д�ļ�
				file->write(fileContent[i].toStdString().c_str(), fileContent[i].toStdString().length());
			}
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Software abnormal exit!";
			file->close();
		}	
	}
	close();
}
//��������
ArteryTechQtProject::~ArteryTechQtProject()
{

	delete actDivision;
	delete actGeomagic;
	delete actMesh;
	//delete actionCompute;
	delete actView;
	//delete actionExecutionscript;
	//delete actionPutty;

	delete processDivision;
	delete processGeomagic;
	delete processMesh;
	delete processCompute;
	delete processView;
	delete processPutty;

	delete qtATMeshSetupDlg;
	delete qtATBoundarysetupDlg;
	delete qtATPhysicsSetupDlg;
	delete qtATNonlinearsolversetupDlg;
	delete qtATLinearSolverSetupDlg;
	delete qtATPreconditionerSetupDlg;
	delete qtATTwoLevelPreconditionerDlg;
	delete qtATOutputSetupDlg;
	delete qtATOtherSetupsDlg;
}

//��Сд��ת����
QString ArteryTechQtProject::UpperEncryption(QString pretext)
{
	QByteArray text = pretext.toLocal8Bit();
	QByteArray by = text.toBase64();
	QString str = QString(by);
	str = ToUpperAndLower(str); // ����
	return str;
}

//��Сд��ת����
QString ArteryTechQtProject::UpperDecryption(QString pretext)
{
	QString str = ToUpperAndLower(pretext); //����
	QByteArray text = str.toLocal8Bit();
	QByteArray by = text.fromBase64(text);
	str = QString::fromLocal8Bit(by);
	return str;
}

//������
QString ArteryTechQtProject::XorEncryption(QString pretext)
{
	QByteArray text = pretext.toLocal8Bit();
	QByteArray by = text.toBase64();
	QString str = QString(by);
	str = ToXOREncryptUncrypt(str, '~'); // ���� --- ע�⣺�������key�ǿ���ָ��Ϊ�����ַ��ģ���Ӧ�ģ�����ҲҪͬ���ַ����У�
	return str;
}

//������
QString ArteryTechQtProject::XorDecryption(QString pretext)
{
	QString str = ToXOREncryptUncrypt(pretext, '~'); //����
	QByteArray text = str.toLocal8Bit();
	QByteArray by = text.fromBase64(text);
	str = QString::fromLocal8Bit(by);
	return str;
}



//��Сд��ת���ܺͽ���
QString ArteryTechQtProject::ToUpperAndLower(QString src)
{
	for (int i = 0; i < src.count(); i++) {
		QChar curC = src.at(i);
		if (curC.isUpper()) {
			curC = curC.toLower();
		}
		else if (curC.isLower()) {
			curC = curC.toUpper();
		}
		src[i] = curC;
	}
	return src;
}

//�����ܺͽ���
QString ArteryTechQtProject::ToXOREncryptUncrypt(QString src, const QChar key)
{
	for (int i = 0; i < src.count(); i++) {
		src[i] = src.at(i).toLatin1() ^ key.toLatin1();
	}
	return src;
}

void ArteryTechQtProject::ActLastInputSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	AbnormalData *abnormalData = new AbnormalData(m_tmpFileName);
	abnormalData->show();
#if 0
	QString filepathname = "tmp.txt";

	//qDebug() << "save file path name:" << filepathname;
	if (NULL == filepathname)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Please select the save data file!";
		QMessageBox::information(this, "Info Message", "Please select the save data file!");
		return;
	}
	else
	{
		//QStringList fileContent;
		QFile *file = new QFile(filepathname);
		bool existStatus = file->exists();
		if (existStatus)
		{
			AbnormalData *abnormalData = new AbnormalData();
			abnormalData->show();
		}
		else
		{
			//�ļ������ڣ������ڳ���֮ǰ����Ϣ
			QMessageBox::information(this,"information:","NO ERROR INFORMATION!");
		}
	}
#endif
}

void ArteryTechQtProject::GetPuttyInfoSignal(puttyInformation* puttyInfo)
{
	m_puttyInfon = puttyInfo;
	QString program = "\"D:/work/putty/putty64.exe\"";

	QStringList arguments;
	arguments << "-pw" << puttyInfo->m_password << QString("%1@%2").arg(puttyInfo->m_username).arg(puttyInfo->m_ip) << puttyInfo->m_port;
	//arguments << "-pw" << "1234567" << QString("%1@%2").arg("cfg").arg("192.168.0.121") << "22";

	//��putty��Ϣ���浽�ļ�
	QString puttyInfoFile = "puttyInfo";
	QFile file(puttyInfoFile);
	bool openStatus = file.open(QIODevice::WriteOnly|QIODevice::Text);
	if (openStatus)
	{
		file.write("username:");
		file.write(m_puttyInfon->m_username.toStdString().c_str());
		file.write("\n");
		file.write("password:");
		file.write(m_puttyInfon->m_password.toStdString().c_str());
		file.write("\n");
		file.write("ip:");
		file.write(m_puttyInfon->m_ip.toStdString().c_str());
		file.write("\n");
		file.write("port:");
		file.write(m_puttyInfon->m_port.toStdString().c_str());
		file.write("\n");
		file.close();
	}

	processPutty->setProcessChannelMode(QProcess::SeparateChannels);
	processPutty->setReadChannel(QProcess::StandardOutput);
	processPutty->start(program, arguments, QIODevice::ReadWrite);
	connect(processPutty, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
}

//�����ļ��ۺ���
void ArteryTechQtProject::ActEncryptedFileSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	encryptedFileDialog->show();
}

//���ɼ����������ۺ���
void ArteryTechQtProject::ActSaveCPRSlot()
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	QString CPRFileName = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath(), tr("Images (*.xls *.xlsx *.doc *.docx)"));
	if (NULL == CPRFileName)
	{
		QMessageBox::warning(this,"���棺","��ѡ����Ҫ������ļ���");
		return;
	}
	QFile file(CPRFileName);
	bool openStatus = file.open(QIODevice::WriteOnly);
	if (!openStatus)
	{
		QMessageBox::critical(this,"����","�ļ���ʧ�ܣ�");
		return;
	}
	file.write("\t�����������\n");
	QStringList SetupUiList = this->qtATMeshSetupDlg->GetMeshData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Mesh Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATBoundarysetupDlg->GetBoundaryData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Boundary Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATPhysicsSetupDlg->GetPhysicsData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Physics Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATNonlinearsolversetupDlg->GetTechNonlinearSolverData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Nonlinear Solver Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATLinearSolverSetupDlg->GetTechLinearSolverData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Linear Solver Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATPreconditionerSetupDlg->GetTechPreconditionerData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Preconditioner Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATTwoLevelPreconditionerDlg->GetTLPreconditionerData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Two-Level Preconditioner \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATOutputSetupDlg->GetOutputData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Output Setup \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}

	SetupUiList = this->qtATOtherSetupsDlg->GetTechOtherData();
	if (SetupUiList.length() != 0)
	{
		QString SetupStr = "Other Setups \n";
		file.write(SetupStr.toLocal8Bit().data(), qstrlen(SetupStr.toLocal8Bit().data()));
		for (size_t i = 0; i < SetupUiList.length(); i++)
		{
			file.write("\t");
			file.write(SetupUiList.at(i).toLocal8Bit().data(), qstrlen(SetupUiList.at(i).toLocal8Bit().data()));
			file.write("\n");
		}
	}
	
	QString fileEnd = "�����ˣ�\tУ���ˣ�\tʱ�䣺\n";
	file.write(fileEnd.toLocal8Bit().data(), qstrlen(fileEnd.toLocal8Bit().data()));
	file.close();
}

//��갴���¼�
void ArteryTechQtProject::mousePressEvent(QMouseEvent *event)
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	// ���������������
	if (event->button() == Qt::LeftButton)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "������갴ѹ����¼�!";
	}
	// ���������Ҽ�����
	else if (event->button() == Qt::RightButton)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "������갴ѹ�һ��¼�!";
	}
}

//����ƶ��¼�
void ArteryTechQtProject::mouseMoveEvent(QMouseEvent *event)
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	m_startTime = QDateTime::currentDateTime().toTime_t();
	// �������ʹ��buttons()
	if (event->buttons() & Qt::LeftButton) //���еİ�λ��
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��������ƶ��¼�!";
	}
}

//����ͷ��¼�
void ArteryTechQtProject::mouseReleaseEvent(QMouseEvent *event)
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	m_startTime = QDateTime::currentDateTime().toTime_t();
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��������ɿ��¼�!";
}

//���˫���¼�
void ArteryTechQtProject::mouseDoubleClickEvent(QMouseEvent *event)
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	// ���������������
	if (event->button() == Qt::LeftButton) {

		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "�������˫���¼�!";
	}
}

//�������¼�
void ArteryTechQtProject::wheelEvent(QWheelEvent *event)
{
	m_startTime = QDateTime::currentDateTime().toTime_t();
	if (event->delta() > 0)// ������Զ��ʹ����ʱ
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����������ǰ���¼�!";
	}
	else//��������ʹ���߷�����תʱ
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "���������ֺ����¼�!";
	}
}

//��ʱ����ʱ�ۺ���
void ArteryTechQtProject::TimeoutSlot()
{
	uint itime = QDateTime::currentDateTime().toTime_t();
	int timeDifference = itime - m_startTime;
	int closeTime = 60 - timeDifference;
	//QMessageBox *messageBox = new QMessageBox(QMessageBox::Information, "����:", "���ڳ�ʱ��û��ʹ�ø����������" + QString::number(closeTime) + "��֮���˳����ϵͳ��", QMessageBox::Close, this);
	//QMessageBox *messageBox = new QMessageBox(QMessageBox::Information, "����:", "���ڳ�ʱ��û��ʹ�ø����������" + QString::number(closeTime) + "��֮���˳����ϵͳ��", this);
	//messageBox->show();
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ʱ��" << timeDifference;
	if (itime - m_startTime > 3600)
	{
		QMessageBox::warning(this,"���棺","���ڳ�ʱ��û��ʹ�ø���������˳������ϵͳ,�����´���������е�¼��");
		close();
	}
}

//ͨ���ۺ�����ȡBoundaryType��ֵ
void ArteryTechQtProject::GetBoundaryTypeSlot(QString boundaryTypeText)
{
	m_boundaryTypeText = boundaryTypeText;
}

//�����źź���
void ArteryTechQtProject::SendBoundaryTypeToPhysicsSetup()
{
	emit BoundaryTypeToPhysicsSetupSignal(m_boundaryTypeText);
}

void ArteryTechQtProject::ActGetResultsSlot()
{
	GetCalculationResultsDialog *getCalculationResultsDialog = new GetCalculationResultsDialog(this);
	getCalculationResultsDialog->show();
}