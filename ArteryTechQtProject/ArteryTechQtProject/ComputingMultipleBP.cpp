#include "ComputingMultipleBP.h"
#include "ui_ComputingMultipleBP.h"

ComputingMultipleBP::ComputingMultipleBP(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::ComputingMultipleBP();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化

	HiddenControls();
	//信号与槽函数的连接
	QObject::connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(PushButtonSlot()));
	QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(PushButton_2Slot()));

}

ComputingMultipleBP::~ComputingMultipleBP()
{
	delete ui;
}

void ComputingMultipleBP::HiddenControls()
{
	ui->label->setVisible(false);
	ui->label2->setVisible(false);
	ui->label3->setVisible(false);
	ui->label4->setVisible(false);
	ui->label5->setVisible(false);
	ui->label6->setVisible(false);
	ui->label7->setVisible(false);
	ui->label8->setVisible(false);
	ui->label9->setVisible(false);
	ui->label10->setVisible(false);
	ui->label11->setVisible(false);
	ui->label12->setVisible(false);
	ui->label13->setVisible(false);
	ui->label14->setVisible(false);
	ui->label15->setVisible(false);
	ui->label16->setVisible(false);
	ui->label17->setVisible(false);
	ui->label18->setVisible(false);
	ui->label19->setVisible(false);
	ui->label20->setVisible(false);
	ui->label21->setVisible(false);
	ui->label22->setVisible(false);
	ui->label23->setVisible(false);
	ui->label24->setVisible(false);
	ui->label25->setVisible(false);
	ui->label26->setVisible(false);
	ui->lineEdit->setVisible(false);
	ui->InputPushButton->setVisible(false);



	ui->ExecMatlabPushButton->setVisible(false);
	ui->SetPushButton->setVisible(false);
	ui->FileNameLabel->setVisible(false);
	ui->FileNameLineEdit->setVisible(false);
	ui->NodeAndSideSetFileLabel->setVisible(false);
	ui->NodeAndSideSetFileLineEdit->setVisible(false);
	ui->InletFlowRateFileLabel->setVisible(false);
	ui->InletFlowRateFileLineEdit->setVisible(false);
	ui->RdForWK3Label->setVisible(false);
	ui->RdForWK3LineEdit->setVisible(false);
	ui->CForWK3Label->setVisible(false);
	ui->CForWK3LineEdit->setVisible(false);
	ui->FinalTimeLabel->setVisible(false);
	ui->FinalTimeLineEdit->setVisible(false);
	ui->TimeStepSizeLabel->setVisible(false);
	ui->TimeStepSizeLineEdit->setVisible(false);
	ui->TotalResistanceLabel->setVisible(false);
	ui->TotalResistanceLineEdit->setVisible(false);
	ui->P0ForWK3Label->setVisible(false);
	ui->P0ForWK3LineEdit->setVisible(false);
	ui->ShowSolutionLabel->setVisible(false);
	ui->ShowSolutionCheckBox->setVisible(false);
	ui->SolutionOutputFileLabel->setVisible(false);
	ui->SolutionOutputFileLineEdit->setVisible(false);
	ui->ShowMeshDataLabel->setVisible(false);
	ui->ShowMeshDataCheckBox->setVisible(false);
	ui->FFRMonitorFileLabel->setVisible(false);
	ui->FFRMonitorFileLineEdit->setVisible(false);
	ui->FlowRateMonitorFileLabel->setVisible(false);
	ui->FlowRateMonitorFileLineEdit->setVisible(false);


	ui->RefMonitorPointLabel->setVisible(false);
	ui->RefMonitorPointLineEdit->setVisible(false);
	ui->MonitorPoint1Label->setVisible(false);
	ui->MonitorPoint1LineEdit->setVisible(false);
	ui->MonitorPoint2Label->setVisible(false);
	ui->MonitorPoint2LineEdit->setVisible(false);
	ui->MonitorPoint3Label->setVisible(false);
	ui->MonitorPoint3LineEdit->setVisible(false);
	ui->MonitorPoint4Label->setVisible(false);
	ui->MonitorPoint4LineEdit->setVisible(false);
	ui->MonitorPoint5Label->setVisible(false);
	ui->MonitorPoint5LineEdit->setVisible(false);
	ui->MonitorPoint6Label->setVisible(false);
	ui->MonitorPoint6LineEdit->setVisible(false);
	ui->MonitorPoint7Label->setVisible(false);
	ui->MonitorPoint7LineEdit->setVisible(false);
	ui->MonitorPoint8Label->setVisible(false);
	ui->MonitorPoint8LineEdit->setVisible(false);
	ui->MonitorPoint9Label->setVisible(false);
	ui->MonitorPoint9LineEdit->setVisible(false);
	ui->NumberOfOutletsLabel->setVisible(false);
	ui->NumberOfOutletsLineEdit->setVisible(false);
	ui->ConfirmPushButton->setVisible(false);
	ui->CancelPushButton->setVisible(false);
}

void ComputingMultipleBP::ReadExcelFile(QString FullFileName)
{
	QString fileFullPathName = FullFileName.trimmed();
	if (NULL == fileFullPathName)
	{
		QMessageBox::warning(this, "警告:", "设置的源文件不能为空，请选择一个设置源文件。");
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

	for (int i = intRowStart; i <= intRow; i++)
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
			//else if (cellStr.compare("编写人") == 0)
			//{
			//	QString RdText;
			//	RdText.clear();
			//	j = j + 3;
			//	cell = worksheet->querySubObject("Cells(int,int)", i, j);
			//	cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			//	qDebug() << "编写人:" << cellStr;
			//	QString name = "陈飞根";
			//	QAxObject* pCell = worksheet->querySubObject("Cells(int, int)", i, j + 1);
			//	if (pCell)
			//	{
			//		//QString strData = data.toString(); //excel 居然只能插入字符串和整型，浮点型无法插入
			//		pCell->dynamicCall("SetValue(const QVariant&)", name); //修改单元格的数据
			//	}

			//	//cell = worksheet->querySubObject("Cells(int,int)", i, j + 1);
			//	//cell->setProperty("Value", name);
			//}
		}
	}
	//workbook->dynamicCall("Save()");
	//workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(excel_file_path));
	workbook->dynamicCall("Close(Boolean)", false);
	excel->dynamicCall("Quit(void)");
	delete excel;
	ui->ConfirmPushButton->setEnabled(true);
	ui->CancelPushButton->setEnabled(true);
#endif
}

//输入文件
void ComputingMultipleBP::PushButtonSlot()
{
	fileList = QFileDialog::getOpenFileNames(this,"导入文件：",QDir::currentPath(),tr("Images *.xlsx"));
	if (0 == fileList.length())
	{
		//	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename<< "文件出口个数:"<< cellStr;
		QMessageBox::warning(this,"警告:","请选择有效的文件！");
		return;
	}
	//将选择的文件显示在界面上
	ui->textEdit->append("需要计算的文件:");
	for (size_t i = 0; i < fileList.length(); i++)
	{
		ui->textEdit->append(fileList.at(i));
	}
	//
	
}
//计算参数
void ComputingMultipleBP::PushButton_2Slot()
{
	QString fullFileName;
	QString dirName; //文件夹名
	QFileInfo fileInfo;
	QString filePath;
	int length = fileList.length();
	if (length > 0)
	{
		//点击计算之后，一个个文件计算
		for (size_t i = 0; i < length; i++)
		{
			fullFileName = fileList.at(i).trimmed();
			fileInfo = QFileInfo(fullFileName);
			dirName = fileInfo.fileName().split(".").at(0);
			//qDebug() << "dirName:" << dirName;
			filePath = fileInfo.path() + "/" + dirName;
			//qDebug() << "filePath:" << filePath;
			g_name = dirName;
			//先判断文件夹，如果不存在创建文件
			bool creatStatus = createFile(filePath);
			if (!creatStatus)
			{
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath << "文件夹创建失败!";
				continue;
			}
			//新建一个.sh文件，然后往.sh文件里面写入内容
			CreateSHFile(fullFileName);
			//通过运行Matlab生成.in文件Create
			CreateINFile(fullFileName);
			//设置可变参数的文件名
			setVPFileName(fullFileName);
			//读取excel文件
			ReadExcelFile(fullFileName);
			//生成option文件
			GetData(fullFileName);
			//新建一个.bc文件，然后往.bc文件里面写入内容
			CreateBCFile(fullFileName);

		}
		//拷贝excel文件和.in文件到对应的目录
		copyFileToDir();
		QMessageBox::information(this, "消息:", "计算完成");
		ui->textEdit->append("完成！");
		return;
	}
	else
	{
		QMessageBox::warning(this,"警告:","请先输入有效的文件！");
		return;
	}


}

//创建文件夹
bool ComputingMultipleBP::createFile(QString filePath)
{
	QFileInfo fileInfo(filePath);
	QString filename = fileInfo.fileName();
	qDebug() << "filename:" << filename;
	QDir tempDir  = fileInfo.dir();
	qDebug() << "tempDir:" << tempDir;
	//临时保存程序当前路径
	//QString currentDir = tempDir.currentPath();
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << currentDir;
	//如果filePath路径不存在，创建它
	if (!tempDir.exists(filePath))//在tempDir目录先创建文件
	{
		//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath;
		bool mkstatus = tempDir.mkpath(filePath);
		if (mkstatus)
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath<< "文件夹创建成功!";
			return mkstatus;
		}
		else
		{
			return mkstatus;
		}
	}
	else
	{
		return true;
	}
}

void ComputingMultipleBP::GetData(QString fullFileName)
{
	qDebug() << "fullFileName:" << fullFileName;
	QStringList uiDateList;
	uiDateList.clear();
	uiDateList.append("Parameter file+" + fullFileName);
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

	//for (int i = 0; i < uiDateList.length(); i++)
	//{
	//	qDebug() << "uiDateList " << i << ":" << uiDateList.at(i);
	//}
	//将结果通过信号发送到出去
	SendComputingMultipleBP(uiDateList);
}

void ComputingMultipleBP::SendComputingMultipleBP(QStringList m_uiDateList)
{
	QString optFilename = g_name;
	QString textEditStr = optFilename + ".opt文件开始生成......";
	ui->textEdit->append(textEditStr);
	show();
	emit ComputingMultipleBPSignal(m_uiDateList);
}

void ComputingMultipleBP::setVPFileName(QString fileFullPathName)
{
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
}

void  ComputingMultipleBP::GetCreateOPTFileSignalSlot(bool createStatus)
{
	QString optFilename = g_name + ".opt";
	QString textEditStr;
	if (createStatus)
	{
		textEditStr = optFilename + "文件生成成功！";
		ui->textEdit->append(textEditStr);
		show();
	}
	else
	{
		textEditStr = optFilename + "文件生成失败！";
		ui->textEdit->append(textEditStr);
		show();
	}
}


void ComputingMultipleBP::on_readoutput()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "执行边界参数计算成功！";
	QString textStr = g_name + ".in文件生成成功！";
	ui->textEdit->append(textStr);
	show();
}

void ComputingMultipleBP::on_readerror()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "执行边界参数计算失败！";
	QString textStr = g_name + ".in文件生成失败！";
	ui->textEdit->append(textStr);
	show();
}

//生成.sh文件
void ComputingMultipleBP::CreateSHFile(QString m_fileFullPathName)
{
	QString suffix = ".sh";
	QString fileFullPathName = m_fileFullPathName;//"C:/Users/Administrator/Desktop/CT无创血流储备分数/测试/sdz00011000117520114100.xlsx"
	qDebug() << "fileFullPathName：" << fileFullPathName;
	QFileInfo fileInfo(fileFullPathName);
	QString filePath = fileInfo.path();//"C:/Users/Administrator/Desktop/CT无创血流储备分数/测试"
	qDebug() << "filePath：" << filePath;
	QString fileName = fileInfo.fileName();//"sdz00011000117520114100.xlsx"
	qDebug() << "fileName：" << fileName;
	QString outputFileName = fileName.split(".").at(0);//"sdz00011000117520114100"
	qDebug() << "outputFileName：" << outputFileName;
	QString outputFullPathName = filePath + "/" + outputFileName + "/";// "C:/Users/Administrator/Desktop/CT无创血流储备分数/测试/sdz00011000117520114100/"
	qDebug() << "outputFullPathName：" << outputFullPathName;
	outputFileName.append(suffix);
	outputFullPathName.append(outputFileName);//"C:/Users/Administrator/Desktop/CT无创血流储备分数/测试/sdz00011000117520114100/sdz00011000117520114100.sh"
	QString textStr = g_name + ".sh文件开始生成......";
	qDebug() << "outputFullPathName：" << outputFullPathName;
	//打开.sh文件，并写如数据
	QFile file(outputFullPathName);
	bool openStatus = file.open(QFile::WriteOnly | QFile::Truncate);
	//bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "计算边界参数时打开" << fileName << ".sh文件失败！";
		textStr = g_name + ".sh文件生成失败！";
		ui->textEdit->append(textStr);
		show();
		return;
	}
	QString fileHead = "#!/bin/bash\n";//shell文件头
	QString casename = "CASENAME='" + fileName.split(".").at(0) + "'\n";
	QString cmd = "yhrun -p work -N 10 -n 240 -t 200 ./../HiBflow -options_file ${CASENAME}.opt > ./results/${CASENAME}.log 2>&1\n";

	QTextStream streamFileOut(&file);
	streamFileOut.setCodec("UTF-8");
	streamFileOut << fileHead;
	streamFileOut << "\n";
	streamFileOut << casename;
	streamFileOut << cmd;
	streamFileOut.flush();

	file.close();
	textStr = g_name + ".sh文件生成成功！";
	ui->textEdit->append(textStr);
	show();
}

//生成.bc文件
void ComputingMultipleBP::CreateBCFile(QString m_fileFullPathName)
{
	QString suffix = ".bc";
	QString fileFullPathName = m_fileFullPathName;
	QFileInfo fileInfo(fileFullPathName);
	QString filePath = fileInfo.path();
	QString fileName = fileInfo.fileName();
	QString outputFileName = fileName.split(".").at(0);
	QString outputFullPathName = filePath + "/" + outputFileName + "/";
	outputFileName.append(suffix);
	outputFullPathName.append(outputFileName);
	QString textStr = g_name + ".bc文件开始生成......";
	ui->textEdit->append(textStr);
	show();
	//打开excel文件获取文件中出口个数的值
	int numberofexports = getNumberofexports(m_fileFullPathName);
	if (numberofexports < 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << fileName << "文件出口个数无效";
		textStr = g_name + ".bc文件生成失败！";
		ui->textEdit->append(textStr);
		show();
		return;
	}
	//打开.bc文件，并写如数据
	QFile file(outputFullPathName);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "outputFullPathName:"<< outputFullPathName ;

	bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "计算边界参数时打开" << fileName << ".bc文件失败！";
		textStr = g_name + ".bc文件生成失败！";
		ui->textEdit->append(textStr);
		show();
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
	textStr = g_name + ".bc文件生成成功！";
	ui->textEdit->append(textStr);
	show();
}

//从excel文件中获取出口的个数
int ComputingMultipleBP::getNumberofexports(QString m_fileFullPathName)
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
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename << "文件出口个数:" << cellStr;
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

void  ComputingMultipleBP::CreateINFile(QString fileFullPathName)
{
	QString runPath = QCoreApplication::applicationDirPath();
	QString Exefilename = runPath + "/Matlab.bat";

	QString fileName = fileFullPathName.split(".").at(0);
	QString textStr = g_name + ".in文件开始生成......";
	ui->textEdit->append(textStr);
	show();
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
}

//拷贝excel文件和.in文件到对应的目录
void ComputingMultipleBP::copyFileToDir()
{
	int length = fileList.length();
	QFileInfo fileInfo;
	QString dirName;
	QString filePath;
	for (size_t i = 0; i < length; i++)
	{
		QString sourceExcelFile = fileList.at(i).trimmed();
		fileInfo = QFileInfo(sourceExcelFile);
		dirName = fileInfo.fileName().split(".").at(0);
		//qDebug() << "sourceExcelFile:" << sourceExcelFile;
		filePath = fileInfo.path() + "/" + dirName;
		QString destExcwlFile = filePath + "/" + fileInfo.fileName();
		//qDebug() << "destExcwlFile:" << destExcwlFile;

		//in源文件
		QString sourceInFile = fileInfo.path() + "/" + dirName + ".in";
		//qDebug() << "sourceInFile:" << sourceInFile;

		//in目标文件
		QString destInFile = filePath + "/" + dirName + ".in";
		//qDebug() << "destInFile:" << destInFile;

		bool copyExcel = QFile::rename(sourceExcelFile, destExcwlFile);
		if (!copyExcel)
		{
			ui->textEdit->append(sourceExcelFile + "文件拷贝失败!");
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << sourceExcelFile << "文件拷贝失败!";
		}
		bool copyIn = QFile::rename(sourceInFile, destInFile);
		if (!copyIn)
		{
			ui->textEdit->append(sourceInFile + "文件拷贝失败!");
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << sourceInFile << "文件拷贝失败!";
		}
	}
}

