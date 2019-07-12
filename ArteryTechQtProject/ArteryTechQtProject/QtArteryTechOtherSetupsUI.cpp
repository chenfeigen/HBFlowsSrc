#include "QtArteryTechOtherSetupsUI.h"
#include "ui_QtArteryTechOtherSetupsUI.h"

QtArteryTechOtherSetupsUI::QtArteryTechOtherSetupsUI(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOtherSetupsUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(848, 256);
	this->setMaximumSize(848, 256);
	this->setWindowTitle("������������");

	this->blockOrderCheckBox = new QCheckBox;
	this->logViewCheckBox = new QCheckBox;
	this->blockOrderCheckBox->setText("select block order");
	this->logViewCheckBox->setText("selet log view");
	//����checkbox�ĳ�ʼ״̬Ϊ�Ѿ�ѡ��
	//this->blockOrderCheckBox->setCheckState(Qt::Checked);
	ui->horizontalLayout_4->addWidget(this->blockOrderCheckBox);
	ui->horizontalLayout_5->addWidget(this->logViewCheckBox);

	InitOtherData();
	//SaveOtherData();
	//�ź���ۺ���
	QObject::connect(ui->InitialNumberOfPartitionLineEdit, SIGNAL(editingFinished()), this, SLOT(InitialNumberOfPartitionLineEditSlot()));
	QObject::connect(ui->DiagnalScalerLineEdit, SIGNAL(editingFinished()), this, SLOT(DiagnalScalerLineEditSlot()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkButtonSlots()));//CancelButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelButtonSlots()));
}

QtArteryTechOtherSetupsUI::QtArteryTechOtherSetupsUI(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechOtherSetupsUI();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	m_tmpFileName = tmpFileName;
	this->setMinimumSize(848, 256);
	this->setMaximumSize(848, 256);
	this->setWindowTitle("������������");

	this->blockOrderCheckBox = new QCheckBox;
	this->logViewCheckBox = new QCheckBox;
	this->blockOrderCheckBox->setText("select block order");
	this->logViewCheckBox->setText("selet log view");
	//����checkbox�ĳ�ʼ״̬Ϊ�Ѿ�ѡ��
	//this->blockOrderCheckBox->setCheckState(Qt::Checked);
	ui->horizontalLayout_4->addWidget(this->blockOrderCheckBox);
	ui->horizontalLayout_5->addWidget(this->logViewCheckBox);

	InitOtherData();
	//SaveOtherData();
	//�ź���ۺ���
	QObject::connect(ui->InitialNumberOfPartitionLineEdit, SIGNAL(editingFinished()), this, SLOT(InitialNumberOfPartitionLineEditSlot()));
	QObject::connect(ui->DiagnalScalerLineEdit, SIGNAL(editingFinished()), this, SLOT(DiagnalScalerLineEditSlot()));
	QObject::connect(ui->OKPushButton, SIGNAL(clicked()), this, SLOT(OkButtonSlots()));//CancelButtonSlots
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelButtonSlots()));
}

void QtArteryTechOtherSetupsUI::InitOtherData()
{
	ui->InitialNumberOfPartitionLineEdit->setText("0");
	ui->TypeOfPartitionerLineEdit->setText(NULL);
	ui->DiagnalScalerLineEdit->setText("0");
	ui->PointBlockSolverLineEdit->setText(NULL);
	ui->LogSummaryLineEdit->setText(NULL);
	//���valueֵΪNULL����ʾ�ڽ�����
	ui->PointBlockSolverLabel->setVisible(true);
	ui->PointBlockSolverLineEdit->setVisible(false);
	ui->LogSummaryLabel->setVisible(true);
	ui->LogSummaryLineEdit->setVisible(false);
}
#if 0
void QtArteryTechOtherSetupsUI::InitOtherData()
{
	ui->InitialNumberOfPartitionLineEdit->setText("0");
	ui->TypeOfPartitionerLineEdit->setText("parmetis");
	ui->DiagnalScalerLineEdit->setText("1");
	ui->PointBlockSolverLineEdit->setText(NULL);
	ui->LogSummaryLineEdit->setText(NULL);
	//���valueֵΪNULL����ʾ�ڽ�����
	ui->PointBlockSolverLabel->setVisible(true);
	ui->PointBlockSolverLineEdit->setVisible(false);
	ui->LogSummaryLabel->setVisible(true);
	ui->LogSummaryLineEdit->setVisible(false);
}
#endif
void QtArteryTechOtherSetupsUI::OkButtonSlots()
{
	SaveOtherData();
	this->close();
}

void QtArteryTechOtherSetupsUI::CancelButtonSlots()
{
	InitOtherData();
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
	/*
	for (int i = 0; i < this->otherDataList.length(); i++)
	{
	qDebug() << "other Data:" << this->otherDataList[i];
	}
	*/
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
		QMessageBox::warning(this, "���棺", m_tmpFileName + " �ļ���ʧ�ܣ�");
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

//InitialNumberOfPartitionLineEdit�ۺ���
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
				QMessageBox::warning(this, "���棺", "����������������������룡");
				ui->InitialNumberOfPartitionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "���棺", "ֻ���������֣����������룡");
			ui->InitialNumberOfPartitionLineEdit->setText("0");
		}
	}
}
//DiagnalScalerLineEdit�ۺ���
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
				QMessageBox::warning(this, "���棺", "����������������������룡");
				ui->DiagnalScalerLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "���棺", "ֻ���������֣����������룡");
			ui->DiagnalScalerLineEdit->setText("0");
		}
	}
}
