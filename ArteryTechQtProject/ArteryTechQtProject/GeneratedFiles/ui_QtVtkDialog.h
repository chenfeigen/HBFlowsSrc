/********************************************************************************
** Form generated from reading UI file 'QtVtkDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTVTKDIALOG_H
#define UI_QTVTKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtVtkDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVTKWidget *qvtkWidget;
    QVTKWidget *qvtkWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVTKWidget *qvtkWidget_3;
    QVTKWidget *qvtkWidget_4;

    void setupUi(QDialog *QtVtkDialog)
    {
        if (QtVtkDialog->objectName().isEmpty())
            QtVtkDialog->setObjectName(QStringLiteral("QtVtkDialog"));
        QtVtkDialog->resize(400, 493);
        verticalLayout_2 = new QVBoxLayout(QtVtkDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qvtkWidget = new QVTKWidget(QtVtkDialog);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        horizontalLayout->addWidget(qvtkWidget);

        qvtkWidget_2 = new QVTKWidget(QtVtkDialog);
        qvtkWidget_2->setObjectName(QStringLiteral("qvtkWidget_2"));

        horizontalLayout->addWidget(qvtkWidget_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qvtkWidget_3 = new QVTKWidget(QtVtkDialog);
        qvtkWidget_3->setObjectName(QStringLiteral("qvtkWidget_3"));

        horizontalLayout_2->addWidget(qvtkWidget_3);

        qvtkWidget_4 = new QVTKWidget(QtVtkDialog);
        qvtkWidget_4->setObjectName(QStringLiteral("qvtkWidget_4"));

        horizontalLayout_2->addWidget(qvtkWidget_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtVtkDialog);

        QMetaObject::connectSlotsByName(QtVtkDialog);
    } // setupUi

    void retranslateUi(QDialog *QtVtkDialog)
    {
        QtVtkDialog->setWindowTitle(QApplication::translate("QtVtkDialog", "QtVtkDialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtVtkDialog: public Ui_QtVtkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTVTKDIALOG_H
