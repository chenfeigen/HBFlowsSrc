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

namespace Ui { class QtArteryTechMeshSetup; };

class QtArteryTechMeshSetup : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechMeshSetup(QWidget *parent = Q_NULLPTR);
	QtArteryTechMeshSetup(QString tmpFileName,QWidget *parent = Q_NULLPTR);
	~QtArteryTechMeshSetup();
	QStringList meshSetupDataList;
	QStringList GetMeshData();

private:
	Ui::QtArteryTechMeshSetup *ui;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitMeshData();
	void SaveMeshData();
	int isDigitStr(QString str);

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void XEditingFinishedSlot();
	void YEditingFinishedSlot();
	void ZEditingFinishedSlot();
};
