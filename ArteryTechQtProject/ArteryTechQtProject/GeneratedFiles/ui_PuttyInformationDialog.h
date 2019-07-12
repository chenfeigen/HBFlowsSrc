/********************************************************************************
** Form generated from reading UI file 'PuttyInformationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUTTYINFORMATIONDIALOG_H
#define UI_PUTTYINFORMATIONDIALOG_H

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

class Ui_PuttyInformationDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Usernamelabel;
    QLineEdit *UsernamelineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Passwordlabel;
    QLineEdit *PasswordlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *IPlabel;
    QLineEdit *IPlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Portlabel;
    QLineEdit *PortlineEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *ConfirmpushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelpushButton;

    void setupUi(QDialog *PuttyInformationDialog)
    {
        if (PuttyInformationDialog->objectName().isEmpty())
            PuttyInformationDialog->setObjectName(QStringLiteral("PuttyInformationDialog"));
        PuttyInformationDialog->resize(290, 173);
        verticalLayout_2 = new QVBoxLayout(PuttyInformationDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Usernamelabel = new QLabel(PuttyInformationDialog);
        Usernamelabel->setObjectName(QStringLiteral("Usernamelabel"));

        horizontalLayout->addWidget(Usernamelabel);

        UsernamelineEdit = new QLineEdit(PuttyInformationDialog);
        UsernamelineEdit->setObjectName(QStringLiteral("UsernamelineEdit"));

        horizontalLayout->addWidget(UsernamelineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Passwordlabel = new QLabel(PuttyInformationDialog);
        Passwordlabel->setObjectName(QStringLiteral("Passwordlabel"));

        horizontalLayout_2->addWidget(Passwordlabel);

        PasswordlineEdit = new QLineEdit(PuttyInformationDialog);
        PasswordlineEdit->setObjectName(QStringLiteral("PasswordlineEdit"));

        horizontalLayout_2->addWidget(PasswordlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        IPlabel = new QLabel(PuttyInformationDialog);
        IPlabel->setObjectName(QStringLiteral("IPlabel"));

        horizontalLayout_3->addWidget(IPlabel);

        IPlineEdit = new QLineEdit(PuttyInformationDialog);
        IPlineEdit->setObjectName(QStringLiteral("IPlineEdit"));

        horizontalLayout_3->addWidget(IPlineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Portlabel = new QLabel(PuttyInformationDialog);
        Portlabel->setObjectName(QStringLiteral("Portlabel"));

        horizontalLayout_4->addWidget(Portlabel);

        PortlineEdit = new QLineEdit(PuttyInformationDialog);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));

        horizontalLayout_4->addWidget(PortlineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ConfirmpushButton = new QPushButton(PuttyInformationDialog);
        ConfirmpushButton->setObjectName(QStringLiteral("ConfirmpushButton"));

        horizontalLayout_5->addWidget(ConfirmpushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        CancelpushButton = new QPushButton(PuttyInformationDialog);
        CancelpushButton->setObjectName(QStringLiteral("CancelpushButton"));

        horizontalLayout_5->addWidget(CancelpushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PuttyInformationDialog);

        QMetaObject::connectSlotsByName(PuttyInformationDialog);
    } // setupUi

    void retranslateUi(QDialog *PuttyInformationDialog)
    {
        PuttyInformationDialog->setWindowTitle(QApplication::translate("PuttyInformationDialog", "PuttyInformationDialog", Q_NULLPTR));
        Usernamelabel->setText(QApplication::translate("PuttyInformationDialog", "Username:", Q_NULLPTR));
        Passwordlabel->setText(QApplication::translate("PuttyInformationDialog", "Password:", Q_NULLPTR));
        IPlabel->setText(QApplication::translate("PuttyInformationDialog", "IP:", Q_NULLPTR));
        Portlabel->setText(QApplication::translate("PuttyInformationDialog", "Port:", Q_NULLPTR));
        ConfirmpushButton->setText(QApplication::translate("PuttyInformationDialog", "Confirm", Q_NULLPTR));
        CancelpushButton->setText(QApplication::translate("PuttyInformationDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PuttyInformationDialog: public Ui_PuttyInformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUTTYINFORMATIONDIALOG_H
