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

namespace Ui { class QtArteryTechTwoLevelPreconditionerUI; };

class QtArteryTechTwoLevelPreconditionerUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechTwoLevelPreconditionerUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechTwoLevelPreconditionerUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechTwoLevelPreconditionerUI();
	QStringList twoLPreconditionerDataList;
	QStringList GetTLPreconditionerData();
	int isDigitStr(QString str);
	QStringList getUIData();

private:
	Ui::QtArteryTechTwoLevelPreconditionerUI *ui;
	QCheckBox *twoLevelPreconditionerCheckBox = NULL;
	//QCheckBox *TwoLevelCheckBox;
	QCheckBox *useMGLineEditCheckBox = NULL;
	QCheckBox *mGTypeLineEditCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitTLPreconditionerData(bool flag);
	void SaveTLPreconditionerData();
	void InitUiData();


private slots:
	void TwoLevelPreconditionerCheckBoxSlots();
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void CoarseLinearSolverRestartLineEditSlot();
	void CoarseLinearSolverMaxIterationLineEditSlot();
	void FineILULevelsLineEditSlot();
	void CoarseILULevelsLineEditSlot();
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
