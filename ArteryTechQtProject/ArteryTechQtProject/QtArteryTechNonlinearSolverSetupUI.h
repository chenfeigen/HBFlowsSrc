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

private:
	QCheckBox *snesViewCheckBox;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitNonlinearSolverData();
	void SaveNonlinearSolverData();
	int isDigitStr(QString str);

private slots:
	void OkPushButton();
	void CancelPushButton();
	void MaxIterationNumberLineEditSlot();
	void RebuildJacobianLineEditSlot();
	void RebuildPreconditionerLineEditSlot();

private:
	Ui::QtArteryTechNonlinearSolverSetupUI *ui;

};
