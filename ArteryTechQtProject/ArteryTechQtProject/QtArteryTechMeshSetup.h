#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QCheckBox>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QDateTime>
#include <QDesktopWidget>

namespace Ui { class QtArteryTechMeshSetup; };

class QtArteryTechMeshSetup : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechMeshSetup(QWidget *parent = Q_NULLPTR);
	QtArteryTechMeshSetup(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~QtArteryTechMeshSetup();
	QStringList meshSetupDataList;
	QStringList GetMeshData();
	
	QStringList getUIData();

private:
	Ui::QtArteryTechMeshSetup *ui;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitMeshData(bool flag);
	void SaveMeshData();
	int isDigitStr(QString str);
	void InitUiData();

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void XEditingFinishedSlot();
	void YEditingFinishedSlot();
	void ZEditingFinishedSlot();
	void XCheckBoxStateChanged(int);
	void YCheckBoxStateChanged(int);
	void ZCheckBoxStateChanged(int);
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
