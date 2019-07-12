/********************************************************************************
** Form generated from reading UI file 'QtArteryTechTwoLevelPreconditionerUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHTWOLEVELPRECONDITIONERUI_H
#define UI_QTARTERYTECHTWOLEVELPRECONDITIONERUI_H

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

class Ui_QtArteryTechTwoLevelPreconditionerUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *CoarseLinearSolverLabel;
    QLineEdit *CoarseLinearSolverLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *CoarsePreconditionerSideLabel;
    QLineEdit *CoarsePreconditionerSideLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *CoarseLinearSolverRestartLabel;
    QLineEdit *CoarseLinearSolverRestartLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *CoarseLinearSolverMaxIterationLabel;
    QLineEdit *CoarseLinearSolverMaxIterationLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *CoarseLinearSolverRelativeTolLabel;
    QLineEdit *CoarseLinearSolverRelativeTolLineEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *CompositeTypeLabel;
    QLineEdit *CompositeTypeLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *MGCycleTypeLabel;
    QLineEdit *MGCycleTypeLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *FinePreconditionerTypeLabel;
    QLineEdit *FinePreconditionerTypeLineEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *FineSubdomainPreconTypeLabel;
    QLineEdit *FineSubdomainPreconTypeLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *FineILULevelsLabel;
    QLineEdit *FineILULevelsLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *FineSubMatrixOderingTypeLabel;
    QLineEdit *FineSubMatrixOderingTypeLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *CoarsePreconditionerTypeLabel;
    QLineEdit *CoarsePreconditionerTypeLineEdit;
    QHBoxLayout *horizontalLayout_16;
    QLabel *CoarseSubdomainPreconTypeLabel;
    QLineEdit *CoarseSubdomainPreconTypeLineEdit;
    QHBoxLayout *horizontalLayout_17;
    QLabel *CoarseILULevelsLabel;
    QLineEdit *CoarseILULevelsLineEdit;
    QHBoxLayout *horizontalLayout_18;
    QLabel *CoarseSubMatrixOderingTypeLabel;
    QLineEdit *CoarseSubMatrixOderingTypeLineEdit;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *OKPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechTwoLevelPreconditionerUI)
    {
        if (QtArteryTechTwoLevelPreconditionerUI->objectName().isEmpty())
            QtArteryTechTwoLevelPreconditionerUI->setObjectName(QStringLiteral("QtArteryTechTwoLevelPreconditionerUI"));
        QtArteryTechTwoLevelPreconditionerUI->resize(279, 553);
        verticalLayout_2 = new QVBoxLayout(QtArteryTechTwoLevelPreconditionerUI);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setSpacing(6);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));

        verticalLayout->addLayout(horizontalLayout_1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CoarseLinearSolverLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverLabel->setObjectName(QStringLiteral("CoarseLinearSolverLabel"));

        horizontalLayout_2->addWidget(CoarseLinearSolverLabel);

        CoarseLinearSolverLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverLineEdit->setObjectName(QStringLiteral("CoarseLinearSolverLineEdit"));

        horizontalLayout_2->addWidget(CoarseLinearSolverLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CoarsePreconditionerSideLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarsePreconditionerSideLabel->setObjectName(QStringLiteral("CoarsePreconditionerSideLabel"));

        horizontalLayout_3->addWidget(CoarsePreconditionerSideLabel);

        CoarsePreconditionerSideLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarsePreconditionerSideLineEdit->setObjectName(QStringLiteral("CoarsePreconditionerSideLineEdit"));

        horizontalLayout_3->addWidget(CoarsePreconditionerSideLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CoarseLinearSolverRestartLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverRestartLabel->setObjectName(QStringLiteral("CoarseLinearSolverRestartLabel"));

        horizontalLayout_4->addWidget(CoarseLinearSolverRestartLabel);

        CoarseLinearSolverRestartLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverRestartLineEdit->setObjectName(QStringLiteral("CoarseLinearSolverRestartLineEdit"));

        horizontalLayout_4->addWidget(CoarseLinearSolverRestartLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        CoarseLinearSolverMaxIterationLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverMaxIterationLabel->setObjectName(QStringLiteral("CoarseLinearSolverMaxIterationLabel"));

        horizontalLayout_5->addWidget(CoarseLinearSolverMaxIterationLabel);

        CoarseLinearSolverMaxIterationLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverMaxIterationLineEdit->setObjectName(QStringLiteral("CoarseLinearSolverMaxIterationLineEdit"));

        horizontalLayout_5->addWidget(CoarseLinearSolverMaxIterationLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        CoarseLinearSolverRelativeTolLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverRelativeTolLabel->setObjectName(QStringLiteral("CoarseLinearSolverRelativeTolLabel"));

        horizontalLayout_6->addWidget(CoarseLinearSolverRelativeTolLabel);

        CoarseLinearSolverRelativeTolLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseLinearSolverRelativeTolLineEdit->setObjectName(QStringLiteral("CoarseLinearSolverRelativeTolLineEdit"));

        horizontalLayout_6->addWidget(CoarseLinearSolverRelativeTolLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        CompositeTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CompositeTypeLabel->setObjectName(QStringLiteral("CompositeTypeLabel"));

        horizontalLayout_9->addWidget(CompositeTypeLabel);

        CompositeTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CompositeTypeLineEdit->setObjectName(QStringLiteral("CompositeTypeLineEdit"));

        horizontalLayout_9->addWidget(CompositeTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        MGCycleTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        MGCycleTypeLabel->setObjectName(QStringLiteral("MGCycleTypeLabel"));

        horizontalLayout_10->addWidget(MGCycleTypeLabel);

        MGCycleTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        MGCycleTypeLineEdit->setObjectName(QStringLiteral("MGCycleTypeLineEdit"));

        horizontalLayout_10->addWidget(MGCycleTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        FinePreconditionerTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        FinePreconditionerTypeLabel->setObjectName(QStringLiteral("FinePreconditionerTypeLabel"));

        horizontalLayout_11->addWidget(FinePreconditionerTypeLabel);

        FinePreconditionerTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        FinePreconditionerTypeLineEdit->setObjectName(QStringLiteral("FinePreconditionerTypeLineEdit"));

        horizontalLayout_11->addWidget(FinePreconditionerTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        FineSubdomainPreconTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        FineSubdomainPreconTypeLabel->setObjectName(QStringLiteral("FineSubdomainPreconTypeLabel"));

        horizontalLayout_12->addWidget(FineSubdomainPreconTypeLabel);

        FineSubdomainPreconTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        FineSubdomainPreconTypeLineEdit->setObjectName(QStringLiteral("FineSubdomainPreconTypeLineEdit"));

        horizontalLayout_12->addWidget(FineSubdomainPreconTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        FineILULevelsLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        FineILULevelsLabel->setObjectName(QStringLiteral("FineILULevelsLabel"));

        horizontalLayout_13->addWidget(FineILULevelsLabel);

        FineILULevelsLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        FineILULevelsLineEdit->setObjectName(QStringLiteral("FineILULevelsLineEdit"));

        horizontalLayout_13->addWidget(FineILULevelsLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        FineSubMatrixOderingTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        FineSubMatrixOderingTypeLabel->setObjectName(QStringLiteral("FineSubMatrixOderingTypeLabel"));

        horizontalLayout_14->addWidget(FineSubMatrixOderingTypeLabel);

        FineSubMatrixOderingTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        FineSubMatrixOderingTypeLineEdit->setObjectName(QStringLiteral("FineSubMatrixOderingTypeLineEdit"));

        horizontalLayout_14->addWidget(FineSubMatrixOderingTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        CoarsePreconditionerTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarsePreconditionerTypeLabel->setObjectName(QStringLiteral("CoarsePreconditionerTypeLabel"));

        horizontalLayout_15->addWidget(CoarsePreconditionerTypeLabel);

        CoarsePreconditionerTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarsePreconditionerTypeLineEdit->setObjectName(QStringLiteral("CoarsePreconditionerTypeLineEdit"));

        horizontalLayout_15->addWidget(CoarsePreconditionerTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        CoarseSubdomainPreconTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseSubdomainPreconTypeLabel->setObjectName(QStringLiteral("CoarseSubdomainPreconTypeLabel"));

        horizontalLayout_16->addWidget(CoarseSubdomainPreconTypeLabel);

        CoarseSubdomainPreconTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseSubdomainPreconTypeLineEdit->setObjectName(QStringLiteral("CoarseSubdomainPreconTypeLineEdit"));

        horizontalLayout_16->addWidget(CoarseSubdomainPreconTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        CoarseILULevelsLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseILULevelsLabel->setObjectName(QStringLiteral("CoarseILULevelsLabel"));

        horizontalLayout_17->addWidget(CoarseILULevelsLabel);

        CoarseILULevelsLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseILULevelsLineEdit->setObjectName(QStringLiteral("CoarseILULevelsLineEdit"));

        horizontalLayout_17->addWidget(CoarseILULevelsLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        CoarseSubMatrixOderingTypeLabel = new QLabel(QtArteryTechTwoLevelPreconditionerUI);
        CoarseSubMatrixOderingTypeLabel->setObjectName(QStringLiteral("CoarseSubMatrixOderingTypeLabel"));

        horizontalLayout_18->addWidget(CoarseSubMatrixOderingTypeLabel);

        CoarseSubMatrixOderingTypeLineEdit = new QLineEdit(QtArteryTechTwoLevelPreconditionerUI);
        CoarseSubMatrixOderingTypeLineEdit->setObjectName(QStringLiteral("CoarseSubMatrixOderingTypeLineEdit"));

        horizontalLayout_18->addWidget(CoarseSubMatrixOderingTypeLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_18);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        OKPushButton = new QPushButton(QtArteryTechTwoLevelPreconditionerUI);
        OKPushButton->setObjectName(QStringLiteral("OKPushButton"));

        horizontalLayout_19->addWidget(OKPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechTwoLevelPreconditionerUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_19->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_19);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtArteryTechTwoLevelPreconditionerUI);

        QMetaObject::connectSlotsByName(QtArteryTechTwoLevelPreconditionerUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechTwoLevelPreconditionerUI)
    {
        QtArteryTechTwoLevelPreconditionerUI->setWindowTitle(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "QtArteryTechTwoLevelPreconditionerUI", Q_NULLPTR));
        CoarseLinearSolverLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Linear Solver:", Q_NULLPTR));
        CoarsePreconditionerSideLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Preconditioner Side:", Q_NULLPTR));
        CoarseLinearSolverRestartLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Linear Solver Restart:", Q_NULLPTR));
        CoarseLinearSolverMaxIterationLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Linear Solver Max Iteration:", Q_NULLPTR));
        CoarseLinearSolverRelativeTolLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Linear Solver Relative Tol:", Q_NULLPTR));
        CompositeTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Composite Type:", Q_NULLPTR));
        MGCycleTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "MG Cycle Type:", Q_NULLPTR));
        FinePreconditionerTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Fine Preconditioner Type:", Q_NULLPTR));
        FineSubdomainPreconTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Fine Subdomain Precon Type:", Q_NULLPTR));
        FineILULevelsLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Fine ILU Levels:", Q_NULLPTR));
        FineSubMatrixOderingTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Fine SubMatrix Odering Type:", Q_NULLPTR));
        CoarsePreconditionerTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Preconditioner Type:", Q_NULLPTR));
        CoarseSubdomainPreconTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse Subdomain Precon Type:", Q_NULLPTR));
        CoarseILULevelsLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse ILU Levels:", Q_NULLPTR));
        CoarseSubMatrixOderingTypeLabel->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Coarse SubMatrix Odering Type:", Q_NULLPTR));
        OKPushButton->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechTwoLevelPreconditionerUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechTwoLevelPreconditionerUI: public Ui_QtArteryTechTwoLevelPreconditionerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHTWOLEVELPRECONDITIONERUI_H
