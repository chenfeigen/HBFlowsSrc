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

namespace Ui { class QtArteryTechPreconditionerSetupUI; };

class QtArteryTechPreconditionerSetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechPreconditionerSetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechPreconditionerSetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechPreconditionerSetupUI();
	QStringList preconditionerDataList;
	QStringList GetTechPreconditionerData();
	int isDigitStr(QString str);
	QStringList getUIData();

private:
	Ui::QtArteryTechPreconditionerSetupUI *ui;
	QCheckBox *geometricAsmCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitPreconditionerData(bool flag);
	void SavePreconditionerData();
	void InitUiData();

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void ILULevelsLineEditSlot();
	void OverlappingSizeLineEditSlot();
	void OverlappingSizeCheckBoxStateChanged(int Status);
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
