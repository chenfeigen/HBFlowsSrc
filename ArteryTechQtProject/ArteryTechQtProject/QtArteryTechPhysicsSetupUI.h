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
	int m_boundaryType = 1;

	void closeEvent(QCloseEvent *event);
	void InitPhysicsData();
	void SavePhysicsData();
	int isDigitStr(QString str);

private slots:
	void OkPushButtonSlots();
	void CancelPushButtonSlots();
	void TotalResistanceLineEditSlot();
	void PdForWK3LineEditSlot();
	void P0ForWK3LineEditSlot();
	void FluidViscosityLineEditSlot();
	void FluidDensityLineEditSlot();
	void TimeDiscretizationMethodLineEditSlot();
	void InitialTimeLineEditSlot();
	void FinalTimeLineEditSlot();
	void TimeStepSizeLineEditSlot();
	void PeriodLineEditSlot();
	void InletVelocityLineEditSlot();
	void GetBoundaryTypeSlot(QString boundaryTypeText);
private:
	Ui::QtArteryTechPhysicsSetupUI *ui;
};
