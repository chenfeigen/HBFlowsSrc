#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QAxObject> //ע�������ͷ�ļ���ͬʱ��pro����QT+= axcontainer
#include <QFileInfo>
#include <QProcess>
#include <string>

namespace Ui { class VariableParametersDialog; };

class VariableParametersDialog : public QDialog
{
	Q_OBJECT

public:
	VariableParametersDialog(QWidget *parent = Q_NULLPTR);
	~VariableParametersDialog();

private:
	Ui::VariableParametersDialog *ui;
	void SendVariableParameters(QStringList VariableParametersList);

	QProcess *process;

	void CreatSHFile(QString m_fileFullPathName);//����.sh�ļ�
	void CreatBCFile(QString m_fileFullPathName);//����.bc�ļ�
	int getNumberofexports(QString m_fileFullPathName);//��excel�ļ��л�ȡ���ڵĸ���
signals:
	void VariableParametersSignal(QStringList);
	private slots:
	void InputPushButtonSlot();
	void SetPushButtonSlot();
	void ConfirmPushButtonSlot();
	void CancelPushButtonSlot();
	void FileNameLineEditSlot();
	void ExecMatlabPushButtonSlot();
	void on_readoutput();
	void on_readerror();
};
