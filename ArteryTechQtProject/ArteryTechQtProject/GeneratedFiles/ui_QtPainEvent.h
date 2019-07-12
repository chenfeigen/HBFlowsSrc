/********************************************************************************
** Form generated from reading UI file 'QtPainEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPAINEVENT_H
#define UI_QTPAINEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtPainEvent
{
public:
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QVTKWidget *qvtkWidget;
    QVTKWidget *qvtkWidget_2;
    QVTKWidget *qvtkWidget_3;
    QVTKWidget *qvtkWidget_4;

    void setupUi(QWidget *QtPainEvent)
    {
        if (QtPainEvent->objectName().isEmpty())
            QtPainEvent->setObjectName(QStringLiteral("QtPainEvent"));
        QtPainEvent->resize(763, 728);
        verticalLayout_4 = new QVBoxLayout(QtPainEvent);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qvtkWidget = new QVTKWidget(QtPainEvent);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        gridLayout->addWidget(qvtkWidget, 0, 0, 1, 1);

        qvtkWidget_2 = new QVTKWidget(QtPainEvent);
        qvtkWidget_2->setObjectName(QStringLiteral("qvtkWidget_2"));

        gridLayout->addWidget(qvtkWidget_2, 0, 1, 1, 1);

        qvtkWidget_3 = new QVTKWidget(QtPainEvent);
        qvtkWidget_3->setObjectName(QStringLiteral("qvtkWidget_3"));

        gridLayout->addWidget(qvtkWidget_3, 1, 0, 1, 1);

        qvtkWidget_4 = new QVTKWidget(QtPainEvent);
        qvtkWidget_4->setObjectName(QStringLiteral("qvtkWidget_4"));

        gridLayout->addWidget(qvtkWidget_4, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        retranslateUi(QtPainEvent);

        QMetaObject::connectSlotsByName(QtPainEvent);
    } // setupUi

    void retranslateUi(QWidget *QtPainEvent)
    {
        QtPainEvent->setWindowTitle(QApplication::translate("QtPainEvent", "QtPainEvent", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtPainEvent: public Ui_QtPainEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPAINEVENT_H
