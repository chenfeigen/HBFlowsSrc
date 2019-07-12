#include "QtArteryTechOutputSetupUI.h"
#include "ui_QtArteryTechOutputSetupUI.h"

QtArteryTechOutputSetupUI::QtArteryTechOutputSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOutputSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(730, 463);
	this->setMaximumSize(730, 463);
	this->setWindowTitle("结果输出设置");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	this->showPartitionBasicCheckBox = new QCheckBox;
	this->basicGridOutputCheckBox = new QCheckBox;
	this->solutionOutputBasicCheckBox = new QCheckBox;
	this->residualOutputBasicCheckBox = new QCheckBox;

	this->showPartitionBasicCheckBox->setText("show_partition_basic");
	this->basicGridOutputCheckBox->setText("basic_grid_output");
	this->solutionOutputBasicCheckBox->setText("solution_output");
	this->residualOutputBasicCheckBox->setText("residual_output");


	InitUiData();
	//SaveOutputData();

	//信号与槽链接
	QObject::connect(ui->NumberOfStepsForOutputLineEdit, SIGNAL(editingFinished()), this, SLOT(NumberOfStepsForOutputLineEditSlot()));
	QObject::connect(ui->TimeIntervalForOutputLineEdit, SIGNAL(editingFinished()), this, SLOT(TimeIntervalForOutputLineEditSlot()));
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

QtArteryTechOutputSetupUI::QtArteryTechOutputSetupUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOutputSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setMinimumSize(730, 463);
	this->setMaximumSize(730, 463);
	this->setWindowTitle("结果输出设置");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	this->showPartitionBasicCheckBox = new QCheckBox;
	this->basicGridOutputCheckBox = new QCheckBox;
	this->solutionOutputBasicCheckBox = new QCheckBox;
	this->residualOutputBasicCheckBox = new QCheckBox;

	this->showPartitionBasicCheckBox->setText("show_partition_basic");
	this->basicGridOutputCheckBox->setText("basic_grid_output");
	this->solutionOutputBasicCheckBox->setText("solution_output");
	this->residualOutputBasicCheckBox->setText("residual_output");


	InitUiData();
	//SaveOutputData();

	//信号与槽链接
	QObject::connect(ui->NumberOfStepsForOutputLineEdit, SIGNAL(editingFinished()), this, SLOT(NumberOfStepsForOutputLineEditSlot()));
	QObject::connect(ui->TimeIntervalForOutputLineEdit, SIGNAL(editingFinished()), this, SLOT(TimeIntervalForOutputLineEditSlot()));
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

void QtArteryTechOutputSetupUI::InitUiData()
{
	ui->RefMonitorPointLineEdit->setText(NULL);
	ui->MonitorPoint1LineEdit->setText(NULL);
	ui->MonitorPoint2LineEdit->setText(NULL);
	ui->MonitorPoint3LineEdit->setText(NULL);
	ui->MonitorPoint4LineEdit->setText(NULL);
	ui->MonitorPoint5LineEdit->setText(NULL);
	ui->MonitorPoint6LineEdit->setText(NULL);
	ui->MonitorPoint7LineEdit->setText(NULL);
	ui->MonitorPoint8LineEdit->setText(NULL);
	ui->MonitorPoint9LineEdit->setText(NULL);
	ui->FFRMonitorFileLineEdit->setText(NULL);
	ui->FlowRateMonitorFileLineEdit->setText(NULL);
	ui->SolutionOutputFileLineEdit->setText(NULL);
	ui->ShowSubdomainMeshDataLineEdit->setText(NULL);
	ui->ShowSubdomainMeshDataLabel->setVisible(true);
	ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
	ui->ShowMeshDataLineEdit->setText(NULL);
	ui->ShowMeshDataLabel->setVisible(true);
	ui->ShowMeshDataLineEdit->setVisible(false);
	ui->ShowSolutionLineEdit->setText(NULL);
	ui->ShowSolutionLabel->setVisible(true);
	ui->ShowSolutionLineEdit->setVisible(false);
	ui->MonitorResidualLineEdit->setText(NULL);
	ui->MonitorResidualLabel->setVisible(true);
	ui->MonitorResidualLineEdit->setVisible(false);

	this->ui->horizontalLayout_8->addWidget(this->showPartitionBasicCheckBox);
	this->ui->horizontalLayout_9->addWidget(this->basicGridOutputCheckBox);
	this->ui->horizontalLayout_10->addWidget(this->solutionOutputBasicCheckBox);
	this->ui->horizontalLayout_11->addWidget(this->residualOutputBasicCheckBox);

	ui->NumberOfStepsForOutputLineEdit->setVisible(false);
	ui->NumberOfStepsForOutputLineEdit->setEnabled(false);
	ui->NumberOfStepsForOutputLineEdit->setText("25");

	ui->TimeIntervalForOutputLineEdit->setText("0");
}

void QtArteryTechOutputSetupUI::InitOutputData(bool flag)
{
	if (flag)
	{
		//ui->RefMonitorPointLineEdit->setText("0");
		//ui->MonitorPoint1LineEdit->setText("0");
		//ui->MonitorPoint2LineEdit->setText("0");
		//ui->MonitorPoint3LineEdit->setText("0");
		//ui->FFRMonitorFileLineEdit->setText(NULL);
		//ui->FlowRateMonitorFileLineEdit->setText(NULL);
		//ui->SolutionOutputFileLineEdit->setText(NULL);
		ui->ShowSubdomainMeshDataLineEdit->setText(NULL);
		ui->ShowSubdomainMeshDataLabel->setVisible(true);
		ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
		ui->ShowMeshDataLineEdit->setText(NULL);
		ui->ShowMeshDataLabel->setVisible(true);
		ui->ShowMeshDataLineEdit->setVisible(false);
		ui->ShowSolutionLineEdit->setText(NULL);
		ui->ShowSolutionLabel->setVisible(true);
		ui->ShowSolutionLineEdit->setVisible(false);
		ui->MonitorResidualLineEdit->setText(NULL);
		ui->MonitorResidualLabel->setVisible(true);
		ui->MonitorResidualLineEdit->setVisible(false);

		this->ui->horizontalLayout_8->addWidget(this->showPartitionBasicCheckBox);
		this->ui->horizontalLayout_9->addWidget(this->basicGridOutputCheckBox);
		this->ui->horizontalLayout_10->addWidget(this->solutionOutputBasicCheckBox);
		this->ui->horizontalLayout_11->addWidget(this->residualOutputBasicCheckBox);

		ui->NumberOfStepsForOutputLineEdit->setVisible(true);
		ui->NumberOfStepsForOutputLineEdit->setEnabled(true);

		ui->TimeIntervalForOutputLineEdit->setText("0");
	}
	else
	{
		//ui->RefMonitorPointLineEdit->setText("0");
		//ui->MonitorPoint1LineEdit->setText("0");
		//ui->MonitorPoint2LineEdit->setText("0");
		//ui->MonitorPoint3LineEdit->setText("0");
		//ui->FFRMonitorFileLineEdit->setText(NULL);
		//ui->FlowRateMonitorFileLineEdit->setText(NULL);
		//ui->SolutionOutputFileLineEdit->setText(NULL);
		ui->ShowSubdomainMeshDataLineEdit->setText(NULL);
		ui->ShowSubdomainMeshDataLabel->setVisible(true);
		ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
		ui->ShowMeshDataLineEdit->setText(NULL);
		ui->ShowMeshDataLabel->setVisible(true);
		ui->ShowMeshDataLineEdit->setVisible(false);
		ui->ShowSolutionLineEdit->setText(NULL);
		ui->ShowSolutionLabel->setVisible(true);
		ui->ShowSolutionLineEdit->setVisible(false);
		ui->MonitorResidualLineEdit->setText(NULL);
		ui->MonitorResidualLabel->setVisible(true);
		ui->MonitorResidualLineEdit->setVisible(false);

		this->ui->horizontalLayout_8->addWidget(this->showPartitionBasicCheckBox);
		this->ui->horizontalLayout_9->addWidget(this->basicGridOutputCheckBox);
		this->ui->horizontalLayout_10->addWidget(this->solutionOutputBasicCheckBox);
		this->ui->horizontalLayout_11->addWidget(this->residualOutputBasicCheckBox);

		ui->NumberOfStepsForOutputLineEdit->setVisible(false);
		ui->NumberOfStepsForOutputLineEdit->setEnabled(false);

		ui->TimeIntervalForOutputLineEdit->setText("0");
	}

}
#if 0
void QtArteryTechOutputSetupUI::InitOutputData()
{
	ui->RefMonitorPointLineEdit->setText("3.01225,-15.5694,110.547");
	ui->MonitorPoint1LineEdit->setText("8.1665,-21.5939,107.279");
	ui->MonitorPoint2LineEdit->setText("5.4613,-11.9784,110.486");
	ui->MonitorPoint3LineEdit->setText("2.19491,-14.5297,106.924");
	ui->FFRMonitorFileLineEdit->setText("./resultsA/ffrmonitor.txt");
	ui->FlowRateMonitorFileLineEdit->setText("./resultsA/bloodflowmonitor.txt");
	ui->SolutionOutputFileLineEdit->setText("./resultsA/solution");
	ui->ShowSubdomainMeshDataLineEdit->setText(NULL);
	ui->ShowSubdomainMeshDataLabel->setVisible(true);
	ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
	ui->ShowMeshDataLineEdit->setText(NULL);
	ui->ShowMeshDataLabel->setVisible(true);
	ui->ShowMeshDataLineEdit->setVisible(false);
	ui->ShowSolutionLineEdit->setText(NULL);
	ui->ShowSolutionLabel->setVisible(true);
	ui->ShowSolutionLineEdit->setVisible(false);
	ui->MonitorResidualLineEdit->setText(NULL);
	ui->MonitorResidualLabel->setVisible(true);
	ui->MonitorResidualLineEdit->setVisible(false);

	this->ui->horizontalLayout_8->addWidget(this->ShowPartitionBasicCheckBox);
	this->ui->horizontalLayout_9->addWidget(this->BasicGridOutputCheckBox);
	this->ui->horizontalLayout_10->addWidget(this->SolutionOutputBasicCheckBox);
	this->ui->horizontalLayout_11->addWidget(this->ResidualOutputBasicCheckBox);

	ui->NumberOfStepsForOutputLineEdit->setText("25");
	ui->TimeIntervalForOutputLineEdit->setText("0.2");
}
#endif
void QtArteryTechOutputSetupUI::OkPushButtonSlots()
{
	SaveOutputData();
	this->close();
}

void QtArteryTechOutputSetupUI::CancelPushButtonSlots()
{
	InitOutputData(false);
	this->close();
}

void QtArteryTechOutputSetupUI::SaveOutputData()
{
	this->outputDataList.clear();
	QString Menustr = "#Output Setup\n";
	this->outputDataList.append(Menustr);
	//QString labeltext = "	" + ui->RefMonitorPointLabel->text() + " " + "-P1coords" + " ";
	QString labeltext = "	-P0coords ";
	QString lineEdit = ui->RefMonitorPointLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint1Label->text() + " " + "-P2coords" + " ";
	labeltext = "	-P1coords ";
	lineEdit = ui->MonitorPoint1LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint2Label->text() + " " + "-P3coords" + " ";
	labeltext = "	-P2coords ";
	lineEdit = ui->MonitorPoint2LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint3Label->text() + " " + "-P4coords" + " ";
	labeltext = "	-P3coords ";
	lineEdit = ui->MonitorPoint3LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P4coords ";
	lineEdit = ui->MonitorPoint4LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P5coords ";
	lineEdit = ui->MonitorPoint5LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P6coords ";
	lineEdit = ui->MonitorPoint6LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P7coords ";
	lineEdit = ui->MonitorPoint7LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P8coords ";
	lineEdit = ui->MonitorPoint8LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	labeltext = "	-P9coords ";
	lineEdit = ui->MonitorPoint9LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->FFRMonitorFileLabel->text() + " " + "-ffroutputname" + " ";
	labeltext = "	-ffroutputname ";
	lineEdit = ui->FFRMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->FlowRateMonitorFileLabel->text() + " " + "-flowoutputname" + " ";
	labeltext = "	-flowoutputname ";
	lineEdit = ui->FlowRateMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->SolutionOutputFileLabel->text() + " " + "-output" + " ";
	labeltext = "	-output ";
	lineEdit = ui->SolutionOutputFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	if (this->showPartitionBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSubdomainMeshDataLabel->text() + " " + "-show_partition_basic" + " ";
		labeltext = "	-show_partition_basic ";
		lineEdit = ui->ShowSubdomainMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->basicGridOutputCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowMeshDataLabel->text() + " " + "-basic_grid_output" + " ";
		labeltext = "	-basic_grid_output ";
		lineEdit = ui->ShowMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->solutionOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSolutionLabel->text() + " " + "-solution_output" + " ";
		labeltext = "	-solution_output ";
		lineEdit = ui->ShowSolutionLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->residualOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->MonitorResidualLabel->text() + " " + "-residual_output" + " ";
		labeltext = "	-residual_output ";
		lineEdit = ui->MonitorResidualLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	//labeltext = "	" + ui->NumberOfStepsForOutputLabel->text() + " " + "-Nplot" + " ";
	labeltext = "	-Nplot ";
	lineEdit = ui->NumberOfStepsForOutputLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->TimeIntervalForOutputLabel->text() + " " + "-dtplot" + " ";
	labeltext = "	#-dtplot ";
	lineEdit = ui->TimeIntervalForOutputLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);
	/*
	for (size_t i = 0; i < this->outputDataList.length(); i++)
	{
	qDebug() << "OutputSetupUiData :" << outputDataList[i];
	}
	*/
}

QStringList QtArteryTechOutputSetupUI::getUIData()
{
	QStringList resultUIDataList;
	resultUIDataList.clear();
	QString Menustr = "#Output Setup\n";
	resultUIDataList.append(Menustr);
	//QString labeltext = "	" + ui->RefMonitorPointLabel->text() + " " + "-P1coords" + " ";
	QString labeltext = "	-P0coords ";
	QString lineEdit = ui->RefMonitorPointLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint1Label->text() + " " + "-P2coords" + " ";
	labeltext = "	-P1coords ";
	lineEdit = ui->MonitorPoint1LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint2Label->text() + " " + "-P3coords" + " ";
	labeltext = "	-P2coords ";
	lineEdit = ui->MonitorPoint2LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint3Label->text() + " " + "-P4coords" + " ";
	labeltext = "	-P3coords ";
	lineEdit = ui->MonitorPoint3LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P4coords ";
	lineEdit = ui->MonitorPoint4LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P5coords ";
	lineEdit = ui->MonitorPoint5LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P6coords ";
	lineEdit = ui->MonitorPoint6LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P7coords ";
	lineEdit = ui->MonitorPoint7LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P8coords ";
	lineEdit = ui->MonitorPoint8LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	labeltext = "	-P9coords ";
	lineEdit = ui->MonitorPoint9LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->FFRMonitorFileLabel->text() + " " + "-ffroutputname" + " ";
	labeltext = "	-ffroutputname ";
	lineEdit = ui->FFRMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->FlowRateMonitorFileLabel->text() + " " + "-flowoutputname" + " ";
	labeltext = "	-flowoutputname ";
	lineEdit = ui->FlowRateMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->SolutionOutputFileLabel->text() + " " + "-output" + " ";
	labeltext = "	-output ";
	lineEdit = ui->SolutionOutputFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	if (this->showPartitionBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSubdomainMeshDataLabel->text() + " " + "-show_partition_basic" + " ";
		labeltext = "	-show_partition_basic ";
		lineEdit = ui->ShowSubdomainMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->basicGridOutputCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowMeshDataLabel->text() + " " + "-basic_grid_output" + " ";
		labeltext = "	-basic_grid_output ";
		lineEdit = ui->ShowMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->solutionOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSolutionLabel->text() + " " + "-solution_output" + " ";
		labeltext = "	-solution_output ";
		lineEdit = ui->ShowSolutionLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->residualOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->MonitorResidualLabel->text() + " " + "-residual_output" + " ";
		labeltext = "	-residual_output ";
		lineEdit = ui->MonitorResidualLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	//labeltext = "	" + ui->NumberOfStepsForOutputLabel->text() + " " + "-Nplot" + " ";
	labeltext = "	-Nplot ";
	lineEdit = ui->NumberOfStepsForOutputLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->TimeIntervalForOutputLabel->text() + " " + "-dtplot" + " ";
	labeltext = "	#-dtplot ";
	lineEdit = ui->TimeIntervalForOutputLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);
	/*
	for (size_t i = 0; i < this->outputDataList.length(); i++)
	{
	qDebug() << "OutputSetupUiData :" << outputDataList[i];
	}
	*/
	return resultUIDataList;
}

QtArteryTechOutputSetupUI::~QtArteryTechOutputSetupUI()
{
	delete ui;
}

void QtArteryTechOutputSetupUI::closeEvent(QCloseEvent *event)
{
	SaveOutputData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "this", m_tmpFileName + " file open fail !");
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
	for (int i = 0; i < outputDataList.length(); i++)
	{
		tmpFile.write(outputDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechOutputSetupUI::GetOutputData()
{
	QStringList TechOutputSetupUiData;
	QString refMonitorPointStr = ui->RefMonitorPointLabel->text() + "\t" + ui->RefMonitorPointLineEdit->text();
	QString monitorPoint1Str = ui->MonitorPoint1Label->text() + "\t" + ui->MonitorPoint1LineEdit->text();
	QString monitorPoint2Str = ui->MonitorPoint2Label->text() + "\t" + ui->MonitorPoint2LineEdit->text();
	QString monitorPoint3Str = ui->MonitorPoint3Label->text() + "\t" + ui->MonitorPoint3LineEdit->text();
	QString FFRMonitorFileStr = ui->FFRMonitorFileLabel->text() + "\t" + ui->FFRMonitorFileLineEdit->text();
	QString flowRateMonitorFileStr = ui->FlowRateMonitorFileLabel->text() + "\t" + ui->FlowRateMonitorFileLineEdit->text();
	QString solutionOutputFileStr = ui->SolutionOutputFileLabel->text() + "\t" + ui->SolutionOutputFileLineEdit->text();
	QString showSubdomainMeshDataStr = ui->ShowSubdomainMeshDataLabel->text() + "\t" + ui->ShowSubdomainMeshDataLineEdit->text();
	QString showMeshDataStr = ui->ShowMeshDataLabel->text() + "\t" + ui->ShowMeshDataLineEdit->text();
	QString showSolutionStr = ui->ShowSolutionLabel->text() + "\t" + ui->ShowSolutionLineEdit->text();
	QString numberOfStepsForOutputStr = ui->NumberOfStepsForOutputLabel->text() + "\t" + ui->NumberOfStepsForOutputLineEdit->text();
	QString NumberOfStepsForOutputStr = ui->NumberOfStepsForOutputLabel->text() + "\t" + ui->NumberOfStepsForOutputLineEdit->text();
	QString timeIntervalForOutputStr = ui->TimeIntervalForOutputLabel->text() + "\t" + ui->TimeIntervalForOutputLineEdit->text();

	TechOutputSetupUiData.append(refMonitorPointStr);
	TechOutputSetupUiData.append(monitorPoint1Str);
	TechOutputSetupUiData.append(monitorPoint2Str);
	TechOutputSetupUiData.append(monitorPoint3Str);
	TechOutputSetupUiData.append(FFRMonitorFileStr);
	TechOutputSetupUiData.append(flowRateMonitorFileStr);
	TechOutputSetupUiData.append(solutionOutputFileStr);
	TechOutputSetupUiData.append(showSubdomainMeshDataStr);
	TechOutputSetupUiData.append(showMeshDataStr);
	TechOutputSetupUiData.append(showSolutionStr);
	TechOutputSetupUiData.append(numberOfStepsForOutputStr);
	TechOutputSetupUiData.append(NumberOfStepsForOutputStr);
	TechOutputSetupUiData.append(timeIntervalForOutputStr);

	return TechOutputSetupUiData;
}

int QtArteryTechOutputSetupUI::isDigitStr(QString src)
{
	QByteArray ba = src.toLatin1();//QString 转换为 char*  
	const char *s = ba.data();
	if (s[0] == '-')
	{
		s++;
	}

	while (*s && *s >= '0' && *s <= '9' || *s == '.') s++;

	if (*s)
	{
		//不是纯数字  
		return -1;
	}
	else
	{
		//纯数字  
		return 0;
	}
}

//NumberOfStepsForOutputLineEdit槽函数
void QtArteryTechOutputSetupUI::NumberOfStepsForOutputLineEditSlot()
{
	if (ui->NumberOfStepsForOutputLineEdit->text() == NULL)
	{
		ui->NumberOfStepsForOutputLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->NumberOfStepsForOutputLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->NumberOfStepsForOutputLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->NumberOfStepsForOutputLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->NumberOfStepsForOutputLineEdit->setText("0");
		}
	}
}
//TimeIntervalForOutputLineEdit槽函数
void QtArteryTechOutputSetupUI::TimeIntervalForOutputLineEditSlot()
{
	if (ui->TimeIntervalForOutputLineEdit->text() == NULL)
	{
		ui->TimeIntervalForOutputLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->TimeIntervalForOutputLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->TimeIntervalForOutputLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->TimeIntervalForOutputLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->TimeIntervalForOutputLineEdit->setText("0");
		}
	}
}

void QtArteryTechOutputSetupUI::GetVerifyPasswordStatuSlot(bool flag)
{
	InitOutputData(flag);
}

void QtArteryTechOutputSetupUI::GetVariableParametersSignalSlot(QStringList VariableParametersList)
{
	//QMessageBox::information(this, "提示:", "接收信号");
	int length = VariableParametersList.length();
	qDebug() << "length:" << length;
	for (size_t i = 0; i < VariableParametersList.length(); i++)
	{
		if (VariableParametersList.at(i).startsWith("Show Solution:"))
		{
			this->solutionOutputBasicCheckBox->setCheckState(Qt::Checked);
		}//Inlet Flow Rate File:
		else if (VariableParametersList.at(i).startsWith("Solution Output File:"))
		{
			ui->SolutionOutputFileLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Show Mesh Data:"))
		{
			this->basicGridOutputCheckBox->setCheckState(Qt::Checked);
		}
		else if (VariableParametersList.at(i).startsWith("FFR Monitor File:"))
		{
			ui->FFRMonitorFileLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Flow Rate Monitor File:"))
		{
			ui->FlowRateMonitorFileLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}

		else if (VariableParametersList.at(i).startsWith("Ref Monitor Point:"))
		{
			ui->RefMonitorPointLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 1:"))
		{
			ui->MonitorPoint1LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 2:"))
		{
			ui->MonitorPoint2LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 3:"))
		{
			ui->MonitorPoint3LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 4:"))
		{
			ui->MonitorPoint4LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 5:"))
		{
			ui->MonitorPoint5LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 6:"))
		{
			ui->MonitorPoint6LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 7:"))
		{
			ui->MonitorPoint7LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 8:"))
		{
			ui->MonitorPoint8LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Monitor Point 9:"))
		{
			ui->MonitorPoint9LineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
	}
}