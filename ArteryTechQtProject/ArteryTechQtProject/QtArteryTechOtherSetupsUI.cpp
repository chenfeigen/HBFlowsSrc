#include "QtArteryTechOtherSetupsUI.h"
#include "ui_QtArteryTechOtherSetupsUI.h"

QtArteryTechOtherSetupsUI::QtArteryTechOtherSetupsUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOtherSetupsUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(557, 171);
	this->setMaximumSize(557, 171);
	this->setWindowTitle("其他参数设置");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	this->blockOrderCheckBox = new QCheckBox;
	this->logViewCheckBox = new QCheckBox;
	this->blockOrderCheckBox->setText("select block order");
	this->logViewCheckBox->setText("selet log view");
	//设置checkbox的初始状态为已经选择
	//this->logViewCheckBox->setCheckState(Qt::Checked);
	ui->horizontalLayout_4->addWidget(this->blockOrderCheckBox);
	ui->horizontalLayout_5->addWidget(this->logViewCheckBox);

	InitUiData();
	//SaveOtherData();
	//信号与槽函数
	QObject::connect(ui->InitialNumberOfPartitionLineEdit, SIGNAL(editingFinished()), this, SLOT(InitialNumberOfPartitionLineEditSlot()));
	QObject::connect(ui->DiagnalScalerLineEdit, SIGNAL(editingFinished()), this, SLOT(DiagnalScalerLineEditSlot()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkButtonSlots()));//CancelButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelButtonSlots()));
	//QObject::connect(ui->INOPCheckBox, SIGNAL(stateChanged(int)), this, SLOT(INOPCheckBoxStateChanged(int)));
}

QtArteryTechOtherSetupsUI::QtArteryTechOtherSetupsUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOtherSetupsUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setMinimumSize(557, 171);
	this->setMaximumSize(557, 171);
	this->setWindowTitle("其他参数设置");
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	//设置界面显示的位置为屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	this->blockOrderCheckBox = new QCheckBox;
	this->logViewCheckBox = new QCheckBox;
	this->blockOrderCheckBox->setText("select block order");
	this->logViewCheckBox->setText("selet log view");
	//设置checkbox的初始状态为已经选择
	//this->logViewCheckBox->setCheckState(Qt::Checked);
	ui->horizontalLayout_4->addWidget(this->blockOrderCheckBox);
	ui->horizontalLayout_5->addWidget(this->logViewCheckBox);

	InitUiData();
	//SaveOtherData();
	//信号与槽函数
	QObject::connect(ui->InitialNumberOfPartitionLineEdit, SIGNAL(editingFinished()), this, SLOT(InitialNumberOfPartitionLineEditSlot()));
	QObject::connect(ui->DiagnalScalerLineEdit, SIGNAL(editingFinished()), this, SLOT(DiagnalScalerLineEditSlot()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkButtonSlots()));//CancelButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelButtonSlots()));
}

#if 0
void QtArteryTechOtherSetupsUI::InitOtherData()
{
	ui->InitialNumberOfPartitionLineEdit->setText("0");
	ui->TypeOfPartitionerLineEdit->setText(NULL);
	ui->DiagnalScalerLineEdit->setText("0");
	ui->PointBlockSolverLineEdit->setText(NULL);
	ui->LogSummaryLineEdit->setText(NULL);
	//如果value值为NULL则不显示在界面上
	ui->PointBlockSolverLabel->setVisible(true);
	ui->PointBlockSolverLineEdit->setVisible(false);
	ui->LogSummaryLabel->setVisible(true);
	ui->LogSummaryLineEdit->setVisible(false);
}
#endif
void QtArteryTechOtherSetupsUI::InitUiData()
{
	ui->InitialNumberOfPartitionLineEdit->setVisible(false);
	ui->InitialNumberOfPartitionLineEdit->setEnabled(false);
	//ui->InitialNumberOfPartitionLineEdit->setReadOnly(true);
	ui->InitialNumberOfPartitionLineEdit->setText("0");

	ui->TypeOfPartitionerLineEdit->setVisible(false);
	ui->TypeOfPartitionerLineEdit->setEnabled(false);
	ui->TypeOfPartitionerLineEdit->setText("parmetis");

	ui->DiagnalScalerLineEdit->setVisible(false);
	ui->DiagnalScalerLineEdit->setEnabled(false);
	ui->DiagnalScalerLineEdit->setText("1");

	ui->PointBlockSolverLineEdit->setText(NULL);
	ui->LogSummaryLineEdit->setText(NULL);
	//如果value值为NULL则不显示在界面上
	ui->PointBlockSolverLabel->setVisible(true);
	ui->PointBlockSolverLineEdit->setVisible(false);
	this->blockOrderCheckBox->setVisible(false);
	this->blockOrderCheckBox->setEnabled(false);
	this->blockOrderCheckBox->setCheckState(Qt::Checked);

	ui->LogSummaryLabel->setVisible(true);
	ui->LogSummaryLineEdit->setVisible(false);

	this->logViewCheckBox->setVisible(false);
	this->logViewCheckBox->setEnabled(false);
	this->logViewCheckBox->setCheckState(Qt::Checked);

	ui->PlotFFRLCheckBox->setVisible(false);
	ui->PlotFFRLCheckBox->setEnabled(false);
	ui->PlotFFRLCheckBox->setCheckState(Qt::Checked);
}

#if 1
void QtArteryTechOtherSetupsUI::InitOtherData(bool flag)
{
	if (flag)
	{
		ui->InitialNumberOfPartitionLineEdit->setVisible(true);
		ui->InitialNumberOfPartitionLineEdit->setEnabled(true);

		ui->TypeOfPartitionerLineEdit->setVisible(true);
		ui->TypeOfPartitionerLineEdit->setEnabled(true);

		ui->DiagnalScalerLineEdit->setVisible(true);
		ui->DiagnalScalerLineEdit->setEnabled(true);

		ui->PointBlockSolverLineEdit->setText(NULL);
		ui->LogSummaryLineEdit->setText(NULL);
		//如果value值为NULL则不显示在界面上
		ui->PointBlockSolverLabel->setVisible(true);
		ui->PointBlockSolverLineEdit->setVisible(false);
		this->blockOrderCheckBox->setVisible(true);
		this->blockOrderCheckBox->setEnabled(true);

		ui->LogSummaryLabel->setVisible(true);
		ui->LogSummaryLineEdit->setVisible(false);
		this->logViewCheckBox->setVisible(true);
		this->logViewCheckBox->setEnabled(true);

		ui->PlotFFRLCheckBox->setVisible(true);
		ui->PlotFFRLCheckBox->setEnabled(true);
	}
	else
	{
		ui->InitialNumberOfPartitionLineEdit->setVisible(false);
		ui->InitialNumberOfPartitionLineEdit->setEnabled(false);
		//ui->InitialNumberOfPartitionLineEdit->setReadOnly(true);

		ui->TypeOfPartitionerLineEdit->setVisible(false);
		ui->TypeOfPartitionerLineEdit->setEnabled(false);

		ui->DiagnalScalerLineEdit->setVisible(false);
		ui->DiagnalScalerLineEdit->setEnabled(false);

		ui->PointBlockSolverLineEdit->setText(NULL);
		ui->LogSummaryLineEdit->setText(NULL);
		//如果value值为NULL则不显示在界面上
		ui->PointBlockSolverLabel->setVisible(true);
		ui->PointBlockSolverLineEdit->setVisible(false);
		this->blockOrderCheckBox->setVisible(false);
		this->blockOrderCheckBox->setEnabled(false);
		//this->blockOrderCheckBox->setCheckState(Qt::Checked);

		ui->LogSummaryLabel->setVisible(true);
		ui->LogSummaryLineEdit->setVisible(false);
		this->logViewCheckBox->setVisible(false);
		this->logViewCheckBox->setEnabled(false);
		//this->logViewCheckBox->setCheckState(Qt::Checked);

		ui->PlotFFRLCheckBox->setVisible(false);
		ui->PlotFFRLCheckBox->setEnabled(false);
	}
	
}
#endif
void QtArteryTechOtherSetupsUI::OkButtonSlots()
{
	SaveOtherData();
	this->close();
}

void QtArteryTechOtherSetupsUI::CancelButtonSlots()
{
	InitOtherData(false);
	this->close();
}

void QtArteryTechOtherSetupsUI::SaveOtherData()
{
	this->otherDataList.clear();
	QString Menustr = "#Other Setups\n";
	this->otherDataList.append(Menustr);
	//QString labeltext = "	" + ui->InitialNumberOfPartitionLabel->text() + " " + "-metis_parts" + " ";
	QString labeltext = "	-metis_parts ";
	QString lineEdit = ui->InitialNumberOfPartitionLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	this->otherDataList.append(contenttext);

	//labeltext = "	" + ui->TypeOfPartitionerLabel->text() + " " + "-mat_partitioning_type" + " ";
	labeltext = "	-mat_partitioning_type ";
	lineEdit = ui->TypeOfPartitionerLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->otherDataList.append(contenttext);

	//labeltext = "	" + ui->DiagnalScalerLabel->text() + " " + "-diag_scale" + " ";
	labeltext = "	-diag_scale ";
	lineEdit = ui->DiagnalScalerLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	this->otherDataList.append(contenttext);

	if (this->blockOrderCheckBox->isChecked())
	{
		//labeltext = "	" + ui->PointBlockSolverLabel->text() + " " + "-block_order" + " ";
		labeltext = "	-block_order ";
		lineEdit = ui->PointBlockSolverLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->otherDataList.append(contenttext);
	}

	if (this->logViewCheckBox->isChecked())
	{
		//labeltext = "	" + ui->LogSummaryLabel->text() + " " + "-log_view" + " ";
		labeltext = "	-log_view ";
		lineEdit = ui->LogSummaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		this->otherDataList.append(contenttext);
	}
	if (ui->PlotFFRLCheckBox->isChecked())
	{
		//labeltext = "	" + ui->LogSummaryLabel->text() + " " + "-log_view" + " ";
		labeltext = "	-plot_FFR\n";
		contenttext = labeltext;
		this->otherDataList.append(contenttext);
	}
	/*
	for (int i = 0; i < this->otherDataList.length(); i++)
	{
	qDebug() << "other Data:" << this->otherDataList[i];
	}
	*/
}

QStringList QtArteryTechOtherSetupsUI::getUIData()
{
	QStringList resultUIDataList;
	resultUIDataList.clear();
	QString Menustr = "#Other Setups\n";
	resultUIDataList.append(Menustr);
	//QString labeltext = "	" + ui->InitialNumberOfPartitionLabel->text() + " " + "-metis_parts" + " ";
	QString labeltext = "	-metis_parts ";
	QString lineEdit = ui->InitialNumberOfPartitionLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->TypeOfPartitionerLabel->text() + " " + "-mat_partitioning_type" + " ";
	labeltext = "	-mat_partitioning_type ";
	lineEdit = ui->TypeOfPartitionerLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	//labeltext = "	" + ui->DiagnalScalerLabel->text() + " " + "-diag_scale" + " ";
	labeltext = "	-diag_scale ";
	lineEdit = ui->DiagnalScalerLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	resultUIDataList.append(contenttext);

	if (this->blockOrderCheckBox->isChecked())
	{
		//labeltext = "	" + ui->PointBlockSolverLabel->text() + " " + "-block_order" + " ";
		labeltext = "	-block_order ";
		lineEdit = ui->PointBlockSolverLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}

	if (this->logViewCheckBox->isChecked())
	{
		//labeltext = "	" + ui->LogSummaryLabel->text() + " " + "-log_view" + " ";
		labeltext = "	-log_view ";
		lineEdit = ui->LogSummaryLineEdit->text() + "\n";
		contenttext = labeltext + lineEdit;
		resultUIDataList.append(contenttext);
	}
	if (ui->PlotFFRLCheckBox->isChecked())
	{
		//labeltext = "	" + ui->LogSummaryLabel->text() + " " + "-log_view" + " ";
		labeltext = "	-plot_FFR\n";
		contenttext = labeltext;
		resultUIDataList.append(contenttext);
	}
	/*
	for (int i = 0; i < this->otherDataList.length(); i++)
	{
	qDebug() << "other Data:" << this->otherDataList[i];
	}
	*/
	return resultUIDataList;
}

QtArteryTechOtherSetupsUI::~QtArteryTechOtherSetupsUI()
{
	delete ui;
}

void QtArteryTechOtherSetupsUI::closeEvent(QCloseEvent *event)
{
	SaveOtherData();
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
	for (int i = 0; i < otherDataList.length(); i++)
	{
		tmpFile.write(otherDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechOtherSetupsUI::GetTechOtherData()
{
	QStringList TechOtherSetupUiData;
	QString initialNumberOfPartitionStr = ui->InitialNumberOfPartitionLabel->text() + "\t" + ui->InitialNumberOfPartitionLineEdit->text();
	QString typeOfPartitionerStr = ui->TypeOfPartitionerLabel->text() + "\t" + ui->TypeOfPartitionerLineEdit->text();
	QString diagnalScalerStr = ui->DiagnalScalerLabel->text() + "\t" + ui->DiagnalScalerLineEdit->text();
	QString pointBlockSolverStr = ui->PointBlockSolverLabel->text() + "\t" + ui->PointBlockSolverLineEdit->text();
	QString logSummaryStr = ui->LogSummaryLabel->text() + "\t" + ui->LogSummaryLineEdit->text();

	TechOtherSetupUiData.append(initialNumberOfPartitionStr);
	TechOtherSetupUiData.append(typeOfPartitionerStr);
	TechOtherSetupUiData.append(diagnalScalerStr);
	TechOtherSetupUiData.append(pointBlockSolverStr);
	TechOtherSetupUiData.append(logSummaryStr);

	return TechOtherSetupUiData  ;
}

int QtArteryTechOtherSetupsUI::isDigitStr(QString src)
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

//InitialNumberOfPartitionLineEdit槽函数
void QtArteryTechOtherSetupsUI::InitialNumberOfPartitionLineEditSlot()
{
	if (ui->InitialNumberOfPartitionLineEdit->text() == NULL)
	{
		ui->InitialNumberOfPartitionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->InitialNumberOfPartitionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->InitialNumberOfPartitionLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->InitialNumberOfPartitionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->InitialNumberOfPartitionLineEdit->setText("0");
		}
	}
}
//DiagnalScalerLineEdit槽函数
void QtArteryTechOtherSetupsUI::DiagnalScalerLineEditSlot()
{
	if (ui->DiagnalScalerLineEdit->text() == NULL)
	{
		ui->DiagnalScalerLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->DiagnalScalerLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->DiagnalScalerLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->DiagnalScalerLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->DiagnalScalerLineEdit->setText("0");
		}
	}
}

void QtArteryTechOtherSetupsUI::INOPCheckBoxStateChanged(int Status)
{
	if (Status == Qt::Checked) // "选中"
	{
		ui->InitialNumberOfPartitionLineEdit->setReadOnly(false);
	}
	else if (Status == Qt::PartiallyChecked) // "半选"
	{
		ui->InitialNumberOfPartitionLineEdit->setReadOnly(true);
	}
	else // 未选中 - Qt::Unchecked
	{
		ui->InitialNumberOfPartitionLineEdit->setReadOnly(true);
	}
}

void QtArteryTechOtherSetupsUI::GetVerifyPasswordStatuSlot(bool flag)
{
	InitOtherData(flag);
}

void QtArteryTechOtherSetupsUI::GetVariableParametersSignalSlot(QStringList VariableParametersList)
{
	//QMessageBox::information(this, "提示:", "接收信号");
}