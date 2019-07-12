#include "ComputingMultipleBP.h"
#include "ui_ComputingMultipleBP.h"

ComputingMultipleBP::ComputingMultipleBP(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::ComputingMultipleBP();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //���ô��������С��

	HiddenControls();
	//�ź���ۺ���������
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
		QMessageBox::warning(this, "����:", "���õ�Դ�ļ�����Ϊ�գ���ѡ��һ������Դ�ļ���");
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

	for (int i = intRowStart; i <= intRow; i++)
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
			//else if (cellStr.compare("��д��") == 0)
			//{
			//	QString RdText;
			//	RdText.clear();
			//	j = j + 3;
			//	cell = worksheet->querySubObject("Cells(int,int)", i, j);
			//	cellStr = cell->dynamicCall("Value2()").toString().trimmed();
			//	qDebug() << "��д��:" << cellStr;
			//	QString name = "�·ɸ�";
			//	QAxObject* pCell = worksheet->querySubObject("Cells(int, int)", i, j + 1);
			//	if (pCell)
			//	{
			//		//QString strData = data.toString(); //excel ��Ȼֻ�ܲ����ַ��������ͣ��������޷�����
			//		pCell->dynamicCall("SetValue(const QVariant&)", name); //�޸ĵ�Ԫ�������
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

//�����ļ�
void ComputingMultipleBP::PushButtonSlot()
{
	fileList = QFileDialog::getOpenFileNames(this,"�����ļ���",QDir::currentPath(),tr("Images *.xlsx"));
	if (0 == fileList.length())
	{
		//	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename<< "�ļ����ڸ���:"<< cellStr;
		QMessageBox::warning(this,"����:","��ѡ����Ч���ļ���");
		return;
	}
	//��ѡ����ļ���ʾ�ڽ�����
	ui->textEdit->append("��Ҫ������ļ�:");
	for (size_t i = 0; i < fileList.length(); i++)
	{
		ui->textEdit->append(fileList.at(i));
	}
	//
	
}
//�������
void ComputingMultipleBP::PushButton_2Slot()
{
	QString fullFileName;
	QString dirName; //�ļ�����
	QFileInfo fileInfo;
	QString filePath;
	int length = fileList.length();
	if (length > 0)
	{
		//�������֮��һ�����ļ�����
		for (size_t i = 0; i < length; i++)
		{
			fullFileName = fileList.at(i).trimmed();
			fileInfo = QFileInfo(fullFileName);
			dirName = fileInfo.fileName().split(".").at(0);
			//qDebug() << "dirName:" << dirName;
			filePath = fileInfo.path() + "/" + dirName;
			//qDebug() << "filePath:" << filePath;
			g_name = dirName;
			//���ж��ļ��У���������ڴ����ļ�
			bool creatStatus = createFile(filePath);
			if (!creatStatus)
			{
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath << "�ļ��д���ʧ��!";
				continue;
			}
			//�½�һ��.sh�ļ���Ȼ����.sh�ļ�����д������
			CreateSHFile(fullFileName);
			//ͨ������Matlab����.in�ļ�Create
			CreateINFile(fullFileName);
			//���ÿɱ�������ļ���
			setVPFileName(fullFileName);
			//��ȡexcel�ļ�
			ReadExcelFile(fullFileName);
			//����option�ļ�
			GetData(fullFileName);
			//�½�һ��.bc�ļ���Ȼ����.bc�ļ�����д������
			CreateBCFile(fullFileName);

		}
		//����excel�ļ���.in�ļ�����Ӧ��Ŀ¼
		copyFileToDir();
		QMessageBox::information(this, "��Ϣ:", "�������");
		ui->textEdit->append("��ɣ�");
		return;
	}
	else
	{
		QMessageBox::warning(this,"����:","����������Ч���ļ���");
		return;
	}


}

//�����ļ���
bool ComputingMultipleBP::createFile(QString filePath)
{
	QFileInfo fileInfo(filePath);
	QString filename = fileInfo.fileName();
	qDebug() << "filename:" << filename;
	QDir tempDir  = fileInfo.dir();
	qDebug() << "tempDir:" << tempDir;
	//��ʱ�������ǰ·��
	//QString currentDir = tempDir.currentPath();
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << currentDir;
	//���filePath·�������ڣ�������
	if (!tempDir.exists(filePath))//��tempDirĿ¼�ȴ����ļ�
	{
		//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath;
		bool mkstatus = tempDir.mkpath(filePath);
		if (mkstatus)
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filePath<< "�ļ��д����ɹ�!";
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
	//�����ͨ���źŷ��͵���ȥ
	SendComputingMultipleBP(uiDateList);
}

void ComputingMultipleBP::SendComputingMultipleBP(QStringList m_uiDateList)
{
	QString optFilename = g_name;
	QString textEditStr = optFilename + ".opt�ļ���ʼ����......";
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
}

void  ComputingMultipleBP::GetCreateOPTFileSignalSlot(bool createStatus)
{
	QString optFilename = g_name + ".opt";
	QString textEditStr;
	if (createStatus)
	{
		textEditStr = optFilename + "�ļ����ɳɹ���";
		ui->textEdit->append(textEditStr);
		show();
	}
	else
	{
		textEditStr = optFilename + "�ļ�����ʧ�ܣ�";
		ui->textEdit->append(textEditStr);
		show();
	}
}


void ComputingMultipleBP::on_readoutput()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ִ�б߽��������ɹ���";
	QString textStr = g_name + ".in�ļ����ɳɹ���";
	ui->textEdit->append(textStr);
	show();
}

void ComputingMultipleBP::on_readerror()
{
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "ִ�б߽��������ʧ�ܣ�";
	QString textStr = g_name + ".in�ļ�����ʧ�ܣ�";
	ui->textEdit->append(textStr);
	show();
}

//����.sh�ļ�
void ComputingMultipleBP::CreateSHFile(QString m_fileFullPathName)
{
	QString suffix = ".sh";
	QString fileFullPathName = m_fileFullPathName;//"C:/Users/Administrator/Desktop/CT�޴�Ѫ����������/����/sdz00011000117520114100.xlsx"
	qDebug() << "fileFullPathName��" << fileFullPathName;
	QFileInfo fileInfo(fileFullPathName);
	QString filePath = fileInfo.path();//"C:/Users/Administrator/Desktop/CT�޴�Ѫ����������/����"
	qDebug() << "filePath��" << filePath;
	QString fileName = fileInfo.fileName();//"sdz00011000117520114100.xlsx"
	qDebug() << "fileName��" << fileName;
	QString outputFileName = fileName.split(".").at(0);//"sdz00011000117520114100"
	qDebug() << "outputFileName��" << outputFileName;
	QString outputFullPathName = filePath + "/" + outputFileName + "/";// "C:/Users/Administrator/Desktop/CT�޴�Ѫ����������/����/sdz00011000117520114100/"
	qDebug() << "outputFullPathName��" << outputFullPathName;
	outputFileName.append(suffix);
	outputFullPathName.append(outputFileName);//"C:/Users/Administrator/Desktop/CT�޴�Ѫ����������/����/sdz00011000117520114100/sdz00011000117520114100.sh"
	QString textStr = g_name + ".sh�ļ���ʼ����......";
	qDebug() << "outputFullPathName��" << outputFullPathName;
	//��.sh�ļ�����д������
	QFile file(outputFullPathName);
	bool openStatus = file.open(QFile::WriteOnly | QFile::Truncate);
	//bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����߽����ʱ��" << fileName << ".sh�ļ�ʧ�ܣ�";
		textStr = g_name + ".sh�ļ�����ʧ�ܣ�";
		ui->textEdit->append(textStr);
		show();
		return;
	}
	QString fileHead = "#!/bin/bash\n";//shell�ļ�ͷ
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
	textStr = g_name + ".sh�ļ����ɳɹ���";
	ui->textEdit->append(textStr);
	show();
}

//����.bc�ļ�
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
	QString textStr = g_name + ".bc�ļ���ʼ����......";
	ui->textEdit->append(textStr);
	show();
	//��excel�ļ���ȡ�ļ��г��ڸ�����ֵ
	int numberofexports = getNumberofexports(m_fileFullPathName);
	if (numberofexports < 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << fileName << "�ļ����ڸ�����Ч";
		textStr = g_name + ".bc�ļ�����ʧ�ܣ�";
		ui->textEdit->append(textStr);
		show();
		return;
	}
	//��.bc�ļ�����д������
	QFile file(outputFullPathName);
	qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "outputFullPathName:"<< outputFullPathName ;

	bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "����߽����ʱ��" << fileName << ".bc�ļ�ʧ�ܣ�";
		textStr = g_name + ".bc�ļ�����ʧ�ܣ�";
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
	textStr = g_name + ".bc�ļ����ɳɹ���";
	ui->textEdit->append(textStr);
	show();
}

//��excel�ļ��л�ȡ���ڵĸ���
int ComputingMultipleBP::getNumberofexports(QString m_fileFullPathName)
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
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << filename << "�ļ����ڸ���:" << cellStr;
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
	QString textStr = g_name + ".in�ļ���ʼ����......";
	ui->textEdit->append(textStr);
	show();
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
}

//����excel�ļ���.in�ļ�����Ӧ��Ŀ¼
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

		//inԴ�ļ�
		QString sourceInFile = fileInfo.path() + "/" + dirName + ".in";
		//qDebug() << "sourceInFile:" << sourceInFile;

		//inĿ���ļ�
		QString destInFile = filePath + "/" + dirName + ".in";
		//qDebug() << "destInFile:" << destInFile;

		bool copyExcel = QFile::rename(sourceExcelFile, destExcwlFile);
		if (!copyExcel)
		{
			ui->textEdit->append(sourceExcelFile + "�ļ�����ʧ��!");
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << sourceExcelFile << "�ļ�����ʧ��!";
		}
		bool copyIn = QFile::rename(sourceInFile, destInFile);
		if (!copyIn)
		{
			ui->textEdit->append(sourceInFile + "�ļ�����ʧ��!");
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << sourceInFile << "�ļ�����ʧ��!";
		}
	}
}

