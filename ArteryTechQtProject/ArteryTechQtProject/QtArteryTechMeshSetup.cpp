#include "QtArteryTechMeshSetup.h"
#include "ui_QtArteryTechMeshSetup.h"

QtArteryTechMeshSetup::QtArteryTechMeshSetup(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechMeshSetup();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setMinimumSize(782, 209);
	this->setMaximumSize(782, 209);
	this->setWindowTitle("网格设置");
	//先给现实界面设计初始值
	InitMeshData();
	//SaveMeshData();
	//信号与槽的链接
	QObject::connect(ui->OkPushButton, SIGNAL(clicked(bool)), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlots()));
	QObject::connect(ui->CoordinateScaleXDirectionLineEdit,SIGNAL(editingFinished()),this, SLOT(XEditingFinishedSlot()));
	QObject::connect(ui->CoordinateScaleYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(YEditingFinishedSlot()));
	QObject::connect(ui->CoordinateScaleZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(ZEditingFinishedSlot()));
}

QtArteryTechMeshSetup::QtArteryTechMeshSetup(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::QtArteryTechMeshSetup();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	m_tmpFileName = tmpFileName;
	this->setMinimumSize(782, 209);
	this->setMaximumSize(782, 209);
	this->setWindowTitle("网格设置");
	//先给现实界面设计初始值
	InitMeshData();
	//SaveMeshData();
	//信号与槽的链接
	QObject::connect(ui->OkPushButton, SIGNAL(clicked(bool)), this, SLOT(OkPushButtonSlots()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlots()));
	QObject::connect(ui->CoordinateScaleXDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(XEditingFinishedSlot()));
	QObject::connect(ui->CoordinateScaleYDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(YEditingFinishedSlot()));
	QObject::connect(ui->CoordinateScaleZDirectionLineEdit, SIGNAL(editingFinished()), this, SLOT(ZEditingFinishedSlot()));
}

void QtArteryTechMeshSetup::InitMeshData()
{
	//实例，只能输入-180到180之间的小数，小数点后最多两位（可用于限制经纬度等）
	//QDoubleValidator *pDfValidator = new QDoubleValidator(-180.0, 180.0, 2, validatorLineEdit);
	//pDfValidator->setNotation(QDoubleValidator::StandardNotation);
	//validatorLineEdit->setValidator(pDfValidator);
	//设置只能输入为整数
#if 0
	QRegExp rx("^-?(180|1?[0-7]?\\d(\\.\\d{1,4})?)$");
	QRegExpValidator *pReg = new QRegExpValidator(rx, this);
	ui->CoordinateScaleXDirectionLineEdit->setValidator(pReg);
	ui->CoordinateScaleXDirectionLineEdit->setValidator(new QIntValidator(ui->CoordinateScaleXDirectionLineEdit));
	ui->CoordinateScaleYDirectionLineEdit->setValidator(new QIntValidator(ui->CoordinateScaleYDirectionLineEdit));
	ui->CoordinateScaleZDirectionLineEdit->setValidator(new QIntValidator(ui->CoordinateScaleZDirectionLineEdit));
#endif
	ui->FileNameLineEdit->setText(NULL);
	ui->CoordinateScaleXDirectionLineEdit->setText("0");
	ui->CoordinateScaleYDirectionLineEdit->setText("0");
	ui->CoordinateScaleZDirectionLineEdit->setText("0");
}
#if 0
void QtArteryTechMeshSetup::InitMeshData()
{
	ui->FileNameLineEdit->setText("./meshfiles/test.exo");
	ui->CoordinateScaleXDirectionLineEdit->setText("10");
	ui->CoordinateScaleYDirectionLineEdit->setText("10");
	ui->CoordinateScaleZDirectionLineEdit->setText("10");
}
#endif

void QtArteryTechMeshSetup::SaveMeshData()
{
	meshSetupDataList.clear();
	QString MenuStr = "#Mesh Setup\n";
	meshSetupDataList.append(MenuStr);
	//QString labeltest = "	" + ui->FileNameLabel->text().trimmed() + " " + "-f" + " ";
	//qDebug() << "labeltest:" << labeltest;
	QString labeltext = "	-f ";
	QString lineEdit = ui->FileNameLineEdit->text() + "\n";
	QString contenttext = labeltext + lineEdit;
	meshSetupDataList.append(contenttext);

	//qDebug() << "contenttext text:" << contenttext;
	//labeltext = "	" + ui->CoordinateScaleXDirectionLabel->text().trimmed() + " " + "-coord_x_scale" + " ";
	labeltext = "	-coord_x_scale ";
	lineEdit = ui->CoordinateScaleXDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	meshSetupDataList.append(contenttext);

	//labeltext = "	" + ui->CoordinateScaleYDirectionLabel->text().trimmed() + " " + "-coord_y_scale" + " ";
	labeltext = "	-coord_y_scale ";
	lineEdit = ui->CoordinateScaleYDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	meshSetupDataList.append(contenttext);

	//labeltext = "	" + ui->CoordinateScaleZDirectionLabel->text().trimmed() + " " + "-coord_z_scale" + " ";
	labeltext = "	-coord_z_scale ";
	lineEdit = ui->CoordinateScaleZDirectionLineEdit->text() + "\n";
	contenttext = labeltext + lineEdit;
	meshSetupDataList.append(contenttext);
}

void QtArteryTechMeshSetup::OkPushButtonSlots()
{
	SaveMeshData();
	this->close();
}

void QtArteryTechMeshSetup::CancelPushButtonSlots()
{
	InitMeshData();//点击取消，设置失败，界面的数据需要恢复到初始值
	this->close();
}

QtArteryTechMeshSetup::~QtArteryTechMeshSetup()
{
	delete ui;
}

void QtArteryTechMeshSetup::closeEvent(QCloseEvent *event)
{
	SaveMeshData();
	QFile tmpFile(m_tmpFileName);
	bool tmpFileOpenStatus = tmpFile.open(QIODevice::Append | QIODevice::Text);
	if (!tmpFileOpenStatus)
	{
		QMessageBox::warning(this,"警告", m_tmpFileName + " 文件打开失败!");
		return;
	}
	QString timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	tmpFile.write(timePoint.toStdString().c_str());
	tmpFile.write("\n");
	for (int i = 0; i < meshSetupDataList.length(); i++)
	{
		tmpFile.write(meshSetupDataList[i].toStdString().c_str());
	}
	tmpFile.close();
	close();
}

QStringList QtArteryTechMeshSetup::GetMeshData()
{
	QStringList meshUiDate;
	QString fileNameStr = ui->FileNameLabel->text() + "\t" + ui->FileNameLineEdit->text();
	QString xDirectionStr = ui->CoordinateScaleXDirectionLabel->text() + "\t" + ui->CoordinateScaleXDirectionLineEdit->text();
	QString yDirectionStr = ui->CoordinateScaleYDirectionLabel->text() + "\t" + ui->CoordinateScaleYDirectionLineEdit->text();
	QString zDirectionStr = ui->CoordinateScaleZDirectionLabel->text() + "\t" + ui->CoordinateScaleZDirectionLineEdit->text();
	meshUiDate.append(fileNameStr);
	meshUiDate.append(xDirectionStr);
	meshUiDate.append(yDirectionStr);
	meshUiDate.append(zDirectionStr);
	return meshUiDate;
}

int QtArteryTechMeshSetup::isDigitStr(QString src)
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

//CoordinateScaleXDirectionLineEdit槽函数
void QtArteryTechMeshSetup::XEditingFinishedSlot()
{
	if (ui->CoordinateScaleXDirectionLineEdit->text() == NULL)
	{
		ui->CoordinateScaleXDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoordinateScaleXDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoordinateScaleXDirectionLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoordinateScaleXDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this,"警告：","只能输入数字，请重新输入！");
			ui->CoordinateScaleXDirectionLineEdit->setText("0");
		}
	}
}
//CoordinateScaleYDirectionLineEdit槽函数
void QtArteryTechMeshSetup::YEditingFinishedSlot()
{
	if (ui->CoordinateScaleYDirectionLineEdit->text() == NULL)
	{
		ui->CoordinateScaleYDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoordinateScaleYDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoordinateScaleYDirectionLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoordinateScaleYDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->CoordinateScaleYDirectionLineEdit->setText("0");
		}
	}
}
//CoordinateScaleZDirectionLineEdit槽函数
void QtArteryTechMeshSetup::ZEditingFinishedSlot()
{
	if (ui->CoordinateScaleZDirectionLineEdit->text() == NULL)
	{
		ui->CoordinateScaleZDirectionLineEdit->setText("0");
		return;
	}
	else
	{
		bool digitsStatus = isDigitStr(ui->CoordinateScaleZDirectionLineEdit->text().trimmed());
		if (digitsStatus == 0)
		{
			if (ui->CoordinateScaleZDirectionLineEdit->text().trimmed().length() > 8)
			{
				QMessageBox::warning(this, "警告：", "数字输入过长，请重新输入！");
				ui->CoordinateScaleZDirectionLineEdit->setText("0");
				return;
			}
			return;
		}
		else
		{
			QMessageBox::warning(this, "警告：", "只能输入数字，请重新输入！");
			ui->CoordinateScaleZDirectionLineEdit->setText("0");
		}
	}
}