/********************************************************************************
** Form generated from reading UI file 'QtArteryTechMeshSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTARTERYTECHMESHSETUP_H
#define UI_QTARTERYTECHMESHSETUP_H

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

class Ui_QtArteryTechMeshSetup
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *FileNameLabel;
    QLineEdit *FileNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *CoordinateScaleXDirectionLabel;
    QLineEdit *CoordinateScaleXDirectionLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *CoordinateScaleYDirectionLabel;
    QLineEdit *CoordinateScaleYDirectionLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *CoordinateScaleZDirectionLabel;
    QLineEdit *CoordinateScaleZDirectionLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *OkPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *QtArteryTechMeshSetup)
    {
        if (QtArteryTechMeshSetup->objectName().isEmpty())
            QtArteryTechMeshSetup->setObjectName(QStringLiteral("QtArteryTechMeshSetup"));
        QtArteryTechMeshSetup->resize(253, 157);
        verticalLayout_2 = new QVBoxLayout(QtArteryTechMeshSetup);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        FileNameLabel = new QLabel(QtArteryTechMeshSetup);
        FileNameLabel->setObjectName(QStringLiteral("FileNameLabel"));

        horizontalLayout->addWidget(FileNameLabel);

        FileNameLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        FileNameLineEdit->setObjectName(QStringLiteral("FileNameLineEdit"));

        horizontalLayout->addWidget(FileNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CoordinateScaleXDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleXDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleXDirectionLabel"));

        horizontalLayout_2->addWidget(CoordinateScaleXDirectionLabel);

        CoordinateScaleXDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleXDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleXDirectionLineEdit"));

        horizontalLayout_2->addWidget(CoordinateScaleXDirectionLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CoordinateScaleYDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleYDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleYDirectionLabel"));

        horizontalLayout_3->addWidget(CoordinateScaleYDirectionLabel);

        CoordinateScaleYDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleYDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleYDirectionLineEdit"));

        horizontalLayout_3->addWidget(CoordinateScaleYDirectionLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CoordinateScaleZDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleZDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleZDirectionLabel"));

        horizontalLayout_4->addWidget(CoordinateScaleZDirectionLabel);

        CoordinateScaleZDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleZDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleZDirectionLineEdit"));

        horizontalLayout_4->addWidget(CoordinateScaleZDirectionLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        OkPushButton = new QPushButton(QtArteryTechMeshSetup);
        OkPushButton->setObjectName(QStringLiteral("OkPushButton"));

        horizontalLayout_5->addWidget(OkPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        CancelPushButton = new QPushButton(QtArteryTechMeshSetup);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout_5->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtArteryTechMeshSetup);

        QMetaObject::connectSlotsByName(QtArteryTechMeshSetup);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechMeshSetup)
    {
        QtArteryTechMeshSetup->setWindowTitle(QApplication::translate("QtArteryTechMeshSetup", "QtArteryTechMeshSetup", Q_NULLPTR));
        FileNameLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "File Name:", Q_NULLPTR));
        CoordinateScaleXDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (X-direction):", Q_NULLPTR));
        CoordinateScaleYDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (Y-direction):", Q_NULLPTR));
        CoordinateScaleZDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (Z-direction):", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechMeshSetup", "OK", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechMeshSetup", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechMeshSetup: public Ui_QtArteryTechMeshSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHMESHSETUP_H
