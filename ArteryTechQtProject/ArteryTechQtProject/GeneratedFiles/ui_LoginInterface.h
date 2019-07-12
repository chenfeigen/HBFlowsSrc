/********************************************************************************
** Form generated from reading UI file 'LoginInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGININTERFACE_H
#define UI_LOGININTERFACE_H

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

class Ui_LoginInterface
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
    QPushButton *RetrievePasswordPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *RegisterPushButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *LoginPushButton;

    void setupUi(QDialog *LoginInterface)
    {
        if (LoginInterface->objectName().isEmpty())
            LoginInterface->setObjectName(QStringLiteral("LoginInterface"));
        LoginInterface->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("images/ArteryTech.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginInterface->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(LoginInterface);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BackgroundLabel = new QLabel(LoginInterface);
        BackgroundLabel->setObjectName(QStringLiteral("BackgroundLabel"));

        verticalLayout->addWidget(BackgroundLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UsernameLabel = new QLabel(LoginInterface);
        UsernameLabel->setObjectName(QStringLiteral("UsernameLabel"));

        horizontalLayout->addWidget(UsernameLabel);

        UsernameLineEdit = new QLineEdit(LoginInterface);
        UsernameLineEdit->setObjectName(QStringLiteral("UsernameLineEdit"));

        horizontalLayout->addWidget(UsernameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PasswordLabel = new QLabel(LoginInterface);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        horizontalLayout_2->addWidget(PasswordLabel);

        PasswordLineEdit = new QLineEdit(LoginInterface);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        horizontalLayout_2->addWidget(PasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        RetrievePasswordPushButton = new QPushButton(LoginInterface);
        RetrievePasswordPushButton->setObjectName(QStringLiteral("RetrievePasswordPushButton"));

        horizontalLayout_3->addWidget(RetrievePasswordPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        RegisterPushButton = new QPushButton(LoginInterface);
        RegisterPushButton->setObjectName(QStringLiteral("RegisterPushButton"));

        horizontalLayout_3->addWidget(RegisterPushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LoginPushButton = new QPushButton(LoginInterface);
        LoginPushButton->setObjectName(QStringLiteral("LoginPushButton"));

        horizontalLayout_4->addWidget(LoginPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(UsernameLineEdit, PasswordLineEdit);
        QWidget::setTabOrder(PasswordLineEdit, LoginPushButton);
        QWidget::setTabOrder(LoginPushButton, RetrievePasswordPushButton);
        QWidget::setTabOrder(RetrievePasswordPushButton, RegisterPushButton);

        retranslateUi(LoginInterface);

        QMetaObject::connectSlotsByName(LoginInterface);
    } // setupUi

    void retranslateUi(QDialog *LoginInterface)
    {
        LoginInterface->setWindowTitle(QApplication::translate("LoginInterface", "LoginInterface", Q_NULLPTR));
        BackgroundLabel->setText(QString());
        UsernameLabel->setText(QApplication::translate("LoginInterface", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("LoginInterface", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        RetrievePasswordPushButton->setText(QApplication::translate("LoginInterface", "\345\257\206\347\240\201\346\211\276\345\233\236", Q_NULLPTR));
        RegisterPushButton->setText(QApplication::translate("LoginInterface", "\346\263\250\345\206\214", Q_NULLPTR));
        LoginPushButton->setText(QApplication::translate("LoginInterface", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginInterface: public Ui_LoginInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGININTERFACE_H
