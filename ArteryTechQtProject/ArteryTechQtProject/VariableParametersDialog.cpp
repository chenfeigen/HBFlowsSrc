#include "VariableParametersDialog.h"
#include "ui_VariableParametersDialog.h"
using namespace std;

VariableParametersDialog::VariableParametersDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::VariableParametersDialog();
	ui->setupUi(this);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	setMaximumSize(720, 651);
	setMinimumSize(720, 651);
	setWindowTitle("�ɱ��������");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //���ô��������С��
	ui->ShowSolutionCheckBox->setChecked(true);
	ui->ShowMeshDataCheckBox->setChecked(true);
	//��ʼ�����ð�ť����ɹ����ý���֮ǰ��ȷ����ť��ȡ����ť����ʼ��Ϊ��Ч
	ui->ConfirmPushButton->setEnabled(false);
	ui->CancelPushButton->setEnabled(false);
	//�ź���ܺ���������
	QObject::connect(ui->InputPushButton,SIGNAL(clicked(bool)),this,SLOT(InputPushButtonSlot()));
	QObject::connect(ui->SetPushButton, SIGNAL(clicked(bool)), this, SLOT(SetPushButtonSlot()));
	QObject::connect(ui->ConfirmPushButton, SIGNAL(clicked(bool)), this, SLOT(ConfirmPushButtonSlot()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlot()));
	QObject::connect(ui->ExecMatlabPushButton, SIGNAL(clicked(bool)), this, SLOT(ExecMatlabPushButtonSlot()));
}

VariableParametersDialog::~VariableParametersDialog()
{
	delete ui;
}


void  VariableParametersDialog::InputPushButtonSlot()
{
	QString fileFullPathName = QFileDialog::getOpenFileName(this,"��",QDir::currentPath(),tr("Images *.xlsx"));
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this, "����:", "�ļ�ѡ����Ч��������ѡ��");
		return;
	}
	ui->lineEdit->setText(fileFullPathName);

	QFileInfo fileInfo(fileFullPathName);
	QString fileName = fileInfo.fileName();
	QString name = fileName.split(".").at(0);
	QString FileNameLineEdit = "./mesh/" + name + ".exo";
	ui->FileNameLineEdit->setText(FileNameLineEdit);
	//===========================���ý����ϵ��ļ���
	QString nodeAndSideSetFileText = name + ".bc";
	ui->NodeAndSideSetFileLineEdit->setText(nodeAndSideSetFileText);
	QString inletFlowRateFileText = name + ".in";
	ui->InletFlowRateFileLineEdit->setText(inletFlowRateFileText);
	QString solutionOutputFileText = "./results/" + name;
	ui->SolutionOutputFileLineEdit->setText(solutionOutputFileText);
	QString FFRMonitorFileText = "./results/" + name + ".ffr";
	ui->FFRMonitorFileLineEdit->setText(FFRMonitorFileText);
	QString flowRateMonitorFileText = "./results/" + name + ".flow";
	ui->FlowRateMonitorFileLineEdit->setText(flowRateMonitorFileText);

	QObject::connect(ui->FileNameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(FileNameLineEditSlot()));
}

void VariableParametersDialog::SetPushButtonSlot()
{
	QString fileFullPathName = ui->lineEdit->text().trimmed();
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this,"����:","���õ�Դ�ļ�����Ϊ�գ���ѡ��һ������Դ�ļ���");
		return;
	}

	//***********************************����excel***************************************
#if 1
	//QString excel_file_path = QDir::currentPath() + "/a.xlsx";//fileName
	QString excel_file_path = fileFullPathName;
	excel_file_path = QDir::toNativeSeparators(excel_file_path);
	QAxObject *excel = new QAxObject(this);//����excel��������
	excel->setControl("Excel.Application");//����Excel�ؼ�
	//excel->setProperty("Visible", true);//��ʾ���忴Ч��
	excel->setProperty("Visible", false);//��ʾ���忴Ч��
	excel->setProperty("DisplayAlerts", true);//��ʾ���濴Ч��
	QAxObject *workbooks = excel->querySubObject
		("WorkBooks");//��ȡ������(excel�ļ�)����
	workbooks->dynamicCall("Open(const QString&)", excel_file_path);
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//��ȡ�������

	QAxObject *worksheets = workbook->querySubObject("WorkSheets");//��ȡ���еĹ�����,��ͼ
	int intCount = worksheets->property("Count").toInt();           //��ȡ�˱�ĸ���

	//�ӵڶ���sheet��ʼ��ȡֵ
	int startsheet = 1;
	//=======================================����sheet2==========================================
	//QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 2);
	QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", startsheet);//startsheetΪ��Ӧ�Ĵ���һ��sheet
	QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet��Χ

	int intRowStart = usedRange->property("Row").toInt();//��ʼ����
	int intColStart = usedRange->property("Column").toInt(); //��ʼ����
	QAxObject *rows, *columns;
	rows = usedRange->querySubObject("Rows");//��
	columns = usedRange->querySubObject("Columns");//��
	int intRow = rows->property("Count").toInt();//����
	int intCol = columns->property("Count").toInt();//����
	//qDebug() << "����:" << intRow;
	//qDebug() << "����:" << intCol;
	QAxObject *cell = NULL;//��ȡ��Ӧ���е�����
	QString cellStr;//��Ӧ���е�����ת����QString
	cellStr.clear();

	for (int i = intRowStart; i  <= intRow; i++)
	{
		for (int j = intColStart; j < intCol; j++)
		{
			cell = worksheet->querySubObject("Cells(int,int)", i, j);
			cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			if (cellStr.compare("����(���)ѹ����������P0") == 0)
			{
				QString p0Text;
				p0Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p0Text.append(cellStr);
				p0Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p0Text.append(cellStr);
				p0Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p0Text.append(cellStr);
				j = intCol;
				ui->RefMonitorPointLineEdit->setText(p0Text);

			}
			else if (cellStr.compare("��һ��Զ��ѹ������P1") == 0)
			{
				QString p1Text;
				p1Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p1Text.append(cellStr);
				p1Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p1Text.append(cellStr);
				p1Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p1Text.append(cellStr);
				ui->MonitorPoint1LineEdit->setText(p1Text);
			}
			else if (cellStr.compare("�ڶ���Զ��ѹ������P2") == 0)
			{
				QString p2Text;
				p2Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p2Text.append(cellStr);
				p2Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p2Text.append(cellStr);
				p2Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p2Text.append(cellStr);
				ui->MonitorPoint2LineEdit->setText(p2Text);
			}
			else if (cellStr.compare("������Զ��ѹ������P3") == 0)
			{
				QString p3Text;
				p3Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p3Text.append(cellStr);
				p3Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p3Text.append(cellStr);
				p3Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p3Text.append(cellStr);
				ui->MonitorPoint3LineEdit->setText(p3Text);
			}
			else if (cellStr.compare("���ĸ�Զ��ѹ������P4") == 0)
			{
				QString p4Text;
				p4Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p4Text.append(cellStr);
				p4Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p4Text.append(cellStr);
				p4Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p4Text.append(cellStr);
				ui->MonitorPoint4LineEdit->setText(p4Text);
			}
			else if (cellStr.compare("�����Զ��ѹ������P5") == 0)
			{
				QString p5Text;
				p5Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p5Text.append(cellStr);
				p5Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p5Text.append(cellStr);
				p5Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p5Text.append(cellStr);
				ui->MonitorPoint5LineEdit->setText(p5Text);
			}
			else if (cellStr.compare("������Զ��ѹ������P6") == 0)
			{
				QString p6Text;
				p6Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p6Text.append(cellStr);
				p6Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p6Text.append(cellStr);
				p6Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p6Text.append(cellStr);
				ui->MonitorPoint6LineEdit->setText(p6Text);
			}
			else if (cellStr.compare("���߸�Զ��ѹ������P7") == 0)
			{
				QString p7Text;
				p7Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p7Text.append(cellStr);
				p7Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p7Text.append(cellStr);
				p7Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p7Text.append(cellStr);
				ui->MonitorPoint7LineEdit->setText(p7Text);
			}
			else if (cellStr.compare("�ڰ˸�Զ��ѹ������P8") == 0)
			{
				QString p8Text;
				p8Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p8Text.append(cellStr);
				p8Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p8Text.append(cellStr);
				p8Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p8Text.append(cellStr);
				ui->MonitorPoint8LineEdit->setText(p8Text);
			}
			else if (cellStr.compare("�ھŸ�Զ��ѹ������P9") == 0)
			{
				QString p9Text;
				p9Text.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p9Text.append(cellStr);
				p9Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				p9Text.append(cellStr);
				p9Text.append(",");
				cell = worksheet->querySubObject("Cells(int,int)", i, ++j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				p9Text.append(cellStr);
				ui->MonitorPoint9LineEdit->setText(p9Text);
			}
			else if (cellStr.compare("���ڸ���") == 0)
			{
				QString numberOfOutletsText;
				numberOfOutletsText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);//�в��䣬�м�4
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				numberOfOutletsText.append(cellStr);
				ui->NumberOfOutletsLineEdit->setText(numberOfOutletsText);
			}
			else if (cellStr.compare("WK3ģ�Ͳ���WKRd") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->RdForWK3LineEdit->setText(RdText);
			}
			else if (cellStr.compare("WK3ģ�Ͳ���WKC") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->CForWK3LineEdit->setText(RdText);
			}
			else if (cellStr.compare("����ʱ��T") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->FinalTimeLineEdit->setText(RdText);
			}
			else if (cellStr.compare("ʱ�䲽��dt") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->TimeStepSizeLineEdit->setText(RdText);
			}
			else if (cellStr.compare("������Rtotal") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->TotalResistanceLineEdit->setText(RdText);
			}
			else if (cellStr.compare("WK3ģ�Ͳ���WKP0") == 0)
			{
				QString RdText;
				RdText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				RdText.append(cellStr);
				j = intCol;
				ui->P0ForWK3LineEdit->setText(RdText);
			}
		}
	}

	workbook->dynamicCall("Close(Boolean)", false);
	excel->dynamicCall("Quit(void)");
	delete excel;
	ui->ConfirmPushButton->setEnabled(true);
	ui->CancelPushButton->setEnabled(true);
#endif
}

void VariableParametersDialog::ConfirmPushButtonSlot()
{
	QStringList uiDateList;
	uiDateList.clear();
	uiDateList.append(ui->FileNameLabel->text().trimmed() + ui->FileNameLineEdit->text().trimmed());
	uiDateList.append(ui->NodeAndSideSetFileLabel->text().trimmed() + ui->NodeAndSideSetFileLineEdit->text().trimmed());
	uiDateList.append(ui->InletFlowRateFileLabel->text().trimmed() + ui->InletFlowRateFileLineEdit->text().trimmed());
	uiDateList.append(ui->RdForWK3Label->text().trimmed() + ui->RdForWK3LineEdit->text().trimmed());
	uiDateList.append(ui->CForWK3Label->text().trimmed() + ui->CForWK3LineEdit->text().trimmed());
	uiDateList.append(ui->FinalTimeLabel->text().trimmed() + ui->FinalTimeLineEdit->text().trimmed());
	uiDateList.append(ui->TimeStepSizeLabel->text().trimmed() + ui->TimeStepSizeLineEdit->text().trimmed());
	uiDateList.append(ui->TotalResistanceLabel->text().trimmed() + ui->TotalResistanceLineEdit->text().trimmed());
	uiDateList.append(ui->P0ForWK3Label->text().trimmed() + ui->P0ForWK3LineEdit->text().trimmed());

	uiDateList.append(ui->ShowSolutionLabel->text().trimmed() + ui->ShowSolutionCheckBox->text().trimmed());
	uiDateList.append(ui->SolutionOutputFileLabel->text().trimmed() + ui->SolutionOutputFileLineEdit->text().trimmed());
	uiDateList.append(ui->ShowMeshDataLabel->text().trimmed() + ui->ShowMeshDataCheckBox->text().trimmed());
	uiDateList.append(ui->FFRMonitorFileLabel->text().trimmed() + ui->FFRMonitorFileLineEdit->text().trimmed());
	uiDateList.append(ui->FlowRateMonitorFileLabel->text().trimmed() + ui->FlowRateMonitorFileLineEdit->text().trimmed());
	uiDateList.append(ui->RefMonitorPointLabel->text().trimmed() + ui->RefMonitorPointLineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint1Label->text().trimmed() + ui->MonitorPoint1LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint2Label->text().trimmed() + ui->MonitorPoint2LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint3Label->text().trimmed() + ui->MonitorPoint3LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint4Label->text().trimmed() + ui->MonitorPoint4LineEdit->text().trimmed());

	uiDateList.append(ui->MonitorPoint5Label->text().trimmed() + ui->MonitorPoint5LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint6Label->text().trimmed() + ui->MonitorPoint6LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint7Label->text().trimmed() + ui->MonitorPoint7LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint8Label->text().trimmed() + ui->MonitorPoint8LineEdit->text().trimmed());
	uiDateList.append(ui->MonitorPoint9Label->text().trimmed() + ui->MonitorPoint9LineEdit->text().trimmed());
	uiDateList.append(ui->NumberOfOutletsLabel->text().trimmed() + ui->NumberOfOutletsLineEdit->text().trimmed());

	/*for (int i = 0; i < uiDateList.length(); i++)
	{
		qDebug() << "uiDateList " << i << ":" << uiDateList.at(i);
	}*/
	//�����ͨ���źŷ��͵���ȥ
	SendVariableParameters(uiDateList);
	close();
}

void VariableParametersDialog::CancelPushButtonSlot()
{
	close();
}

void VariableParametersDialog::FileNameLineEditSlot()
{
	QString fileFullPathName = ui->FileNameLineEdit->text().trimmed();
	if (NULL == fileFullPathName)
	{
		ui->NodeAndSideSetFileLineEdit->setText(NULL);
		ui->InletFlowRateFileLineEdit->setText(NULL);
		ui->SolutionOutputFileLineEdit->setText(NULL);
		ui->FFRMonitorFileLineEdit->setText(NULL);
		ui->FlowRateMonitorFileLineEdit->setText(NULL);
	}
	QFileInfo fileInfo(fileFullPathName);
	QString fileName = fileInfo.fileName();
	QString name = fileName.split(".").at(0);
	/*
		sdz00011000117520114100.bc
		sdz00011000117520114100.in
		./results/sdz00011000117520114100
		./results/sdz00011000117520114100.ffr
		./results/sdz00011000117520114100.flow
	*/
	QString nodeAndSideSetFileText = name + ".bc";
	ui->NodeAndSideSetFileLineEdit->setText(nodeAndSideSetFileText);
	QString inletFlowRateFileText = name + ".in";
	ui->InletFlowRateFileLineEdit->setText(inletFlowRateFileText);
	QString solutionOutputFileText = "./results/" + name;
	ui->SolutionOutputFileLineEdit->setText(solutionOutputFileText);
	QString FFRMonitorFileText = "./results/" + name + ".ffr";
	ui->FFRMonitorFileLineEdit->setText(FFRMonitorFileText);
	QString flowRateMonitorFileText = "./results/" + name + ".flow";
	ui->FlowRateMonitorFileLineEdit->setText(flowRateMonitorFileText);
}

void VariableParametersDialog::SendVariableParameters(QStringList VariableParametersList)
{
	emit VariableParametersSignal(VariableParametersList);
}

//����߽����Ͳۺ���
void VariableParametersDialog::ExecMatlabPushButtonSlot()
{
	//��ȡ��ǰ���г����·��
	QString fileFullPathName = ui->lineEdit->text().trimmed();
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this,"����:","�ļ�����Ϊ�գ����������룡");
		return;
	}
	//QMessageBox::information(this,"����:","����߽����");
	//�½�һ��.sh�ļ���Ȼ����.sh�ļ�����д������
	CreatSHFile(fileFullPathName);
	//�½�һ��.bc�ļ���Ȼ����.bc�ļ�����д������
	CreatBCFile(fileFullPathName);
	QString runPath = QCoreApplication::applicationDirPath();
	QString Exefilename = runPath + "/Matlab.bat";

	QString fileName = fileFullPathName.split(".").at(0);
	//QString Exefilename = "\"E:/Program Files/MATLAB/R2017b/bin/matlab.exe\"";
	process = new QProcess(this);
	connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_readoutput()));
	connect(process, SIGNAL(readyReadStandardError()), this, SLOT(on_readerror()));
	//1������·��
	process->setProgram(Exefilename);
	//2)���ò���
	QStringList arguments;
	arguments.clear();
	arguments.append("caculateboundarypar");
	arguments.append(fileName);
	process->setArguments(arguments);
	process->start(Exefilename, arguments);
	process->waitForFinished();
	delete process;
	//QString readyReadStandardOutputStr = process->readAllStandardOutput().data();
	//qDebug() << "readyReadStandardOutputStr:" << readyReadStandardOutputStr;
	//processGeomagic->execute(Exefilename);//executeִ�иý���֮����ִ�������Ľ���
}

void VariableParametersDialog::on_readoutput()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ִ�б߽��������ɹ���";
}

void VariableParametersDialog::on_readerror()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ִ�б߽��������ʧ�ܣ�";
}

//����.sh�ļ�
void VariableParametersDialog::CreatSHFile(QString m_fileFullPathName)
{
	QString suffix = ".sh";
	QString fileFullPathName = m_fileFullPathName;
	QFileInfo fileInfo(fileFullPathName);
	QString filePath = fileInfo.path();
	QString fileName = fileInfo.fileName();
	QString outputFileName = fileName.split(".").at(0);
	outputFileName.append(suffix);
	QString outputFullPathName = filePath + "/" + outputFileName;

	//��.sh�ļ�����д������
	QFile file(outputFullPathName);
	bool openStatus = file.open(QFile::WriteOnly | QFile::Truncate);
	//bool openStatus = file.open(QIODevice::WriteOnly|QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����߽����ʱ��"<<fileName<<".sh�ļ�ʧ�ܣ�";
		return;
	}
	QString fileHead = "#!/bin/bash\n";//shell�ļ�ͷ
	QString casename = "CASENAME='" + fileName.split(".").at(0) + "'\n";
	QString cmd = "yhrun -p work -N 10 -n 240 -t 200 ./../HiBflow -options_file ${CASENAME}.opt > ./results/${CASENAME}.log 2>&1\n";
	QByteArray array = fileHead.toUtf8();
	for (int i = 0; i < array.length(); i++)
	{
		printf("array[i]:", array.at(i));
	}

	QTextStream streamFileOut(&file);
	streamFileOut.setCodec("UTF-8");
	streamFileOut << fileHead;
	streamFileOut << "\n";
	streamFileOut << casename;
	streamFileOut << cmd;
	streamFileOut.flush();

	// ZC: �鵽˵������Ĳ�����true�Ļ� ���Ǳ����"UTF-8 + BOM"��false�Ļ� ���Ǳ����"UTF-8"
	//  ���ǣ��ҳ�����һ�£�����"UTF-8"... ��֪Ϊɶ...
	streamFileOut.setGenerateByteOrderMark(true);

	//file.write(fileHead.toUtf8());
	//file.write("\n");
	//file.write(casename.toUtf8());
	//file.write(cmd.toUtf8());
	file.close();
}

//����.bc�ļ�
void VariableParametersDialog::CreatBCFile(QString m_fileFullPathName)
{
	QString suffix = ".bc";
	QString fileFullPathName = m_fileFullPathName;
	QFileInfo fileInfo(fileFullPathName);
	QString filePath = fileInfo.path();
	QString fileName = fileInfo.fileName();
	QString outputFileName = fileName.split(".").at(0);
	outputFileName.append(suffix);
	QString outputFullPathName = filePath + "/" + outputFileName;

	//��excel�ļ���ȡ�ļ��г��ڸ�����ֵ
	int numberofexports = getNumberofexports(m_fileFullPathName);
	if (numberofexports < 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << fileName << "�ļ����ڸ�����Ч";
		return;
	}
	//��.bc�ļ�����д������
	QFile file(outputFullPathName);
	bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����߽����ʱ��"<< fileName<<".bc�ļ�ʧ�ܣ�";
		return;
	}
	QString fileLine1 = "id nodeset  sideset\n";
	QString fileLine2 = "nodeset: inlet 1  wall 3  outlet 21 22 23 ...\n";
	QString fileLine3 = "sideset: fluid_inlet 1  wall_sideset 3  fluid_outside 21 22 23 ...\n";
	QString fileLine;
	fileLine.clear();
	int count = 1;
	int count2 = 21;
	int count3 = 21;
	file.write(fileLine1.toUtf8());
	file.write(fileLine2.toUtf8());
	file.write(fileLine3.toUtf8());
	QString startStr = QString::number(count) + " " + QString::number(count) + " " + QString::number(count) + "\n";
	file.write(startStr.toUtf8());
	for (int i = 0; i < numberofexports; i++)
	{
		fileLine = QString::number(count + 1 + i) + " " + QString::number(count2 + i) + " " + QString::number(count3 + i) + "\n";
		file.write(fileLine.toUtf8());
	}
	QString endStr = QString::number(numberofexports + count + 1) + " " + QString::number(3) + " " + QString::number(3) + "\n";
	file.write(endStr.toUtf8());
	file.close();
}

//��excel�ļ��л�ȡ���ڵĸ���
int VariableParametersDialog::getNumberofexports(QString m_fileFullPathName)
{
	QString excel_file_path = m_fileFullPathName;
	excel_file_path = QDir::toNativeSeparators(excel_file_path);
	QAxObject *excel = new QAxObject(this);//����excel��������
	excel->setControl("Excel.Application");//����Excel�ؼ�
										   //excel->setProperty("Visible", true);//��ʾ���忴Ч��
	excel->setProperty("Visible", false);//��ʾ���忴Ч��
	excel->setProperty("DisplayAlerts", true);//��ʾ���濴Ч��
	QAxObject *workbooks = excel->querySubObject
		("WorkBooks");//��ȡ������(excel�ļ�)����
	workbooks->dynamicCall("Open(const QString&)", excel_file_path);
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//��ȡ�������

	QAxObject *worksheets = workbook->querySubObject("WorkSheets");//��ȡ���еĹ�����,��ͼ
	int intCount = worksheets->property("Count").toInt();           //��ȡ�˱�ĸ���

																	//�ӵڶ���sheet��ʼ��ȡֵ
	int startsheet = 1;
	//=======================================����sheet2==========================================
	//QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 2);
	QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", startsheet);//startsheetΪ��Ӧ�Ĵ���һ��sheet
	QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet��Χ

	int intRowStart = usedRange->property("Row").toInt();//��ʼ����
	int intColStart = usedRange->property("Column").toInt(); //��ʼ����
	QAxObject *rows, *columns;
	rows = usedRange->querySubObject("Rows");//��
	columns = usedRange->querySubObject("Columns");//��
	int intRow = rows->property("Count").toInt();//����
	int intCol = columns->property("Count").toInt();//����
													//qDebug() << "����:" << intRow;
													//qDebug() << "����:" << intCol;
	QAxObject *cell = NULL;//��ȡ��Ӧ���е�����
	QString cellStr;//��Ӧ���е�����ת����QString
	cellStr.clear();

	for (int i = intRowStart; i <= intRow; i++)
	{
		for (int j = intColStart; j < intCol; j++)
		{
			cell = worksheet->querySubObject("Cells(int,int)", i, j);
			cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			if (cellStr.compare("���ڸ���") == 0)
			{
				QFileInfo fileInfo(excel_file_path);
				QString filename = fileInfo.fileName();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename<< "�ļ����ڸ���:"<< cellStr;
				workbook->dynamicCall("Close(Boolean)", false);
				excel->dynamicCall("Quit(void)");
				delete excel;
				int cellInt = cellStr.toInt();
				return cellInt;
			}
			else 
			{
				continue;
			}
			
		}
	}

	workbook->dynamicCall("Close(Boolean)", false);
	excel->dynamicCall("Quit(void)");
	delete excel;
	return -1;
}