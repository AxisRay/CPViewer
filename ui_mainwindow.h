/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVTKWidget *qvtkAxialView;
    QVTKWidget *qvtkSagittalView;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *tbx_CT;
    QPushButton *pbLoadCT;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *tbx_OPT;
    QPushButton *pbLoadOPT;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSlider *hsAxisX;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSlider *hsAxisY;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSlider *hsAxisZ;
    QTabWidget *tabWidget;
    QWidget *tab_CT;
    QWidget *tab_OPT;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSlider *hsOffsetX;
    QSpinBox *dsOffsetX;
    QHBoxLayout *horizontalLayout_7;
    QSlider *hsOffsetY;
    QSpinBox *dsOffsetY;
    QHBoxLayout *horizontalLayout_8;
    QSlider *hsOffsetZ;
    QSpinBox *dsOffsetZ;
    QPushButton *pbRender;
    QSpacerItem *verticalSpacer;
    QWidget *tab_Render;
    QVTKWidget *qvtkCoronalView;
    QVTKWidget *qvtkRenderView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(684, 437);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qvtkAxialView = new QVTKWidget(centralwidget);
        qvtkAxialView->setObjectName(QStringLiteral("qvtkAxialView"));

        gridLayout->addWidget(qvtkAxialView, 0, 2, 1, 1);

        qvtkSagittalView = new QVTKWidget(centralwidget);
        qvtkSagittalView->setObjectName(QStringLiteral("qvtkSagittalView"));

        gridLayout->addWidget(qvtkSagittalView, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 0, 9, 0);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tbx_CT = new QLineEdit(centralwidget);
        tbx_CT->setObjectName(QStringLiteral("tbx_CT"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbx_CT->sizePolicy().hasHeightForWidth());
        tbx_CT->setSizePolicy(sizePolicy);
        tbx_CT->setReadOnly(true);

        horizontalLayout_2->addWidget(tbx_CT);

        pbLoadCT = new QPushButton(centralwidget);
        pbLoadCT->setObjectName(QStringLiteral("pbLoadCT"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbLoadCT->sizePolicy().hasHeightForWidth());
        pbLoadCT->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pbLoadCT);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tbx_OPT = new QLineEdit(centralwidget);
        tbx_OPT->setObjectName(QStringLiteral("tbx_OPT"));
        sizePolicy.setHeightForWidth(tbx_OPT->sizePolicy().hasHeightForWidth());
        tbx_OPT->setSizePolicy(sizePolicy);
        tbx_OPT->setReadOnly(true);

        horizontalLayout_5->addWidget(tbx_OPT);

        pbLoadOPT = new QPushButton(centralwidget);
        pbLoadOPT->setObjectName(QStringLiteral("pbLoadOPT"));
        sizePolicy1.setHeightForWidth(pbLoadOPT->sizePolicy().hasHeightForWidth());
        pbLoadOPT->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pbLoadOPT);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_3);

        hsAxisX = new QSlider(centralwidget);
        hsAxisX->setObjectName(QStringLiteral("hsAxisX"));
        hsAxisX->setEnabled(false);
        sizePolicy.setHeightForWidth(hsAxisX->sizePolicy().hasHeightForWidth());
        hsAxisX->setSizePolicy(sizePolicy);
        hsAxisX->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hsAxisX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_4);

        hsAxisY = new QSlider(centralwidget);
        hsAxisY->setObjectName(QStringLiteral("hsAxisY"));
        hsAxisY->setEnabled(false);
        sizePolicy.setHeightForWidth(hsAxisY->sizePolicy().hasHeightForWidth());
        hsAxisY->setSizePolicy(sizePolicy);
        hsAxisY->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hsAxisY);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_5);

        hsAxisZ = new QSlider(centralwidget);
        hsAxisZ->setObjectName(QStringLiteral("hsAxisZ"));
        hsAxisZ->setEnabled(false);
        sizePolicy.setHeightForWidth(hsAxisZ->sizePolicy().hasHeightForWidth());
        hsAxisZ->setSizePolicy(sizePolicy);
        hsAxisZ->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hsAxisZ);


        verticalLayout->addLayout(horizontalLayout_4);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tab_CT = new QWidget();
        tab_CT->setObjectName(QStringLiteral("tab_CT"));
        tabWidget->addTab(tab_CT, QString());
        tab_OPT = new QWidget();
        tab_OPT->setObjectName(QStringLiteral("tab_OPT"));
        verticalLayout_3 = new QVBoxLayout(tab_OPT);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        hsOffsetX = new QSlider(tab_OPT);
        hsOffsetX->setObjectName(QStringLiteral("hsOffsetX"));
        hsOffsetX->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(hsOffsetX);

        dsOffsetX = new QSpinBox(tab_OPT);
        dsOffsetX->setObjectName(QStringLiteral("dsOffsetX"));

        horizontalLayout_6->addWidget(dsOffsetX);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        hsOffsetY = new QSlider(tab_OPT);
        hsOffsetY->setObjectName(QStringLiteral("hsOffsetY"));
        hsOffsetY->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(hsOffsetY);

        dsOffsetY = new QSpinBox(tab_OPT);
        dsOffsetY->setObjectName(QStringLiteral("dsOffsetY"));

        horizontalLayout_7->addWidget(dsOffsetY);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        hsOffsetZ = new QSlider(tab_OPT);
        hsOffsetZ->setObjectName(QStringLiteral("hsOffsetZ"));
        hsOffsetZ->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(hsOffsetZ);

        dsOffsetZ = new QSpinBox(tab_OPT);
        dsOffsetZ->setObjectName(QStringLiteral("dsOffsetZ"));

        horizontalLayout_8->addWidget(dsOffsetZ);


        verticalLayout_3->addLayout(horizontalLayout_8);

        pbRender = new QPushButton(tab_OPT);
        pbRender->setObjectName(QStringLiteral("pbRender"));
        pbRender->setEnabled(false);

        verticalLayout_3->addWidget(pbRender);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tab_OPT, QString());
        tab_Render = new QWidget();
        tab_Render->setObjectName(QStringLiteral("tab_Render"));
        tabWidget->addTab(tab_Render, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        qvtkCoronalView = new QVTKWidget(centralwidget);
        qvtkCoronalView->setObjectName(QStringLiteral("qvtkCoronalView"));

        gridLayout->addWidget(qvtkCoronalView, 1, 2, 1, 1);

        qvtkRenderView = new QVTKWidget(centralwidget);
        qvtkRenderView->setObjectName(QStringLiteral("qvtkRenderView"));

        gridLayout->addWidget(qvtkRenderView, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 684, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CPViewer", 0));
        label_2->setText(QApplication::translate("MainWindow", "CT", 0));
        pbLoadCT->setText(QApplication::translate("MainWindow", "Load CT", 0));
        label->setText(QApplication::translate("MainWindow", "OPT", 0));
        pbLoadOPT->setText(QApplication::translate("MainWindow", "Load OPT", 0));
        label_3->setText(QApplication::translate("MainWindow", "X:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Z:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_CT), QApplication::translate("MainWindow", "CT", 0));
        pbRender->setText(QApplication::translate("MainWindow", "Render", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_OPT), QApplication::translate("MainWindow", "OPT", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Render), QApplication::translate("MainWindow", "Render", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
