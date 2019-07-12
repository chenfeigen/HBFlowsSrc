/********************************************************************************
** Form generated from reading UI file 'QtArteryTechNonlinearSolverSetupUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHNONLINEARSOLVERSETUPUI_H
#define UI_QTARTERYTECHNONLINEARSOLVERSETUPUI_H

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

class Ui_QtArteryTechNonlinearSolverSetupUI
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *NonlinearSolverTypeLabel;
    QLineEdit *NonlinearSolverTypeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *RelativeTolleranceLabel;
    QLineEdit *RelativeTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *AbsoluteTolleranceLabel;
    QLineEdit *AbsoluteTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MaxIterationNumberLabel;
    QLineEdit *MaxIterationNumberLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *MonitorNonlinearSolverLabel;
    QLineEdit *MonitorNonlinearSolverLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *RebuildJacobianLabel;
    QLineEdit *RebuildJacobianLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *RebuildPreconditionerLabel;
    QLineEdit *RebuildPreconditionerLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OkPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechNonlinearSolverSetupUI)
    {
        if (QtArteryTechNonlinearSolverSetupUI->objectName().isEmpty())
            QtArteryTechNonlinearSolverSetupUI->setObjectName(QStringLiteral("QtArteryTechNonlinearSolverSetupUI"));
        QtArteryTechNonlinearSolverSetupUI->resize(219, 243);
        verticalLayout_3 = new QVBoxLayout(QtArteryTechNonlinearSolverSetupUI);
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
        NonlinearSolverTypeLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        NonlinearSolverTypeLabel->setObjectName(QStringLiteral("NonlinearSolverTypeLabel"));

        horizontalLayout->addWidget(NonlinearSolverTypeLabel);

        NonlinearSolverTypeLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        NonlinearSolverTypeLineEdit->setObjectName(QStringLiteral("NonlinearSolverTypeLineEdit"));

        horizontalLayout->addWidget(NonlinearSolverTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        RelativeTolleranceLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RelativeTolleranceLabel->setObjectName(QStringLiteral("RelativeTolleranceLabel"));

        horizontalLayout_2->addWidget(RelativeTolleranceLabel);

        RelativeTolleranceLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RelativeTolleranceLineEdit->setObjectName(QStringLiteral("RelativeTolleranceLineEdit"));

        horizontalLayout_2->addWidget(RelativeTolleranceLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        AbsoluteTolleranceLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        AbsoluteTolleranceLabel->setObjectName(QStringLiteral("AbsoluteTolleranceLabel"));

        horizontalLayout_3->addWidget(AbsoluteTolleranceLabel);

        AbsoluteTolleranceLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        AbsoluteTolleranceLineEdit->setObjectName(QStringLiteral("AbsoluteTolleranceLineEdit"));

        horizontalLayout_3->addWidget(AbsoluteTolleranceLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        MaxIterationNumberLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        MaxIterationNumberLabel->setObjectName(QStringLiteral("MaxIterationNumberLabel"));

        horizontalLayout_4->addWidget(MaxIterationNumberLabel);

        MaxIterationNumberLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        MaxIterationNumberLineEdit->setObjectName(QStringLiteral("MaxIterationNumberLineEdit"));

        horizontalLayout_4->addWidget(MaxIterationNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        MonitorNonlinearSolverLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        MonitorNonlinearSolverLabel->setObjectName(QStringLiteral("MonitorNonlinearSolverLabel"));

        horizontalLayout_5->addWidget(MonitorNonlinearSolverLabel);

        MonitorNonlinearSolverLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        MonitorNonlinearSolverLineEdit->setObjectName(QStringLiteral("MonitorNonlinearSolverLineEdit"));

        horizontalLayout_5->addWidget(MonitorNonlinearSolverLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        RebuildJacobianLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RebuildJacobianLabel->setObjectName(QStringLiteral("RebuildJacobianLabel"));

        horizontalLayout_6->addWidget(RebuildJacobianLabel);

        RebuildJacobianLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RebuildJacobianLineEdit->setObjectName(QStringLiteral("RebuildJacobianLineEdit"));

        horizontalLayout_6->addWidget(RebuildJacobianLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        RebuildPreconditionerLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RebuildPreconditionerLabel->setObjectName(QStringLiteral("RebuildPreconditionerLabel"));

        horizontalLayout_7->addWidget(RebuildPreconditionerLabel);

        RebuildPreconditionerLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RebuildPreconditionerLineEdit->setObjectName(QStringLiteral("RebuildPreconditionerLineEdit"));

        horizontalLayout_7->addWidget(RebuildPreconditionerLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        OkPushButton = new QPushButton(QtArteryTechNonlinearSolverSetupUI);
        OkPushButton->setObjectName(QStringLiteral("OkPushButton"));

        horizontalLayout_8->addWidget(OkPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechNonlinearSolverSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_8->addWidget(CancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(QtArteryTechNonlinearSolverSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechNonlinearSolverSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechNonlinearSolverSetupUI)
    {
        QtArteryTechNonlinearSolverSetupUI->setWindowTitle(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "QtArteryTechNonlinearSolverSetupUI", Q_NULLPTR));
        NonlinearSolverTypeLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Nonlinear Solver Type:", Q_NULLPTR));
        RelativeTolleranceLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Relative Tollerance:", Q_NULLPTR));
        AbsoluteTolleranceLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Absolute Tollerance:", Q_NULLPTR));
        MaxIterationNumberLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Max Iteration Number:", Q_NULLPTR));
        MonitorNonlinearSolverLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Monitor Nonlinear Solver:", Q_NULLPTR));
        RebuildJacobianLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Rebuild Jacobian:", Q_NULLPTR));
        RebuildPreconditionerLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Rebuild Preconditioner:", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Ok", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechNonlinearSolverSetupUI: public Ui_QtArteryTechNonlinearSolverSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHNONLINEARSOLVERSETUPUI_H
