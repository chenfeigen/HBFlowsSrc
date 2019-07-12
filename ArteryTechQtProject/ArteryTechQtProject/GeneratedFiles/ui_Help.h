/********************************************************************************
** Form generated from reading UI file 'Help.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *SoftwareName;
    QLabel *softwareNamelabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *TypeSpecificationName;
    QLabel *TypeSpecificationlabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *SoftwareVersion;
    QLabel *softwareVersionlabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *SoftwareReleaseVersion;
    QLabel *softwareReleaseVersionlabel;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(844, 240);
        verticalLayout_2 = new QVBoxLayout(Help);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SoftwareName = new QLabel(Help);
        SoftwareName->setObjectName(QStringLiteral("SoftwareName"));

        horizontalLayout->addWidget(SoftwareName);

        softwareNamelabel = new QLabel(Help);
        softwareNamelabel->setObjectName(QStringLiteral("softwareNamelabel"));

        horizontalLayout->addWidget(softwareNamelabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        TypeSpecificationName = new QLabel(Help);
        TypeSpecificationName->setObjectName(QStringLiteral("TypeSpecificationName"));

        horizontalLayout_4->addWidget(TypeSpecificationName);

        TypeSpecificationlabel = new QLabel(Help);
        TypeSpecificationlabel->setObjectName(QStringLiteral("TypeSpecificationlabel"));

        horizontalLayout_4->addWidget(TypeSpecificationlabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SoftwareVersion = new QLabel(Help);
        SoftwareVersion->setObjectName(QStringLiteral("SoftwareVersion"));

        horizontalLayout_2->addWidget(SoftwareVersion);

        softwareVersionlabel = new QLabel(Help);
        softwareVersionlabel->setObjectName(QStringLiteral("softwareVersionlabel"));

        horizontalLayout_2->addWidget(softwareVersionlabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SoftwareReleaseVersion = new QLabel(Help);
        SoftwareReleaseVersion->setObjectName(QStringLiteral("SoftwareReleaseVersion"));

        horizontalLayout_3->addWidget(SoftwareReleaseVersion);

        softwareReleaseVersionlabel = new QLabel(Help);
        softwareReleaseVersionlabel->setObjectName(QStringLiteral("softwareReleaseVersionlabel"));

        horizontalLayout_3->addWidget(softwareReleaseVersionlabel);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        SoftwareReleaseVersion->raise();
        TypeSpecificationName->raise();
        TypeSpecificationlabel->raise();

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Help", Q_NULLPTR));
        SoftwareName->setText(QApplication::translate("Help", "\350\275\257\344\273\266\345\220\215\347\247\260:", Q_NULLPTR));
        softwareNamelabel->setText(QString());
        TypeSpecificationName->setText(QApplication::translate("Help", "\350\275\257\344\273\266\345\236\213\345\217\267\350\247\204\346\240\274\357\274\232", Q_NULLPTR));
        TypeSpecificationlabel->setText(QString());
        SoftwareVersion->setText(QApplication::translate("Help", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267:", Q_NULLPTR));
        softwareVersionlabel->setText(QString());
        SoftwareReleaseVersion->setText(QApplication::translate("Help", "\350\275\257\344\273\266\345\217\221\345\270\203\347\211\210\346\234\254\345\217\267:", Q_NULLPTR));
        softwareReleaseVersionlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
