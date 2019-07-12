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
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *FileNameLabel;
    QLineEdit *FileNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *CoordinateScaleXDirectionLabel;
    QLineEdit *CoordinateScaleXDirectionLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *CoordinateScaleYDirectionLabel;
    QLineEdit *CoordinateScaleYDirectionLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
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
        QtArteryTechMeshSetup->resize(576, 205);
        verticalLayout_6 = new QVBoxLayout(QtArteryTechMeshSetup);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(QtArteryTechMeshSetup);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        FileNameLabel = new QLabel(QtArteryTechMeshSetup);
        FileNameLabel->setObjectName(QStringLiteral("FileNameLabel"));

        verticalLayout->addWidget(FileNameLabel);


        horizontalLayout->addLayout(verticalLayout);

        FileNameLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        FileNameLineEdit->setObjectName(QStringLiteral("FileNameLineEdit"));

        horizontalLayout->addWidget(FileNameLineEdit);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(QtArteryTechMeshSetup);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        CoordinateScaleXDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleXDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleXDirectionLabel"));

        verticalLayout_2->addWidget(CoordinateScaleXDirectionLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);

        CoordinateScaleXDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleXDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleXDirectionLineEdit"));

        horizontalLayout_2->addWidget(CoordinateScaleXDirectionLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(QtArteryTechMeshSetup);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        CoordinateScaleYDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleYDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleYDirectionLabel"));

        verticalLayout_3->addWidget(CoordinateScaleYDirectionLabel);


        horizontalLayout_3->addLayout(verticalLayout_3);

        CoordinateScaleYDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleYDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleYDirectionLineEdit"));

        horizontalLayout_3->addWidget(CoordinateScaleYDirectionLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(QtArteryTechMeshSetup);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        CoordinateScaleZDirectionLabel = new QLabel(QtArteryTechMeshSetup);
        CoordinateScaleZDirectionLabel->setObjectName(QStringLiteral("CoordinateScaleZDirectionLabel"));

        verticalLayout_4->addWidget(CoordinateScaleZDirectionLabel);


        horizontalLayout_4->addLayout(verticalLayout_4);

        CoordinateScaleZDirectionLineEdit = new QLineEdit(QtArteryTechMeshSetup);
        CoordinateScaleZDirectionLineEdit->setObjectName(QStringLiteral("CoordinateScaleZDirectionLineEdit"));

        horizontalLayout_4->addWidget(CoordinateScaleZDirectionLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_4);

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


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(QtArteryTechMeshSetup);

        QMetaObject::connectSlotsByName(QtArteryTechMeshSetup);
    } // setupUi

    void retranslateUi(QDialog *QtArteryTechMeshSetup)
    {
        QtArteryTechMeshSetup->setWindowTitle(QApplication::translate("QtArteryTechMeshSetup", "QtArteryTechMeshSetup", Q_NULLPTR));
        label->setText(QApplication::translate("QtArteryTechMeshSetup", "\350\256\241\347\256\227\347\275\221\346\240\274\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        FileNameLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "File Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtArteryTechMeshSetup", "\345\235\220\346\240\207\347\274\251\346\224\276\346\257\224\344\276\213\357\274\210X\346\226\271\345\220\221\357\274\211", Q_NULLPTR));
        CoordinateScaleXDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (X-direction):", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtArteryTechMeshSetup", "\345\235\220\346\240\207\347\274\251\346\224\276\346\257\224\344\276\213\357\274\210Y\346\226\271\345\220\221\357\274\211", Q_NULLPTR));
        CoordinateScaleYDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (Y-direction):", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtArteryTechMeshSetup", "\345\235\220\346\240\207\347\274\251\346\224\276\346\257\224\344\276\213\357\274\210Z\346\226\271\345\220\221\357\274\211", Q_NULLPTR));
        CoordinateScaleZDirectionLabel->setText(QApplication::translate("QtArteryTechMeshSetup", "Coordinate Scale (Z-direction):", Q_NULLPTR));
        OkPushButton->setText(QApplication::translate("QtArteryTechMeshSetup", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("QtArteryTechMeshSetup", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtArteryTechMeshSetup: public Ui_QtArteryTechMeshSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTARTERYTECHMESHSETUP_H
