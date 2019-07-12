#include "InstallationAlignment.h"

InstallationAlignment::InstallationAlignment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	ui.textEdit->setReadOnly(true);
	QString textEditStr = "Welcome to use HBFlows software. Since the software is protected by copyright, you need to provide a unique authentication code. If there is a sequence code, please enter the sequence code, otherwise, please exit and obtain the code by contant us. Please use genuine software to avoid copyright disputes. Thank you!";
	ui.textEdit->setText(textEditStr);
	//信号与槽函数的连接
	QObject::connect(ui.pushButton,SIGNAL(clicked(bool)),this,SLOT(PushButtonSlot()));
}

InstallationAlignment::~InstallationAlignment()
{
}

void InstallationAlignment::SendInstallAlignmentSignal()
{
	QString serialNumber = ui.lineEdit->text();
	InstallAlignmentSignal(serialNumber);
}

void InstallationAlignment::PushButtonSlot()
{
	if (NULL == ui.lineEdit->text())
	{
		QMessageBox::information(this,"Message:","Serial number can not be empty, please enter the correct serial number!");
		return;
	}
	SendInstallAlignmentSignal();
}
