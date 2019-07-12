#include "Help.h"
#include "ui_Help.h"

Help::Help(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::Help();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("Help");
	this->setMinimumSize(395, 143);
	this->setMaximumSize(395, 143);

	InitHelpUi();
}

void Help::InitHelpUi()
{
	ui->softwareNamelabel->setText("HBFlows");
	ui->softwareVersionlabel->setText("01");
	ui->softwareReleaseVersionlabel->setText("01.00.00");
}

Help::~Help()
{
	delete ui;
}
