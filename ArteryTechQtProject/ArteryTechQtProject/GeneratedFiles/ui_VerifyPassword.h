/********************************************************************************
** Form generated from reading UI file 'VerifyPassword.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYPASSWORD_H
#define UI_VERIFYPASSWORD_H

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

class Ui_VerifyPassword
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ConfirmPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *VerifyPassword)
    {
        if (VerifyPassword->objectName().isEmpty())
            VerifyPassword->setObjectName(QStringLiteral("VerifyPassword"));
        VerifyPassword->resize(359, 73);
        verticalLayout_2 = new QVBoxLayout(VerifyPassword);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PasswordLabel = new QLabel(VerifyPassword);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        horizontalLayout->addWidget(PasswordLabel);

        PasswordLineEdit = new QLineEdit(VerifyPassword);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        horizontalLayout->addWidget(PasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ConfirmPushButton = new QPushButton(VerifyPassword);
        ConfirmPushButton->setObjectName(QStringLiteral("ConfirmPushButton"));

        horizontalLayout_2->addWidget(ConfirmPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(VerifyPassword);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_2->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(VerifyPassword);

        QMetaObject::connectSlotsByName(VerifyPassword);
    } // setupUi

    void retranslateUi(QDialog *VerifyPassword)
    {
        VerifyPassword->setWindowTitle(QApplication::translate("VerifyPassword", "VerifyPassword", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("VerifyPassword", "\345\257\206\347\240\201:", Q_NULLPTR));
        ConfirmPushButton->setText(QApplication::translate("VerifyPassword", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("VerifyPassword", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VerifyPassword: public Ui_VerifyPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYPASSWORD_H
