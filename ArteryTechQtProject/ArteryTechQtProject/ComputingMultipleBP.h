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

	bool createFile(QString filePath);//�����ļ���
	void HiddenControls();//���ؿؼ�
	void ReadExcelFile(QString FullFileName);//��ȡexcel�ļ�
	void GetData(QString fullFileName);
	void SendComputingMultipleBP(QStringList uiDateList);
	void setVPFileName(QString fileFullPathName);//���ÿɱ�����漰�����ļ���
	void CreateSHFile(QString m_fileFullPathName);//����shell�ļ�
	void CreateBCFile(QString m_fileFullPathName);//����bc�ļ�
	int getNumberofexports(QString m_fileFullPathName);//��excel�ļ��л�ȡ���ڸ���
	void CreateINFile(QString fileFullPathName);//ͨ������Matlab����in�ļ�
	void copyFileToDir();//�����ļ�����Ӧ��Ŀ¼
signals:
	void ComputingMultipleBPSignal(QStringList uiDateList);
	private slots:
	void PushButtonSlot();//�����ļ�
	void PushButton_2Slot();//�������
	void GetCreateOPTFileSignalSlot(bool createStatus);//���opt�ļ�������״̬
	void on_readoutput();//QProcess�ɹ��ۺ���
	void on_readerror();//QProcessʧ�ܲۺ���
};
