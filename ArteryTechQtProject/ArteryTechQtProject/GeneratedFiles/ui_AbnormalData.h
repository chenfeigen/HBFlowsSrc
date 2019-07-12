/********************************************************************************
** Form generated from reading UI file 'AbnormalData.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABNORMALDATA_H
#define UI_ABNORMALDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AbnormalData
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *AbnormalData)
    {
        if (AbnormalData->objectName().isEmpty())
            AbnormalData->setObjectName(QStringLiteral("AbnormalData"));
        AbnormalData->resize(830, 602);
        verticalLayout = new QVBoxLayout(AbnormalData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(AbnormalData);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(AbnormalData);

        QMetaObject::connectSlotsByName(AbnormalData);
    } // setupUi

    void retranslateUi(QDialog *AbnormalData)
    {
        AbnormalData->setWindowTitle(QApplication::translate("AbnormalData", "AbnormalData", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AbnormalData: public Ui_AbnormalData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABNORMALDATA_H
