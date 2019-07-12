#include "InstallationAlignment.h"

InstallationAlignment::InstallationAlignment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("软件授权");
	ui.textEdit->setReadOnly(true);
	QString textEditStr = "欢迎使用CT无创血流储备分数测量系统软件，由于软件受版权保护,需要提供软件序列码。如果有序列码，请输入序列码， 否则请联系官方获取软件序列码。请使用正版的软件避免版权纠纷。多谢！";
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
		QMessageBox::information(this,"消息:","序列码不能为空，请输入正确的序列码！");
		return;
	}
	SendInstallAlignmentSignal();
}
