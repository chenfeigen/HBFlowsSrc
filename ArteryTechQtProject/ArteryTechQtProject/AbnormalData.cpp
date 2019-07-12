#include "AbnormalData.h"

AbnormalData::AbnormalData(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	QString filepathname = "tmp.txt";
	QFile *file = new QFile(filepathname);
	//文件存在先打开文件，然后显示
	bool ok = file->open(QIODevice::Text | QIODevice::ReadOnly);
	if (!ok)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong!";
		QMessageBox::critical(this, "错误", "文件打开失败！");
		return;
	}
	QTextStream out(file);
	QString fileContent = out.readAll();
	ui.textEdit->setText(fileContent);

	//for (size_t i = 0; i < fileContent.length(); i++)
	//{
	//	//写文件
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
	//文件存在先打开文件，然后显示
	bool ok = file->open(QIODevice::Text | QIODevice::ReadOnly);
	if (!ok)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Open save file is wrong!";
		QMessageBox::critical(this, "错误", "文件打开失败！");
		return;
	}
	QTextStream out(file);
	QString fileContent = out.readAll();
	ui.textEdit->setText(fileContent);

	//for (size_t i = 0; i < fileContent.length(); i++)
	//{
	//	//写文件
	//	file->write(fileContent[i].toStdString().c_str(), fileContent[i].toStdString().length());
	//}
	file->close();
}

AbnormalData::~AbnormalData()
{
}
