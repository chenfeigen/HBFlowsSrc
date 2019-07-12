#include "InstallationAlignment.h"

InstallationAlignment::InstallationAlignment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("�����Ȩ");
	ui.textEdit->setReadOnly(true);
	QString textEditStr = "��ӭʹ��CT�޴�Ѫ��������������ϵͳ�������������ܰ�Ȩ����,��Ҫ�ṩ��������롣����������룬�����������룬 ��������ϵ�ٷ���ȡ��������롣��ʹ���������������Ȩ���ס���л��";
	ui.textEdit->setText(textEditStr);
	//�ź���ۺ���������
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
		QMessageBox::information(this,"��Ϣ:","�����벻��Ϊ�գ���������ȷ�������룡");
		return;
	}
	SendInstallAlignmentSignal();
}
