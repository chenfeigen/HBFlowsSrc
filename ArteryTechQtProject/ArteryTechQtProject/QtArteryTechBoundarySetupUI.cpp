#include "QtArteryTechBoundarySetupUI.h"
#include "ui_QtArteryTechBoundarySetupUI.h"

QtArteryTechBoundarySetupUI::QtArteryTechBoundarySetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechBoundarySetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("边界条件设置");
	setMinimumSize(1115, 500);
	setMaximumSize(1115, 500);
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	this->vinCheckBox = new QCheckBox;
	this->wallCheckBox = new QCheckBox;
	this->inletFlowfactorCheckBox = new QCheckBox;
	this->parabolicInflowCheckBox = new QCheckBox;

	this->vinCheckBox->setText("vin");
	this->wallCheckBox->setText("wall");
	this->inletFlowfactorCheckBox->setText("inlet_flowfactor");
	this->parabolicInflowCheckBox->setText("parabolic_inflow");
	//设置checkbox的初始状态为已经选择
	//this->VinCheckBox->setCheckState(Qt::Checked);
	//this->WallCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_9->addWidget(this->vinCheckBox);
	ui->horizontalLayout_10->addWidget(this->wallCheckBox);
	ui->horizontalLayout_21->addWidget(this->inletFlowfactorCheckBox);
	ui->horizontalLayout_22->addWidget(this->parabolicInflowCheckBox);


	//设置初始值
	InitUiData();
	//获取UI界面上的数据
	//SaveBoundaryData();
	QObject::connect(ui->OKPushButton, SIGNAL(clicked(bool)), this, SLOT(OKPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlots()));

	QObject::connect(ui->BoundaryTypeLineEdit, SIGNAL(editingFinished()), this, SLOT(BoundaryTypeLineEditSlot()));
	QObject::connect(ui->NumberOfOutletsLineEdit, SIGNAL(editingFinished()), this, SLOT(NumberOfOutletsLineEditSlot()));
	QObject::connect(ui->IndexForAortaOutletLineEdit, SIGNAL(editingFinished()), this, SLOT(IndexForAortaOutletLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryAreaLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryAreaLineEditSlot()));
}

QtArteryTechBoundarySetupUI::QtArteryTechBoundarySetupUI(QString tmpFileName,QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechBoundarySetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("边界条件设置");
	setMinimumSize(1115, 500);
	setMaximumSize(1115, 500);
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	m_tmpFileName = tmpFileName;

	this->vinCheckBox = new QCheckBox;
	this->wallCheckBox = new QCheckBox;
	this->inletFlowfactorCheckBox = new QCheckBox;
	this->parabolicInflowCheckBox = new QCheckBox;

	this->vinCheckBox->setText("vin");
	this->wallCheckBox->setText("wall");
	this->inletFlowfactorCheckBox->setText("inlet_flowfactor");
	this->parabolicInflowCheckBox->setText("parabolic_inflow");
	//设置checkbox的初始状态为已经选择
	//this->VinCheckBox->setCheckState(Qt::Checked);
	//this->WallCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_9->addWidget(this->vinCheckBox);
	ui->horizontalLayout_10->addWidget(this->wallCheckBox);
	ui->horizontalLayout_21->addWidget(this->inletFlowfactorCheckBox);
	ui->horizontalLayout_22->addWidget(this->parabolicInflowCheckBox);


	//设置初始值
	InitUiData();
	//获取UI界面上的数据
	//SaveBoundaryData();
	QObject::connect(ui->OKPushButton, SIGNAL(clicked(bool)), this, SLOT(OKPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlots()));

	QObject::connect(ui->BoundaryTypeLineEdit, SIGNAL(editingFinished()), this, SLOT(BoundaryTypeLineEditSlot()));
	QObject::connect(ui->NumberOfOutletsLineEdit, SIGNAL(editingFinished()), this, SLOT(NumberOfOutletsLineEditSlot()));
	QObject::connect(ui->IndexForAortaOutletLineEdit, SIGNAL(editingFinished()), this, SLOT(IndexForAortaOutletLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryNormZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryNormZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryLowBoundZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryLowBoundZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundXDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundYDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryUpperBoundZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryUpperBoundZDirectionLineEditSlot()));
	QObject::connect(ui->InletBoudaryAreaLineEdit, SIGNAL(editingFinished()), this, SLOT(InletBoudaryAreaLineEditSlot()));
}

void QtArteryTechBoundarySetupUI::OKPushButtonSlots()
{
	SaveBoundaryData();
	this->close();
}

void QtArteryTechBoundarySetupUI::CancelPushButtonSlots()
{
	InitBoundaryData(false);
	this->close();
}

#if 0
//初始化UI界面上的数据
void QtArteryTechBoundarySetupUI::InitBoundaryData()
{
	ui->BoundaryTypeLineEdit->setText("0");
	ui->NodeSetFileLineEdit->setText(NULL);
	ui->SideSetFileLineEdit->setText(NULL);
	ui->NodeAndSideSetFileLineEdit->setText(NULL);
	ui->WindkesselFileLineEdit->setText(NULL);
	ui->InletFlowRateFileLineEdit->setText(NULL);
	ui->NumberOfOutletsLineEdit->setText("0");
	ui->IndexForAortaOutletLineEdit->setText("0");
	ui->IncludeInletBoundaryLineEdit->setText(NULL);
	ui->IncludeInletBoundaryLabel->setVisible(true);
	ui->IncludeInletBoundaryLineEdit->setVisible(false);
	ui->IncludeWallBoundaryLineEdit->setText(NULL);
	ui->IncludeWallBoundaryLabel->setVisible(true);
	ui->IncludeWallBoundaryLineEdit->setVisible(false);
	ui->InletBoudaryNormXDirectionLineEdit->setText("0");
	ui->InletBoudaryNormYDirectionLineEdit->setText("0");
	ui->InletBoudaryNormZDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
	ui->InletBoudaryAreaLineEdit->setText("0");
	ui->InletFlowRateFactorLineEdit->setText(NULL);
	ui->InletFlowRateFactorLabel->setVisible(true);
	ui->InletFlowRateFactorLineEdit->setVisible(false);
	ui->ParabolicInflowLineEdit->setText(NULL);
	ui->ParabolicInflowLabel->setVisible(true);
	ui->ParabolicInflowLineEdit->setVisible(false);
}
#endif

void QtArteryTechBoundarySetupUI::InitUiData()
{
	this->vinCheckBox->setVisible(false);
	this->vinCheckBox->setEnabled(false);
	this->vinCheckBox->setCheckState(Qt::Checked);

	this->wallCheckBox->setVisible(false);
	this->wallCheckBox->setEnabled(false);
	this->wallCheckBox->setCheckState(Qt::Checked);

	ui->BoundaryTypeLineEdit->setVisible(false);
	ui->BoundaryTypeLineEdit->setEnabled(false);
	ui->BoundaryTypeLineEdit->setText("2");

	ui->NodeSetFileLineEdit->setText(NULL);
	ui->SideSetFileLineEdit->setText(NULL);
	ui->NodeAndSideSetFileLineEdit->setText(NULL);
	ui->WindkesselFileLineEdit->setText(NULL);
	ui->InletFlowRateFileLineEdit->setText(NULL);
	ui->NumberOfOutletsLineEdit->setText("0");

	ui->IndexForAortaOutletLineEdit->setVisible(false);
	ui->IndexForAortaOutletLineEdit->setEnabled(false);
	ui->IndexForAortaOutletLineEdit->setText("21");

	ui->IncludeInletBoundaryLineEdit->setText(NULL);
	ui->IncludeInletBoundaryLabel->setVisible(true);
	ui->IncludeInletBoundaryLineEdit->setVisible(false);
	ui->IncludeWallBoundaryLineEdit->setText(NULL);
	ui->IncludeWallBoundaryLabel->setVisible(true);
	ui->IncludeWallBoundaryLineEdit->setVisible(false);
	ui->InletBoudaryNormXDirectionLineEdit->setText("0");
	ui->InletBoudaryNormYDirectionLineEdit->setText("0");
	ui->InletBoudaryNormZDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
	ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
	ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
	ui->InletBoudaryAreaLineEdit->setText("0");
	ui->InletFlowRateFactorLineEdit->setText(NULL);
	ui->InletFlowRateFactorLabel->setVisible(true);
	ui->InletFlowRateFactorLineEdit->setVisible(false);
	ui->ParabolicInflowLineEdit->setText(NULL);
	ui->ParabolicInflowLabel->setVisible(true);
	ui->ParabolicInflowLineEdit->setVisible(false);
}

#if 1
//初始化UI界面上的数据
void QtArteryTechBoundarySetupUI::InitBoundaryData(bool flag)
{
	if (flag)
	{
		//允许修改
		this->vinCheckBox->setVisible(true);
		this->vinCheckBox->setEnabled(true);
		this->wallCheckBox->setVisible(true);
		this->wallCheckBox->setEnabled(true);
		ui->BoundaryTypeLineEdit->setVisible(true);
		ui->BoundaryTypeLineEdit->setEnabled(true);
		//ui->BoundaryTypeLineEdit->setText("2");
		ui->NodeSetFileLineEdit->setText(NULL);
		ui->SideSetFileLineEdit->setText(NULL);
		//ui->NodeAndSideSetFileLineEdit->setText(NULL);
		ui->WindkesselFileLineEdit->setText(NULL);
		//ui->InletFlowRateFileLineEdit->setText(NULL);
		//ui->NumberOfOutletsLineEdit->setText("0");

		ui->IndexForAortaOutletLineEdit->setVisible(true);
		ui->IndexForAortaOutletLineEdit->setEnabled(true);
		//ui->IndexForAortaOutletLineEdit->setText("21");
		ui->IncludeInletBoundaryLineEdit->setText(NULL);
		ui->IncludeInletBoundaryLabel->setVisible(true);
		ui->IncludeInletBoundaryLineEdit->setVisible(false);
		ui->IncludeWallBoundaryLineEdit->setText(NULL);
		ui->IncludeWallBoundaryLabel->setVisible(true);
		ui->IncludeWallBoundaryLineEdit->setVisible(false);
		ui->InletBoudaryNormXDirectionLineEdit->setText("0");
		ui->InletBoudaryNormYDirectionLineEdit->setText("0");
		ui->InletBoudaryNormZDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
		ui->InletBoudaryAreaLineEdit->setText("0");
		ui->InletFlowRateFactorLineEdit->setText(NULL);
		ui->InletFlowRateFactorLabel->setVisible(true);
		ui->InletFlowRateFactorLineEdit->setVisible(false);
		ui->ParabolicInflowLineEdit->setText(NULL);
		ui->ParabolicInflowLabel->setVisible(true);
		ui->ParabolicInflowLineEdit->setVisible(false);
	}
	else
	{
		this->vinCheckBox->setVisible(false);
		this->vinCheckBox->setEnabled(false);

		this->wallCheckBox->setVisible(false);
		this->wallCheckBox->setEnabled(false);

		ui->BoundaryTypeLineEdit->setVisible(false);
		ui->BoundaryTypeLineEdit->setEnabled(false);

		ui->NodeSetFileLineEdit->setText(NULL);
		ui->SideSetFileLineEdit->setText(NULL);
		//ui->NodeAndSideSetFileLineEdit->setText(NULL);
		ui->WindkesselFileLineEdit->setText(NULL);
		//ui->InletFlowRateFileLineEdit->setText(NULL);
		//ui->NumberOfOutletsLineEdit->setText("0");

		ui->IndexForAortaOutletLineEdit->setVisible(false);
		ui->IndexForAortaOutletLineEdit->setEnabled(false);

		ui->IncludeInletBoundaryLineEdit->setText(NULL);
		ui->IncludeInletBoundaryLabel->setVisible(true);
		ui->IncludeInletBoundaryLineEdit->setVisible(false);
		ui->IncludeWallBoundaryLineEdit->setText(NULL);
		ui->IncludeWallBoundaryLabel->setVisible(true);
		ui->IncludeWallBoundaryLineEdit->setVisible(false);
		ui->InletBoudaryNormXDirectionLineEdit->setText("0");
		ui->InletBoudaryNormYDirectionLineEdit->setText("0");
		ui->InletBoudaryNormZDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
		ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
		ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
		ui->InletBoudaryAreaLineEdit->setText("0");
		ui->InletFlowRateFactorLineEdit->setText(NULL);
		ui->InletFlowRateFactorLabel->setVisible(true);
		ui->InletFlowRateFactorLineEdit->setVisible(false);
		ui->ParabolicInflowLineEdit->setText(NULL);
		ui->ParabolicInflowLabel->setVisible(true);
		ui->ParabolicInflowLineEdit->setVisible(false);
	}
	
}
#endif
//获取UI界面上的数据
void QtArteryTechBoundarySetupUI::SaveBoundaryData()
{
	boundaryDataList.clear();
	QString MenuStr = "#Boundary Setup\n";
	boundaryDataList.append(MenuStr);
	//QString labeltext = "	" + ui->BoundaryTypeLabel->text() + " " + "-bloodflow_bc_type" + " ";
	QString labeltext = "	-bloodflow_bc_type ";
	QString lineEdit = ui->BoundaryTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	bloodflowBcTypeText = ui->BoundaryTypeLineEdit->text().trimmed();
	SendBoundaryTypeSignal(bloodflowBcTypeText);
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->NodeSetFileLabel->text() + " " + "-nodeset_file" + " ";
	if (NULL == ui->NodeSetFileLineEdit->text().trimmed())
	{
		contenttext = "	#-nodeset_file\n";
		boundaryDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-nodeset_file ";
		lineEdit = ui->NodeSetFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	if (NULL == ui->SideSetFileLineEdit->text().trimmed())
	{
		contenttext = "	#-sideset_file\n";;
		boundaryDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-sideset_file ";
		lineEdit = ui->SideSetFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	//labeltext = "	" + ui->NodeAndSideSetFileLabel->text() + " " + "-BC_setup_file" + " ";
	labeltext = "	-BC_setup_file ";
	lineEdit = ui->NodeAndSideSetFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->WindkesselFileLabel->text() + " " + "-Windkessel_file" + " ";
	if (NULL == ui->WindkesselFileLineEdit->text().trimmed())
	{
		contenttext = "	#-Windkessel_file\n";
		boundaryDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-Windkessel_file ";
		lineEdit = ui->WindkesselFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	//labeltext = "	" + ui->InletFlowRateFileLabel->text() + " " + "-Q_file" + " ";
	labeltext = "	-Q_file ";
	lineEdit = ui->InletFlowRateFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->NumberOfOutletsLabel->text() + " " + "-num_outlet" + " ";
	labeltext = "	-num_outlet ";
	lineEdit = ui->NumberOfOutletsLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->IndexForAortaOutletLabel->text() + " " + "-aortic_outlet" + " ";
	labeltext = "	-aortic_outlet ";
	lineEdit = ui->IndexForAortaOutletLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	if (this->vinCheckBox->isChecked())
	{
		//labeltext = "	" + ui->IncludeInletBoundaryLabel->text() + " " + "-vin" + " ";
		labeltext = "	-vin ";
		lineEdit = ui->IncludeInletBoundaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	if (this->wallCheckBox->isChecked())
	{
		//labeltext = "	" + ui->IncludeWallBoundaryLabel->text() + " " + "-wall" + " ";
		labeltext = "	-wall ";
		lineEdit = ui->IncludeWallBoundaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	//labeltext = "	" + ui->InletBoudaryNormXDirectionLabel->text() + " " + "-inlet_nx" + " ";
	labeltext = "	#-inlet_nx ";
	lineEdit = ui->InletBoudaryNormXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryNormYDirectionLabel->text() + " " + "-inlet_ny" + " ";
	labeltext = "	#-inlet_ny ";
	lineEdit = ui->InletBoudaryNormYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryNormZDirectionLabel->text() + " " + "-inlet_nz" + " ";
	labeltext = "	#-inlet_nz ";
	lineEdit = ui->InletBoudaryNormZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundXDirectionLabel->text() + " " + "-inlet_xi" + " ";
	labeltext = "	#-inlet_xi ";
	lineEdit = ui->InletBoudaryLowBoundXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundYDirectionLabel->text() + " " + "-inlet_yi" + " ";
	labeltext = "	#-inlet_yi ";
	lineEdit = ui->InletBoudaryLowBoundYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundZDirectionLabel->text() + " " + "-inlet_zi" + " ";
	labeltext = "	#-inlet_zi ";
	lineEdit = ui->InletBoudaryLowBoundZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundXDirectionLabel->text() + " " + "-inlet_xf" + " ";
	labeltext = "	#-inlet_xf ";
	lineEdit = ui->InletBoudaryUpperBoundXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundYDirectionLabel->text() + " " + "-inlet_yf" + " ";
	labeltext = "	#-inlet_yf ";
	lineEdit = ui->InletBoudaryUpperBoundYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundZDirectionLabel->text() + " " + "-inlet_zf" + " ";
	labeltext = "	#-inlet_zf ";
	lineEdit = ui->InletBoudaryUpperBoundZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryAreaLabel->text() + " " + "-inlet_area" + " ";
	labeltext = "	#-inlet_area ";
	lineEdit = ui->InletBoudaryAreaLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	boundaryDataList.append(contenttext);

	if (this->inletFlowfactorCheckBox->isChecked())
	{
		//labeltext = "	" + ui->InletFlowRateFactorLabel->text() + " " + "-inlet_flowfactor" + " ";
		labeltext = "	-inlet_flowfactor ";
		lineEdit = ui->InletFlowRateFactorLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}

	if (this->parabolicInflowCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ParabolicInflowLabel->text() + " " + "-parabolic_inflow" + " ";
		labeltext = "	-parabolic_inflow ";
		lineEdit = ui->ParabolicInflowLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		boundaryDataList.append(contenttext);
	}
}

// 获取UI界面上的数据
QStringList QtArteryTechBoundarySetupUI::getUIData()
{
	QStringList resultUIDataList;
	resultUIDataList.clear();
	QString MenuStr = "#Boundary Setup\n";
	resultUIDataList.append(MenuStr);
	//QString labeltext = "	" + ui->BoundaryTypeLabel->text() + " " + "-bloodflow_bc_type" + " ";
	QString labeltext = "	-bloodflow_bc_type ";
	QString lineEdit = ui->BoundaryTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	bloodflowBcTypeText = ui->BoundaryTypeLineEdit->text().trimmed();
	SendBoundaryTypeSignal(bloodflowBcTypeText);
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->NodeSetFileLabel->text() + " " + "-nodeset_file" + " ";
	if (NULL == ui->NodeSetFileLineEdit->text().trimmed())
	{
		contenttext = "	#-nodeset_file\n";
		resultUIDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-nodeset_file ";
		lineEdit = ui->NodeSetFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (NULL == ui->SideSetFileLineEdit->text().trimmed())
	{
		contenttext = "	#-sideset_file\n";;
		resultUIDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-sideset_file ";
		lineEdit = ui->SideSetFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	//labeltext = "	" + ui->NodeAndSideSetFileLabel->text() + " " + "-BC_setup_file" + " ";
	labeltext = "	-BC_setup_file ";
	lineEdit = ui->NodeAndSideSetFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->WindkesselFileLabel->text() + " " + "-Windkessel_file" + " ";
	if (NULL == ui->WindkesselFileLineEdit->text().trimmed())
	{
		contenttext = "	#-Windkessel_file\n";
		resultUIDataList.append(contenttext);
	}
	else
	{
		labeltext = "	-Windkessel_file ";
		lineEdit = ui->WindkesselFileLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	//labeltext = "	" + ui->InletFlowRateFileLabel->text() + " " + "-Q_file" + " ";
	labeltext = "	-Q_file ";
	lineEdit = ui->InletFlowRateFileLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->NumberOfOutletsLabel->text() + " " + "-num_outlet" + " ";
	labeltext = "	-num_outlet ";
	lineEdit = ui->NumberOfOutletsLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->IndexForAortaOutletLabel->text() + " " + "-aortic_outlet" + " ";
	labeltext = "	-aortic_outlet ";
	lineEdit = ui->IndexForAortaOutletLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	if (this->vinCheckBox->isChecked())
	{
		//labeltext = "	" + ui->IncludeInletBoundaryLabel->text() + " " + "-vin" + " ";
		labeltext = "	-vin ";
		lineEdit = ui->IncludeInletBoundaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->wallCheckBox->isChecked())
	{
		//labeltext = "	" + ui->IncludeWallBoundaryLabel->text() + " " + "-wall" + " ";
		labeltext = "	-wall ";
		lineEdit = ui->IncludeWallBoundaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	//labeltext = "	" + ui->InletBoudaryNormXDirectionLabel->text() + " " + "-inlet_nx" + " ";
	labeltext = "	#-inlet_nx ";
	lineEdit = ui->InletBoudaryNormXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryNormYDirectionLabel->text() + " " + "-inlet_ny" + " ";
	labeltext = "	#-inlet_ny ";
	lineEdit = ui->InletBoudaryNormYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryNormZDirectionLabel->text() + " " + "-inlet_nz" + " ";
	labeltext = "	#-inlet_nz ";
	lineEdit = ui->InletBoudaryNormZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundXDirectionLabel->text() + " " + "-inlet_xi" + " ";
	labeltext = "	#-inlet_xi ";
	lineEdit = ui->InletBoudaryLowBoundXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundYDirectionLabel->text() + " " + "-inlet_yi" + " ";
	labeltext = "	#-inlet_yi ";
	lineEdit = ui->InletBoudaryLowBoundYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryLowBoundZDirectionLabel->text() + " " + "-inlet_zi" + " ";
	labeltext = "	#-inlet_zi ";
	lineEdit = ui->InletBoudaryLowBoundZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundXDirectionLabel->text() + " " + "-inlet_xf" + " ";
	labeltext = "	#-inlet_xf ";
	lineEdit = ui->InletBoudaryUpperBoundXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundYDirectionLabel->text() + " " + "-inlet_yf" + " ";
	labeltext = "	#-inlet_yf ";
	lineEdit = ui->InletBoudaryUpperBoundYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryUpperBoundZDirectionLabel->text() + " " + "-inlet_zf" + " ";
	labeltext = "	#-inlet_zf ";
	lineEdit = ui->InletBoudaryUpperBoundZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->InletBoudaryAreaLabel->text() + " " + "-inlet_area" + " ";
	labeltext = "	#-inlet_area ";
	lineEdit = ui->InletBoudaryAreaLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	if (this->inletFlowfactorCheckBox->isChecked())
	{
		//labeltext = "	" + ui->InletFlowRateFactorLabel->text() + " " + "-inlet_flowfactor" + " ";
		labeltext = "	-inlet_flowfactor ";
		lineEdit = ui->InletFlowRateFactorLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->parabolicInflowCheckBox->isChecked())
	{
		//labeltext = "	" + ui->ParabolicInflowLabel->text() + " " + "-parabolic_inflow" + " ";
		labeltext = "	-parabolic_inflow ";
		lineEdit = ui->ParabolicInflowLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}
	return resultUIDataList;
}

QtArteryTechBoundarySetupUI::~QtArteryTechBoundarySetupUI()
{
	delete ui;
}

void QtArteryTechBoundarySetupUI::closeEvent(QCloseEvent *event)
{
	SaveBoundaryData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "警告", m_tmpFileName + " 文件打开失败！");
		return;
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
	for (int i = 0; i < boundaryDataList.length(); i++)
	{
		tmpFile.write(boundaryDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechBoundarySetupUI::GetBoundaryData()
{
	QStringList boundarySetupUiData;
	QString boundaryTypeStr = ui->BoundaryTypeLabel->text() + "\t" + ui->BoundaryTypeLineEdit->text();
	QString nodeSetFileStr = ui->NodeSetFileLabel->text() + "\t" + ui->NodeSetFileLineEdit->text();
	QString sideSetFileStr = ui->SideSetFileLabel->text() + "\t" + ui->SideSetFileLineEdit->text();
	QString nodeAndSideSetFileStr = ui->NodeAndSideSetFileLabel->text() + "\t" + ui->NodeAndSideSetFileLineEdit->text();
	QString windkesselFileStr = ui->WindkesselFileLabel->text() + "\t" + ui->WindkesselFileLineEdit->text();
	QString inletFlowRateFileStr = ui->InletFlowRateFileLabel->text() + "\t" + ui->InletFlowRateFileLineEdit->text();
	QString numberOfOutletsStr = ui->NumberOfOutletsLabel->text() + "\t" + ui->NumberOfOutletsLineEdit->text();
	QString indexForAortaOutletStr = ui->IndexForAortaOutletLabel->text() + "\t" + ui->IndexForAortaOutletLineEdit->text();
	QString includeInletBoundaryStr = ui->IncludeInletBoundaryLabel->text() + "\t" + ui->IncludeInletBoundaryLineEdit->text();
	QString includeWallBoundaryStr = ui->IncludeWallBoundaryLabel->text() + "\t" + ui->IncludeWallBoundaryLineEdit->text();
	QString inletBoudaryNormXDirectionStr = ui->InletBoudaryNormXDirectionLabel->text() + "\t" + ui->InletBoudaryNormXDirectionLineEdit->text();
	QString inletBoudaryNormYDirectionStr = ui->InletBoudaryNormYDirectionLabel->text() + "\t" + ui->InletBoudaryNormYDirectionLineEdit->text();
	QString inletBoudaryNormZDirectionStr = ui->InletBoudaryNormZDirectionLabel->text() + "\t" + ui->InletBoudaryNormZDirectionLineEdit->text();
	QString inletBoudaryLowBoundXDirectionStr = ui->InletBoudaryLowBoundXDirectionLabel->text() + "\t" + ui->InletBoudaryLowBoundXDirectionLineEdit->text();
	QString inletBoudaryLowBoundYDirectionStr = ui->InletBoudaryLowBoundYDirectionLabel->text() + "\t" + ui->InletBoudaryLowBoundYDirectionLineEdit->text();
	QString inletBoudaryLowBoundZDirectionStr = ui->InletBoudaryLowBoundZDirectionLabel->text() + "\t" + ui->InletBoudaryLowBoundZDirectionLineEdit->text();
	QString inletBoudaryUpperBoundXDirectionStr = ui->InletBoudaryUpperBoundXDirectionLabel->text() + "\t" + ui->InletBoudaryUpperBoundXDirectionLineEdit->text();
	QString inletBoudaryUpperBoundYDirectionStr = ui->InletBoudaryUpperBoundYDirectionLabel->text() + "\t" + ui->InletBoudaryUpperBoundYDirectionLineEdit->text();
	QString inletBoudaryUpperBoundZDirectionStr = ui->InletBoudaryUpperBoundZDirectionLabel->text() + "\t" + ui->InletBoudaryUpperBoundZDirectionLineEdit->text();
	QString inletBoudaryAreaStr = ui->InletBoudaryAreaLabel->text() + "\t" + ui->InletBoudaryAreaLineEdit->text();
	QString inletFlowRateFactorStr = ui->InletFlowRateFactorLabel->text() + "\t" + ui->InletFlowRateFactorLineEdit->text();
	QString parabolicInflowStr = ui->ParabolicInflowLabel->text() + "\t" + ui->ParabolicInflowLineEdit->text();

	boundarySetupUiData.append(boundaryTypeStr);
	boundarySetupUiData.append(nodeSetFileStr);
	boundarySetupUiData.append(sideSetFileStr);
	boundarySetupUiData.append(nodeAndSideSetFileStr);
	boundarySetupUiData.append(windkesselFileStr);
	boundarySetupUiData.append(inletFlowRateFileStr);
	boundarySetupUiData.append(numberOfOutletsStr);
	boundarySetupUiData.append(indexForAortaOutletStr);
	boundarySetupUiData.append(includeInletBoundaryStr);
	boundarySetupUiData.append(includeWallBoundaryStr);
	boundarySetupUiData.append(inletBoudaryNormXDirectionStr);
	boundarySetupUiData.append(inletBoudaryNormYDirectionStr);
	boundarySetupUiData.append(inletBoudaryNormZDirectionStr);
	boundarySetupUiData.append(inletBoudaryLowBoundXDirectionStr);
	boundarySetupUiData.append(inletBoudaryLowBoundYDirectionStr);
	boundarySetupUiData.append(inletBoudaryLowBoundZDirectionStr);
	boundarySetupUiData.append(inletBoudaryUpperBoundXDirectionStr);
	boundarySetupUiData.append(inletBoudaryUpperBoundYDirectionStr);
	boundarySetupUiData.append(inletBoudaryUpperBoundZDirectionStr);
	boundarySetupUiData.append(inletBoudaryAreaStr);
	boundarySetupUiData.append(inletFlowRateFactorStr);
	boundarySetupUiData.append(parabolicInflowStr);

	return boundarySetupUiData;
}

int QtArteryTechBoundarySetupUI::isDigitStr(QString src)
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

//BoundaryTypeLineEdit槽函数
void QtArteryTechBoundarySetupUI::BoundaryTypeLineEditSlot()
{
	if (ui->BoundaryTypeLineEdit->text() == NULL)
	{
		ui->BoundaryTypeLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->BoundaryTypeLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->BoundaryTypeLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告:", "数字输入过长，请重新输入！");
				ui->BoundaryTypeLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告:", "只能输入数字，请重新输入！");
			ui->BoundaryTypeLineEdit->setText("0");
		}
	}
}

//NumberOfOutletsLineEdit槽函数
void QtArteryTechBoundarySetupUI::NumberOfOutletsLineEditSlot()
{
	if (ui->NumberOfOutletsLineEdit->text() == NULL)
	{
		ui->NumberOfOutletsLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->NumberOfOutletsLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->NumberOfOutletsLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告:", "数字输入过长，请重新输入！");
				ui->NumberOfOutletsLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告:", "只能输入数字，请重新输入！");
			ui->NumberOfOutletsLineEdit->setText("0");
		}
	}
}

//IndexForAortaOutletLineEdit槽函数
void QtArteryTechBoundarySetupUI::IndexForAortaOutletLineEditSlot()
{
	if (ui->IndexForAortaOutletLineEdit->text() == NULL)
	{
		ui->IndexForAortaOutletLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->IndexForAortaOutletLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->IndexForAortaOutletLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告:", "数字输入过长，请重新输入！");
				ui->IndexForAortaOutletLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告:", "只能输入数字，请重新输入！");
			ui->IndexForAortaOutletLineEdit->setText("0");
		}
	}
}

//InletBoudaryNormXDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryNormXDirectionLineEditSlot()
{
	if (ui->InletBoudaryNormXDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryNormXDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryNormXDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryNormXDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryNormXDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryNormXDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryNormYDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryNormYDirectionLineEditSlot()
{
	if (ui->InletBoudaryNormYDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryNormYDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryNormYDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryNormYDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryNormYDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryNormYDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryNormZDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryNormZDirectionLineEditSlot()
{
	if (ui->InletBoudaryNormZDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryNormZDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryNormZDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryNormZDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryNormZDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryNormZDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryLowBoundXDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryLowBoundXDirectionLineEditSlot()
{
	if (ui->InletBoudaryLowBoundXDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryLowBoundXDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryLowBoundXDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryLowBoundXDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryLowBoundYDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryLowBoundYDirectionLineEditSlot()
{
	if (ui->InletBoudaryLowBoundYDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryLowBoundYDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryLowBoundYDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryLowBoundYDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryLowBoundZDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryLowBoundZDirectionLineEditSlot()
{
	if (ui->InletBoudaryLowBoundZDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryLowBoundZDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryLowBoundZDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryLowBoundZDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryUpperBoundXDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryUpperBoundXDirectionLineEditSlot()
{
	if (ui->InletBoudaryUpperBoundXDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryUpperBoundXDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryUpperBoundXDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryUpperBoundXDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryUpperBoundYDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryUpperBoundYDirectionLineEditSlot()
{
	if (ui->InletBoudaryUpperBoundYDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryUpperBoundYDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryUpperBoundYDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryUpperBoundYDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryUpperBoundZDirectionLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryUpperBoundZDirectionLineEditSlot()
{
	if (ui->InletBoudaryUpperBoundZDirectionLineEdit->text() == NULL)
	{
		ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryUpperBoundZDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryUpperBoundZDirectionLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryUpperBoundZDirectionLineEdit->setText("0");
		}
	}
}

//InletBoudaryAreaLineEdit槽函数
void QtArteryTechBoundarySetupUI::InletBoudaryAreaLineEditSlot()
{
	if (ui->InletBoudaryAreaLineEdit->text() == NULL)
	{
		ui->InletBoudaryAreaLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InletBoudaryAreaLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InletBoudaryAreaLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InletBoudaryAreaLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InletBoudaryAreaLineEdit->setText("0");
		}
	}
}

void QtArteryTechBoundarySetupUI::SendBoundaryTypeSignal(QString boundaryTypeText)
{
	emit BoundaryTypeSignal(boundaryTypeText);
}

void QtArteryTechBoundarySetupUI::BTCheckBoxStateChanged(int Status)
{
	if (Status == Qt::Checked) // "选中"
	{
		ui->BoundaryTypeLineEdit->setReadOnly(false);
	}
	else if (Status == Qt::PartiallyChecked) // "半选"
	{
		ui->BoundaryTypeLineEdit->setReadOnly(true);
	}
	else // 未选中 - Qt::Unchecked
	{
		ui->BoundaryTypeLineEdit->setReadOnly(true);
	}
}


void QtArteryTechBoundarySetupUI::IFAOCheckBoxStateChanged(int Status)
{
	if (Status == Qt::Checked) // "选中"
	{
		ui->IndexForAortaOutletLineEdit->setReadOnly(false);
	}
	else if (Status == Qt::PartiallyChecked) // "半选"
	{
		ui->IndexForAortaOutletLineEdit->setReadOnly(true);
	}
	else // 未选中 - Qt::Unchecked
	{
		ui->IndexForAortaOutletLineEdit->setReadOnly(true);
	}
}

void QtArteryTechBoundarySetupUI::GetVerifyPasswordStatuSlot(bool flag)
{
	InitBoundaryData(flag);
}

void QtArteryTechBoundarySetupUI::GetVariableParametersSignalSlot(QStringList VariableParametersList)
{
	//QMessageBox::information(this,"提示:","接收信号");
	int length = VariableParametersList.length();
	qDebug() << "length:" << length;
	for (size_t i = 0; i < VariableParametersList.length(); i++)
	{
		if (VariableParametersList.at(i).startsWith("Node & Side Set File:"))
		{
			ui->NodeAndSideSetFileLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Inlet Flow Rate File:"))
		{
			ui->InletFlowRateFileLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
		else if (VariableParametersList.at(i).startsWith("Number of Outlets:"))
		{
			ui->NumberOfOutletsLineEdit->setText(VariableParametersList.at(i).split(":").at(1));
		}
	}
}
