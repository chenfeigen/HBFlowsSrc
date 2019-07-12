#include "QtArteryTechPreconditionerSetupUI.h"
#include "ui_QtArteryTechPreconditionerSetupUI.h"

QtArteryTechPreconditionerSetupUI::QtArteryTechPreconditionerSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechPreconditionerSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("Ԥ�����㷨��������");
	this->setMinimumSize(647, 211);
	this->setMaximumSize(647, 211);

	this->geometricAsmCheckBox = new QCheckBox;
	this->geometricAsmCheckBox->setText("geometric_asm");
	//����checkbox�ĳ�ʼ״̬Ϊ�Ѿ�ѡ��
	//this->GeometricAsmCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_7->addWidget(this->geometricAsmCheckBox);

	InitPreconditionerData();
	//SavePreconditionerData();
	//�ź���ۺ���������
	QObject::connect(ui->ILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(ILULevelsLineEditSlot()));
	QObject::connect(ui->OverlappingSizeLineEdit, SIGNAL(editingFinished()), this, SLOT(OverlappingSizeLineEditSlot()));
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
	this->setWindowTitle("Ԥ�����㷨��������");
	this->setMinimumSize(647, 211);
	this->setMaximumSize(647, 211);

	this->geometricAsmCheckBox = new QCheckBox;
	this->geometricAsmCheckBox->setText("geometric_asm");
	//����checkbox�ĳ�ʼ״̬Ϊ�Ѿ�ѡ��
	//this->GeometricAsmCheckBox->setCheckState(Qt::Checked);

	ui->horizontalLayout_6->addWidget(this->geometricAsmCheckBox);

	InitPreconditionerData();
	//SavePreconditionerData();
	//�ź���ۺ���������
	QObject::connect(ui->ILULevelsLineEdit, SIGNAL(editingFinished()), this, SLOT(ILULevelsLineEditSlot()));
	QObject::connect(ui->OverlappingSizeLineEdit, SIGNAL(editingFinished()), this, SLOT(OverlappingSizeLineEditSlot()));
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
	ui->OverlappingTypeLabel->setVisible(true);
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
	QString labeltext = "	-pc_type ";
	QString lineEdit = ui->PreconditionerTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->ASMTypeLabel->text() + " " + "-pc_asm_type" + " ";
	labeltext = "	#-pc_asm_type ";
	lineEdit = ui->ASMTypeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->SubdomainSolverLabel->text() + " " + "-sub_pc_type" + " ";
	labeltext = "	-sub_pc_type ";
	lineEdit = ui->SubdomainSolverLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->ILULevelsLabel->text() + " " + "-sub_pc_factor_levels" + " ";
	labeltext = "	-sub_pc_factor_levels ";
	lineEdit = ui->ILULevelsLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	//labeltext = "	" + ui->SubdomainMatrixOrderingTypeLabel->text() + " " + "-sub_pc_factor_mat_ordering_type" + " ";
	labeltext = "	-sub_pc_factor_mat_ordering_type ";
	lineEdit = ui->SubdomainMatrixOrderingTypeLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->preconditionerDataList.append(contenttext);

	if (this->geometricAsmCheckBox->isChecked())
	{
		//labeltext = "	" + ui->OverlappingTypeLabel->text() + " " + "-geometric_asm" + " ";
		labeltext = "	-geometric_asm ";
		lineEdit = ui->OverlappingTypeLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->preconditionerDataList.append(contenttext);
	}

	//labeltext = "	" + ui->OverlappingSizeLabel->text() + " " + "-geometric_asm_overlap" + " ";
	labeltext = "	-geometric_asm_overlap ";
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
		QMessageBox::warning(this, "���棺", m_tmpFileName + " �ļ���ʧ��!");
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
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


int QtArteryTechPreconditionerSetupUI::isDigitStr(QString src)
{
	QByteArray ba = src.toLatin1();//QString ת��Ϊ char*  
	const char *s = ba.data();
	if (s[0] == '-')
	{
		s++;
	}

	while (*s && *s >= '0' && *s <= '9' || *s == '.') s++;

	if (*s)
	{
		//���Ǵ�����  
		return -1;
	}
	else
	{
		//������  
		return 0;
	}
}

//ILULevelsLineEdit�ۺ���
void QtArteryTechPreconditionerSetupUI::ILULevelsLineEditSlot()
{
	if (ui->ILULevelsLineEdit->text() == NULL)
	{
		ui->ILULevelsLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->ILULevelsLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->ILULevelsLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "���棺", "����������������������룡");
				ui->ILULevelsLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "���棺", "ֻ���������֣����������룡");
			ui->ILULevelsLineEdit->setText("0");
		}
	}
}

//TotalResistanceLineEdit�ۺ���
void QtArteryTechPreconditionerSetupUI::OverlappingSizeLineEditSlot()
{
	if (ui->OverlappingSizeLineEdit->text() == NULL)
	{
		ui->OverlappingSizeLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->OverlappingSizeLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->OverlappingSizeLineEdit->text().trimmed().length() > 15)
			{
				QMessageBox::warning(this, "���棺", "����������������������룡");
				ui->OverlappingSizeLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "���棺", "ֻ���������֣����������룡");
			ui->OverlappingSizeLineEdit->setText("0");
		}
	}
}