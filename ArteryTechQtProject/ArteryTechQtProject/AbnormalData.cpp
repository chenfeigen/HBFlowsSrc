#include "AbnormalData.h"

AbnormalData::AbnormalData(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	QString filepathname = "tmp.txt";
	QFile *file = new QFile(filepathname);
	//�ļ������ȴ��ļ���Ȼ����ʾ
	bool ok = file->open(QIODevice::Text | QIODevice::ReadOnly);
	if (!ok)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong!";
		QMessageBox::critical(this, "����", "�ļ���ʧ�ܣ�");
		return;
	}
	QTextStream out(file);
	QString fileContent = out.readAll();
	ui.textEdit->setText(fileContent);

	//for (size_t i = 0; i < fileContent.length(); i++)
	//{
	//	//д�ļ�
	//	file->write(fileContent[i].toStdString().c_str(), fileContent[i].toStdString().length());
	//}
	file->close();
}

AbnormalData::AbnormalData(QString tmpFileName, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	//QString filepathname = "tmp.txt";
	QString filepathname = tmpFileName;
	QFile *file = new QFile(filepathname);
	//�ļ������ȴ��ļ���Ȼ����ʾ
	bool ok = file->open(QIODevice::Text | QIODevice::ReadOnly);
	if (!ok)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong!";
		QMessageBox::critical(this, "����", "�ļ���ʧ�ܣ�");
		return;
	}
	QTextStream out(file);
	QString fileContent = out.readAll();
	ui.textEdit->setText(fileContent);

	//for (size_t i = 0; i < fileContent.length(); i++)
	//{
	//	//д�ļ�
	//	file->write(fileContent[i].toStdString().c_str(), fileContent[i].toStdString().length());
	//}
	file->close();
}

AbnormalData::~AbnormalData()
{
}
