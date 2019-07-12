/********************************************************************************
** Form generated from reading UI file 'SshClient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSHCLIENT_H
#define UI_SSHCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SshClient
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *SshClient)
    {
        if (SshClient->objectName().isEmpty())
            SshClient->setObjectName(QStringLiteral("SshClient"));
        SshClient->resize(768, 726);
        verticalLayout_3 = new QVBoxLayout(SshClient);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(SshClient);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SshClient);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout->addWidget(textEdit_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_2);


        retranslateUi(SshClient);

        QMetaObject::connectSlotsByName(SshClient);
    } // setupUi

    void retranslateUi(QDialog *SshClient)
    {
        SshClient->setWindowTitle(QApplication::translate("SshClient", "SshClient", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SshClient", "Get result:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SshClient", "Send cmd:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SshClient: public Ui_SshClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHCLIENT_H
