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
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *NonlinearSolverTypeLabel;
    QLineEdit *NonlinearSolverTypeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *RelativeTolleranceLabel;
    QLineEdit *RelativeTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *AbsoluteTolleranceLabel;
    QLineEdit *AbsoluteTolleranceLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *MaxIterationNumberLabel;
    QLineEdit *MaxIterationNumberLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *MonitorNonlinearSolverLabel;
    QLineEdit *MonitorNonlinearSolverLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *RebuildJacobianLabel;
    QLineEdit *RebuildJacobianLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
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
        QtArteryTechNonlinearSolverSetupUI->resize(702, 243);
        verticalLayout_9 = new QVBoxLayout(QtArteryTechNonlinearSolverSetupUI);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        NonlinearSolverTypeLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        NonlinearSolverTypeLabel->setObjectName(QStringLiteral("NonlinearSolverTypeLabel"));

        verticalLayout->addWidget(NonlinearSolverTypeLabel);


        horizontalLayout->addLayout(verticalLayout);

        NonlinearSolverTypeLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        NonlinearSolverTypeLineEdit->setObjectName(QStringLiteral("NonlinearSolverTypeLineEdit"));

        horizontalLayout->addWidget(NonlinearSolverTypeLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        RelativeTolleranceLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RelativeTolleranceLabel->setObjectName(QStringLiteral("RelativeTolleranceLabel"));

        verticalLayout_2->addWidget(RelativeTolleranceLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);

        RelativeTolleranceLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RelativeTolleranceLineEdit->setObjectName(QStringLiteral("RelativeTolleranceLineEdit"));

        horizontalLayout_2->addWidget(RelativeTolleranceLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        AbsoluteTolleranceLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        AbsoluteTolleranceLabel->setObjectName(QStringLiteral("AbsoluteTolleranceLabel"));

        verticalLayout_3->addWidget(AbsoluteTolleranceLabel);


        horizontalLayout_3->addLayout(verticalLayout_3);

        AbsoluteTolleranceLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        AbsoluteTolleranceLineEdit->setObjectName(QStringLiteral("AbsoluteTolleranceLineEdit"));

        horizontalLayout_3->addWidget(AbsoluteTolleranceLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        MaxIterationNumberLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        MaxIterationNumberLabel->setObjectName(QStringLiteral("MaxIterationNumberLabel"));

        verticalLayout_4->addWidget(MaxIterationNumberLabel);


        horizontalLayout_4->addLayout(verticalLayout_4);

        MaxIterationNumberLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        MaxIterationNumberLineEdit->setObjectName(QStringLiteral("MaxIterationNumberLineEdit"));

        horizontalLayout_4->addWidget(MaxIterationNumberLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        MonitorNonlinearSolverLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        MonitorNonlinearSolverLabel->setObjectName(QStringLiteral("MonitorNonlinearSolverLabel"));

        verticalLayout_5->addWidget(MonitorNonlinearSolverLabel);


        horizontalLayout_5->addLayout(verticalLayout_5);

        MonitorNonlinearSolverLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        MonitorNonlinearSolverLineEdit->setObjectName(QStringLiteral("MonitorNonlinearSolverLineEdit"));

        horizontalLayout_5->addWidget(MonitorNonlinearSolverLineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        RebuildJacobianLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RebuildJacobianLabel->setObjectName(QStringLiteral("RebuildJacobianLabel"));

        verticalLayout_6->addWidget(RebuildJacobianLabel);


        horizontalLayout_6->addLayout(verticalLayout_6);

        RebuildJacobianLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RebuildJacobianLineEdit->setObjectName(QStringLiteral("RebuildJacobianLineEdit"));

        horizontalLayout_6->addWidget(RebuildJacobianLineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_7 = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);

        RebuildPreconditionerLabel = new QLabel(QtArteryTechNonlinearSolverSetupUI);
        RebuildPreconditionerLabel->setObjectName(QStringLiteral("RebuildPreconditionerLabel"));

        verticalLayout_7->addWidget(RebuildPreconditionerLabel);


        horizontalLayout_7->addLayout(verticalLayout_7);

        RebuildPreconditionerLineEdit = new QLineEdit(QtArteryTechNonlinearSolverSetupUI);
        RebuildPreconditionerLineEdit->setObjectName(QStringLiteral("RebuildPreconditionerLineEdit"));

        horizontalLayout_7->addWidget(RebuildPreconditionerLineEdit);


        verticalLayout_8->addLayout(horizontalLayout_7);

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


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_9->addLayout(verticalLayout_8);


        retranslateUi(QtArteryTechNonlinearSolverSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechNonlinearSolverSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechNonlinearSolverSetupUI)
    {
        QtArteryTechNonlinearSolverSetupUI->setWindowTitle(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "QtArteryTechNonlinearSolverSetupUI", Q_NULLPTR));
        label->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\351\235\236\347\272\277\346\200\247\346\261\202\350\247\243\345\231\250\347\261\273\345\236\213", Q_NULLPTR));
        NonlinearSolverTypeLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Nonlinear Solver Type:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\351\235\236\347\272\277\346\200\247\346\224\266\346\225\233\347\233\270\345\257\271\350\257\257\345\267\256", Q_NULLPTR));
        RelativeTolleranceLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Relative Tollerance:", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\351\235\236\347\272\277\346\200\247\346\224\266\346\225\233\347\273\235\345\257\271\350\257\257\345\267\256", Q_NULLPTR));
        AbsoluteTolleranceLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Absolute Tollerance:", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\346\234\200\345\244\247\351\235\236\347\272\277\346\200\247\350\277\255\344\273\243\346\254\241\346\225\260", Q_NULLPTR));
        MaxIterationNumberLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Max Iteration Number:", Q_NULLPTR));
        label_5->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\347\233\221\350\247\206\351\235\236\347\272\277\346\200\247\346\261\202\350\247\243\345\231\250", Q_NULLPTR));
        MonitorNonlinearSolverLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Monitor Nonlinear Solver:", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\351\207\215\345\273\272\351\233\205\345\217\257\346\257\224\350\241\214\345\210\227\345\274\217", Q_NULLPTR));
        RebuildJacobianLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Rebuild Jacobian:", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\351\207\215\345\273\272\351\242\204\345\244\204\347\220\206\345\231\250", Q_NULLPTR));
        RebuildPreconditionerLabel->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "Rebuild Preconditioner:", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechNonlinearSolverSetupUI", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechNonlinearSolverSetupUI: public Ui_QtArteryTechNonlinearSolverSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHNONLINEARSOLVERSETUPUI_H
