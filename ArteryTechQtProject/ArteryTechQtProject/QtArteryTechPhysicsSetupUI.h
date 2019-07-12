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
#include "QtArteryTechBoundarySetupUI.h"

namespace Ui { class QtArteryTechPhysicsSetupUI; };

class QtArteryTechPhysicsSetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechPhysicsSetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechPhysicsSetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechPhysicsSetupUI();
	QStringList physicsDataList;
	QStringList GetPhysicsData();

private:
	QCheckBox *allImpedanceCheckBox;
	QCheckBox *bloodflowCheckBox;
	QCheckBox *fluidonlyCheckBox;
	QCheckBox *fixedMeshCheckBox;
	QCheckBox *zeroInitialCheckBox;
	QString m_tmpFileName = NULL;

	void closeEvent(QCloseEvent *event);
	void InitPhysicsData();
	void SavePhysicsData();

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();

private:
	Ui::QtArteryTechPhysicsSetupUI *ui;
};
