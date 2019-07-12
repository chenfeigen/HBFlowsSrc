/********************************************************************************
** Form generated from reading UI file 'QtArteryTechOutputSetupUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHOUTPUTSETUPUI_H
#define UI_QTARTERYTECHOUTPUTSETUPUI_H

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

class Ui_QtArteryTechOutputSetupUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *RefMonitorPointLabel;
    QLineEdit *RefMonitorPointLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *MonitorPoint1Label;
    QLineEdit *MonitorPoint1LineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *MonitorPoint2Label;
    QLineEdit *MonitorPoint2LineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MonitorPoint3Label;
    QLineEdit *MonitorPoint3LineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *FFRMonitorFileLabel;
    QLineEdit *FFRMonitorFileLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *FlowRateMonitorFileLabel;
    QLineEdit *FlowRateMonitorFileLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *SolutionOutputFileLabel;
    QLineEdit *SolutionOutputFileLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *ShowSubdomainMeshDataLabel;
    QLineEdit *ShowSubdomainMeshDataLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *ShowMeshDataLabel;
    QLineEdit *ShowMeshDataLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *ShowSolutionLabel;
    QLineEdit *ShowSolutionLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *MonitorResidualLabel;
    QLineEdit *MonitorResidualLineEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *NumberOfStepsForOutputLabel;
    QLineEdit *NumberOfStepsForOutputLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *TimeIntervalForOutputLabel;
    QLineEdit *TimeIntervalForOutputLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *OkPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechOutputSetupUI)
    {
        if (QtArteryTechOutputSetupUI->objectName().isEmpty())
            QtArteryTechOutputSetupUI->setObjectName(QStringLiteral("QtArteryTechOutputSetupUI"));
        QtArteryTechOutputSetupUI->resize(229, 409);
        verticalLayout_2 = new QVBoxLayout(QtArteryTechOutputSetupUI);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RefMonitorPointLabel = new QLabel(QtArteryTechOutputSetupUI);
        RefMonitorPointLabel->setObjectName(QStringLiteral("RefMonitorPointLabel"));

        horizontalLayout->addWidget(RefMonitorPointLabel);

        RefMonitorPointLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        RefMonitorPointLineEdit->setObjectName(QStringLiteral("RefMonitorPointLineEdit"));

        horizontalLayout->addWidget(RefMonitorPointLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        MonitorPoint1Label = new QLabel(QtArteryTechOutputSetupUI);
        MonitorPoint1Label->setObjectName(QStringLiteral("MonitorPoint1Label"));

        horizontalLayout_2->addWidget(MonitorPoint1Label);

        MonitorPoint1LineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        MonitorPoint1LineEdit->setObjectName(QStringLiteral("MonitorPoint1LineEdit"));

        horizontalLayout_2->addWidget(MonitorPoint1LineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        MonitorPoint2Label = new QLabel(QtArteryTechOutputSetupUI);
        MonitorPoint2Label->setObjectName(QStringLiteral("MonitorPoint2Label"));

        horizontalLayout_3->addWidget(MonitorPoint2Label);

        MonitorPoint2LineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        MonitorPoint2LineEdit->setObjectName(QStringLiteral("MonitorPoint2LineEdit"));

        horizontalLayout_3->addWidget(MonitorPoint2LineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        MonitorPoint3Label = new QLabel(QtArteryTechOutputSetupUI);
        MonitorPoint3Label->setObjectName(QStringLiteral("MonitorPoint3Label"));

        horizontalLayout_4->addWidget(MonitorPoint3Label);

        MonitorPoint3LineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        MonitorPoint3LineEdit->setObjectName(QStringLiteral("MonitorPoint3LineEdit"));

        horizontalLayout_4->addWidget(MonitorPoint3LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        FFRMonitorFileLabel = new QLabel(QtArteryTechOutputSetupUI);
        FFRMonitorFileLabel->setObjectName(QStringLiteral("FFRMonitorFileLabel"));

        horizontalLayout_5->addWidget(FFRMonitorFileLabel);

        FFRMonitorFileLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        FFRMonitorFileLineEdit->setObjectName(QStringLiteral("FFRMonitorFileLineEdit"));

        horizontalLayout_5->addWidget(FFRMonitorFileLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        FlowRateMonitorFileLabel = new QLabel(QtArteryTechOutputSetupUI);
        FlowRateMonitorFileLabel->setObjectName(QStringLiteral("FlowRateMonitorFileLabel"));

        horizontalLayout_6->addWidget(FlowRateMonitorFileLabel);

        FlowRateMonitorFileLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        FlowRateMonitorFileLineEdit->setObjectName(QStringLiteral("FlowRateMonitorFileLineEdit"));

        horizontalLayout_6->addWidget(FlowRateMonitorFileLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        SolutionOutputFileLabel = new QLabel(QtArteryTechOutputSetupUI);
        SolutionOutputFileLabel->setObjectName(QStringLiteral("SolutionOutputFileLabel"));

        horizontalLayout_7->addWidget(SolutionOutputFileLabel);

        SolutionOutputFileLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        SolutionOutputFileLineEdit->setObjectName(QStringLiteral("SolutionOutputFileLineEdit"));

        horizontalLayout_7->addWidget(SolutionOutputFileLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ShowSubdomainMeshDataLabel = new QLabel(QtArteryTechOutputSetupUI);
        ShowSubdomainMeshDataLabel->setObjectName(QStringLiteral("ShowSubdomainMeshDataLabel"));

        horizontalLayout_8->addWidget(ShowSubdomainMeshDataLabel);

        ShowSubdomainMeshDataLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        ShowSubdomainMeshDataLineEdit->setObjectName(QStringLiteral("ShowSubdomainMeshDataLineEdit"));

        horizontalLayout_8->addWidget(ShowSubdomainMeshDataLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ShowMeshDataLabel = new QLabel(QtArteryTechOutputSetupUI);
        ShowMeshDataLabel->setObjectName(QStringLiteral("ShowMeshDataLabel"));

        horizontalLayout_9->addWidget(ShowMeshDataLabel);

        ShowMeshDataLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        ShowMeshDataLineEdit->setObjectName(QStringLiteral("ShowMeshDataLineEdit"));

        horizontalLayout_9->addWidget(ShowMeshDataLineEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        ShowSolutionLabel = new QLabel(QtArteryTechOutputSetupUI);
        ShowSolutionLabel->setObjectName(QStringLiteral("ShowSolutionLabel"));

        horizontalLayout_10->addWidget(ShowSolutionLabel);

        ShowSolutionLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        ShowSolutionLineEdit->setObjectName(QStringLiteral("ShowSolutionLineEdit"));

        horizontalLayout_10->addWidget(ShowSolutionLineEdit);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        MonitorResidualLabel = new QLabel(QtArteryTechOutputSetupUI);
        MonitorResidualLabel->setObjectName(QStringLiteral("MonitorResidualLabel"));

        horizontalLayout_11->addWidget(MonitorResidualLabel);

        MonitorResidualLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        MonitorResidualLineEdit->setObjectName(QStringLiteral("MonitorResidualLineEdit"));

        horizontalLayout_11->addWidget(MonitorResidualLineEdit);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        NumberOfStepsForOutputLabel = new QLabel(QtArteryTechOutputSetupUI);
        NumberOfStepsForOutputLabel->setObjectName(QStringLiteral("NumberOfStepsForOutputLabel"));

        horizontalLayout_12->addWidget(NumberOfStepsForOutputLabel);

        NumberOfStepsForOutputLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        NumberOfStepsForOutputLineEdit->setObjectName(QStringLiteral("NumberOfStepsForOutputLineEdit"));

        horizontalLayout_12->addWidget(NumberOfStepsForOutputLineEdit);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        TimeIntervalForOutputLabel = new QLabel(QtArteryTechOutputSetupUI);
        TimeIntervalForOutputLabel->setObjectName(QStringLiteral("TimeIntervalForOutputLabel"));

        horizontalLayout_13->addWidget(TimeIntervalForOutputLabel);

        TimeIntervalForOutputLineEdit = new QLineEdit(QtArteryTechOutputSetupUI);
        TimeIntervalForOutputLineEdit->setObjectName(QStringLiteral("TimeIntervalForOutputLineEdit"));

        horizontalLayout_13->addWidget(TimeIntervalForOutputLineEdit);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        OkPushButton = new QPushButton(QtArteryTechOutputSetupUI);
        OkPushButton->setObjectName(QStringLiteral("OkPushButton"));

        horizontalLayout_14->addWidget(OkPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechOutputSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_14->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_14);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtArteryTechOutputSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechOutputSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechOutputSetupUI)
    {
        QtArteryTechOutputSetupUI->setWindowTitle(QApplication::translate("QtArteryTechOutputSetupUI", "QtArteryTechOutputSetupUI", Q_NULLPTR));
        RefMonitorPointLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Ref Monitor Point:", Q_NULLPTR));
        MonitorPoint1Label->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Monitor Point 1:", Q_NULLPTR));
        MonitorPoint2Label->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Monitor Point 2: ", Q_NULLPTR));
        MonitorPoint3Label->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Monitor Point 3:", Q_NULLPTR));
        FFRMonitorFileLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "FFR Monitor File:", Q_NULLPTR));
        FlowRateMonitorFileLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Flow Rate Monitor File:", Q_NULLPTR));
        SolutionOutputFileLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Solution Output File:", Q_NULLPTR));
        ShowSubdomainMeshDataLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Show Subdomain Mesh Data:", Q_NULLPTR));
        ShowMeshDataLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Show Mesh Data:", Q_NULLPTR));
        ShowSolutionLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Show Solution:", Q_NULLPTR));
        MonitorResidualLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Monitor Residual:", Q_NULLPTR));
        NumberOfStepsForOutputLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Number of Steps for Output:", Q_NULLPTR));
        TimeIntervalForOutputLabel->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Time Interval for Output:", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechOutputSetupUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechOutputSetupUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechOutputSetupUI: public Ui_QtArteryTechOutputSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHOUTPUTSETUPUI_H
