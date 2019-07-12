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

private:
	Ui::QtArteryTechPreconditionerSetupUI *ui;
	QCheckBox *geometricAsmCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitPreconditionerData();
	void SavePreconditionerData();

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
};
