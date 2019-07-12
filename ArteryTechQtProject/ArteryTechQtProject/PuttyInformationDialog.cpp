#include "PuttyInformationDialog.h"

PuttyInformationDialog::PuttyInformationDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->setWindowTitle("Connect Information:");
	this->setMaximumSize(290, 180);
	this->setMinimumSize(290, 180);
	//先给界面上的信息赋初值
	InitUI();

	//信号与槽函数的连接
	QObject::connect(ui.ConfirmpushButton, SIGNAL(clicked()), SLOT(ConfirmPushButtonSlot()));
	QObject::connect(ui.CancelpushButton, SIGNAL(clicked()), SLOT(CancelPushButtonSlot()));

}

PuttyInformationDialog::~PuttyInformationDialog()
{

}

void PuttyInformationDialog::InitUI()
{
	QString filename = "puttyInfo";

	QFile file(filename);
	bool ok = file.exists();
	if (ok)
	{
		bool openStatus = file.open(QIODevice::ReadOnly|QIODevice::Text);
		QString fileContent;
		if (openStatus)
		{
			while (!file.atEnd())
			{
				fileContent = file.readLine();
				qDebug() << "fileContent:" << fileContent;
				if (fileContent.startsWith("username:"))
				{
					ui.UsernamelineEdit->setText(fileContent.split(":").at(1));
				}
				else if (fileContent.startsWith("password:"))
				{
					ui.PasswordlineEdit->setText(fileContent.split(":").at(1));
				}
				else if (fileContent.startsWith("ip:"))
				{
					ui.IPlineEdit->setText(fileContent.split(":").at(1));
				}
				else if (fileContent.startsWith("port:"))
				{
					ui.PortlineEdit->setText(fileContent.split(":").at(1));
				}
			}
		}
	}
	else
	{
		ui.UsernamelineEdit->setText("cfg");
		ui.PasswordlineEdit->setText("123456");
		ui.IPlineEdit->setText("127.0.0.1");
		ui.PortlineEdit->setText("22");
	}
}

void PuttyInformationDialog::ConfirmPushButtonSlot()
{
	puttyInfon = new puttyInformation(this);
	if (NULL == ui.UsernamelineEdit->text())
	{
		QMessageBox::information(this,"information:","User name cannot be empty! ");
		return;
	}
	if (NULL == ui.PasswordlineEdit->text())
	{
		QMessageBox::information(this, "information:", "Password cannot be empty! ");
		return;
	}
	if (NULL == ui.IPlineEdit->text())
	{
		QMessageBox::information(this, "information:", "IP cannot be empty! ");
		return;
	}
	if (NULL == ui.PortlineEdit->text())
	{
		QMessageBox::information(this, "information:", "Port cannot be empty! ");
		return;
	}
	puttyInfon->m_username = ui.UsernamelineEdit->text().trimmed();
	puttyInfon->m_password = ui.PasswordlineEdit->text().trimmed();
	puttyInfon->m_ip = ui.IPlineEdit->text().trimmed();
	puttyInfon->m_port = ui.PortlineEdit->text().trimmed();
	SendPuttyInfoSignal();
	close();
}

void PuttyInformationDialog::CancelPushButtonSlot()
{
	close();
}

void PuttyInformationDialog::SendPuttyInfoSignal()
{
	emit PuttyInfoSignal(puttyInfon);
}
