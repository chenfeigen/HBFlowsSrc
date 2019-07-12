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
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *PreconditionerTypeLabel;
    QLineEdit *PreconditionerTypeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *ASMTypeLabel;
    QLineEdit *ASMTypeLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *SubdomainSolverLabel;
    QLineEdit *SubdomainSolverLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *ILULevelsLabel;
    QLineEdit *ILULevelsLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *SubdomainMatrixOrderingTypeLabel;
    QLineEdit *SubdomainMatrixOrderingTypeLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *OverlappingTypeLabel;
    QLineEdit *OverlappingTypeLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLabel *OverlappingSizeLabel;
    QLineEdit *OverlappingSizeLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OKPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechPreconditionerSetupUI)
    {
        if (QtArteryTechPreconditionerSetupUI->objectName().isEmpty())
            QtArteryTechPreconditionerSetupUI->setObjectName(QStringLiteral("QtArteryTechPreconditionerSetupUI"));
        QtArteryTechPreconditionerSetupUI->resize(610, 211);
        verticalLayout_9 = new QVBoxLayout(QtArteryTechPreconditionerSetupUI);
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
        label = new QLabel(QtArteryTechPreconditionerSetupUI);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        PreconditionerTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        PreconditionerTypeLabel->setObjectName(QStringLiteral("PreconditionerTypeLabel"));

        verticalLayout->addWidget(PreconditionerTypeLabel);


        horizontalLayout->addLayout(verticalLayout);

        PreconditionerTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        PreconditionerTypeLineEdit->setObjectName(QStringLiteral("PreconditionerTypeLineEdit"));

        horizontalLayout->addWidget(PreconditionerTypeLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        ASMTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        ASMTypeLabel->setObjectName(QStringLiteral("ASMTypeLabel"));

        verticalLayout_2->addWidget(ASMTypeLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);

        ASMTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        ASMTypeLineEdit->setObjectName(QStringLiteral("ASMTypeLineEdit"));

        horizontalLayout_2->addWidget(ASMTypeLineEdit);


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
        label_3 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        SubdomainSolverLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        SubdomainSolverLabel->setObjectName(QStringLiteral("SubdomainSolverLabel"));

        verticalLayout_3->addWidget(SubdomainSolverLabel);


        horizontalLayout_3->addLayout(verticalLayout_3);

        SubdomainSolverLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        SubdomainSolverLineEdit->setObjectName(QStringLiteral("SubdomainSolverLineEdit"));

        horizontalLayout_3->addWidget(SubdomainSolverLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        ILULevelsLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        ILULevelsLabel->setObjectName(QStringLiteral("ILULevelsLabel"));

        verticalLayout_4->addWidget(ILULevelsLabel);


        horizontalLayout_4->addLayout(verticalLayout_4);

        ILULevelsLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        ILULevelsLineEdit->setObjectName(QStringLiteral("ILULevelsLineEdit"));

        horizontalLayout_4->addWidget(ILULevelsLineEdit);


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
        label_5 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        SubdomainMatrixOrderingTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        SubdomainMatrixOrderingTypeLabel->setObjectName(QStringLiteral("SubdomainMatrixOrderingTypeLabel"));

        verticalLayout_5->addWidget(SubdomainMatrixOrderingTypeLabel);


        horizontalLayout_5->addLayout(verticalLayout_5);

        SubdomainMatrixOrderingTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        SubdomainMatrixOrderingTypeLineEdit->setObjectName(QStringLiteral("SubdomainMatrixOrderingTypeLineEdit"));

        horizontalLayout_5->addWidget(SubdomainMatrixOrderingTypeLineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        OverlappingTypeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        OverlappingTypeLabel->setObjectName(QStringLiteral("OverlappingTypeLabel"));

        verticalLayout_6->addWidget(OverlappingTypeLabel);


        horizontalLayout_6->addLayout(verticalLayout_6);

        OverlappingTypeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        OverlappingTypeLineEdit->setObjectName(QStringLiteral("OverlappingTypeLineEdit"));

        horizontalLayout_6->addWidget(OverlappingTypeLineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_7 = new QLabel(QtArteryTechPreconditionerSetupUI);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);

        OverlappingSizeLabel = new QLabel(QtArteryTechPreconditionerSetupUI);
        OverlappingSizeLabel->setObjectName(QStringLiteral("OverlappingSizeLabel"));

        verticalLayout_7->addWidget(OverlappingSizeLabel);


        horizontalLayout_7->addLayout(verticalLayout_7);

        OverlappingSizeLineEdit = new QLineEdit(QtArteryTechPreconditionerSetupUI);
        OverlappingSizeLineEdit->setObjectName(QStringLiteral("OverlappingSizeLineEdit"));

        horizontalLayout_7->addWidget(OverlappingSizeLineEdit);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        OKPushButton = new QPushButton(QtArteryTechPreconditionerSetupUI);
        OKPushButton->setObjectName(QStringLiteral("OKPushButton"));

        horizontalLayout_8->addWidget(OKPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechPreconditionerSetupUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_8->addWidget(CancelPushButton);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_9->addLayout(verticalLayout_8);


        retranslateUi(QtArteryTechPreconditionerSetupUI);

        QMetaObject::connectSlotsByName(QtArteryTechPreconditionerSetupUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechPreconditionerSetupUI)
    {
        QtArteryTechPreconditionerSetupUI->setWindowTitle(QApplication::translate("QtArteryTechPreconditionerSetupUI", "QtArteryTechPreconditionerSetupUI", Q_NULLPTR));
        label->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\351\242\204\345\244\204\347\220\206\347\261\273\345\236\213", Q_NULLPTR));
        PreconditionerTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Preconditioner Type:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ASM\347\261\273\345\236\213", Q_NULLPTR));
        ASMTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ASM Type:", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\345\255\220\345\237\237\346\261\202\350\247\243\345\231\250", Q_NULLPTR));
        SubdomainSolverLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Subdomain Solver:", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ILU\345\241\253\345\205\205\346\260\264\345\271\263", Q_NULLPTR));
        ILULevelsLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "ILU Levels:", Q_NULLPTR));
        label_5->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\345\255\220\345\214\272\345\237\237\347\237\251\351\230\265\346\216\222\345\272\217\347\261\273\345\236\213", Q_NULLPTR));
        SubdomainMatrixOrderingTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Subdomain Matrix Ordering Type:", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\351\207\215\345\217\240\347\261\273\345\236\213", Q_NULLPTR));
        OverlappingTypeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Overlapping Type:", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\351\207\215\345\217\240\345\261\202\346\225\260", Q_NULLPTR));
        OverlappingSizeLabel->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "Overlapping Size:", Q_NULLPTR));
        OKPushButton->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechPreconditionerSetupUI", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechPreconditionerSetupUI: public Ui_QtArteryTechPreconditionerSetupUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHPRECONDITIONERSETUPUI_H
