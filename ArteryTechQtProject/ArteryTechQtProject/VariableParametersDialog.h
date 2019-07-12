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
#include <QAxObject> //注意包含此头文件，同时在pro增加QT+= axcontainer
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

	void CreatSHFile(QString m_fileFullPathName);//生成.sh文件
	void CreatBCFile(QString m_fileFullPathName);//生成.bc文件
	int getNumberofexports(QString m_fileFullPathName);//从excel文件中获取出口的个数
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
