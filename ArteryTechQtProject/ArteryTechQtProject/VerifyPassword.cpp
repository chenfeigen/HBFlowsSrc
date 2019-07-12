#include "VerifyPassword.h"
#include "ui_VerifyPassword.h"

VerifyPassword::VerifyPassword(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::VerifyPassword();
	ui->setupUi(this);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowTitle("�޸Ĳ�������");
	setMinimumSize(359, 70);
	setMaximumSize(359, 70);
	ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);//�����ʱ�����ʾԲ��
	m_initialPassword = "Artery8888";

	//�ź���ۺ���������
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
		QMessageBox::warning(this,"����:","���벻��Ϊ�գ����������룡");
		return;
	}

	if (password.compare(m_initialPassword) != 0)
	{
		QMessageBox::warning(this, "����:", "��������������������룡");
		return;
	}
	QMessageBox::information(this, "��Ϣ:", "��������ɹ���");
	if (m_flag)
	{
		m_flag = false;
	}
	else
	{
		m_flag = true;
	}
	//�����ź�
	SendPasswordStatu(m_flag);
	close();
}


void VerifyPassword::CancelPushButtonSlot()
{
	close();
}

//�����ź�
void VerifyPassword::SendPasswordStatu(bool flag)
{
	emit PasswordStatu(flag);
}
