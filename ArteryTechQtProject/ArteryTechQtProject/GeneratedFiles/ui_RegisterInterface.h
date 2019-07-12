/********************************************************************************
** Form generated from reading UI file 'RegisterInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERINTERFACE_H
#define UI_REGISTERINTERFACE_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterInterface
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *BackgroundLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *UsernameLabel;
    QLineEdit *UsernameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PasswordLabel2;
    QLineEdit *PasswordLineEdit2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ConfirmPushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *RegisterInterface)
    {
        if (RegisterInterface->objectName().isEmpty())
            RegisterInterface->setObjectName(QStringLiteral("RegisterInterface"));
        RegisterInterface->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("images/ArteryTech.ico"), QSize(), QIcon::Normal, QIcon::Off);
        RegisterInterface->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(RegisterInterface);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BackgroundLabel = new QLabel(RegisterInterface);
        BackgroundLabel->setObjectName(QStringLiteral("BackgroundLabel"));

        verticalLayout->addWidget(BackgroundLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UsernameLabel = new QLabel(RegisterInterface);
        UsernameLabel->setObjectName(QStringLiteral("UsernameLabel"));

        horizontalLayout->addWidget(UsernameLabel);

        UsernameLineEdit = new QLineEdit(RegisterInterface);
        UsernameLineEdit->setObjectName(QStringLiteral("UsernameLineEdit"));

        horizontalLayout->addWidget(UsernameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PasswordLabel = new QLabel(RegisterInterface);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        horizontalLayout_2->addWidget(PasswordLabel);

        PasswordLineEdit = new QLineEdit(RegisterInterface);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        horizontalLayout_2->addWidget(PasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PasswordLabel2 = new QLabel(RegisterInterface);
        PasswordLabel2->setObjectName(QStringLiteral("PasswordLabel2"));

        horizontalLayout_3->addWidget(PasswordLabel2);

        PasswordLineEdit2 = new QLineEdit(RegisterInterface);
        PasswordLineEdit2->setObjectName(QStringLiteral("PasswordLineEdit2"));

        horizontalLayout_3->addWidget(PasswordLineEdit2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ConfirmPushButton = new QPushButton(RegisterInterface);
        ConfirmPushButton->setObjectName(QStringLiteral("ConfirmPushButton"));

        horizontalLayout_4->addWidget(ConfirmPushButton);

        CancelPushButton = new QPushButton(RegisterInterface);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_4->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterInterface);

        QMetaObject::connectSlotsByName(RegisterInterface);
    } // setupUi

    void retranslateUi(QDialog *RegisterInterface)
    {
        RegisterInterface->setWindowTitle(QApplication::translate("RegisterInterface", "RegisterInterface", Q_NULLPTR));
        BackgroundLabel->setText(QString());
        UsernameLabel->setText(QApplication::translate("RegisterInterface", "Number\357\274\232", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("RegisterInterface", "Password\357\274\232", Q_NULLPTR));
        PasswordLabel2->setText(QApplication::translate("RegisterInterface", "Password Again\357\274\232", Q_NULLPTR));
        ConfirmPushButton->setText(QApplication::translate("RegisterInterface", "Confirm", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("RegisterInterface", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterInterface: public Ui_RegisterInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERINTERFACE_H
