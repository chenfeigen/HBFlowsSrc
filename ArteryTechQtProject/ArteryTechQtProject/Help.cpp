#include "Help.h"
#include "ui_Help.h"

Help::Help(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::Help();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("����");
	this->setMinimumSize(844, 240);
	this->setMaximumSize(844, 240);

	InitHelpUi();
}

void Help::InitHelpUi()
{
	ui->softwareNamelabel->setText("CT�޴�Ѫ��������������ϵͳ");
	ui->TypeSpecificationlabel->setText("HBFlows");
	ui->softwareVersionlabel->setText("01.00.00");
	ui->softwareReleaseVersionlabel->setText("01");
}

Help::~Help()
{
	delete ui;
}
