/********************************************************************************
** Form generated from reading UI file 'TcpClientDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENTDIALOG_H
#define UI_TCPCLIENTDIALOG_H

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

class Ui_TcpClientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *serverIplabel;
    QLineEdit *iplineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *portlabel;
    QLineEdit *portlineEdit;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *userNamelabel;
    QLineEdit *userNamelineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *passWordlabel;
    QLineEdit *passWordlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *inputlabel;
    QLineEdit *inputfilelineEdit;
    QPushButton *inputpushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *outputlabel;
    QLineEdit *outputlineEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *connectcomputepushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectsshpushButton;

    void setupUi(QDialog *TcpClientDialog)
    {
        if (TcpClientDialog->objectName().isEmpty())
            TcpClientDialog->setObjectName(QStringLiteral("TcpClientDialog"));
        TcpClientDialog->resize(605, 182);
        verticalLayout = new QVBoxLayout(TcpClientDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        serverIplabel = new QLabel(TcpClientDialog);
        serverIplabel->setObjectName(QStringLiteral("serverIplabel"));

        horizontalLayout_2->addWidget(serverIplabel);

        iplineEdit = new QLineEdit(TcpClientDialog);
        iplineEdit->setObjectName(QStringLiteral("iplineEdit"));

        horizontalLayout_2->addWidget(iplineEdit);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        portlabel = new QLabel(TcpClientDialog);
        portlabel->setObjectName(QStringLiteral("portlabel"));

        horizontalLayout->addWidget(portlabel);

        portlineEdit = new QLineEdit(TcpClientDialog);
        portlineEdit->setObjectName(QStringLiteral("portlineEdit"));

        horizontalLayout->addWidget(portlineEdit);


        horizontalLayout_5->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        userNamelabel = new QLabel(TcpClientDialog);
        userNamelabel->setObjectName(QStringLiteral("userNamelabel"));

        horizontalLayout_7->addWidget(userNamelabel);

        userNamelineEdit = new QLineEdit(TcpClientDialog);
        userNamelineEdit->setObjectName(QStringLiteral("userNamelineEdit"));

        horizontalLayout_7->addWidget(userNamelineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        passWordlabel = new QLabel(TcpClientDialog);
        passWordlabel->setObjectName(QStringLiteral("passWordlabel"));

        horizontalLayout_8->addWidget(passWordlabel);

        passWordlineEdit = new QLineEdit(TcpClientDialog);
        passWordlineEdit->setObjectName(QStringLiteral("passWordlineEdit"));

        horizontalLayout_8->addWidget(passWordlineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        inputlabel = new QLabel(TcpClientDialog);
        inputlabel->setObjectName(QStringLiteral("inputlabel"));

        horizontalLayout_3->addWidget(inputlabel);

        inputfilelineEdit = new QLineEdit(TcpClientDialog);
        inputfilelineEdit->setObjectName(QStringLiteral("inputfilelineEdit"));

        horizontalLayout_3->addWidget(inputfilelineEdit);

        inputpushButton = new QPushButton(TcpClientDialog);
        inputpushButton->setObjectName(QStringLiteral("inputpushButton"));
        inputpushButton->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));

        horizontalLayout_3->addWidget(inputpushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        outputlabel = new QLabel(TcpClientDialog);
        outputlabel->setObjectName(QStringLiteral("outputlabel"));

        horizontalLayout_4->addWidget(outputlabel);

        outputlineEdit = new QLineEdit(TcpClientDialog);
        outputlineEdit->setObjectName(QStringLiteral("outputlineEdit"));

        horizontalLayout_4->addWidget(outputlineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        connectcomputepushButton = new QPushButton(TcpClientDialog);
        connectcomputepushButton->setObjectName(QStringLiteral("connectcomputepushButton"));
        connectcomputepushButton->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));

        horizontalLayout_6->addWidget(connectcomputepushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        connectsshpushButton = new QPushButton(TcpClientDialog);
        connectsshpushButton->setObjectName(QStringLiteral("connectsshpushButton"));
        connectsshpushButton->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));

        horizontalLayout_6->addWidget(connectsshpushButton);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(TcpClientDialog);

        QMetaObject::connectSlotsByName(TcpClientDialog);
    } // setupUi

    void retranslateUi(QDialog *TcpClientDialog)
    {
        TcpClientDialog->setWindowTitle(QApplication::translate("TcpClientDialog", "TcpClientDialog", Q_NULLPTR));
        serverIplabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Server IP:</span></p></body></html>", Q_NULLPTR));
        iplineEdit->setText(QString());
        portlabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Port:</span></p></body></html>", Q_NULLPTR));
        portlineEdit->setText(QString());
        userNamelabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">userName\357\274\232</span></p></body></html>", Q_NULLPTR));
        passWordlabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">passWord:</span></p></body></html>", Q_NULLPTR));
        inputlabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Input Filename Path:</span></p></body></html>", Q_NULLPTR));
        inputpushButton->setText(QApplication::translate("TcpClientDialog", "Input", Q_NULLPTR));
        outputlabel->setText(QApplication::translate("TcpClientDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Output File Path:</span></p></body></html>", Q_NULLPTR));
        connectcomputepushButton->setText(QApplication::translate("TcpClientDialog", "connect", Q_NULLPTR));
        connectsshpushButton->setText(QApplication::translate("TcpClientDialog", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpClientDialog: public Ui_TcpClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENTDIALOG_H
