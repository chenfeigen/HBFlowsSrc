#include "VerifyPassword.h"
#include "ui_VerifyPassword.h"

VerifyPassword::VerifyPassword(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::VerifyPassword();
	ui->setupUi(this);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("修改参数密码");
	setMinimumSize(359, 70);
	setMaximumSize(359, 70);
	ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
	m_initialPassword = "Artery8888";

	//信号与槽函数的连接
	QObject::connect(ui->ConfirmPushButton, SIGNAL(clicked(bool)), this, SLOT(ConfirmPushButtonSlot()));
	QObject::connect(ui->CancelPushButton, SIGNAL(clicked(bool)), this, SLOT(CancelPushButtonSlot()));
}

VerifyPassword::~VerifyPassword()
{
	delete ui;
}


void VerifyPassword::ConfirmPushButtonSlot()
{
	QString password = ui->PasswordLineEdit->text().trimmed();
	if (NULL == password)
	{
		QMessageBox::warning(this,"警告:","密码不能为空，请重新输入！");
		return;
	}

	if (password.compare(m_initialPassword) != 0)
	{
		QMessageBox::warning(this, "警告:", "密码输入错误，请重新输入！");
		return;
	}
	QMessageBox::information(this, "消息:", "密码输入成功！");
	if (m_flag)
	{
		m_flag = false;
	}
	else
	{
		m_flag = true;
	}
	//发送信号
	SendPasswordStatu(m_flag);
	close();
}


void VerifyPassword::CancelPushButtonSlot()
{
	close();
}

//发送信号
void VerifyPassword::SendPasswordStatu(bool flag)
{
	emit PasswordStatu(flag);
}
