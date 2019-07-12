/********************************************************************************
** Form generated from reading UI file 'QtArteryTechPhysicsSetupUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHPHYSICSSETUPUI_H
#define UI_QTARTERYTECHPHYSICSSETUPUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QtArteryTechPhysicsSetupUI
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *TotalResistanceLabel;
    QLineEdit *TotalResistanceLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TotalCapacityLabel;
    QLineEdit *TotalCapacityLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *AllImpedanceLabel;
    QLineEdit *AllImpedanceLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *PdForWK3Label;
    QLineEdit *PdForWK3LineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *P0ForWK3Label;
    QLineEdit *P0ForWK3LineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *FluidViscosityLabel;
    QLineEdit *FluidViscosityLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *FluidDensityLabel;
    QLineEdit *FluidDensityLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *BloodFlowSimulationLabel;
    QLineEdit *BloodFlowSimulationLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *FluidOnlySimulationLabel;
    QLineEdit *FluidOnlySimulationLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *TimeDiscretizationMethodLabel;
    QLineEdit *TimeDiscretizationMethodLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *InitialTimeLabel;
    QLineEdit *InitialTimeLineEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *FinalTimeLabel;
    QLineEdit *FinalTimeLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *TimeStepSizeLabel;
    QLineEdit *TimeStepSizeLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *PeriodLabel;
    QLineEdit *PeriodLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *FixedMeshLabel;
    QLineEdit *FixedMeshLineEdit;
    QHBoxLayout *horizontalLayout_16;
    QLabel *ZeroInitialConditionLabel;
    QLineEdit *ZeroInitialConditionLineEdit;
    QHBoxLayout *horizontalLayout_17;
    QLabel *InletVelocityLabel;
    QLineEdit *InletVelocityLineEdit;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *OkPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechPhysicsSetupUI)
    {
        if (QtArteryTechPhysicsSetupUI->objectName().isEmpty())
            QtArteryTechPhysicsSetupUI->setObjectName(QStringLiteral("QtArteryTechPhysicsSetupUI"));
        QtArteryTechPhysicsSetupUI->resize(231, 523);
        verticalLayout_3 = new QVBoxLayout(QtArteryTechPhysicsSetupUI);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        TotalResistanceLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        TotalResistanceLabel->setObjectName(QStringLiteral("TotalResistanceLabel"));

        horizontalLayout->addWidget(TotalResistanceLabel);

        TotalResistanceLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        TotalResistanceLineEdit->setObjectName(QStringLiteral("TotalResistanceLineEdit"));

        horizontalLayout->addWidget(TotalResistanceLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TotalCapacityLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        TotalCapacityLabel->setObjectName(QStringLiteral("TotalCapacityLabel"));

        horizontalLayout_2->addWidget(TotalCapacityLabel);

        TotalCapacityLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        TotalCapacityLineEdit->setObjectName(QStringLiteral("TotalCapacityLineEdit"));

        horizontalLayout_2->addWidget(TotalCapacityLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        AllImpedanceLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        AllImpedanceLabel->setObjectName(QStringLiteral("AllImpedanceLabel"));

        horizontalLayout_3->addWidget(AllImpedanceLabel);

        AllImpedanceLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        AllImpedanceLineEdit->setObjectName(QStringLiteral("AllImpedanceLineEdit"));

        horizontalLayout_3->addWidget(AllImpedanceLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        PdForWK3Label = new QLabel(QtArteryTechPhysicsSetupUI);
        PdForWK3Label->setObjectName(QStringLiteral("PdForWK3Label"));

        horizontalLayout_4->addWidget(PdForWK3Label);

        PdForWK3LineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        PdForWK3LineEdit->setObjectName(QStringLiteral("PdForWK3LineEdit"));

        horizontalLayout_4->addWidget(PdForWK3LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        P0ForWK3Label = new QLabel(QtArteryTechPhysicsSetupUI);
        P0ForWK3Label->setObjectName(QStringLiteral("P0ForWK3Label"));

        horizontalLayout_5->addWidget(P0ForWK3Label);

        P0ForWK3LineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        P0ForWK3LineEdit->setObjectName(QStringLiteral("P0ForWK3LineEdit"));

        horizontalLayout_5->addWidget(P0ForWK3LineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        FluidViscosityLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        FluidViscosityLabel->setObjectName(QStringLiteral("FluidViscosityLabel"));

        horizontalLayout_6->addWidget(FluidViscosityLabel);

        FluidViscosityLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        FluidViscosityLineEdit->setObjectName(QStringLiteral("FluidViscosityLineEdit"));

        horizontalLayout_6->addWidget(FluidViscosityLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        FluidDensityLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        FluidDensityLabel->setObjectName(QStringLiteral("FluidDensityLabel"));

        horizontalLayout_7->addWidget(FluidDensityLabel);

        FluidDensityLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        FluidDensityLineEdit->setObjectName(QStringLiteral("FluidDensityLineEdit"));

        horizontalLayout_7->addWidget(FluidDensityLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        BloodFlowSimulationLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        BloodFlowSimulationLabel->setObjectName(QStringLiteral("BloodFlowSimulationLabel"));

        horizontalLayout_8->addWidget(BloodFlowSimulationLabel);

        BloodFlowSimulationLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        BloodFlowSimulationLineEdit->setObjectName(QStringLiteral("BloodFlowSimulationLineEdit"));

        horizontalLayout_8->addWidget(BloodFlowSimulationLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        FluidOnlySimulationLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        FluidOnlySimulationLabel->setObjectName(QStringLiteral("FluidOnlySimulationLabel"));

        horizontalLayout_9->addWidget(FluidOnlySimulationLabel);

        FluidOnlySimulationLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        FluidOnlySimulationLineEdit->setObjectName(QStringLiteral("FluidOnlySimulationLineEdit"));

        horizontalLayout_9->addWidget(FluidOnlySimulationLineEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        TimeDiscretizationMethodLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        TimeDiscretizationMethodLabel->setObjectName(QStringLiteral("TimeDiscretizationMethodLabel"));

        horizontalLayout_10->addWidget(TimeDiscretizationMethodLabel);

        TimeDiscretizationMethodLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        TimeDiscretizationMethodLineEdit->setObjectName(QStringLiteral("TimeDiscretizationMethodLineEdit"));

        horizontalLayout_10->addWidget(TimeDiscretizationMethodLineEdit);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        InitialTimeLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        InitialTimeLabel->setObjectName(QStringLiteral("InitialTimeLabel"));

        horizontalLayout_11->addWidget(InitialTimeLabel);

        InitialTimeLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        InitialTimeLineEdit->setObjectName(QStringLiteral("InitialTimeLineEdit"));

        horizontalLayout_11->addWidget(InitialTimeLineEdit);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        FinalTimeLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        FinalTimeLabel->setObjectName(QStringLiteral("FinalTimeLabel"));

        horizontalLayout_12->addWidget(FinalTimeLabel);

        FinalTimeLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        FinalTimeLineEdit->setObjectName(QStringLiteral("FinalTimeLineEdit"));

        horizontalLayout_12->addWidget(FinalTimeLineEdit);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        TimeStepSizeLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        TimeStepSizeLabel->setObjectName(QStringLiteral("TimeStepSizeLabel"));

        horizontalLayout_13->addWidget(TimeStepSizeLabel);

        TimeStepSizeLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        TimeStepSizeLineEdit->setObjectName(QStringLiteral("TimeStepSizeLineEdit"));

        horizontalLayout_13->addWidget(TimeStepSizeLineEdit);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        PeriodLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        PeriodLabel->setObjectName(QStringLiteral("PeriodLabel"));

        horizontalLayout_14->addWidget(PeriodLabel);

        PeriodLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        PeriodLineEdit->setObjectName(QStringLiteral("PeriodLineEdit"));

        horizontalLayout_14->addWidget(PeriodLineEdit);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        FixedMeshLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        FixedMeshLabel->setObjectName(QStringLiteral("FixedMeshLabel"));

        horizontalLayout_15->addWidget(FixedMeshLabel);

        FixedMeshLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        FixedMeshLineEdit->setObjectName(QStringLiteral("FixedMeshLineEdit"));

        horizontalLayout_15->addWidget(FixedMeshLineEdit);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        ZeroInitialConditionLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        ZeroInitialConditionLabel->setObjectName(QStringLiteral("ZeroInitialConditionLabel"));

        horizontalLayout_16->addWidget(ZeroInitialConditionLabel);

        ZeroInitialConditionLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        ZeroInitialConditionLineEdit->setObjectName(QStringLiteral("ZeroInitialConditionLineEdit"));

        horizontalLayout_16->addWidget(ZeroInitialConditionLineEdit);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        InletVelocityLabel = new QLabel(QtArteryTechPhysicsSetupUI);
        InletVelocityLabel->setObjectName(QStringLiteral("InletVelocityLabel"));

        horizontalLayout_17->addWidget(InletVelocityLabel);

        InletVelocityLineEdit = new QLineEdit(QtArteryTechPhysicsSetupUI);
        InletVelocityLineEdit->setObjectName(QStringLiteral("InletVelocityLineEdit"));

        horizontalLayout_17->addWidget(InletVelocityLineEdit);


        verticalLayout->addLayout(horizontalLayout_17);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        OkPushButton = new QPushButton(QtArteryTechPhysicsSetupUI);
        OkPushButton->setObjectName(QStringLiteral("OkPushButton"));

        horizontalLayout_18->addWidget(OkPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechPhysicsSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_18->addWidget(CancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout_18);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(QtArteryTechPhysicsSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechPhysicsSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechPhysicsSetupUI)
    {
        QtArteryTechPhysicsSetupUI->setWindowTitle(QApplication::translate("QtArteryTechPhysicsSetupUI", "QtArteryTechPhysicsSetupUI", Q_NULLPTR));
        TotalResistanceLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Total Resistance:", Q_NULLPTR));
        TotalCapacityLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Total Capacity:", Q_NULLPTR));
        AllImpedanceLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "All Impedance:", Q_NULLPTR));
        PdForWK3Label->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Pd for WK3:", Q_NULLPTR));
        P0ForWK3Label->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "P0 for WK3:", Q_NULLPTR));
        P0ForWK3LineEdit->setText(QString());
        FluidViscosityLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Fluid Viscosity:", Q_NULLPTR));
        FluidDensityLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Fluid Density:", Q_NULLPTR));
        BloodFlowSimulationLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Blood Flow Simulation:", Q_NULLPTR));
        FluidOnlySimulationLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Fluid Only Simulation:", Q_NULLPTR));
        TimeDiscretizationMethodLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Time Discretization Method:", Q_NULLPTR));
        InitialTimeLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Initial Time:", Q_NULLPTR));
        FinalTimeLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Final Time:", Q_NULLPTR));
        TimeStepSizeLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Time Step Size:", Q_NULLPTR));
        PeriodLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Period:", Q_NULLPTR));
        FixedMeshLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Fixed Mesh:", Q_NULLPTR));
        ZeroInitialConditionLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Zero Initial Condition:", Q_NULLPTR));
        InletVelocityLabel->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Inlet Velocity:", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechPhysicsSetupUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechPhysicsSetupUI: public Ui_QtArteryTechPhysicsSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHPHYSICSSETUPUI_H
