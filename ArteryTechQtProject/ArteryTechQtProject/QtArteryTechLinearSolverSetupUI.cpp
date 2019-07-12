#include "QtArteryTechLinearSolverSetupUI.h"
#include "ui_QtArteryTechLinearSolverSetupUI.h"

QtArteryTechLinearSolverSetupUI::QtArteryTechLinearSolverSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechLinearSolverSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("线性求解器参数设置");
	this->setMinimumSize(791, 250);
	this->setMaximumSize(791, 250);
	this->diffLKRtolGAsmCheckBox = new QCheckBox;
	this->diffLKRtolGAsmCheckBox->setText("diff_1st_ksp_rtol");

	InitLinearSolverData();
	//SaveLinearSolverData();
	//信号与槽的连接
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));

	QObject::connect(ui->RestartNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(RestartNumberLineEditSlot()));
	QObject::connect(ui->MaxIterationNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(MaxIterationNumberLineEditSlot()));
	QObject::connect(ui->RatioOfThe1stStepTolLineEdit, SIGNAL(editingFinished()), this, SLOT(RatioOfThe1stStepTolLineEditSlot()));
}

QtArteryTechLinearSolverSetupUI::QtArteryTechLinearSolverSetupUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechLinearSolverSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setWindowTitle("线性求解器参数设置");
	this->setMinimumSize(791, 250);
	this->setMaximumSize(791, 250);
	this->diffLKRtolGAsmCheckBox = new QCheckBox;
	this->diffLKRtolGAsmCheckBox->setText("diff_1st_ksp_rtol");

	InitLinearSolverData();
	//SaveLinearSolverData();
	//信号与槽的连接
	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButtonSlots()));

	QObject::connect(ui->RestartNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(RestartNumberLineEditSlot()));
	QObject::connect(ui->MaxIterationNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(MaxIterationNumberLineEditSlot()));
	QObject::connect(ui->RatioOfThe1stStepTolLineEdit, SIGNAL(editingFinished()), this, SLOT(RatioOfThe1stStepTolLineEditSlot()));

}

void QtArteryTechLinearSolverSetupUI::InitLinearSolverData()
{
	ui->LinearSolverTypeLineEdit->setText(NULL);
	ui->PreconditioningSideLineEdit->setText(NULL);
	ui->RestartNumberLineEdit->setText("0");
	ui->MaxIterationNumberLineEdit->setText("0");
	ui->RelativeTolleranceLineEdit->setText("0");
	ui->AbsoluteTolleranceLineEdit->setText("0");
	ui->Different1stStepTolLineEdit->setText(NULL);
	ui->Different1stStepTolLabel->setVisible(true);
	ui->Different1stStepTolLineEdit->setVisible(false);
	ui->horizontalLayout_7->addWidget(this->diffLKRtolGAsmCheckBox);
	ui->RatioOfThe1stStepTolLineEdit->setText("0");
}
#if 0
void QtArteryTechLinearSolverSetupUI::InitLinearSolverData()
{
	ui->LinearSolverTypeLineEdit->setText("fgmres");
	ui->PreconditioningSideLineEdit->setText("right");
	ui->RestartNumberLineEdit->setText("400");
	ui->MaxIterationNumberLineEdit->setText("3000");
	ui->RelativeTolleranceLineEdit->setText("1.e-5");
	ui->AbsoluteTolleranceLineEdit->setText("1.e-30");
	ui->Different1stStepTolLineEdit->setText(NULL);
	ui->Different1stStepTolLabel->setVisible(true);
	ui->Different1stStepTolLineEdit->setVisible(false);
	ui->horizontalLayout_7->addWidget(this->diffLKRtolGAsmCheckBox);
	ui->RatioOfThe1stStepTolLineEdit->setText("0.001");
}
#endif

void QtArteryTechLinearSolverSetupUI::SaveLinearSolverData()
{
	this->linearSolverDataList.clear();
	QString Menustr = "#Linear Solver Setup\n";
	this->linearSolverDataList.append(Menustr);
	//QString labeltext = "	" + ui->LinearSolverTypeLabel->text() + " " + "-ksp_type" + " ";
	QString labeltext = "	-ksp_type ";
	QString lineEdit = ui->LinearSolverTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->PreconditioningSideLabel->text() + " " + "-ksp_pc_side" + " ";
	labeltext = "	-ksp_pc_side ";
	lineEdit = ui->PreconditioningSideLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->RestartNumberLabel->text() + " " + "-ksp_gmres_restart" + " ";
	labeltext = "	-ksp_gmres_restart ";
	lineEdit = ui->RestartNumberLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->MaxIterationNumberLabel->text() + " " + "-ksp_max_it" + " ";
	labeltext = "	-ksp_max_it ";
	lineEdit = ui->MaxIterationNumberLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->RelativeTolleranceLabel->text() + " " + "-ksp_rtol" + " ";
	labeltext = "	-ksp_rtol ";
	lineEdit = ui->RelativeTolleranceLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->AbsoluteTolleranceLabel->text() + " " + "-ksp_atol" + " ";
	labeltext = "	#-ksp_atol ";
	lineEdit = ui->AbsoluteTolleranceLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);

	if (this->diffLKRtolGAsmCheckBox->isChecked())
	{
		//labeltext = "	" + ui->Different1stStepTolLabel->text() + " " + "-diff_lst_ksp_rtol" + " ";
		labeltext = "	-diff_1st_ksp_rtol ";
		lineEdit = ui->Different1stStepTolLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->linearSolverDataList.append(contenttext);
	}

	//labeltext = "	" + ui->RatioOfThe1stStepTolLabel->text() + " " + "-diff_lst_ksp_rtol_ratio" + " ";
	labeltext = "	-diff_1st_ksp_rtol_ratio ";
	lineEdit = ui->RatioOfThe1stStepTolLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->linearSolverDataList.append(contenttext);
	/*
	for (size_t i = 0; i < linearSolverDataList.length(); i++)
	{
	qDebug() << "LinearSolverSetupUiData:" << linearSolverDataList[i];
	}
	*/
}

void QtArteryTechLinearSolverSetupUI::OkPushButtonSlots()
{
	SaveLinearSolverData();
	this->close();
}

void QtArteryTechLinearSolverSetupUI::CancelPushButtonSlots()
{
	InitLinearSolverData();
	this->close();
}

QtArteryTechLinearSolverSetupUI::~QtArteryTechLinearSolverSetupUI()
{
	delete ui;
}

void QtArteryTechLinearSolverSetupUI::closeEvent(QCloseEvent *event)
{
	SaveLinearSolverData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this, "警告：", m_tmpFileName + " 文件打开失败！");
		return;
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
	for (int i = 0; i < linearSolverDataList.length(); i++)
	{
		tmpFile.write(linearSolverDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechLinearSolverSetupUI::GetTechLinearSolverData()
{
	QStringList techLinearSolverSetupUiData;
	QString linearSolverTypeStr = ui->LinearSolverTypeLabel->text() + "\t" + ui->LinearSolverTypeLineEdit->text();
	QString preconditioningSideStr = ui->PreconditioningSideLabel->text() + "\t" + ui->PreconditioningSideLineEdit->text();
	QString restartNumberStr = ui->RestartNumberLabel->text() + "\t" + ui->RestartNumberLineEdit->text();
	QString maxIterationNumberStr = ui->MaxIterationNumberLabel->text() + "\t" + ui->MaxIterationNumberLineEdit->text();
	QString relativeTolleranceStr = ui->RelativeTolleranceLabel->text() + "\t" + ui->RelativeTolleranceLineEdit->text();
	QString absoluteTolleranceStr = ui->AbsoluteTolleranceLabel->text() + "\t" + ui->AbsoluteTolleranceLineEdit->text();
	QString different1stStepTolStr = ui->Different1stStepTolLabel->text() + "\t" + ui->Different1stStepTolLineEdit->text();
	QString ratioOfThe1stStepTol = ui->RatioOfThe1stStepTolLabel->text() + "\t" + ui->RatioOfThe1stStepTolLineEdit->text();

	techLinearSolverSetupUiData.append(linearSolverTypeStr);
	techLinearSolverSetupUiData.append(preconditioningSideStr);
	techLinearSolverSetupUiData.append(restartNumberStr);
	techLinearSolverSetupUiData.append(maxIterationNumberStr);
	techLinearSolverSetupUiData.append(relativeTolleranceStr);
	techLinearSolverSetupUiData.append(absoluteTolleranceStr);
	techLinearSolverSetupUiData.append(different1stStepTolStr);
	techLinearSolverSetupUiData.append(ratioOfThe1stStepTol);

	return techLinearSolverSetupUiData;
}

int QtArteryTechLinearSolverSetupUI::isDigitStr(QString src)
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

//RestartNumberLineEdit槽函数
void QtArteryTechLinearSolverSetupUI::RestartNumberLineEditSlot()
{
	if (ui->RestartNumberLineEdit->text() == NULL)
	{
		ui->RestartNumberLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->RestartNumberLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->RestartNumberLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->RestartNumberLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->RestartNumberLineEdit->setText("0");
		}
	}
}

//MaxIterationNumberLineEdit槽函数
void QtArteryTechLinearSolverSetupUI::MaxIterationNumberLineEditSlot()
{
	if (ui->MaxIterationNumberLineEdit->text() == NULL)
	{
		ui->MaxIterationNumberLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->MaxIterationNumberLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->MaxIterationNumberLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->MaxIterationNumberLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->MaxIterationNumberLineEdit->setText("0");
		}
	}
}

//RatioOfThe1stStepTolLineEdit槽函数
void QtArteryTechLinearSolverSetupUI::RatioOfThe1stStepTolLineEditSlot()
{
	if (ui->RatioOfThe1stStepTolLineEdit->text() == NULL)
	{
		ui->RatioOfThe1stStepTolLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->RatioOfThe1stStepTolLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->RatioOfThe1stStepTolLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->RatioOfThe1stStepTolLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->RatioOfThe1stStepTolLineEdit->setText("0");
		}
	}
}