#include "QtArteryTechPreconditionerSetupUI.h"
#include "ui_QtArteryTechPreconditionerSetupUI.h"

QtArteryTechPreconditionerSetupUI::QtArteryTechPreconditionerSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechPreconditionerSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("Preconditioner Setup");
	this->setMinimumSize(255, 243);
	this->setMaximumSize(255, 243);

	this->geometricAsmCheckBox = new QCheckBox;
	this->geometricAsmCheckBox->setText("geometric_asm");
	//设置checkbox的初始状态为已经选择
	//this->GeometricAsmCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_7->addWidget(this->geometricAsmCheckBox);

	InitPreconditionerData();
	//SavePreconditionerData();
	//信号与槽函数的连接
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

QtArteryTechPreconditionerSetupUI::QtArteryTechPreconditionerSetupUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechPreconditionerSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setWindowTitle("Preconditioner Setup");
	this->setMinimumSize(255, 243);
	this->setMaximumSize(255, 243);

	this->geometricAsmCheckBox = new QCheckBox;
	this->geometricAsmCheckBox->setText("geometric_asm");
	//设置checkbox的初始状态为已经选择
	//this->GeometricAsmCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_7->addWidget(this->geometricAsmCheckBox);

	InitPreconditionerData();
	//SavePreconditionerData();
	//信号与槽函数的连接
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));
}

void QtArteryTechPreconditionerSetupUI::InitPreconditionerData()
{
	ui->PreconditionerTypeLineEdit->setText(NULL);
	ui->ASMTypeLineEdit->setText(NULL);
	ui->SubdomainSolverLineEdit->setText(NULL);
	ui->ILULevelsLineEdit->setText("0");
	ui->SubdomainMatrixOrderingTypeLineEdit->setText(NULL);
	ui->OverlappingTypeLineEdit->setText(NULL);
	ui->OverlappingTypeLabel->setVisible(false);
	ui->OverlappingTypeLineEdit->setVisible(false);
	ui->OverlappingSizeLineEdit->setText("0");
}
#if 0
void QtArteryTechPreconditionerSetupUI::InitPreconditionerData()
{
	ui->PreconditionerTypeLineEdit->setText("asm");
	ui->ASMTypeLineEdit->setText("RESTRICT");
	ui->SubdomainSolverLineEdit->setText("ilu");
	ui->ILULevelsLineEdit->setText("1");
	ui->SubdomainMatrixOrderingTypeLineEdit->setText("rcm");
	ui->OverlappingTypeLineEdit->setText(NULL);
	ui->OverlappingTypeLabel->setVisible(false);
	ui->OverlappingTypeLineEdit->setVisible(false);
	ui->OverlappingSizeLineEdit->setText("1");
}
#endif
void QtArteryTechPreconditionerSetupUI::SavePreconditionerData()
{
	this->preconditionerDataList.clear();
	QString Menustr = "#Preconditioner Setup\n";
	this->preconditionerDataList.append(Menustr);
	//QString labeltext = "	" + ui->PreconditionerTypeLabel->text() + " " + "-pc_type" + " ";
	QString labeltext = "   -pc_type ";
	QString lineEdit = ui->PreconditionerTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->ASMTypeLabel->text() + " " + "-pc_asm_type" + " ";
	labeltext = "   -pc_asm_type ";
	lineEdit = ui->ASMTypeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->SubdomainSolverLabel->text() + " " + "-sub_pc_type" + " ";
	labeltext = "   -sub_pc_type ";
	lineEdit = ui->SubdomainSolverLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->ILULevelsLabel->text() + " " + "-sub_pc_factor_levels" + " ";
	labeltext = "   -sub_pc_factor_levels ";
	lineEdit = ui->ILULevelsLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->SubdomainMatrixOrderingTypeLabel->text() + " " + "-sub_pc_factor_mat_ordering_type" + " ";
	labeltext = "   -sub_pc_factor_mat_ordering_type ";
	lineEdit = ui->SubdomainMatrixOrderingTypeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	if (this->geometricAsmCheckBox->isChecked())
	{
		//labeltext = "	" + ui->OverlappingTypeLabel->text() + " " + "-geometric_asm" + " ";
		labeltext = "   -geometric_asm ";
		lineEdit = ui->OverlappingTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->preconditionerDataList.append(contenttext);
	}

	//labeltext = "	" + ui->OverlappingSizeLabel->text() + " " + "-geometric_asm_overlap" + " ";
	labeltext = "   -geometric_asm_overlap ";
	lineEdit = ui->OverlappingSizeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);
	/*
	for (size_t i = 0; i < preconditionerDataList.length(); i++)
	{
	qDebug() << "PreconditionerSetupUiData:" << preconditionerDataList[i];
	}
	*/
}

void QtArteryTechPreconditionerSetupUI::OkPushButtonSlots()
{
	SavePreconditionerData();
	this->close();
}

void QtArteryTechPreconditionerSetupUI::CancelPushButtonSlots()
{
	InitPreconditionerData();
	this->close();
}

QtArteryTechPreconditionerSetupUI::~QtArteryTechPreconditionerSetupUI()
{
	delete ui;
}


void QtArteryTechPreconditionerSetupUI::closeEvent(QCloseEvent *event)
{
	SavePreconditionerData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "this", m_tmpFileName + " file open fail !");
	}
	for (int i = 0; i < preconditionerDataList.length(); i++)
	{
		tmpFile.write(preconditionerDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechPreconditionerSetupUI::GetTechPreconditionerData()
{
	QStringList TechPreconditionerSetupUiData;
	QString preconditionerTypeStr = ui->PreconditionerTypeLabel->text() + "\t" + ui->PreconditionerTypeLineEdit->text();
	QString aSMTypeStr = ui->ASMTypeLabel->text() + "\t" + ui->ASMTypeLineEdit->text();
	QString subdomainSolverStr = ui->SubdomainSolverLabel->text() + "\t" + ui->SubdomainSolverLineEdit->text();
	QString ILULevelsStr = ui->ILULevelsLabel->text() + "\t" + ui->ILULevelsLineEdit->text();
	QString subdomainMatrixOrderingTypeStr = ui->SubdomainMatrixOrderingTypeLabel->text() + "\t" + ui->SubdomainMatrixOrderingTypeLineEdit->text();
	QString overlappingTypeStr = ui->OverlappingTypeLabel->text() + "\t" + ui->OverlappingTypeLineEdit->text();
	QString overlappingSizeStr = ui->OverlappingSizeLabel->text() + "\t" + ui->OverlappingSizeLineEdit->text();


	TechPreconditionerSetupUiData.append(preconditionerTypeStr);
	TechPreconditionerSetupUiData.append(aSMTypeStr);
	TechPreconditionerSetupUiData.append(subdomainSolverStr);
	TechPreconditionerSetupUiData.append(ILULevelsStr);
	TechPreconditionerSetupUiData.append(subdomainMatrixOrderingTypeStr);
	TechPreconditionerSetupUiData.append(overlappingTypeStr);
	TechPreconditionerSetupUiData.append(overlappingSizeStr);

	return TechPreconditionerSetupUiData;
}

