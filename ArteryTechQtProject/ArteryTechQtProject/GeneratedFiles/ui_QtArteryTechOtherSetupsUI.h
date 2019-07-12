/********************************************************************************
** Form generated from reading UI file 'QtArteryTechOtherSetupsUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHOTHERSETUPSUI_H
#define UI_QTARTERYTECHOTHERSETUPSUI_H

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

class Ui_QtArteryTechOtherSetupsUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *InitialNumberOfPartitionLabel;
    QLineEdit *InitialNumberOfPartitionLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TypeOfPartitionerLabel;
    QLineEdit *TypeOfPartitionerLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *DiagnalScalerLabel;
    QLineEdit *DiagnalScalerLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *PointBlockSolverLabel;
    QLineEdit *PointBlockSolverLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LogSummaryLabel;
    QLineEdit *LogSummaryLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *OKPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechOtherSetupsUI)
    {
        if (QtArteryTechOtherSetupsUI->objectName().isEmpty())
            QtArteryTechOtherSetupsUI->setObjectName(QStringLiteral("QtArteryTechOtherSetupsUI"));
        QtArteryTechOtherSetupsUI->resize(235, 185);
        verticalLayout_2 = new QVBoxLayout(QtArteryTechOtherSetupsUI);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        InitialNumberOfPartitionLabel = new QLabel(QtArteryTechOtherSetupsUI);
        InitialNumberOfPartitionLabel->setObjectName(QStringLiteral("InitialNumberOfPartitionLabel"));

        horizontalLayout->addWidget(InitialNumberOfPartitionLabel);

        InitialNumberOfPartitionLineEdit = new QLineEdit(QtArteryTechOtherSetupsUI);
        InitialNumberOfPartitionLineEdit->setObjectName(QStringLiteral("InitialNumberOfPartitionLineEdit"));

        horizontalLayout->addWidget(InitialNumberOfPartitionLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TypeOfPartitionerLabel = new QLabel(QtArteryTechOtherSetupsUI);
        TypeOfPartitionerLabel->setObjectName(QStringLiteral("TypeOfPartitionerLabel"));

        horizontalLayout_2->addWidget(TypeOfPartitionerLabel);

        TypeOfPartitionerLineEdit = new QLineEdit(QtArteryTechOtherSetupsUI);
        TypeOfPartitionerLineEdit->setObjectName(QStringLiteral("TypeOfPartitionerLineEdit"));

        horizontalLayout_2->addWidget(TypeOfPartitionerLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DiagnalScalerLabel = new QLabel(QtArteryTechOtherSetupsUI);
        DiagnalScalerLabel->setObjectName(QStringLiteral("DiagnalScalerLabel"));

        horizontalLayout_3->addWidget(DiagnalScalerLabel);

        DiagnalScalerLineEdit = new QLineEdit(QtArteryTechOtherSetupsUI);
        DiagnalScalerLineEdit->setObjectName(QStringLiteral("DiagnalScalerLineEdit"));

        horizontalLayout_3->addWidget(DiagnalScalerLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        PointBlockSolverLabel = new QLabel(QtArteryTechOtherSetupsUI);
        PointBlockSolverLabel->setObjectName(QStringLiteral("PointBlockSolverLabel"));

        horizontalLayout_4->addWidget(PointBlockSolverLabel);

        PointBlockSolverLineEdit = new QLineEdit(QtArteryTechOtherSetupsUI);
        PointBlockSolverLineEdit->setObjectName(QStringLiteral("PointBlockSolverLineEdit"));

        horizontalLayout_4->addWidget(PointBlockSolverLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LogSummaryLabel = new QLabel(QtArteryTechOtherSetupsUI);
        LogSummaryLabel->setObjectName(QStringLiteral("LogSummaryLabel"));

        horizontalLayout_5->addWidget(LogSummaryLabel);

        LogSummaryLineEdit = new QLineEdit(QtArteryTechOtherSetupsUI);
        LogSummaryLineEdit->setObjectName(QStringLiteral("LogSummaryLineEdit"));

        horizontalLayout_5->addWidget(LogSummaryLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        OKPushButton = new QPushButton(QtArteryTechOtherSetupsUI);
        OKPushButton->setObjectName(QStringLiteral("OKPushButton"));

        horizontalLayout_6->addWidget(OKPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechOtherSetupsUI);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_6->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtArteryTechOtherSetupsUI);

        QMetaObject::connectSlotsByName(QtArteryTechOtherSetupsUI);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechOtherSetupsUI)
    {
        QtArteryTechOtherSetupsUI->setWindowTitle(QApplication::translate("QtArteryTechOtherSetupsUI", "QtArteryTechOtherSetupsUI", Q_NULLPTR));
        InitialNumberOfPartitionLabel->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Initial Number of Partition:", Q_NULLPTR));
        TypeOfPartitionerLabel->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Type of Partitioner:", Q_NULLPTR));
        DiagnalScalerLabel->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Diagnal Scaler:", Q_NULLPTR));
        PointBlockSolverLabel->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Point Block Solver:", Q_NULLPTR));
        LogSummaryLabel->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Log Summary:", Q_NULLPTR));
        OKPushButton->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechOtherSetupsUI", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechOtherSetupsUI: public Ui_QtArteryTechOtherSetupsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHOTHERSETUPSUI_H
