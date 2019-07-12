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

namespace Ui { class QtArteryTechLinearSolverSetupUI; };

class QtArteryTechLinearSolverSetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechLinearSolverSetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechLinearSolverSetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechLinearSolverSetupUI();
	QStringList linearSolverDataList;
	QStringList GetTechLinearSolverData();
private:
	Ui::QtArteryTechLinearSolverSetupUI *ui;
	QCheckBox *diffLKRtolGAsmCheckBox;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitLinearSolverData();
	void SaveLinearSolverData();
	int isDigitStr(QString src);
private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void RestartNumberLineEditSlot();
	void MaxIterationNumberLineEditSlot();
	void RatioOfThe1stStepTolLineEditSlot();
};
