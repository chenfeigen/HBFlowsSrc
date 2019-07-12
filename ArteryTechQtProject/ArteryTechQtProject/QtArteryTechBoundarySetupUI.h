#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QCheckBox>
#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QDateTime>
#include <QDesktopWidget>

namespace Ui { class QtArteryTechBoundarySetupUI; };

class QtArteryTechBoundarySetupUI : public QDialog
{
	Q_OBJECT

public:
	QtArteryTechBoundarySetupUI(QWidget *parent = Q_NULLPTR);
	QtArteryTechBoundarySetupUI(QString tmpFileName, QWidget *parent = Q_NULLPTR);
	~QtArteryTechBoundarySetupUI();
	QStringList boundaryDataList;//将界面上的数据保存在这个链表里面
	QString bloodflowBcTypeText = NULL;
	QStringList GetBoundaryData();
	QStringList getUIData();
protected:
	void closeEvent(QCloseEvent *event);
private:
	Ui::QtArteryTechBoundarySetupUI *ui;
	QCheckBox *vinCheckBox = NULL;
	QCheckBox *wallCheckBox = NULL;
	QCheckBox *inletFlowfactorCheckBox = NULL;
	QCheckBox *parabolicInflowCheckBox = NULL;
	QString m_tmpFileName = NULL;
	void InitBoundaryData(bool flag);
	void SaveBoundaryData();
	int isDigitStr(QString src);
	void SendBoundaryTypeSignal(QString boundaryTypeText);
	void InitUiData();

signals:
	void BoundaryTypeSignal(QString boundaryTypeText);
private slots:
	void OKPushButtonSlots();
	void CancelPushButtonSlots();
	void BoundaryTypeLineEditSlot();
	void NumberOfOutletsLineEditSlot();
	void IndexForAortaOutletLineEditSlot();
	void InletBoudaryNormXDirectionLineEditSlot();
	void InletBoudaryNormYDirectionLineEditSlot();
	void InletBoudaryNormZDirectionLineEditSlot();
	void InletBoudaryLowBoundXDirectionLineEditSlot();
	void InletBoudaryLowBoundYDirectionLineEditSlot();
	void InletBoudaryLowBoundZDirectionLineEditSlot();
	void InletBoudaryUpperBoundXDirectionLineEditSlot();
	void InletBoudaryUpperBoundYDirectionLineEditSlot();
	void InletBoudaryUpperBoundZDirectionLineEditSlot();
	void InletBoudaryAreaLineEditSlot();
	void BTCheckBoxStateChanged(int Status);
	void IFAOCheckBoxStateChanged(int Status);
	void GetVerifyPasswordStatuSlot(bool flag);
	void GetVariableParametersSignalSlot(QStringList VariableParametersList);//获取可变参数槽函数
};
