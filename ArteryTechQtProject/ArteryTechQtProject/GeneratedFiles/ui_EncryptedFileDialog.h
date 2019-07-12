/********************************************************************************
** Form generated from reading UI file 'EncryptedFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTEDFILEDIALOG_H
#define UI_ENCRYPTEDFILEDIALOG_H

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

class Ui_EncryptedFileDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *SourceFileLabel;
    QLineEdit *SourceFileLineEdit;
    QPushButton *InputFilePushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *EncryptionPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *DecryptionPushButton;

    void setupUi(QDialog *EncryptedFileDialog)
    {
        if (EncryptedFileDialog->objectName().isEmpty())
            EncryptedFileDialog->setObjectName(QStringLiteral("EncryptedFileDialog"));
        EncryptedFileDialog->resize(600, 76);
        verticalLayout_2 = new QVBoxLayout(EncryptedFileDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SourceFileLabel = new QLabel(EncryptedFileDialog);
        SourceFileLabel->setObjectName(QStringLiteral("SourceFileLabel"));

        horizontalLayout->addWidget(SourceFileLabel);

        SourceFileLineEdit = new QLineEdit(EncryptedFileDialog);
        SourceFileLineEdit->setObjectName(QStringLiteral("SourceFileLineEdit"));

        horizontalLayout->addWidget(SourceFileLineEdit);

        InputFilePushButton = new QPushButton(EncryptedFileDialog);
        InputFilePushButton->setObjectName(QStringLiteral("InputFilePushButton"));

        horizontalLayout->addWidget(InputFilePushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        EncryptionPushButton = new QPushButton(EncryptedFileDialog);
        EncryptionPushButton->setObjectName(QStringLiteral("EncryptionPushButton"));

        horizontalLayout_2->addWidget(EncryptionPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        DecryptionPushButton = new QPushButton(EncryptedFileDialog);
        DecryptionPushButton->setObjectName(QStringLiteral("DecryptionPushButton"));

        horizontalLayout_2->addWidget(DecryptionPushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EncryptedFileDialog);

        QMetaObject::connectSlotsByName(EncryptedFileDialog);
    } // setupUi

    void retranslateUi(QDialog *EncryptedFileDialog)
    {
        EncryptedFileDialog->setWindowTitle(QApplication::translate("EncryptedFileDialog", "EncryptedFileDialog", Q_NULLPTR));
        SourceFileLabel->setText(QApplication::translate("EncryptedFileDialog", "SourceFile:", Q_NULLPTR));
        InputFilePushButton->setText(QApplication::translate("EncryptedFileDialog", "InputFile", Q_NULLPTR));
        EncryptionPushButton->setText(QApplication::translate("EncryptedFileDialog", "Encryption", Q_NULLPTR));
        DecryptionPushButton->setText(QApplication::translate("EncryptedFileDialog", "Decryption", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EncryptedFileDialog: public Ui_EncryptedFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTEDFILEDIALOG_H
