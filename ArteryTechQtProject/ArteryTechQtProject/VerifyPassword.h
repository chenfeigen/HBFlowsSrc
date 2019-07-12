#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui { class VerifyPassword; };

class VerifyPassword : public QDialog
{
	Q_OBJECT

public:
	VerifyPassword(QWidget *parent = Q_NULLPTR);
	~VerifyPassword();

private:
	Ui::VerifyPassword *ui;
	QString m_initialPassword;
	bool m_flag = false;
	void SendPasswordStatu(bool flag);//发送信号
signals:
	void PasswordStatu(bool flag);//信号，发送密码输入的标志
	private slots:
	void ConfirmPushButtonSlot();
	void CancelPushButtonSlot();
};
