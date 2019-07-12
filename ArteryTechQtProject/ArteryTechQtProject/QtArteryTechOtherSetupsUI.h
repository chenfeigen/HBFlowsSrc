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

namespace Ui { class QtArteryTechOtherSetupsUI; };

class QtArteryTechOtherSetupsUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechOtherSetupsUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechOtherSetupsUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechOtherSetupsUI();
	QStringList otherDataList;
	QStringList GetTechOtherData();

private:
	QCheckBox *blockOrderCheckBox =	NULL;
	QCheckBox *logViewCheckBox = NULL;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitOtherData();
	void SaveOtherData();
	int isDigitStr(QString str);
private slots:
	void OkButtonSlots();
	void CancelButtonSlots();
	void InitialNumberOfPartitionLineEditSlot();
	void DiagnalScalerLineEditSlot();

private:
	Ui::QtArteryTechOtherSetupsUI *ui;
};
