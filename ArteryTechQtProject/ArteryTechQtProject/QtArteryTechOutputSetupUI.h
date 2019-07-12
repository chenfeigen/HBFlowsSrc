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

private:
	QCheckBox *showPartitionBasicCheckBox =	NULL;
	QCheckBox *basicGridOutputCheckBox = NULL;
	QCheckBox *solutionOutputBasicCheckBox = NULL;
	QCheckBox *residualOutputBasicCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitOutputData();
	void SaveOutputData();

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();

private:
	Ui::QtArteryTechOutputSetupUI *ui;
};
