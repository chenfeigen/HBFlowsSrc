#include "GetCalculationResultsDialog.h"
#include "ui_GetCalculationResultsDialog.h"

GetCalculationResultsDialog::GetCalculationResultsDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::GetCalculationResultsDialog();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	setMaximumSize(940,720);
	setMinimumSize(940, 720);
	setWindowTitle("获取计算结果");
	//设置窗口最大化最小化

	//Qt::WindowFlags windowFlag = Qt::Dialog;
	//windowFlag |= Qt::WindowMinimizeButtonHint;
	//windowFlag |= Qt::WindowMaximizeButtonHint;
	//windowFlag |= Qt::WindowCloseButtonHint;

	setWindowFlags(Qt::Dialog| Qt::WindowMinimizeButtonHint| Qt::WindowMaximizeButtonHint| Qt::WindowCloseButtonHint); //设置窗口最大化最小化
	ui->ResultTextEdit->setReadOnly(true);
	//信号与槽函数的连接
	QObject::connect(ui->InputFilePushButton,SIGNAL(clicked(bool)),this,SLOT(InputFilePushButtonSlot()));
	QObject::connect(ui->GetResultPushButton, SIGNAL(clicked(bool)), this, SLOT(GetResultPushButtonSlot()));
	QObject::connect(ui->SaveAspushButton, SIGNAL(clicked(bool)), this, SLOT(SaveAspushButtonSlot()));
	QObject::connect(ui->PrintPushButton, SIGNAL(clicked(bool)), this, SLOT(PrintPushButtonSlot()));
}

GetCalculationResultsDialog::~GetCalculationResultsDialog()
{
	delete ui;
}

//输入文件按钮槽函数
void GetCalculationResultsDialog::InputFilePushButtonSlot()
{
	//输入文件按钮槽函数
	QString fileNameLineEdit;
	fileNameLineEdit.clear();
	QStringList fullFileName = QFileDialog::getOpenFileNames(this,"打开",QDir::currentPath());
	int length = fullFileName.length();
	if (0 == length)
	{
		QMessageBox::warning(this, "警告:", "请选择有效的文件！");
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG1:" << fullFileName.at(i);
		fileNameLineEdit.append(fullFileName.at(i));
		if (i < length-1)
		{
			fileNameLineEdit.append(";");
		}
	}
	ui->FileNameLineEdit->setText(fileNameLineEdit);
}

//获取结果按钮槽函数
void GetCalculationResultsDialog::GetResultPushButtonSlot()
{
	QString fullFileName = ui->FileNameLineEdit->text().trimmed();
	QString outputelapsed;
	QString fileLine;
	QStringList outputRes;
	//获取结果按钮槽函数
	if (NULL == fullFileName)
	{
		QMessageBox::warning(this, "警告:", "请先选择计算结果文件！");
		return;
	}
	QStringList fileList = fullFileName.split(";");

	QFile file(fullFileName);
	bool openStatus = file.open(QIODevice::ReadOnly|QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::warning(this, "警告:", "请先选择计算结果文件！");
		return;
	}
	while (!file.atEnd())
	{
		fileLine = file.readLine();
		if (fileLine.startsWith("output elapsed"))
		{
			outputRes.clear();
			//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG1:" << fileLine;
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			//判断第四条有没有设置输出
			if (fileLine.startsWith("Total number of timesteps"))
			{
				//没有设置输出
				outputRes.append(fileLine.trimmed());
			}
			else
			{
				//有设置输出
				outputRes.append(fileLine.trimmed());
				fileLine = file.readLine();
				if (!fileLine.startsWith("Total number of timesteps"))
				{
					continue;
				}
				outputRes.append(fileLine.trimmed());
			}

			fileLine = file.readLine();
			if (!fileLine.startsWith("Total number of nonlinear iterations"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			if (!fileLine.startsWith("Average nonlinear iterations per timestep"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			if (!fileLine.startsWith("Total number of linear iterations"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG9:" << fileLine;
			if (!fileLine.startsWith("Average number of linear iterations"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			if (!fileLine.startsWith("Average walltime per timestep (excluding output)"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			if (!fileLine.startsWith("Latex line (df)"))
			{
				continue;
			}
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());

			fileLine = file.readLine();
			outputRes.append(fileLine.trimmed());
		}
		else
		{
			continue;
		}
	}
	for (size_t i = 0; i < outputRes.length(); i++)
	{
		ui->ResultTextEdit->append(outputRes.at(i));
	}
}

//另存为槽函数
void GetCalculationResultsDialog::SaveAspushButtonSlot()
{
	QString fullFileName = QFileDialog::getSaveFileName(this,"保存",QDir::currentPath());
	if (NULL == fullFileName)
	{
		QMessageBox::warning(this,"警告","文件不存在，保存失败！");
		return;
	}
	else
	{
		QFile file(fullFileName.trimmed());
		QString textEditStr = ui->ResultTextEdit->toPlainText();
		bool openstatu = file.open(QIODevice::WriteOnly|QIODevice::Text);
		if (!openstatu)
		{
			QMessageBox::warning(this, "警告", "文件保存失败！");
			return;
		}
		file.write(textEditStr.toUtf8());
		file.close();
	}
}
//打印槽函数
void GetCalculationResultsDialog::PrintPushButtonSlot()
{
	QPrinter printer;
	QPrintDialog printDialog(&printer,this);
	if (printDialog.exec())
	{
		QTextDocument *doc = ui->ResultTextEdit->document();
		doc->print(&printer);
	}
}
