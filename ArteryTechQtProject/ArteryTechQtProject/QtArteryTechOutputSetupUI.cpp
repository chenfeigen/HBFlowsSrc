#include "QtArteryTechOutputSetupUI.h"
#include "ui_QtArteryTechOutputSetupUI.h"

QtArteryTechOutputSetupUI::QtArteryTechOutputSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOutputSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(299, 409);
	this->setMaximumSize(299, 409);
	this->setWindowTitle("Output Setup");

	this->showPartitionBasicCheckBox = new QCheckBox;
	this->basicGridOutputCheckBox = new QCheckBox;
	this->solutionOutputBasicCheckBox = new QCheckBox;
	this->residualOutputBasicCheckBox = new QCheckBox;

	this->showPartitionBasicCheckBox->setText("show_partition_basic");
	this->basicGridOutputCheckBox->setText("basic_grid_output");
	this->solutionOutputBasicCheckBox->setText("solution_output");
	this->residualOutputBasicCheckBox->setText("residual_output");


	InitOutputData();
	//SaveOutputData();

	//信号与槽链接
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
	this->setMinimumSize(299, 409);
	this->setMaximumSize(299, 409);
	this->setWindowTitle("Output Setup");

	this->showPartitionBasicCheckBox = new QCheckBox;
	this->basicGridOutputCheckBox = new QCheckBox;
	this->solutionOutputBasicCheckBox = new QCheckBox;
	this->residualOutputBasicCheckBox = new QCheckBox;

	this->showPartitionBasicCheckBox->setText("show_partition_basic");
	this->basicGridOutputCheckBox->setText("basic_grid_output");
	this->solutionOutputBasicCheckBox->setText("solution_output");
	this->residualOutputBasicCheckBox->setText("residual_output");


	InitOutputData();
	//SaveOutputData();

	//信号与槽链接
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

void QtArteryTechOutputSetupUI::InitOutputData()
{
	ui->RefMonitorPointLineEdit->setText("0");
	ui->MonitorPoint1LineEdit->setText("0");
	ui->MonitorPoint2LineEdit->setText("0");
	ui->MonitorPoint3LineEdit->setText("0");
	ui->FFRMonitorFileLineEdit->setText(NULL);
	ui->FlowRateMonitorFileLineEdit->setText(NULL);
	ui->SolutionOutputFileLineEdit->setText(NULL);
	ui->ShowSubdomainMeshDataLineEdit->setText(NULL);
	ui->ShowSubdomainMeshDataLabel->setVisible(false);
	ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
	ui->ShowMeshDataLineEdit->setText(NULL);
	ui->ShowMeshDataLabel->setVisible(false);
	ui->ShowMeshDataLineEdit->setVisible(false);
	ui->ShowSolutionLineEdit->setText(NULL);
	ui->ShowSolutionLabel->setVisible(false);
	ui->ShowSolutionLineEdit->setVisible(false);
	ui->MonitorResidualLineEdit->setText(NULL);
	ui->MonitorResidualLabel->setVisible(false);
	ui->MonitorResidualLineEdit->setVisible(false);

	this->ui->horizontalLayout_8->addWidget(this->showPartitionBasicCheckBox);
	this->ui->horizontalLayout_9->addWidget(this->basicGridOutputCheckBox);
	this->ui->horizontalLayout_10->addWidget(this->solutionOutputBasicCheckBox);
	this->ui->horizontalLayout_11->addWidget(this->residualOutputBasicCheckBox);

	ui->NumberOfStepsForOutputLineEdit->setText("0");
	ui->TimeIntervalForOutputLineEdit->setText("0");
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
	ui->ShowSubdomainMeshDataLabel->setVisible(false);
	ui->ShowSubdomainMeshDataLineEdit->setVisible(false);
	ui->ShowMeshDataLineEdit->setText(NULL);
	ui->ShowMeshDataLabel->setVisible(false);
	ui->ShowMeshDataLineEdit->setVisible(false);
	ui->ShowSolutionLineEdit->setText(NULL);
	ui->ShowSolutionLabel->setVisible(false);
	ui->ShowSolutionLineEdit->setVisible(false);
	ui->MonitorResidualLineEdit->setText(NULL);
	ui->MonitorResidualLabel->setVisible(false);
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
	InitOutputData();
	this->close();
}

void QtArteryTechOutputSetupUI::SaveOutputData()
{
	this->outputDataList.clear();
	QString Menustr = "#Output Setup\n";
	this->outputDataList.append(Menustr);
	//QString labeltext = "	" + ui->RefMonitorPointLabel->text() + " " + "-P1coords" + " ";
	QString labeltext = "   -P1coords ";
	QString lineEdit = ui->RefMonitorPointLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint1Label->text() + " " + "-P2coords" + " ";
	labeltext = "   -P2coords ";
	lineEdit = ui->MonitorPoint1LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint2Label->text() + " " + "-P3coords" + " ";
	labeltext = "   -P3coords ";
	lineEdit = ui->MonitorPoint2LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->MonitorPoint3Label->text() + " " + "-P4coords" + " ";
	labeltext = "   -P4coords ";
	lineEdit = ui->MonitorPoint3LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->FFRMonitorFileLabel->text() + " " + "-ffroutputname" + " ";
	labeltext = "   -ffroutputname ";
	lineEdit = ui->FFRMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->FlowRateMonitorFileLabel->text() + " " + "-flowoutputname" + " ";
	labeltext = "   -flowoutputname ";
	lineEdit = ui->FlowRateMonitorFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->SolutionOutputFileLabel->text() + " " + "-output" + " ";
	labeltext = "   -output ";
	lineEdit = ui->SolutionOutputFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	if (this->showPartitionBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSubdomainMeshDataLabel->text() + " " + "-show_partition_basic" + " ";
		labeltext = "   -show_partition_basic ";
		lineEdit = ui->ShowSubdomainMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->basicGridOutputCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowMeshDataLabel->text() + " " + "-basic_grid_output" + " ";
		labeltext = "   -basic_grid_output ";
		lineEdit = ui->ShowMeshDataLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->solutionOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ShowSolutionLabel->text() + " " + "-solution_output" + " ";
		labeltext = "   -solution_output ";
		lineEdit = ui->ShowSolutionLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	if (this->residualOutputBasicCheckBox->isChecked())
	{
		//labeltext = "	" + ui->MonitorResidualLabel->text() + " " + "-residual_output" + " ";
		labeltext = "   -residual_output ";
		lineEdit = ui->MonitorResidualLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->outputDataList.append(contenttext);
	}

	//labeltext = "	" + ui->NumberOfStepsForOutputLabel->text() + " " + "-Nplot" + " ";
	labeltext = "   -Nplot ";
	lineEdit = ui->NumberOfStepsForOutputLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->outputDataList.append(contenttext);

	//labeltext = "	" + ui->TimeIntervalForOutputLabel->text() + " " + "-dtplot" + " ";
	labeltext = "   -dtplot ";
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
