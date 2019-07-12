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
	setWindowTitle("��ȡ������");

	ui->ResultTextEdit->setReadOnly(true);
	//�ź���ۺ���������
	QObject::connect(ui->InputFilePushButton,SIGNAL(clicked(bool)),this,SLOT(InputFilePushButtonSlot()));
	QObject::connect(ui->GetResultPushButton, SIGNAL(clicked(bool)), this, SLOT(GetResultPushButtonSlot()));
}

GetCalculationResultsDialog::~GetCalculationResultsDialog()
{
	delete ui;
}

//�����ļ���ť�ۺ���
void GetCalculationResultsDialog::InputFilePushButtonSlot()
{
	//�����ļ���ť�ۺ���
	QString fileNameLineEdit;
	fileNameLineEdit.clear();
	QStringList fullFileName = QFileDialog::getOpenFileNames(this,"��",QDir::currentPath());
	int length = fullFileName.length();
	if (0 == length)
	{
		QMessageBox::warning(this, "����:", "��ѡ����Ч���ļ���");
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

//��ȡ�����ť�ۺ���
void GetCalculationResultsDialog::GetResultPushButtonSlot()
{
	QString fullFileName = ui->FileNameLineEdit->text().trimmed();
	QString outputelapsed;
	QString fileLine;
	QStringList outputRes;
	//��ȡ�����ť�ۺ���
	if (NULL == fullFileName)
	{
		QMessageBox::warning(this, "����:", "����ѡ��������ļ���");
		return;
	}
	QStringList fileList = fullFileName.split(";");

	QFile file(fullFileName);
	bool openStatus = file.open(QIODevice::ReadOnly|QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::warning(this, "����:", "����ѡ��������ļ���");
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
			//�жϵ�������û���������
			if (fileLine.startsWith("Total number of timesteps"))
			{
				//û���������
				outputRes.append(fileLine.trimmed());
			}
			else
			{
				//���������
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
