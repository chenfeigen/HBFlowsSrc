#include "QtArteryTechPhysicsSetupUI.h"
#include "ui_QtArteryTechPhysicsSetupUI.h"

QtArteryTechPhysicsSetupUI::QtArteryTechPhysicsSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechPhysicsSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMaximumSize(231, 523);
	this->setMinimumSize(231, 523);
	this->setWindowTitle("Physics Setup");

	this->allImpedanceCheckBox = new QCheckBox;
	this->bloodflowCheckBox = new QCheckBox;
	this->fluidonlyCheckBox = new QCheckBox;
	this->fixedMeshCheckBox = new QCheckBox;
	this->zeroInitialCheckBox = new QCheckBox;

	this->allImpedanceCheckBox->setText("All Impedance");
	this->bloodflowCheckBox->setText("bloodflow");
	this->fluidonlyCheckBox->setText("fluidonly");
	this->fixedMeshCheckBox->setText("fixed_mesh");
	this->zeroInitialCheckBox->setText("zero_initial");
	//设置checkbox的初始状态为已经选择
	//this->BloodflowCheckBox->setCheckState(Qt::Checked);
	//this->FluidonlyCheckBox->setCheckState(Qt::Checked);
	//this->FixedMeshCheckBox->setCheckState(Qt::Checked);
	//this->ZeroInitialCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_3->addWidget(this->allImpedanceCheckBox);
	ui->horizontalLayout_8->addWidget(this->bloodflowCheckBox);
	ui->horizontalLayout_9->addWidget(this->fluidonlyCheckBox);
	ui->horizontalLayout_15->addWidget(this->fixedMeshCheckBox);
	ui->horizontalLayout_16->addWidget(this->zeroInitialCheckBox);



	InitPhysicsData();
	//SavePhysicsData();
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

QtArteryTechPhysicsSetupUI::QtArteryTechPhysicsSetupUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechPhysicsSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setMaximumSize(231, 523);
	this->setMinimumSize(231, 523);
	this->setWindowTitle("Physics Setup");

	this->allImpedanceCheckBox = new QCheckBox;
	this->bloodflowCheckBox = new QCheckBox;
	this->fluidonlyCheckBox = new QCheckBox;
	this->fixedMeshCheckBox = new QCheckBox;
	this->zeroInitialCheckBox = new QCheckBox;

	this->allImpedanceCheckBox->setText("All Impedance");
	this->bloodflowCheckBox->setText("bloodflow");
	this->fluidonlyCheckBox->setText("fluidonly");
	this->fixedMeshCheckBox->setText("fixed_mesh");
	this->zeroInitialCheckBox->setText("zero_initial");
	//设置checkbox的初始状态为已经选择
	//this->BloodflowCheckBox->setCheckState(Qt::Checked);
	//this->FluidonlyCheckBox->setCheckState(Qt::Checked);
	//this->FixedMeshCheckBox->setCheckState(Qt::Checked);
	//this->ZeroInitialCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_3->addWidget(this->allImpedanceCheckBox);
	ui->horizontalLayout_8->addWidget(this->bloodflowCheckBox);
	ui->horizontalLayout_9->addWidget(this->fluidonlyCheckBox);
	ui->horizontalLayout_15->addWidget(this->fixedMeshCheckBox);
	ui->horizontalLayout_16->addWidget(this->zeroInitialCheckBox);



	InitPhysicsData();
	//SavePhysicsData();
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

void QtArteryTechPhysicsSetupUI::InitPhysicsData()
{
	ui->TotalResistanceLineEdit->setText("0");
	ui->TotalCapacityLineEdit->setText("0");
	ui->AllImpedanceLineEdit->setText(NULL);
	ui->AllImpedanceLabel->setVisible(false);
	ui->AllImpedanceLineEdit->setVisible(false);
	ui->PdForWK3LineEdit->setText("0");
	ui->P0ForWK3LineEdit->setText("0");
	ui->FluidViscosityLineEdit->setText("0");
	ui->FluidDensityLineEdit->setText("0");
	ui->BloodFlowSimulationLineEdit->setText(NULL);
	ui->BloodFlowSimulationLabel->setVisible(false);
	ui->BloodFlowSimulationLineEdit->setVisible(false);
	ui->FluidOnlySimulationLineEdit->setText(NULL);
	ui->FluidOnlySimulationLabel->setVisible(false);
	ui->FluidOnlySimulationLineEdit->setVisible(false);
	ui->TimeDiscretizationMethodLineEdit->setText("0");
	ui->InitialTimeLineEdit->setText("0");
	ui->FinalTimeLineEdit->setText("0");
	ui->TimeStepSizeLineEdit->setText("0");
	ui->PeriodLineEdit->setText("0");
	ui->FixedMeshLineEdit->setText(NULL);
	ui->FixedMeshLabel->setVisible(false);
	ui->FixedMeshLineEdit->setVisible(false);
	ui->ZeroInitialConditionLineEdit->setText(NULL);
	ui->ZeroInitialConditionLabel->setVisible(false);
	ui->ZeroInitialConditionLineEdit->setVisible(false);
	ui->InletVelocityLineEdit->setText("0");
}
#if 0
void QtArteryTechPhysicsSetupUI::InitPhysicsData()
{
	ui->TotalResistanceLineEdit->setText("7600.0");
	ui->TotalCapacityLineEdit->setText("8.e-4");
	ui->AllImpedanceLineEdit->setText(NULL);
	ui->AllImpedanceLabel->setVisible(false);
	ui->AllImpedanceLineEdit->setVisible(false);
	ui->PdForWK3LineEdit->setText("0.0");
	ui->P0ForWK3LineEdit->setText("77.0");
	ui->FluidViscosityLineEdit->setText("0.035");
	ui->FluidDensityLineEdit->setText("1.060");
	ui->BloodFlowSimulationLineEdit->setText(NULL);
	ui->BloodFlowSimulationLabel->setVisible(false);
	ui->BloodFlowSimulationLineEdit->setVisible(false);
	ui->FluidOnlySimulationLineEdit->setText(NULL);
	ui->FluidOnlySimulationLabel->setVisible(false);
	ui->FluidOnlySimulationLineEdit->setVisible(false);
	ui->TimeDiscretizationMethodLineEdit->setText("1");
	ui->InitialTimeLineEdit->setText("0.0");
	ui->FinalTimeLineEdit->setText("0.909090909");
	ui->TimeStepSizeLineEdit->setText("0.00909090909");
	ui->PeriodLineEdit->setText("5.0");
	ui->FixedMeshLineEdit->setText(NULL);
	ui->FixedMeshLabel->setVisible(false);
	ui->FixedMeshLineEdit->setVisible(false);
	ui->ZeroInitialConditionLineEdit->setText(NULL);
	ui->ZeroInitialConditionLabel->setVisible(false);
	ui->ZeroInitialConditionLineEdit->setVisible(false);
	ui->InletVelocityLineEdit->setText("1.0");
}
#endif
void QtArteryTechPhysicsSetupUI::SavePhysicsData()
{
	QtArteryTechBoundarySetupUI *BoundarySetupUiDialog = new QtArteryTechBoundarySetupUI;
	this->physicsDataList.clear();
	QString Menustr = "#Physics Setup\n";
	this->physicsDataList.append(Menustr);
	//QString labeltext = "	" + ui->TotalResistanceLabel->text() + " " + "-R_total" + " ";
	QString labeltext = "   -R_total ";
	QString lineEdit = ui->TotalResistanceLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->TotalCapacityLabel->text() + " " + "-C_total" + " ";
	labeltext = "   -C_total ";
	lineEdit = ui->TotalCapacityLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	if (this->allImpedanceCheckBox->isChecked())
	{
		if (BoundarySetupUiDialog->bloodflowBcTypeText == "2")
		{
			//labeltext = "	" + ui->AllImpedanceLabel->text() + " " + "-all_impedance_bc" + " ";
			labeltext = "   -all_impedance_bc ";
			lineEdit = ui->AllImpedanceLineEdit->text() + "\n";
			contenttext = labeltext + lineEdit;
			this->physicsDataList.append(contenttext);
		}
		else
		{
			//labeltext = "	" + ui->AllImpedanceLabel->text() + " " + "-resistance_distribution_pulmonary" + " ";
			labeltext = "   -resistance_distribution_pulmonary ";
			lineEdit = ui->AllImpedanceLineEdit->text() + "\n";
			contenttext = labeltext + lineEdit;
			this->physicsDataList.append(contenttext);
		}

	}


	//labeltext = "	" + ui->PdForWK3Label->text() + " " + "-impedance_pd" + " ";
	labeltext = "   -impedance_pd ";
	lineEdit = ui->PdForWK3LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->P0ForWK3Label->text() + " " + "-impedance_p0" + " ";
	labeltext = "   -impedance_p0 ";
	lineEdit = ui->P0ForWK3LineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->FluidViscosityLabel->text() + " " + "-viscosity" + " ";
	labeltext = "   -viscosity ";
	lineEdit = ui->FluidViscosityLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->FluidDensityLabel->text() + " " + "-fluid_density" + " ";
	labeltext = "   -fluid_density ";
	lineEdit = ui->FluidDensityLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	if (this->bloodflowCheckBox->isChecked())
	{
		//labeltext = "	" + ui->BloodFlowSimulationLabel->text() + " " + "-bloodflow" + " ";
		labeltext = "   -bloodflow ";
		lineEdit = ui->BloodFlowSimulationLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->physicsDataList.append(contenttext);
	}

	if (this->fluidonlyCheckBox->isChecked())
	{
		//labeltext = "	" + ui->FluidOnlySimulationLabel->text() + " " + "-fluidonly" + " ";
		labeltext = "   -fluidonly ";
		lineEdit = ui->FluidOnlySimulationLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->physicsDataList.append(contenttext);
	}

	//labeltext = "	" + ui->TimeDiscretizationMethodLabel->text() + " " + "-timestep" + " ";
	labeltext = "   -timestep ";
	lineEdit = ui->TimeDiscretizationMethodLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->InitialTimeLabel->text() + " " + "-initial_time" + " ";
	labeltext = "   -initial_time ";
	lineEdit = ui->InitialTimeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->FinalTimeLabel->text() + " " + "-final_time" + " ";
	labeltext = "   -final_time ";
	lineEdit = ui->FinalTimeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->TimeStepSizeLabel->text() + " " + "-dt" + " ";
	labeltext = "   -dt ";
	lineEdit = ui->TimeStepSizeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	//labeltext = "	" + ui->PeriodLabel->text() + " " + "-period" + " ";
	labeltext = "   -period ";
	lineEdit = ui->PeriodLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);

	if (this->fixedMeshCheckBox->isChecked())
	{
		//labeltext = "	" + ui->FixedMeshLabel->text() + " " + "-fixed_mesh" + " ";
		labeltext = "   -fixed_mesh ";
		lineEdit = ui->FixedMeshLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->physicsDataList.append(contenttext);
	}

	if (this->zeroInitialCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ZeroInitialConditionLabel->text() + " " + "-zero_initial" + " ";
		labeltext = "   -zero_initial ";
		lineEdit = ui->ZeroInitialConditionLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->physicsDataList.append(contenttext);
	}

	//labeltext = "	" + ui->InletVelocityLabel->text() + " " + "-P1coords" + " ";
	labeltext = "   -P1coords ";
	lineEdit = ui->InletVelocityLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->physicsDataList.append(contenttext);
	/*
	for (size_t i = 0; i < physicsDataList.length(); i++)
	{
	qDebug() << "PhysicsSetupUiData:" << physicsDataList[i];
	}
	*/
}

void QtArteryTechPhysicsSetupUI::OkPushButtonSlots()
{
	SavePhysicsData();
	this->close();
}

void QtArteryTechPhysicsSetupUI::CancelPushButtonSlots()
{
	InitPhysicsData();
	this->close();
}

QtArteryTechPhysicsSetupUI::~QtArteryTechPhysicsSetupUI()
{
	delete ui;
}

void QtArteryTechPhysicsSetupUI::closeEvent(QCloseEvent *event)
{
	SavePhysicsData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "this", m_tmpFileName + " file open fail !");
	}
	for (int i = 0; i < physicsDataList.length(); i++)
	{
		tmpFile.write(physicsDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechPhysicsSetupUI::GetPhysicsData()
{
	QStringList PhysicsSetupUiData;
	QString totalResistanceStr = ui->TotalResistanceLabel->text() + "\t" + ui->TotalResistanceLineEdit->text();
	QString totalCapacityStr = ui->TotalCapacityLabel->text() + "\t" + ui->TotalCapacityLineEdit->text();
	QString allImpedanceStr = ui->AllImpedanceLabel->text() + "\t" + ui->AllImpedanceLineEdit->text();
	QString pdForWK3Str = ui->PdForWK3Label->text() + "\t" + ui->PdForWK3LineEdit->text();
	QString p0ForWK3Str = ui->P0ForWK3Label->text() + "\t" + ui->P0ForWK3LineEdit->text();
	QString fluidViscosityFileStr = ui->FluidViscosityLabel->text() + "\t" + ui->FluidViscosityLineEdit->text();
	QString fluidDensityStr = ui->FluidDensityLabel->text() + "\t" + ui->FluidDensityLineEdit->text();
	QString bloodFlowSimulationStr = ui->BloodFlowSimulationLabel->text() + "\t" + ui->BloodFlowSimulationLineEdit->text();
	QString fluidOnlySimulationStr = ui->FluidOnlySimulationLabel->text() + "\t" + ui->FluidOnlySimulationLineEdit->text();
	QString timeDiscretizationMethodStr = ui->TimeDiscretizationMethodLabel->text() + "\t" + ui->TimeDiscretizationMethodLineEdit->text();
	QString initialTimeStr = ui->InitialTimeLabel->text() + "\t" + ui->InitialTimeLineEdit->text();
	QString finalTimeStr = ui->FinalTimeLabel->text() + "\t" + ui->FinalTimeLineEdit->text();
	QString timeStepSizeStr = ui->TimeStepSizeLabel->text() + "\t" + ui->TimeStepSizeLineEdit->text();
	QString periodStr = ui->PeriodLabel->text() + "\t" + ui->PeriodLineEdit->text();
	QString fixedMeshStr = ui->FixedMeshLabel->text() + "\t" + ui->FixedMeshLineEdit->text();
	QString zeroInitialConditionStr = ui->ZeroInitialConditionLabel->text() + "\t" + ui->ZeroInitialConditionLineEdit->text();
	QString inletVelocityStr = ui->InletVelocityLabel->text() + "\t" + ui->InletVelocityLineEdit->text();

	PhysicsSetupUiData.append(totalResistanceStr);
	PhysicsSetupUiData.append(totalCapacityStr);
	PhysicsSetupUiData.append(allImpedanceStr);
	PhysicsSetupUiData.append(pdForWK3Str);
	PhysicsSetupUiData.append(p0ForWK3Str);
	PhysicsSetupUiData.append(fluidViscosityFileStr);
	PhysicsSetupUiData.append(fluidDensityStr);
	PhysicsSetupUiData.append(bloodFlowSimulationStr);
	PhysicsSetupUiData.append(fluidOnlySimulationStr);
	PhysicsSetupUiData.append(timeDiscretizationMethodStr);
	PhysicsSetupUiData.append(initialTimeStr);
	PhysicsSetupUiData.append(finalTimeStr);
	PhysicsSetupUiData.append(timeStepSizeStr);
	PhysicsSetupUiData.append(periodStr);
	PhysicsSetupUiData.append(fixedMeshStr);
	PhysicsSetupUiData.append(zeroInitialConditionStr);
	PhysicsSetupUiData.append(inletVelocityStr);

	return PhysicsSetupUiData;
}
