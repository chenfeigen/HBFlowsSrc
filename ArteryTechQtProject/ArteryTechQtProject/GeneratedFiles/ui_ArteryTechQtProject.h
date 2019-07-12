/********************************************************************************
** Form generated from reading UI file 'ArteryTechQtProject.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTERYTECHQTPROJECT_H
#define UI_ARTERYTECHQTPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArteryTechQtProjectClass
{
public:
    QAction *actionopen;
    QAction *actionOpenExe;
    QAction *actionMesh_Setup_2;
    QAction *actionBoundary_Setup;
    QAction *actionPhysics_Setup_2;
    QAction *actionNonlinear_Solver_Setup;
    QAction *actionLinear_Solver_Setup;
    QAction *actionPreconditioner_Setup;
    QAction *actionTwo_Level_Preconditioner;
    QAction *actionOutput_Setup;
    QAction *actionOther_Setups;
    QAction *actionModify_Finish;
    QAction *actionOpen_Dicompicture;
    QAction *actionView;
    QAction *actionDivision;
    QAction *actionGeometry;
    QAction *actionMesh;
    QAction *actionCompute;
    QAction *actionPutty;
    QAction *actionadd_username;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArteryTechQtProjectClass)
    {
        if (ArteryTechQtProjectClass->objectName().isEmpty())
            ArteryTechQtProjectClass->setObjectName(QStringLiteral("ArteryTechQtProjectClass"));
        ArteryTechQtProjectClass->resize(623, 710);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/ArteryTech.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ArteryTechQtProjectClass->setWindowIcon(icon);
        actionopen = new QAction(ArteryTechQtProjectClass);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionopen->setCheckable(false);
        actionopen->setEnabled(true);
        actionOpenExe = new QAction(ArteryTechQtProjectClass);
        actionOpenExe->setObjectName(QStringLiteral("actionOpenExe"));
        actionMesh_Setup_2 = new QAction(ArteryTechQtProjectClass);
        actionMesh_Setup_2->setObjectName(QStringLiteral("actionMesh_Setup_2"));
        actionBoundary_Setup = new QAction(ArteryTechQtProjectClass);
        actionBoundary_Setup->setObjectName(QStringLiteral("actionBoundary_Setup"));
        actionPhysics_Setup_2 = new QAction(ArteryTechQtProjectClass);
        actionPhysics_Setup_2->setObjectName(QStringLiteral("actionPhysics_Setup_2"));
        actionNonlinear_Solver_Setup = new QAction(ArteryTechQtProjectClass);
        actionNonlinear_Solver_Setup->setObjectName(QStringLiteral("actionNonlinear_Solver_Setup"));
        actionLinear_Solver_Setup = new QAction(ArteryTechQtProjectClass);
        actionLinear_Solver_Setup->setObjectName(QStringLiteral("actionLinear_Solver_Setup"));
        actionPreconditioner_Setup = new QAction(ArteryTechQtProjectClass);
        actionPreconditioner_Setup->setObjectName(QStringLiteral("actionPreconditioner_Setup"));
        actionTwo_Level_Preconditioner = new QAction(ArteryTechQtProjectClass);
        actionTwo_Level_Preconditioner->setObjectName(QStringLiteral("actionTwo_Level_Preconditioner"));
        actionOutput_Setup = new QAction(ArteryTechQtProjectClass);
        actionOutput_Setup->setObjectName(QStringLiteral("actionOutput_Setup"));
        actionOther_Setups = new QAction(ArteryTechQtProjectClass);
        actionOther_Setups->setObjectName(QStringLiteral("actionOther_Setups"));
        actionModify_Finish = new QAction(ArteryTechQtProjectClass);
        actionModify_Finish->setObjectName(QStringLiteral("actionModify_Finish"));
        actionOpen_Dicompicture = new QAction(ArteryTechQtProjectClass);
        actionOpen_Dicompicture->setObjectName(QStringLiteral("actionOpen_Dicompicture"));
        actionView = new QAction(ArteryTechQtProjectClass);
        actionView->setObjectName(QStringLiteral("actionView"));
        actionDivision = new QAction(ArteryTechQtProjectClass);
        actionDivision->setObjectName(QStringLiteral("actionDivision"));
        actionGeometry = new QAction(ArteryTechQtProjectClass);
        actionGeometry->setObjectName(QStringLiteral("actionGeometry"));
        actionMesh = new QAction(ArteryTechQtProjectClass);
        actionMesh->setObjectName(QStringLiteral("actionMesh"));
        actionCompute = new QAction(ArteryTechQtProjectClass);
        actionCompute->setObjectName(QStringLiteral("actionCompute"));
        actionPutty = new QAction(ArteryTechQtProjectClass);
        actionPutty->setObjectName(QStringLiteral("actionPutty"));
        actionadd_username = new QAction(ArteryTechQtProjectClass);
        actionadd_username->setObjectName(QStringLiteral("actionadd_username"));
        centralWidget = new QWidget(ArteryTechQtProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        ArteryTechQtProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ArteryTechQtProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 623, 23));
        ArteryTechQtProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ArteryTechQtProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ArteryTechQtProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ArteryTechQtProjectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ArteryTechQtProjectClass->setStatusBar(statusBar);

        retranslateUi(ArteryTechQtProjectClass);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(ArteryTechQtProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ArteryTechQtProjectClass)
    {
        ArteryTechQtProjectClass->setWindowTitle(QApplication::translate("ArteryTechQtProjectClass", "ArteryTechQtProject", Q_NULLPTR));
        actionopen->setText(QApplication::translate("ArteryTechQtProjectClass", "Open Picture", Q_NULLPTR));
        actionOpenExe->setText(QApplication::translate("ArteryTechQtProjectClass", "Open Exe", Q_NULLPTR));
        actionMesh_Setup_2->setText(QApplication::translate("ArteryTechQtProjectClass", "Mesh Setup", Q_NULLPTR));
        actionBoundary_Setup->setText(QApplication::translate("ArteryTechQtProjectClass", "Boundary Setup", Q_NULLPTR));
        actionPhysics_Setup_2->setText(QApplication::translate("ArteryTechQtProjectClass", "Physics Setup", Q_NULLPTR));
        actionNonlinear_Solver_Setup->setText(QApplication::translate("ArteryTechQtProjectClass", "Nonlinear Solver Setup", Q_NULLPTR));
        actionLinear_Solver_Setup->setText(QApplication::translate("ArteryTechQtProjectClass", "Linear Solver Setup", Q_NULLPTR));
        actionPreconditioner_Setup->setText(QApplication::translate("ArteryTechQtProjectClass", "Preconditioner Setup", Q_NULLPTR));
        actionTwo_Level_Preconditioner->setText(QApplication::translate("ArteryTechQtProjectClass", "Two-Level Preconditioner", Q_NULLPTR));
        actionOutput_Setup->setText(QApplication::translate("ArteryTechQtProjectClass", "Output Setup", Q_NULLPTR));
        actionOther_Setups->setText(QApplication::translate("ArteryTechQtProjectClass", "Other Setups", Q_NULLPTR));
        actionModify_Finish->setText(QApplication::translate("ArteryTechQtProjectClass", "Modify Finish", Q_NULLPTR));
        actionOpen_Dicompicture->setText(QApplication::translate("ArteryTechQtProjectClass", "Open Dicompicture", Q_NULLPTR));
        actionView->setText(QApplication::translate("ArteryTechQtProjectClass", "View", Q_NULLPTR));
        actionDivision->setText(QApplication::translate("ArteryTechQtProjectClass", "Division", Q_NULLPTR));
        actionGeometry->setText(QApplication::translate("ArteryTechQtProjectClass", "Geometry", Q_NULLPTR));
        actionMesh->setText(QApplication::translate("ArteryTechQtProjectClass", "Mesh", Q_NULLPTR));
        actionCompute->setText(QApplication::translate("ArteryTechQtProjectClass", "Compute", Q_NULLPTR));
        actionPutty->setText(QApplication::translate("ArteryTechQtProjectClass", "Open Putty", Q_NULLPTR));
        actionadd_username->setText(QApplication::translate("ArteryTechQtProjectClass", "add username", Q_NULLPTR));
        label->setText(QApplication::translate("ArteryTechQtProjectClass", "text", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ArteryTechQtProjectClass: public Ui_ArteryTechQtProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTERYTECHQTPROJECT_H
