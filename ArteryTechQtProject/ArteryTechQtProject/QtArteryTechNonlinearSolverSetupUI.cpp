#include "QtArteryTechNonlinearSolverSetupUI.h"
#include "ui_QtArteryTechNonlinearSolverSetupUI.h"

QtArteryTechNonlinearSolverSetupUI::QtArteryTechNonlinearSolverSetupUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechNonlinearSolverSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("非线性求解器参数设置");
	this->setMinimumSize(777, 230);
	this->setMaximumSize(777, 230);

	this->snesViewCheckBox = new QCheckBox;
	this->snesViewCheckBox->setText("snes_view");
	ui->horizontalLayout_5->addWidget(this->snesViewCheckBox);

	InitNonlinearSolverData();
	//SaveNonlinearSolverData();

	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButton()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButton()));

	QObject::connect(ui->MaxIterationNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(MaxIterationNumberLineEditSlot()));
	QObject::connect(ui->RebuildJacobianLineEdit, SIGNAL(editingFinished()), this, SLOT(RebuildJacobianLineEditSlot()));
	QObject::connect(ui->RebuildPreconditionerLineEdit, SIGNAL(editingFinished()), this, SLOT(RebuildPreconditionerLineEditSlot()));

}

QtArteryTechNonlinearSolverSetupUI::QtArteryTechNonlinearSolverSetupUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechNonlinearSolverSetupUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setWindowTitle("非线性求解器参数设置");
	this->setMinimumSize(777, 230);
	this->setMaximumSize(777, 230);

	this->snesViewCheckBox = new QCheckBox;
	this->snesViewCheckBox->setText("snes_view");
	ui->horizontalLayout_5->addWidget(this->snesViewCheckBox);

	InitNonlinearSolverData();
	//SaveNonlinearSolverData();

	QObject::connect(ui->OkPushButton, SIGNAL(clicked()), this, SLOT(OkPushButton()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelPushButton()));

	QObject::connect(ui->MaxIterationNumberLineEdit, SIGNAL(editingFinished()), this, SLOT(MaxIterationNumberLineEditSlot()));
	QObject::connect(ui->RebuildJacobianLineEdit, SIGNAL(editingFinished()), this, SLOT(RebuildJacobianLineEditSlot()));
	QObject::connect(ui->RebuildPreconditionerLineEdit, SIGNAL(editingFinished()), this, SLOT(RebuildPreconditionerLineEditSlot()));
}

void QtArteryTechNonlinearSolverSetupUI::InitNonlinearSolverData()
{
	ui->NonlinearSolverTypeLineEdit->setText(NULL);
	ui->RelativeTolleranceLineEdit->setText("0");
	ui->AbsoluteTolleranceLineEdit->setText("0");
	ui->MaxIterationNumberLineEdit->setText("0");
	ui->MonitorNonlinearSolverLineEdit->setText(NULL);
	ui->MonitorNonlinearSolverLabel->setVisible(true);
	ui->MonitorNonlinearSolverLineEdit->setVisible(false);
	ui->RebuildJacobianLineEdit->setText("0");
	ui->RebuildPreconditionerLineEdit->setText("0");
}
#if 0
void QtArteryTechNonlinearSolverSetupUI::InitNonlinearSolverData()
{
	ui->NonlinearSolverTypeLineEdit->setText("newtonls");
	ui->RelativeTolleranceLineEdit->setText("1.e-6");
	ui->AbsoluteTolleranceLineEdit->setText("1.e-6");
	ui->MaxIterationNumberLineEdit->setText("300");
	ui->MonitorNonlinearSolverLineEdit->setText(NULL);
	ui->MonitorNonlinearSolverLabel->setVisible(true);
	ui->MonitorNonlinearSolverLineEdit->setVisible(false);
	ui->RebuildJacobianLineEdit->setText("1");
	ui->RebuildPreconditionerLineEdit->setText("1");
}
#endif
void QtArteryTechNonlinearSolverSetupUI::SaveNonlinearSolverData()
{
	this->nonlinearSolverDataList.clear();
	QString Menustr = "#Nonlinear Solver Setup\n";
	this->nonlinearSolverDataList.append(Menustr);
	//QString labeltext = "	" + ui->NonlinearSolverTypeLabel->text() + " " + "-snes_type" + " ";
	QString labeltext = "	#-snes_type ";
	QString lineEdit = ui->NonlinearSolverTypeLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->RelativeTolleranceLabel->text() + " " + "-snes_rtol" + " ";
	labeltext = "	-snes_rtol ";
	lineEdit = ui->RelativeTolleranceLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->AbsoluteTolleranceLabel->text() + " " + "-snes_atol" + " ";
	labeltext = "	-snes_atol ";
	lineEdit = ui->AbsoluteTolleranceLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->MaxIterationNumberLabel->text() + " " + "-snes_max_it" + " ";
	labeltext = "	-snes_max_it ";
	lineEdit = ui->MaxIterationNumberLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);

	if (this->snesViewCheckBox->isChecked())
	{
		//labeltext = "	" + ui->MonitorNonlinearSolverLabel->text() + " " + "-snes_view" + " ";
		labeltext = "	-snes_view ";
		lineEdit = ui->MonitorNonlinearSolverLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->nonlinearSolverDataList.append(contenttext);
	}

	//labeltext = "	" + ui->RebuildJacobianLabel->text() + " " + "-snes_lag_jacobian" + " ";
	labeltext = "	#-snes_lag_jacobian ";
	lineEdit = ui->RebuildJacobianLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);

	//labeltext = "	" + ui->RebuildPreconditionerLabel->text() + " " + "-snes_lag_preconditioner" + " ";
	labeltext = "	#-snes_lag_preconditioner ";
	lineEdit = ui->RebuildPreconditionerLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->nonlinearSolverDataList.append(contenttext);
	/*
	for (size_t i = 0; i < nonlinearSolverDataList.length(); i++)
	{
	qDebug() << "NonlinearSolverSetupUiData:" << nonlinearSolverDataList[i];
	}
	*/
}

void QtArteryTechNonlinearSolverSetupUI::OkPushButton()
{
	SaveNonlinearSolverData();
	this->close();
}

void QtArteryTechNonlinearSolverSetupUI::CancelPushButton()
{
	InitNonlinearSolverData();
	this->close();
}

QtArteryTechNonlinearSolverSetupUI::~QtArteryTechNonlinearSolverSetupUI()
{
	delete ui;
}

void QtArteryTechNonlinearSolverSetupUI::closeEvent(QCloseEvent *event)
{
	SaveNonlinearSolverData();
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
	for (int i = 0; i < nonlinearSolverDataList.length(); i++)
	{
		tmpFile.write(nonlinearSolverDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
	close();
}

QStringList QtArteryTechNonlinearSolverSetupUI::GetTechNonlinearSolverData()
{
	QStringList techNonlinearSolverSetupUiData;
	QString nonlinearSolverTypeStr = ui->NonlinearSolverTypeLabel->text() + "\t" + ui->NonlinearSolverTypeLineEdit->text();
	QString relativeTolleranceStr = ui->RelativeTolleranceLabel->text() + "\t" + ui->RelativeTolleranceLineEdit->text();
	QString absoluteTolleranceStr = ui->AbsoluteTolleranceLabel->text() + "\t" + ui->AbsoluteTolleranceLineEdit->text();
	QString maxIterationNumberStr = ui->MaxIterationNumberLabel->text() + "\t" + ui->MaxIterationNumberLineEdit->text();
	QString monitorNonlinearSolverStr = ui->MonitorNonlinearSolverLabel->text() + "\t" + ui->MonitorNonlinearSolverLineEdit->text();
	QString rebuildJacobianStr = ui->RebuildJacobianLabel->text() + "\t" + ui->RebuildJacobianLineEdit->text();
	QString rebuildPreconditionerStr = ui->RebuildPreconditionerLabel->text() + "\t" + ui->RebuildPreconditionerLineEdit->text();

	techNonlinearSolverSetupUiData.append(nonlinearSolverTypeStr);
	techNonlinearSolverSetupUiData.append(relativeTolleranceStr);
	techNonlinearSolverSetupUiData.append(absoluteTolleranceStr);
	techNonlinearSolverSetupUiData.append(maxIterationNumberStr);
	techNonlinearSolverSetupUiData.append(monitorNonlinearSolverStr);
	techNonlinearSolverSetupUiData.append(rebuildJacobianStr);
	techNonlinearSolverSetupUiData.append(rebuildPreconditionerStr);

	return techNonlinearSolverSetupUiData;
}


int QtArteryTechNonlinearSolverSetupUI::isDigitStr(QString src)
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

//MaxIterationNumberLineEdit槽函数
void QtArteryTechNonlinearSolverSetupUI::MaxIterationNumberLineEditSlot()
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

//RebuildJacobianLineEdit槽函数
void QtArteryTechNonlinearSolverSetupUI::RebuildJacobianLineEditSlot()
{
	if (ui->RebuildJacobianLineEdit->text() == NULL)
	{
		ui->RebuildJacobianLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->RebuildJacobianLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->RebuildJacobianLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->RebuildJacobianLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->RebuildJacobianLineEdit->setText("0");
		}
	}
}

//RebuildPreconditionerLineEditSlot槽函数
void QtArteryTechNonlinearSolverSetupUI::RebuildPreconditionerLineEditSlot()
{
	if (ui->RebuildPreconditionerLineEdit->text() == NULL)
	{
		ui->RebuildPreconditionerLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->RebuildPreconditionerLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->RebuildPreconditionerLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->RebuildPreconditionerLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->RebuildPreconditionerLineEdit->setText("0");
		}
	}
}