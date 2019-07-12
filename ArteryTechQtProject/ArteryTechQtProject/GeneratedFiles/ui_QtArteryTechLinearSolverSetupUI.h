/********************************************************************************
** Form generated from reading UI file 'QtArteryTechLinearSolverSetupUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHLINEARSOLVERSETUPUI_H
#define UI_QTARTERYTECHLINEARSOLVERSETUPUI_H

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

class Ui_QtArteryTechLinearSolverSetupUI
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LinearSolverTypeLabel;
    QLineEdit *LinearSolverTypeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PreconditioningSideLabel;
    QLineEdit *PreconditioningSideLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *RestartNumberLabel;
    QLineEdit *RestartNumberLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MaxIterationNumberLabel;
    QLineEdit *MaxIterationNumberLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *RelativeTolleranceLabel;
    QLineEdit *RelativeTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *AbsoluteTolleranceLabel;
    QLineEdit *AbsoluteTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Different1stStepTolLabel;
    QLineEdit *Different1stStepTolLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *RatioOfThe1stStepTolLabel;
    QLineEdit *RatioOfThe1stStepTolLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *OkPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechLinearSolverSetupUI)
    {
        if (QtArteryTechLinearSolverSetupUI->objectName().isEmpty())
            QtArteryTechLinearSolverSetupUI->setObjectName(QStringLiteral("QtArteryTechLinearSolverSetupUI"));
        QtArteryTechLinearSolverSetupUI->resize(225, 271);
        verticalLayout_3 = new QVBoxLayout(QtArteryTechLinearSolverSetupUI);
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
        LinearSolverTypeLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        LinearSolverTypeLabel->setObjectName(QStringLiteral("LinearSolverTypeLabel"));

        horizontalLayout->addWidget(LinearSolverTypeLabel);

        LinearSolverTypeLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        LinearSolverTypeLineEdit->setObjectName(QStringLiteral("LinearSolverTypeLineEdit"));

        horizontalLayout->addWidget(LinearSolverTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PreconditioningSideLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        PreconditioningSideLabel->setObjectName(QStringLiteral("PreconditioningSideLabel"));

        horizontalLayout_2->addWidget(PreconditioningSideLabel);

        PreconditioningSideLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        PreconditioningSideLineEdit->setObjectName(QStringLiteral("PreconditioningSideLineEdit"));

        horizontalLayout_2->addWidget(PreconditioningSideLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        RestartNumberLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        RestartNumberLabel->setObjectName(QStringLiteral("RestartNumberLabel"));

        horizontalLayout_3->addWidget(RestartNumberLabel);

        RestartNumberLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        RestartNumberLineEdit->setObjectName(QStringLiteral("RestartNumberLineEdit"));

        horizontalLayout_3->addWidget(RestartNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        MaxIterationNumberLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        MaxIterationNumberLabel->setObjectName(QStringLiteral("MaxIterationNumberLabel"));

        horizontalLayout_4->addWidget(MaxIterationNumberLabel);

        MaxIterationNumberLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        MaxIterationNumberLineEdit->setObjectName(QStringLiteral("MaxIterationNumberLineEdit"));

        horizontalLayout_4->addWidget(MaxIterationNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        RelativeTolleranceLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        RelativeTolleranceLabel->setObjectName(QStringLiteral("RelativeTolleranceLabel"));

        horizontalLayout_5->addWidget(RelativeTolleranceLabel);

        RelativeTolleranceLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        RelativeTolleranceLineEdit->setObjectName(QStringLiteral("RelativeTolleranceLineEdit"));

        horizontalLayout_5->addWidget(RelativeTolleranceLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        AbsoluteTolleranceLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        AbsoluteTolleranceLabel->setObjectName(QStringLiteral("AbsoluteTolleranceLabel"));

        horizontalLayout_6->addWidget(AbsoluteTolleranceLabel);

        AbsoluteTolleranceLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        AbsoluteTolleranceLineEdit->setObjectName(QStringLiteral("AbsoluteTolleranceLineEdit"));

        horizontalLayout_6->addWidget(AbsoluteTolleranceLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Different1stStepTolLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        Different1stStepTolLabel->setObjectName(QStringLiteral("Different1stStepTolLabel"));

        horizontalLayout_7->addWidget(Different1stStepTolLabel);

        Different1stStepTolLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        Different1stStepTolLineEdit->setObjectName(QStringLiteral("Different1stStepTolLineEdit"));

        horizontalLayout_7->addWidget(Different1stStepTolLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        RatioOfThe1stStepTolLabel = new QLabel(QtArteryTechLinearSolverSetupUI);
        RatioOfThe1stStepTolLabel->setObjectName(QStringLiteral("RatioOfThe1stStepTolLabel"));

        horizontalLayout_8->addWidget(RatioOfThe1stStepTolLabel);

        RatioOfThe1stStepTolLineEdit = new QLineEdit(QtArteryTechLinearSolverSetupUI);
        RatioOfThe1stStepTolLineEdit->setObjectName(QStringLiteral("RatioOfThe1stStepTolLineEdit"));

        horizontalLayout_8->addWidget(RatioOfThe1stStepTolLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        OkPushButton = new QPushButton(QtArteryTechLinearSolverSetupUI);
        OkPushButton->setObjectName(QStringLiteral("OkPushButton"));

        horizontalLayout_9->addWidget(OkPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechLinearSolverSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_9->addWidget(CancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(QtArteryTechLinearSolverSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechLinearSolverSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechLinearSolverSetupUI)
    {
        QtArteryTechLinearSolverSetupUI->setWindowTitle(QApplication::translate("QtArteryTechLinearSolverSetupUI", "QtArteryTechLinearSolverSetupUI", Q_NULLPTR));
        LinearSolverTypeLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Linear Solver Type:", Q_NULLPTR));
        PreconditioningSideLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Preconditioning Side:", Q_NULLPTR));
        RestartNumberLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Restart Number:", Q_NULLPTR));
        MaxIterationNumberLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Max Iteration Number:", Q_NULLPTR));
        RelativeTolleranceLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Relative Tollerance:", Q_NULLPTR));
        AbsoluteTolleranceLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Absolute Tollerance:", Q_NULLPTR));
        Different1stStepTolLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Different 1st Step Tol:", Q_NULLPTR));
        RatioOfThe1stStepTolLabel->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Ratio of the 1st Step Tol:", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechLinearSolverSetupUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechLinearSolverSetupUI: public Ui_QtArteryTechLinearSolverSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHLINEARSOLVERSETUPUI_H
