#include "QtArteryTechTwoLevelPreconditionerUI.h"
#include "ui_QtArteryTechTwoLevelPreconditionerUI.h"

QtArteryTechTwoLevelPreconditionerUI::QtArteryTechTwoLevelPreconditionerUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechTwoLevelPreconditionerUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("两水平预处理参数设置");
	this->setMinimumSize(528, 100);
	this->setMaximumSize(528, 100);

	this->twoLevelPreconditionerCheckBox = new QCheckBox;
	//this->TwoLevelCheckBox = new QCheckBox;
	this->useMGLineEditCheckBox = new QCheckBox;
	this->mGTypeLineEditCheckBox = new QCheckBox;

	this->twoLevelPreconditionerCheckBox->setText("Two-Level Preconditioner");
	//this->TwoLevelCheckBox->setText("two_level");
	this->useMGLineEditCheckBox->setText("mg");
	this->mGTypeLineEditCheckBox->setText("cascade");

	//设置checkbox的初始状态为已经选择
	//this->UseMGLineEditCheckBox->setCheckState(Qt::Checked);


	InitTLPreconditionerData();
	//SaveTLPreconditionerData();
	//信号与槽函数
	QObject::connect(ui->CoarseLinearSolverRestartLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseLinearSolverRestartLineEditSlot()));
	QObject::connect(ui->CoarseLinearSolverMaxIterationLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseLinearSolverMaxIterationLineEditSlot()));
	QObject::connect(ui->FineILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(FineILULevelsLineEditSlot()));
	QObject::connect(ui->CoarseILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseILULevelsLineEditSlot()));
	QObject::connect(this->twoLevelPreconditionerCheckBox, SIGNAL(clicked()), this, SLOT(TwoLevelPreconditionerCheckBoxSlots()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));//CancelPushButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

QtArteryTechTwoLevelPreconditionerUI::QtArteryTechTwoLevelPreconditionerUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechTwoLevelPreconditionerUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setWindowTitle("两水平预处理参数设置");
	this->setMinimumSize(528, 100);
	this->setMaximumSize(528, 100);

	this->twoLevelPreconditionerCheckBox = new QCheckBox;
	//this->TwoLevelCheckBox = new QCheckBox;
	this->useMGLineEditCheckBox = new QCheckBox;
	this->mGTypeLineEditCheckBox = new QCheckBox;

	this->twoLevelPreconditionerCheckBox->setText("Two-Level Preconditioner");
	//this->TwoLevelCheckBox->setText("two_level");
	this->useMGLineEditCheckBox->setText("mg");
	this->mGTypeLineEditCheckBox->setText("cascade");

	//设置checkbox的初始状态为已经选择
	//this->UseMGLineEditCheckBox->setCheckState(Qt::Checked);


	InitTLPreconditionerData();
	//SaveTLPreconditionerData();
	//信号与槽函数
	QObject::connect(ui->CoarseLinearSolverRestartLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseLinearSolverRestartLineEditSlot()));
	QObject::connect(ui->CoarseLinearSolverMaxIterationLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseLinearSolverMaxIterationLineEditSlot()));
	QObject::connect(ui->FineILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(FineILULevelsLineEditSlot()));
	QObject::connect(ui->CoarseILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(CoarseILULevelsLineEditSlot()));
	QObject::connect(this->twoLevelPreconditionerCheckBox, SIGNAL(clicked()), this, SLOT(TwoLevelPreconditionerCheckBoxSlots()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));//OkPushButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));//CancelPushButtonSlots
}

void QtArteryTechTwoLevelPreconditionerUI::InitTLPreconditionerData()
{
	//ui->TwoLevelPreconditionerLineEdit->setText(NULL);
	ui->horizontalLayout->addWidget(this->twoLevelPreconditionerCheckBox);
	ui->CoarseLinearSolverLineEdit->setText(NULL);
	ui->CoarsePreconditionerSideLineEdit->setText(NULL);
	ui->CoarseLinearSolverRestartLineEdit->setText("0");
	ui->CoarseLinearSolverMaxIterationLineEdit->setText("0");
	ui->CoarseLinearSolverRelativeTolLineEdit->setText(NULL);
	//ui->UseMGLineEdit->setText(NULL);
	//ui->MGTypeLineEdit->setText(NULL);
	ui->CompositeTypeLineEdit->setText(NULL);
	ui->MGCycleTypeLineEdit->setText(NULL);
	ui->FinePreconditionerTypeLineEdit->setText(NULL);
	ui->FineSubdomainPreconTypeLineEdit->setText(NULL);
	ui->FineILULevelsLineEdit->setText("0");
	ui->FineSubMatrixOderingTypeLineEdit->setText(NULL);
	ui->CoarsePreconditionerTypeLineEdit->setText(NULL);
	ui->CoarseSubdomainPreconTypeLineEdit->setText(NULL);
	ui->CoarseILULevelsLineEdit->setText("0");
	ui->CoarseSubMatrixOderingTypeLineEdit->setText(NULL);
	//初始化的时候将下面的标签都先进行隐藏
	//将中文标签隐藏
	ui->TwoLevelPreconditionerLineEdit->setVisible(false);
	ui->label_2->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);
	ui->label_7->setVisible(false);
	ui->label_8->setVisible(false);
	ui->label_9->setVisible(false);
	ui->label_10->setVisible(false);
	ui->label_11->setVisible(false);
	ui->label_12->setVisible(false);
	ui->label_13->setVisible(false);
	ui->label_14->setVisible(false);
	ui->label_15->setVisible(false);
	ui->label_16->setVisible(false);
	ui->label_17->setVisible(false);
	ui->label_18->setVisible(false);
	ui->UseMGLabel->setVisible(false);
	ui->UseMGLineEdit->setVisible(false);
	ui->MGTypeLabel->setVisible(false);
	ui->MGTypeLineEdit->setVisible(false);

	ui->CoarseLinearSolverLabel->setVisible(false);
	ui->CoarseLinearSolverLineEdit->setVisible(false);
	ui->CoarsePreconditionerSideLabel->setVisible(false);
	ui->CoarsePreconditionerSideLineEdit->setVisible(false);
	ui->CoarseLinearSolverRestartLabel->setVisible(false);
	ui->CoarseLinearSolverRestartLineEdit->setVisible(false);
	ui->CoarseLinearSolverMaxIterationLabel->setVisible(false);
	ui->CoarseLinearSolverMaxIterationLineEdit->setVisible(false);
	ui->CoarseLinearSolverRelativeTolLabel->setVisible(false);
	ui->CoarseLinearSolverRelativeTolLineEdit->setVisible(false);
	ui->CompositeTypeLabel->setVisible(false);
	ui->CompositeTypeLineEdit->setVisible(false);
	ui->MGCycleTypeLabel->setVisible(false);
	ui->MGCycleTypeLineEdit->setVisible(false);
	ui->FinePreconditionerTypeLabel->setVisible(false);
	ui->FinePreconditionerTypeLineEdit->setVisible(false);
	ui->FineSubdomainPreconTypeLabel->setVisible(false);
	ui->FineSubdomainPreconTypeLineEdit->setVisible(false);
	ui->FineILULevelsLabel->setVisible(false);
	ui->FineILULevelsLineEdit->setVisible(false);
	ui->FineSubMatrixOderingTypeLabel->setVisible(false);
	ui->FineSubMatrixOderingTypeLineEdit->setVisible(false);
	ui->CoarsePreconditionerTypeLabel->setVisible(false);
	ui->CoarsePreconditionerTypeLineEdit->setVisible(false);
	ui->CoarseSubdomainPreconTypeLabel->setVisible(false);
	ui->CoarseSubdomainPreconTypeLineEdit->setVisible(false);
	ui->CoarseILULevelsLabel->setVisible(false);
	ui->CoarseILULevelsLineEdit->setVisible(false);
	ui->CoarseSubMatrixOderingTypeLabel->setVisible(false);
	ui->CoarseSubMatrixOderingTypeLineEdit->setVisible(false);
}
#if 0
void QtArteryTechTwoLevelPreconditionerUI::InitTLPreconditionerData()
{
	//ui->TwoLevelPreconditionerLineEdit->setText(NULL);
	this->ui->horizontalLayout_1->addWidget(this->TwoLevelPreconditionerCheckBox);
	ui->CoarseLinearSolverLineEdit->setText("gmres");
	ui->CoarsePreconditionerSideLineEdit->setText("right");
	ui->CoarseLinearSolverRestartLineEdit->setText("30");
	ui->CoarseLinearSolverMaxIterationLineEdit->setText("30");
	ui->CoarseLinearSolverRelativeTolLineEdit->setText("1.e-1");
	ui->UseMGLineEdit->setText(NULL);
	ui->MGTypeLineEdit->setText(NULL);
	ui->CompositeTypeLineEdit->setText("multiplicative");
	ui->MGCycleTypeLineEdit->setText("v");
	ui->FinePreconditionerTypeLineEdit->setText("asm");
	ui->FineSubdomainPreconTypeLineEdit->setText("ilu");
	ui->FineILULevelsLineEdit->setText("0");
	ui->FineSubMatrixOderingTypeLineEdit->setText("rcm");
	ui->CoarsePreconditionerTypeLineEdit->setText("asm");
	ui->CoarseSubdomainPreconTypeLineEdit->setText("ilu");
	ui->CoarseILULevelsLineEdit->setText("0");
	ui->CoarseSubMatrixOderingTypeLineEdit->setText("rcm");
	//初始化的时候将下面的标签都先进行隐藏
	//将中文标签隐藏
	ui->TwoLevelPreconditionerLineEdit->setVisible(false);
	ui->label_2->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);
	ui->label_7->setVisible(false);
	ui->label_8->setVisible(false);
	ui->label_9->setVisible(false);
	ui->label_10->setVisible(false);
	ui->label_11->setVisible(false);
	ui->label_12->setVisible(false);
	ui->label_13->setVisible(false);
	ui->label_14->setVisible(false);
	ui->label_15->setVisible(false);
	ui->label_16->setVisible(false);
	ui->label_17->setVisible(false);
	ui->label_18->setVisible(false);
	ui->UseMGLabel->setVisible(false);
	ui->UseMGLineEdit->setVisible(false);
	ui->MGTypeLabel->setVisible(false);
	ui->MGTypeLineEdit->setVisible(false);

	ui->CoarseLinearSolverLabel->setVisible(false);
	ui->CoarseLinearSolverLineEdit->setVisible(false);
	ui->CoarsePreconditionerSideLabel->setVisible(false);
	ui->CoarsePreconditionerSideLineEdit->setVisible(false);
	ui->CoarseLinearSolverRestartLabel->setVisible(false);
	ui->CoarseLinearSolverRestartLineEdit->setVisible(false);
	ui->CoarseLinearSolverMaxIterationLabel->setVisible(false);
	ui->CoarseLinearSolverMaxIterationLineEdit->setVisible(false);
	ui->CoarseLinearSolverRelativeTolLabel->setVisible(false);
	ui->CoarseLinearSolverRelativeTolLineEdit->setVisible(false);
	ui->CompositeTypeLabel->setVisible(false);
	ui->CompositeTypeLineEdit->setVisible(false);
	ui->MGCycleTypeLabel->setVisible(false);
	ui->MGCycleTypeLineEdit->setVisible(false);
	ui->FinePreconditionerTypeLabel->setVisible(false);
	ui->FinePreconditionerTypeLineEdit->setVisible(false);
	ui->FineSubdomainPreconTypeLabel->setVisible(false);
	ui->FineSubdomainPreconTypeLineEdit->setVisible(false);
	ui->FineILULevelsLabel->setVisible(false);
	ui->FineILULevelsLineEdit->setVisible(false);
	ui->FineSubMatrixOderingTypeLabel->setVisible(false);
	ui->FineSubMatrixOderingTypeLineEdit->setVisible(false);
	ui->CoarsePreconditionerTypeLabel->setVisible(false);
	ui->CoarsePreconditionerTypeLineEdit->setVisible(false);
	ui->CoarseSubdomainPreconTypeLabel->setVisible(false);
	ui->CoarseSubdomainPreconTypeLineEdit->setVisible(false);
	ui->CoarseILULevelsLabel->setVisible(false);
	ui->CoarseILULevelsLineEdit->setVisible(false);
	ui->CoarseSubMatrixOderingTypeLabel->setVisible(false);
	ui->CoarseSubMatrixOderingTypeLineEdit->setVisible(false);
	this->useMGLineEditCheckBox->setVisible(true);
	this->mGTypeLineEditCheckBox->setVisible(true);

}
#endif

void QtArteryTechTwoLevelPreconditionerUI::TwoLevelPreconditionerCheckBoxSlots()
{
	if (this->twoLevelPreconditionerCheckBox->isChecked())
	{
		this->setMinimumSize(757, 425);
		this->setMaximumSize(757, 425);
		//ui->horizontalLayout_1->addWidget(this->TwoLevelCheckBox);
		//将中文标签隐藏
		ui->TwoLevelPreconditionerLineEdit->setVisible(false);
		ui->label_2->setVisible(true);
		ui->label_3->setVisible(true);
		ui->label_4->setVisible(true);
		ui->label_5->setVisible(true);
		ui->label_6->setVisible(true);
		ui->label_7->setVisible(true);
		ui->label_8->setVisible(true);
		ui->label_9->setVisible(true);
		ui->label_10->setVisible(true);
		ui->label_11->setVisible(true);
		ui->label_12->setVisible(true);
		ui->label_13->setVisible(true);
		ui->label_14->setVisible(true);
		ui->label_15->setVisible(true);
		ui->label_16->setVisible(true);
		ui->label_17->setVisible(true);
		ui->label_18->setVisible(true);
		ui->UseMGLabel->setVisible(true);
		ui->UseMGLineEdit->setVisible(false);
		ui->MGTypeLabel->setVisible(true);
		ui->MGTypeLineEdit->setVisible(false);

		ui->CoarseLinearSolverLabel->setVisible(true);
		ui->CoarseLinearSolverLineEdit->setVisible(true);
		ui->CoarsePreconditionerSideLabel->setVisible(true);
		ui->CoarsePreconditionerSideLineEdit->setVisible(true);
		ui->CoarseLinearSolverRestartLabel->setVisible(true);
		ui->CoarseLinearSolverRestartLineEdit->setVisible(true);
		ui->CoarseLinearSolverMaxIterationLabel->setVisible(true);
		ui->CoarseLinearSolverMaxIterationLineEdit->setVisible(true);
		ui->CoarseLinearSolverRelativeTolLabel->setVisible(true);
		ui->CoarseLinearSolverRelativeTolLineEdit->setVisible(true);
		ui->horizontalLayout_7->addWidget(this->useMGLineEditCheckBox);
		ui->horizontalLayout_8->addWidget(this->mGTypeLineEditCheckBox);
		ui->CompositeTypeLabel->setVisible(true);
		ui->CompositeTypeLineEdit->setVisible(true);
		ui->MGCycleTypeLabel->setVisible(true);
		ui->MGCycleTypeLineEdit->setVisible(true);
		ui->FinePreconditionerTypeLabel->setVisible(true);
		ui->FinePreconditionerTypeLineEdit->setVisible(true);
		ui->FineSubdomainPreconTypeLabel->setVisible(true);
		ui->FineSubdomainPreconTypeLineEdit->setVisible(true);
		ui->FineILULevelsLabel->setVisible(true);
		ui->FineILULevelsLineEdit->setVisible(true);
		ui->FineSubMatrixOderingTypeLabel->setVisible(true);
		ui->FineSubMatrixOderingTypeLineEdit->setVisible(true);
		ui->CoarsePreconditionerTypeLabel->setVisible(true);
		ui->CoarsePreconditionerTypeLineEdit->setVisible(true);
		ui->CoarseSubdomainPreconTypeLabel->setVisible(true);
		ui->CoarseSubdomainPreconTypeLineEdit->setVisible(true);
		ui->CoarseILULevelsLabel->setVisible(true);
		ui->CoarseILULevelsLineEdit->setVisible(true);
		ui->CoarseSubMatrixOderingTypeLabel->setVisible(true);
		ui->CoarseSubMatrixOderingTypeLineEdit->setVisible(true);
		this->useMGLineEditCheckBox->setVisible(true);
		this->mGTypeLineEditCheckBox->setVisible(true);
	}
	else
	{
		this->setMinimumSize(528, 100);
		this->setMaximumSize(528, 100);
		//将中文标签隐藏
		ui->TwoLevelPreconditionerLineEdit->setVisible(false);
		ui->label_2->setVisible(false);
		ui->label_3->setVisible(false);
		ui->label_4->setVisible(false);
		ui->label_5->setVisible(false);
		ui->label_6->setVisible(false);
		ui->label_7->setVisible(false);
		ui->label_8->setVisible(false);
		ui->label_9->setVisible(false);
		ui->label_10->setVisible(false);
		ui->label_11->setVisible(false);
		ui->label_12->setVisible(false);
		ui->label_13->setVisible(false);
		ui->label_14->setVisible(false);
		ui->label_15->setVisible(false);
		ui->label_16->setVisible(false);
		ui->label_17->setVisible(false);
		ui->label_18->setVisible(false);
		ui->UseMGLabel->setVisible(false);
		ui->UseMGLineEdit->setVisible(false);
		ui->MGTypeLabel->setVisible(false);
		ui->MGTypeLineEdit->setVisible(false);

		ui->CoarseLinearSolverLabel->setVisible(false);
		ui->CoarseLinearSolverLineEdit->setVisible(false);
		ui->CoarsePreconditionerSideLabel->setVisible(false);
		ui->CoarsePreconditionerSideLineEdit->setVisible(false);
		ui->CoarseLinearSolverRestartLabel->setVisible(false);
		ui->CoarseLinearSolverRestartLineEdit->setVisible(false);
		ui->CoarseLinearSolverMaxIterationLabel->setVisible(false);
		ui->CoarseLinearSolverMaxIterationLineEdit->setVisible(false);
		ui->CoarseLinearSolverRelativeTolLabel->setVisible(false);
		ui->CoarseLinearSolverRelativeTolLineEdit->setVisible(false);
		ui->CompositeTypeLabel->setVisible(false);
		ui->CompositeTypeLineEdit->setVisible(false);
		ui->MGCycleTypeLabel->setVisible(false);
		ui->MGCycleTypeLineEdit->setVisible(false);
		ui->FinePreconditionerTypeLabel->setVisible(false);
		ui->FinePreconditionerTypeLineEdit->setVisible(false);
		ui->FineSubdomainPreconTypeLabel->setVisible(false);
		ui->FineSubdomainPreconTypeLineEdit->setVisible(false);
		ui->FineILULevelsLabel->setVisible(false);
		ui->FineILULevelsLineEdit->setVisible(false);
		ui->FineSubMatrixOderingTypeLabel->setVisible(false);
		ui->FineSubMatrixOderingTypeLineEdit->setVisible(false);
		ui->CoarsePreconditionerTypeLabel->setVisible(false);
		ui->CoarsePreconditionerTypeLineEdit->setVisible(false);
		ui->CoarseSubdomainPreconTypeLabel->setVisible(false);
		ui->CoarseSubdomainPreconTypeLineEdit->setVisible(false);
		ui->CoarseILULevelsLabel->setVisible(false);
		ui->CoarseILULevelsLineEdit->setVisible(false);
		ui->CoarseSubMatrixOderingTypeLabel->setVisible(false);
		ui->CoarseSubMatrixOderingTypeLineEdit->setVisible(false);
		//this->TwoLevelPreconditionerCheckBox->setVisible(false);
		//this->TwoLevelCheckBox->setVisible(false);
		this->useMGLineEditCheckBox->setVisible(false);
		this->mGTypeLineEditCheckBox->setVisible(false);
	}
}
void QtArteryTechTwoLevelPreconditionerUI::SaveTLPreconditionerData()
{
	this->twoLPreconditionerDataList.clear();
	QString Menustr = "#Two-Level Preconditioner\n";
	this->twoLPreconditionerDataList.append(Menustr);
	if (this->twoLevelPreconditionerCheckBox->isChecked())
	{
		//QString labeltext = "   -two_level ";
		//QString lineEdit = ui->TwoLevelPreconditionerLineEdit->text() + "\n";
		//QString contenttext = labeltext + lineEdit;
		QString labeltext = "	-two_level \n";
		QString lineEdit = NULL;
		QString contenttext = labeltext;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseLinearSolverLabel->text() + " " + "-coarse_ksp_type" + " ";
		labeltext = "	-coarse_ksp_type ";
		lineEdit = ui->CoarseLinearSolverLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarsePreconditionerSideLabel->text() + " " + "-coarse_ksp_pc_side" + " ";
		labeltext = "	-coarse_ksp_pc_side ";
		lineEdit = ui->CoarsePreconditionerSideLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseLinearSolverRestartLabel->text() + " " + "-coarse_ksp_gmres_restart" + " ";
		labeltext = "	-coarse_ksp_gmres_restart ";
		lineEdit = ui->CoarseLinearSolverRestartLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseLinearSolverMaxIterationLabel->text() + " " + "-coarse_ksp_max_it" + " ";
		labeltext = "	-coarse_ksp_max_it ";
		lineEdit = ui->CoarseLinearSolverMaxIterationLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseLinearSolverRelativeTolLabel->text() + " " + "-coarse_ksp_rtol" + " ";
		labeltext = "	-coarse_ksp_rtol ";
		lineEdit = ui->CoarseLinearSolverRelativeTolLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		if (this->useMGLineEditCheckBox->isChecked())
		{
			labeltext = "	-mg ";
			//lineEdit = ui->UseMGLineEdit->text() + "\n";
			lineEdit = "\n";
			contenttext = labeltext + lineEdit;
			this->twoLPreconditionerDataList.append(contenttext);
		}

		if (this->mGTypeLineEditCheckBox->isChecked())
		{
			labeltext = "	-cascade ";
			//lineEdit = ui->MGTypeLineEdit->text() + "\n";
			lineEdit = "\n";
			contenttext = labeltext + lineEdit;
			this->twoLPreconditionerDataList.append(contenttext);
		}

		//labeltext = "	" + ui->CompositeTypeLabel->text() + " " + "-pc_composite_type" + " ";
		labeltext = "	-pc_composite_type ";
		lineEdit = ui->CompositeTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->MGCycleTypeLabel->text() + " " + "-pc_mg_cycle_type" + " ";
		labeltext = "	-pc_mg_cycle_type ";
		lineEdit = ui->MGCycleTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->FinePreconditionerTypeLabel->text() + " " + "-fine_pc_type" + " ";
		labeltext = "	-fine_pc_type ";
		lineEdit = ui->FinePreconditionerTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->FineSubdomainPreconTypeLabel->text() + " " + "-fine_sub_pc_type" + " ";
		labeltext = "	-fine_sub_pc_type ";
		lineEdit = ui->FineSubdomainPreconTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->FineILULevelsLabel->text() + " " + "-fine_sub_pc_factor_levels" + " ";
		labeltext = "	-fine_sub_pc_factor_levels ";
		lineEdit = ui->FineILULevelsLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->FineSubMatrixOderingTypeLabel->text() + " " + "-fine_sub_pc_factor_mat_ordering_type" + " ";
		labeltext = "	-fine_sub_pc_factor_mat_ordering_type ";
		lineEdit = ui->FineSubMatrixOderingTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarsePreconditionerTypeLabel->text() + " " + "-coarse_pc_type" + " ";
		labeltext = "	-coarse_pc_type ";
		lineEdit = ui->CoarsePreconditionerTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseSubdomainPreconTypeLabel->text() + " " + "-coarse_sub_pc_type" + " ";
		labeltext = "	-coarse_sub_pc_type ";
		lineEdit = ui->CoarseSubdomainPreconTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		//labeltext = "	" + ui->CoarseILULevelsLabel->text() + " " + "-coarse_sub_pc_factor_levels" + " ";
		labeltext = "	-coarse_sub_pc_factor_levels ";
		lineEdit = ui->CoarseILULevelsLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

		labeltext = "	" + ui->CoarseSubMatrixOderingTypeLabel->text() + " " + "-two_level" + " ";
		labeltext = "	-coarse_sub_pc_factor_mat_ordering_type ";
		lineEdit = ui->CoarseSubMatrixOderingTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->twoLPreconditionerDataList.append(contenttext);

	}


}

void QtArteryTechTwoLevelPreconditionerUI::OkPushButtonSlots()
{
	SaveTLPreconditionerData();
	this->close();
}

void QtArteryTechTwoLevelPreconditionerUI::CancelPushButtonSlots()
{
	InitTLPreconditionerData();
	this->close();
}

QtArteryTechTwoLevelPreconditionerUI::~QtArteryTechTwoLevelPreconditionerUI()
{
	delete ui;
}

void QtArteryTechTwoLevelPreconditionerUI::closeEvent(QCloseEvent *event)
{
	SaveTLPreconditionerData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "警告：", m_tmpFileName + " 文件打开失败！");
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
	for (int i = 0; i < twoLPreconditionerDataList.length(); i++)
	{
		tmpFile.write(twoLPreconditionerDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechTwoLevelPreconditionerUI::GetTLPreconditionerData()
{
	QStringList TechTwoLevelPreconditionerSetupUiData;
	if (this->twoLevelPreconditionerCheckBox->isChecked())
	{
		QString coarseLinearSolverStr = ui->CoarseLinearSolverLabel->text() + "\t" + ui->CoarseLinearSolverLineEdit->text();
		QString coarsePreconditionerSideStr = ui->CoarsePreconditionerSideLabel->text() + "\t" + ui->CoarsePreconditionerSideLineEdit->text();
		QString coarseLinearSolverRestartStr = ui->CoarseLinearSolverRestartLabel->text() + "\t" + ui->CoarseLinearSolverRestartLineEdit->text();
		QString coarseLinearSolverMaxIterationStr = ui->CoarseLinearSolverMaxIterationLabel->text() + "\t" + ui->CoarseLinearSolverMaxIterationLineEdit->text();
		QString coarseLinearSolverRelativeTolStr = ui->CoarseLinearSolverRelativeTolLabel->text() + "\t" + ui->CoarseLinearSolverRelativeTolLineEdit->text();
		QString compositeTypeStr = ui->CompositeTypeLabel->text() + "\t" + ui->CompositeTypeLineEdit->text();
		QString MGCycleTypeStr = ui->MGCycleTypeLabel->text() + "\t" + ui->MGCycleTypeLineEdit->text();
		QString finePreconditionerTypeaStr = ui->FinePreconditionerTypeLabel->text() + "\t" + ui->FinePreconditionerTypeLineEdit->text();
		QString fineSubdomainPreconTypeStr = ui->FineSubdomainPreconTypeLabel->text() + "\t" + ui->FineSubdomainPreconTypeLineEdit->text();
		QString fineILULevelsStr = ui->FineILULevelsLabel->text() + "\t" + ui->FineILULevelsLineEdit->text();
		QString fineSubMatrixOderingTypeStr = ui->FineSubMatrixOderingTypeLabel->text() + "\t" + ui->FineSubMatrixOderingTypeLineEdit->text();
		QString coarsePreconditionerTypeStr = ui->CoarsePreconditionerTypeLabel->text() + "\t" + ui->CoarsePreconditionerTypeLineEdit->text();
		QString coarseSubdomainPreconTypeStr = ui->CoarseSubdomainPreconTypeLabel->text() + "\t" + ui->CoarseSubdomainPreconTypeLineEdit->text();
		QString coarseILULevelsStr = ui->CoarseILULevelsLabel->text() + "\t" + ui->CoarseILULevelsLineEdit->text();
		QString coarseSubMatrixOderingTypeStr = ui->CoarseSubMatrixOderingTypeLabel->text() + "\t" + ui->CoarseSubMatrixOderingTypeLineEdit->text();

		TechTwoLevelPreconditionerSetupUiData.append(coarseLinearSolverStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarsePreconditionerSideStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseLinearSolverRestartStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseLinearSolverMaxIterationStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseLinearSolverRelativeTolStr);
		TechTwoLevelPreconditionerSetupUiData.append(compositeTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(MGCycleTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(finePreconditionerTypeaStr);
		TechTwoLevelPreconditionerSetupUiData.append(fineSubdomainPreconTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(fineILULevelsStr);
		TechTwoLevelPreconditionerSetupUiData.append(fineSubMatrixOderingTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarsePreconditionerTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseSubdomainPreconTypeStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseILULevelsStr);
		TechTwoLevelPreconditionerSetupUiData.append(coarseSubMatrixOderingTypeStr);

		return TechTwoLevelPreconditionerSetupUiData;

	}
	return TechTwoLevelPreconditionerSetupUiData;
}


int QtArteryTechTwoLevelPreconditionerUI::isDigitStr(QString src)
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

//CoarseLinearSolverRestartLineEdit槽函数
void QtArteryTechTwoLevelPreconditionerUI::CoarseLinearSolverRestartLineEditSlot()
{
	if (ui->CoarseLinearSolverRestartLineEdit->text() == NULL)
	{
		ui->CoarseLinearSolverRestartLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoarseLinearSolverRestartLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoarseLinearSolverRestartLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoarseLinearSolverRestartLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->CoarseLinearSolverRestartLineEdit->setText("0");
		}
	}
}


//CoarseLinearSolverMaxIterationLineEdit槽函数
void QtArteryTechTwoLevelPreconditionerUI::CoarseLinearSolverMaxIterationLineEditSlot()
{
	if (ui->CoarseLinearSolverMaxIterationLineEdit->text() == NULL)
	{
		ui->CoarseLinearSolverMaxIterationLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoarseLinearSolverMaxIterationLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoarseLinearSolverMaxIterationLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoarseLinearSolverMaxIterationLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->CoarseLinearSolverMaxIterationLineEdit->setText("0");
		}
	}
}

//FineILULevelsLineEdit槽函数
void QtArteryTechTwoLevelPreconditionerUI::FineILULevelsLineEditSlot()
{
	if (ui->FineILULevelsLineEdit->text() == NULL)
	{
		ui->FineILULevelsLineEdit->setText("0");
		return;
	}
	else
	{
		if (ui->FineILULevelsLineEdit->text().trimmed().length() > 8)
		{
			QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
			ui->FineILULevelsLineEdit->setText("0");
			return;
		}
		bool digitsStatus = isDigitStr(ui->FineILULevelsLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->FineILULevelsLineEdit->setText("0");
		}
	}
}

//CoarseILULevelsLineEdit槽函数
void QtArteryTechTwoLevelPreconditionerUI::CoarseILULevelsLineEditSlot()
{
	if (ui->CoarseILULevelsLineEdit->text() == NULL)
	{
		ui->CoarseILULevelsLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoarseILULevelsLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoarseILULevelsLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoarseILULevelsLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->CoarseILULevelsLineEdit->setText("0");
		}
	}
}