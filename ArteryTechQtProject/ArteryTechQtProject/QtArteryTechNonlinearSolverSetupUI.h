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

namespace Ui { class QtArteryTechNonlinearSolverSetupUI; };

class QtArteryTechNonlinearSolverSetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechNonlinearSolverSetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechNonlinearSolverSetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechNonlinearSolverSetupUI();
	QStringList nonlinearSolverDataList;
	QStringList GetTechNonlinearSolverData();
	QStringList getUIData();

private:
	Ui::QtArteryTechNonlinearSolverSetupUI *ui;
	QCheckBox *snesViewCheckBox;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitNonlinearSolverData(bool flag);
	void SaveNonlinearSolverData();
	int isDigitStr(QString str);
	void InitUiData();

private slots:
	void OkPushButton();
	void CancelPushButton();
	void MaxIterationNumberLineEditSlot();
	void RebuildJacobianLineEditSlot();
	void RebuildPreconditionerLineEditSlot();
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
