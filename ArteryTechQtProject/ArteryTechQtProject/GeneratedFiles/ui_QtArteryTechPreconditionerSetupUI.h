/********************************************************************************
** Form generated from reading UI file 'QtArteryTechPreconditionerSetupUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHPRECONDITIONERSETUPUI_H
#define UI_QTARTERYTECHPRECONDITIONERSETUPUI_H

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

class Ui_QtArteryTechPreconditionerSetupUI
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *PreconditionerTypeLabel;
    QLineEdit *PreconditionerTypeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ASMTypeLabel;
    QLineEdit *ASMTypeLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *SubdomainSolverLabel;
    QLineEdit *SubdomainSolverLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *ILULevelsLabel;
    QLineEdit *ILULevelsLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *SubdomainMatrixOrderingTypeLabel;
    QLineEdit *SubdomainMatrixOrderingTypeLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *OverlappingTypeLabel;
    QLineEdit *OverlappingTypeLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *OverlappingSizeLabel;
    QLineEdit *OverlappingSizeLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *OKPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechPreconditionerSetupUI)
    {
        if (QtArteryTechPreconditionerSetupUI->objectName().isEmpty())
            QtArteryTechPreconditionerSetupUI->setObjectName(QStringLiteral("QtArteryTechPreconditionerSetupUI"));
        QtArteryTechPreconditionerSetupUI->resize(255, 243);
        verticalLayout_3 = new QVBoxLayout(QtArteryTechPreconditionerSetupUI);
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
        PreconditionerTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        PreconditionerTypeLabel->setObjectName(QStringLiteral("PreconditionerTypeLabel"));

        horizontalLayout->addWidget(PreconditionerTypeLabel);

        PreconditionerTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        PreconditionerTypeLineEdit->setObjectName(QStringLiteral("PreconditionerTypeLineEdit"));

        horizontalLayout->addWidget(PreconditionerTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ASMTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        ASMTypeLabel->setObjectName(QStringLiteral("ASMTypeLabel"));

        horizontalLayout_2->addWidget(ASMTypeLabel);

        ASMTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        ASMTypeLineEdit->setObjectName(QStringLiteral("ASMTypeLineEdit"));

        horizontalLayout_2->addWidget(ASMTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        SubdomainSolverLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        SubdomainSolverLabel->setObjectName(QStringLiteral("SubdomainSolverLabel"));

        horizontalLayout_4->addWidget(SubdomainSolverLabel);

        SubdomainSolverLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        SubdomainSolverLineEdit->setObjectName(QStringLiteral("SubdomainSolverLineEdit"));

        horizontalLayout_4->addWidget(SubdomainSolverLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ILULevelsLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        ILULevelsLabel->setObjectName(QStringLiteral("ILULevelsLabel"));

        horizontalLayout_5->addWidget(ILULevelsLabel);

        ILULevelsLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        ILULevelsLineEdit->setObjectName(QStringLiteral("ILULevelsLineEdit"));

        horizontalLayout_5->addWidget(ILULevelsLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        SubdomainMatrixOrderingTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        SubdomainMatrixOrderingTypeLabel->setObjectName(QStringLiteral("SubdomainMatrixOrderingTypeLabel"));

        horizontalLayout_6->addWidget(SubdomainMatrixOrderingTypeLabel);

        SubdomainMatrixOrderingTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        SubdomainMatrixOrderingTypeLineEdit->setObjectName(QStringLiteral("SubdomainMatrixOrderingTypeLineEdit"));

        horizontalLayout_6->addWidget(SubdomainMatrixOrderingTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        OverlappingTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        OverlappingTypeLabel->setObjectName(QStringLiteral("OverlappingTypeLabel"));

        horizontalLayout_7->addWidget(OverlappingTypeLabel);

        OverlappingTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        OverlappingTypeLineEdit->setObjectName(QStringLiteral("OverlappingTypeLineEdit"));

        horizontalLayout_7->addWidget(OverlappingTypeLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        OverlappingSizeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        OverlappingSizeLabel->setObjectName(QStringLiteral("OverlappingSizeLabel"));

        horizontalLayout_8->addWidget(OverlappingSizeLabel);

        OverlappingSizeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        OverlappingSizeLineEdit->setObjectName(QStringLiteral("OverlappingSizeLineEdit"));

        horizontalLayout_8->addWidget(OverlappingSizeLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        OKPushButton = new QPushButton(QtArteryTechPreconditionerSetupUI);
        OKPushButton->setObjectName(QStringLiteral("OKPushButton"));

        horizontalLayout_3->addWidget(OKPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechPreconditionerSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_3->addWidget(CancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(QtArteryTechPreconditionerSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechPreconditionerSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechPreconditionerSetupUI)
    {
        QtArteryTechPreconditionerSetupUI->setWindowTitle(QApplication::translate("QtArteryTechPreconditionerSetupUI", "QtArteryTechPreconditionerSetupUI", Q_NULLPTR));
        PreconditionerTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Preconditioner Type:", Q_NULLPTR));
        ASMTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ASM Type:", Q_NULLPTR));
        SubdomainSolverLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Subdomain Solver:", Q_NULLPTR));
        ILULevelsLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ILU Levels:", Q_NULLPTR));
        SubdomainMatrixOrderingTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Subdomain Matrix Ordering Type:", Q_NULLPTR));
        OverlappingTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Overlapping Type:", Q_NULLPTR));
        OverlappingSizeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Overlapping Size:", Q_NULLPTR));
        OKPushButton->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechPreconditionerSetupUI: public Ui_QtArteryTechPreconditionerSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHPRECONDITIONERSETUPUI_H
