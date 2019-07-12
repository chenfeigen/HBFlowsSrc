/********************************************************************************
** Form generated from reading UI file 'RetrievePasswordInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVEPASSWORDINTERFACE_H
#define UI_RETRIEVEPASSWORDINTERFACE_H

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

class Ui_RetrievePasswordInterface
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
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ConfirmPushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *RetrievePasswordInterface)
    {
        if (RetrievePasswordInterface->objectName().isEmpty())
            RetrievePasswordInterface->setObjectName(QStringLiteral("RetrievePasswordInterface"));
        RetrievePasswordInterface->resize(516, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("images/ArteryTech.ico"), QSize(), QIcon::Normal, QIcon::Off);
        RetrievePasswordInterface->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(RetrievePasswordInterface);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BackgroundLabel = new QLabel(RetrievePasswordInterface);
        BackgroundLabel->setObjectName(QStringLiteral("BackgroundLabel"));

        verticalLayout->addWidget(BackgroundLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UsernameLabel = new QLabel(RetrievePasswordInterface);
        UsernameLabel->setObjectName(QStringLiteral("UsernameLabel"));

        horizontalLayout->addWidget(UsernameLabel);

        UsernameLineEdit = new QLineEdit(RetrievePasswordInterface);
        UsernameLineEdit->setObjectName(QStringLiteral("UsernameLineEdit"));

        horizontalLayout->addWidget(UsernameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PasswordLabel = new QLabel(RetrievePasswordInterface);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        horizontalLayout_2->addWidget(PasswordLabel);

        PasswordLineEdit = new QLineEdit(RetrievePasswordInterface);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        horizontalLayout_2->addWidget(PasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ConfirmPushButton = new QPushButton(RetrievePasswordInterface);
        ConfirmPushButton->setObjectName(QStringLiteral("ConfirmPushButton"));

        horizontalLayout_4->addWidget(ConfirmPushButton);

        CancelPushButton = new QPushButton(RetrievePasswordInterface);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_4->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RetrievePasswordInterface);

        QMetaObject::connectSlotsByName(RetrievePasswordInterface);
    } // setupUi

    void retranslateUi(QDialog *RetrievePasswordInterface)
    {
        RetrievePasswordInterface->setWindowTitle(QApplication::translate("RetrievePasswordInterface", "RetrievePasswordInterface", Q_NULLPTR));
        BackgroundLabel->setText(QString());
        UsernameLabel->setText(QApplication::translate("RetrievePasswordInterface", "Number\357\274\232", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("RetrievePasswordInterface", "Password\357\274\232", Q_NULLPTR));
        ConfirmPushButton->setText(QApplication::translate("RetrievePasswordInterface", "Confirm", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("RetrievePasswordInterface", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RetrievePasswordInterface: public Ui_RetrievePasswordInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVEPASSWORDINTERFACE_H
