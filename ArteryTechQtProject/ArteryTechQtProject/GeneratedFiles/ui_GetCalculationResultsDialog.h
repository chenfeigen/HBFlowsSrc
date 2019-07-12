/********************************************************************************
** Form generated from reading UI file 'GetCalculationResultsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCALCULATIONRESULTSDIALOG_H
#define UI_GETCALCULATIONRESULTSDIALOG_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GetCalculationResultsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *FileNameLabel;
    QLineEdit *FileNameLineEdit;
    QPushButton *InputFilePushButton;
    QPushButton *GetResultPushButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ResultLabel;
    QSpacerItem *horizontalSpacer;
    QTextEdit *ResultTextEdit;

    void setupUi(QDialog *GetCalculationResultsDialog)
    {
        if (GetCalculationResultsDialog->objectName().isEmpty())
            GetCalculationResultsDialog->setObjectName(QStringLiteral("GetCalculationResultsDialog"));
        GetCalculationResultsDialog->resize(931, 716);
        verticalLayout_3 = new QVBoxLayout(GetCalculationResultsDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        FileNameLabel = new QLabel(GetCalculationResultsDialog);
        FileNameLabel->setObjectName(QStringLiteral("FileNameLabel"));

        horizontalLayout->addWidget(FileNameLabel);

        FileNameLineEdit = new QLineEdit(GetCalculationResultsDialog);
        FileNameLineEdit->setObjectName(QStringLiteral("FileNameLineEdit"));

        horizontalLayout->addWidget(FileNameLineEdit);

        InputFilePushButton = new QPushButton(GetCalculationResultsDialog);
        InputFilePushButton->setObjectName(QStringLiteral("InputFilePushButton"));

        horizontalLayout->addWidget(InputFilePushButton);

        GetResultPushButton = new QPushButton(GetCalculationResultsDialog);
        GetResultPushButton->setObjectName(QStringLiteral("GetResultPushButton"));

        horizontalLayout->addWidget(GetResultPushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ResultLabel = new QLabel(GetCalculationResultsDialog);
        ResultLabel->setObjectName(QStringLiteral("ResultLabel"));

        horizontalLayout_2->addWidget(ResultLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        ResultTextEdit = new QTextEdit(GetCalculationResultsDialog);
        ResultTextEdit->setObjectName(QStringLiteral("ResultTextEdit"));

        verticalLayout->addWidget(ResultTextEdit);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(GetCalculationResultsDialog);

        QMetaObject::connectSlotsByName(GetCalculationResultsDialog);
    } // setupUi

    void retranslateUi(QDialog *GetCalculationResultsDialog)
    {
        GetCalculationResultsDialog->setWindowTitle(QApplication::translate("GetCalculationResultsDialog", "GetCalculationResultsDialog", Q_NULLPTR));
        FileNameLabel->setText(QApplication::translate("GetCalculationResultsDialog", "\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        InputFilePushButton->setText(QApplication::translate("GetCalculationResultsDialog", "\350\276\223\345\205\245\346\226\207\344\273\266", Q_NULLPTR));
        GetResultPushButton->setText(QApplication::translate("GetCalculationResultsDialog", "\350\216\267\345\217\226\347\273\223\346\236\234", Q_NULLPTR));
        ResultLabel->setText(QApplication::translate("GetCalculationResultsDialog", "\347\273\223\346\236\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GetCalculationResultsDialog: public Ui_GetCalculationResultsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCALCULATIONRESULTSDIALOG_H
