#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QAxObject>
#include <QProcess>

namespace Ui { class ComputingMultipleBP; };

class ComputingMultipleBP : public QDialog
{
	Q_OBJECT

public:
	ComputingMultipleBP(QWidget *parent = Q_NULLPTR);
	~ComputingMultipleBP();

private:
	Ui::ComputingMultipleBP *ui;
	QStringList fileList;
	QString g_name;
	QProcess *process;

	bool createFile(QString filePath);//创建文件夹
	void HiddenControls();//隐藏控件
	void ReadExcelFile(QString FullFileName);//读取excel文件
	void GetData(QString fullFileName);
	void SendComputingMultipleBP(QStringList uiDateList);
	void setVPFileName(QString fileFullPathName);//设置可变参数涉及到的文件名
	void CreateSHFile(QString m_fileFullPathName);//生成shell文件
	void CreateBCFile(QString m_fileFullPathName);//生成bc文件
	int getNumberofexports(QString m_fileFullPathName);//从excel文件中获取出口个数
	void CreateINFile(QString fileFullPathName);//通过调用Matlab生成in文件
	void copyFileToDir();//拷贝文件到对应的目录
signals:
	void ComputingMultipleBPSignal(QStringList uiDateList);
	private slots:
	void PushButtonSlot();//输入文件
	void PushButton_2Slot();//计算参数
	void GetCreateOPTFileSignalSlot(bool createStatus);//获得opt文件创建的状态
	void on_readoutput();//QProcess成功槽函数
	void on_readerror();//QProcess失败槽函数
};
