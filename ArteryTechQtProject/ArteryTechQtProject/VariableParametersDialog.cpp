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
	setWindowTitle("可变参数设置");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	ui->ShowSolutionCheckBox->setChecked(true);
	ui->ShowMeshDataCheckBox->setChecked(true);
	//初始化配置按钮点击成功设置界面之前，确定按钮和取消按钮都初始化为无效
	ui->ConfirmPushButton->setEnabled(false);
	ui->CancelPushButton->setEnabled(false);
	//信号与曹函数的连接
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
	QString fileFullPathName = QFileDialog::getOpenFileName(this,"打开",QDir::currentPath(),tr("Images *.xlsx"));
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this, "警告:", "文件选择无效，请重新选择！");
		return;
	}
	ui->lineEdit->setText(fileFullPathName);

	QFileInfo fileInfo(fileFullPathName);
	QString fileName = fileInfo.fileName();
	QString name = fileName.split(".").at(0);
	QString FileNameLineEdit = "./mesh/" + name + ".exo";
	ui->FileNameLineEdit->setText(FileNameLineEdit);
	//===========================设置界面上得文件名
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
		QMessageBox::warning(this,"警告:","设置的源文件不能为空，请选择一个设置源文件。");
		return;
	}

	//***********************************操作excel***************************************
#if 1
	//QString excel_file_path = QDir::currentPath() + "/a.xlsx";//fileName
	QString excel_file_path = fileFullPathName;
	excel_file_path = QDir::toNativeSeparators(excel_file_path);
	QAxObject *excel = new QAxObject(this);//建立excel操作对象
	excel->setControl("Excel.Application");//连接Excel控件
	//excel->setProperty("Visible", true);//显示窗体看效果
	excel->setProperty("Visible", false);//显示窗体看效果
	excel->setProperty("DisplayAlerts", true);//显示警告看效果
	QAxObject *workbooks = excel->querySubObject
		("WorkBooks");//获取工作簿(excel文件)集合
	workbooks->dynamicCall("Open(const QString&)", excel_file_path);
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取活动工作簿

	QAxObject *worksheets = workbook->querySubObject("WorkSheets");//获取所有的工作表,如图
	int intCount = worksheets->property("Count").toInt();           //获取了表的个数

	//从第二个sheet开始获取值
	int startsheet = 1;
	//=======================================操作sheet2==========================================
	//QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 2);
	QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", startsheet);//startsheet为对应的打开哪一个sheet
	QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet范围

	int intRowStart = usedRange->property("Row").toInt();//起始行数
	int intColStart = usedRange->property("Column").toInt(); //起始列数
	QAxObject *rows, *columns;
	rows = usedRange->querySubObject("Rows");//行
	columns = usedRange->querySubObject("Columns");//列
	int intRow = rows->property("Count").toInt();//行数
	int intCol = columns->property("Count").toInt();//列数
	//qDebug() << "行数:" << intRow;
	//qDebug() << "列数:" << intCol;
	QAxObject *cell = NULL;//获取对应行列的内容
	QString cellStr;//对应行列的内容转换成QString
	cellStr.clear();

	for (int i = intRowStart; i  <= intRow; i++)
	{
		for (int j = intColStart; j < intCol; j++)
		{
			cell = worksheet->querySubObject("Cells(int,int)", i, j);
			cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			if (cellStr.compare("近端(入口)压力监测点坐标P0") == 0)
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
			else if (cellStr.compare("第一个远端压力监测点P1") == 0)
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
			else if (cellStr.compare("第二个远端压力监测点P2") == 0)
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
			else if (cellStr.compare("第三个远端压力监测点P3") == 0)
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
			else if (cellStr.compare("第四个远端压力监测点P4") == 0)
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
			else if (cellStr.compare("第五个远端压力监测点P5") == 0)
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
			else if (cellStr.compare("第六个远端压力监测点P6") == 0)
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
			else if (cellStr.compare("第七个远端压力监测点P7") == 0)
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
			else if (cellStr.compare("第八个远端压力监测点P8") == 0)
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
			else if (cellStr.compare("第九个远端压力监测点P9") == 0)
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
			else if (cellStr.compare("出口个数") == 0)
			{
				QString numberOfOutletsText;
				numberOfOutletsText.clear();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);//行不变，列加4
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				j = intCol;
				numberOfOutletsText.append(cellStr);
				ui->NumberOfOutletsLineEdit->setText(numberOfOutletsText);
			}
			else if (cellStr.compare("WK3模型参数WKRd") == 0)
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
			else if (cellStr.compare("WK3模型参数WKC") == 0)
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
			else if (cellStr.compare("计算时间T") == 0)
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
			else if (cellStr.compare("时间步长dt") == 0)
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
			else if (cellStr.compare("总阻力Rtotal") == 0)
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
			else if (cellStr.compare("WK3模型参数WKP0") == 0)
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
	//将结果通过信号发送到出去
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

//计算边界类型槽函数
void VariableParametersDialog::ExecMatlabPushButtonSlot()
{
	//获取当前运行程序的路径
	QString fileFullPathName = ui->lineEdit->text().trimmed();
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this,"警告:","文件不能为空，请重新输入！");
		return;
	}
	//QMessageBox::information(this,"测试:","计算边界参数");
	//新建一个.sh文件，然后往.sh文件里面写入内容
	CreatSHFile(fileFullPathName);
	//新建一个.bc文件，然后往.bc文件里面写入内容
	CreatBCFile(fileFullPathName);
	QString runPath = QCoreApplication::applicationDirPath();
	QString Exefilename = runPath + "/Matlab.bat";

	QString fileName = fileFullPathName.split(".").at(0);
	//QString Exefilename = "\"E:/Program Files/MATLAB/R2017b/bin/matlab.exe\"";
	process = new QProcess(this);
	connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_readoutput()));
	connect(process, SIGNAL(readyReadStandardError()), this, SLOT(on_readerror()));
	//1）设置路径
	process->setProgram(Exefilename);
	//2)设置参数
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
	//processGeomagic->execute(Exefilename);//execute执行该进程之后不能执行其他的进程
}

void VariableParametersDialog::on_readoutput()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "执行边界参数计算成功！";
}

void VariableParametersDialog::on_readerror()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "执行边界参数计算失败！";
}

//生成.sh文件
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

	//打开.sh文件，并写如数据
	QFile file(outputFullPathName);
	bool openStatus = file.open(QFile::WriteOnly | QFile::Truncate);
	//bool openStatus = file.open(QIODevice::WriteOnly|QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "计算边界参数时打开"<<fileName<<".sh文件失败！";
		return;
	}
	QString fileHead = "#!/bin/bash\n";//shell文件头
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

	// ZC: 查到说，下面的参数是true的话 就是保存成"UTF-8 + BOM"，false的话 就是保存成"UTF-8"
	//  但是，我尝试了一下，都是"UTF-8"... 不知为啥...
	streamFileOut.setGenerateByteOrderMark(true);

	//file.write(fileHead.toUtf8());
	//file.write("\n");
	//file.write(casename.toUtf8());
	//file.write(cmd.toUtf8());
	file.close();
}

//生成.bc文件
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

	//打开excel文件获取文件中出口个数的值
	int numberofexports = getNumberofexports(m_fileFullPathName);
	if (numberofexports < 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << fileName << "文件出口个数无效";
		return;
	}
	//打开.bc文件，并写如数据
	QFile file(outputFullPathName);
	bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "计算边界参数时打开"<< fileName<<".bc文件失败！";
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

//从excel文件中获取出口的个数
int VariableParametersDialog::getNumberofexports(QString m_fileFullPathName)
{
	QString excel_file_path = m_fileFullPathName;
	excel_file_path = QDir::toNativeSeparators(excel_file_path);
	QAxObject *excel = new QAxObject(this);//建立excel操作对象
	excel->setControl("Excel.Application");//连接Excel控件
										   //excel->setProperty("Visible", true);//显示窗体看效果
	excel->setProperty("Visible", false);//显示窗体看效果
	excel->setProperty("DisplayAlerts", true);//显示警告看效果
	QAxObject *workbooks = excel->querySubObject
		("WorkBooks");//获取工作簿(excel文件)集合
	workbooks->dynamicCall("Open(const QString&)", excel_file_path);
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取活动工作簿

	QAxObject *worksheets = workbook->querySubObject("WorkSheets");//获取所有的工作表,如图
	int intCount = worksheets->property("Count").toInt();           //获取了表的个数

																	//从第二个sheet开始获取值
	int startsheet = 1;
	//=======================================操作sheet2==========================================
	//QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 2);
	QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", startsheet);//startsheet为对应的打开哪一个sheet
	QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet范围

	int intRowStart = usedRange->property("Row").toInt();//起始行数
	int intColStart = usedRange->property("Column").toInt(); //起始列数
	QAxObject *rows, *columns;
	rows = usedRange->querySubObject("Rows");//行
	columns = usedRange->querySubObject("Columns");//列
	int intRow = rows->property("Count").toInt();//行数
	int intCol = columns->property("Count").toInt();//列数
													//qDebug() << "行数:" << intRow;
													//qDebug() << "列数:" << intCol;
	QAxObject *cell = NULL;//获取对应行列的内容
	QString cellStr;//对应行列的内容转换成QString
	cellStr.clear();

	for (int i = intRowStart; i <= intRow; i++)
	{
		for (int j = intColStart; j < intCol; j++)
		{
			cell = worksheet->querySubObject("Cells(int,int)", i, j);
			cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			if (cellStr.compare("出口个数") == 0)
			{
				QFileInfo fileInfo(excel_file_path);
				QString filename = fileInfo.fileName();
				j = j + 4;
				cell = worksheet->querySubObject("Cells(int,int)", i, j);
				cellStr = cell->dynamicCall("Value2()").toString().trimmed();
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename<< "文件出口个数:"<< cellStr;
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