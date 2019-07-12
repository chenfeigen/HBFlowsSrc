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

namespace Ui { class QtArteryTechOutputSetupUI; };

class QtArteryTechOutputSetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechOutputSetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechOutputSetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechOutputSetupUI();
	QStringList outputDataList;
	QStringList GetOutputData();
	QStringList getUIData();

private:
	Ui::QtArteryTechOutputSetupUI *ui;

	QCheckBox *showPartitionBasicCheckBox =	NULL;
	QCheckBox *basicGridOutputCheckBox = NULL;
	QCheckBox *solutionOutputBasicCheckBox = NULL;
	QCheckBox *residualOutputBasicCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitOutputData(bool flag);
	void SaveOutputData();
	int isDigitStr(QString str);
	void InitUiData();

private slots:
	void NumberOfStepsForOutputLineEditSlot();
	void TimeIntervalForOutputLineEditSlot();
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
