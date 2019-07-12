/********************************************************************************
** Form generated from reading UI file 'QtTcpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTCPCLIENT_H
#define UI_QTTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTcpClient
{
public:

    void setupUi(QWidget *QtTcpClient)
    {
        if (QtTcpClient->objectName().isEmpty())
            QtTcpClient->setObjectName(QStringLiteral("QtTcpClient"));
        QtTcpClient->resize(400, 300);

        retranslateUi(QtTcpClient);

        QMetaObject::connectSlotsByName(QtTcpClient);
    } // setupUi

    void retranslateUi(QWidget *QtTcpClient)
    {
        QtTcpClient->setWindowTitle(QApplication::translate("QtTcpClient", "QtTcpClient", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtTcpClient: public Ui_QtTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTCPCLIENT_H
