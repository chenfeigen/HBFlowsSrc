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

private:
	Ui::QtArteryTechTwoLevelPreconditionerUI *ui;
	QCheckBox *twoLevelPreconditionerCheckBox = NULL;
	//QCheckBox *TwoLevelCheckBox;
	QCheckBox *useMGLineEditCheckBox = NULL;
	QCheckBox *mGTypeLineEditCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitTLPreconditionerData();
	void SaveTLPreconditionerData();


private slots:
	void TwoLevelPreconditionerCheckBoxSlots();
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
};
