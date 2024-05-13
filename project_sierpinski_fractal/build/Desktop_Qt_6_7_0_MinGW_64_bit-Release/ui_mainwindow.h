/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lbGraph;
    QCheckBox *cb_choosePoint;
    QPushButton *pb_saveAs;
    QPushButton *pb_clear;
    QPushButton *pb_update;
    QLabel *label_2;
    QCheckBox *cb_fill;
    QCheckBox *cb_showGrid;
    QCheckBox *cb_setZ;
    QLabel *label_3;
    QDoubleSpinBox *sb_z;
    QCheckBox *cb_nAuto;
    QSpinBox *sb_n;
    QLabel *label;
    QPushButton *pb_default;
    QLabel *lbl_sampleColor;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1038, 786);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        lbGraph = new QLabel(centralWidget);
        lbGraph->setObjectName("lbGraph");
        lbGraph->setGeometry(QRect(10, 10, 711, 711));
        lbGraph->setCursor(QCursor(Qt::OpenHandCursor));
        lbGraph->setFrameShape(QFrame::Box);
        cb_choosePoint = new QCheckBox(centralWidget);
        cb_choosePoint->setObjectName("cb_choosePoint");
        cb_choosePoint->setGeometry(QRect(730, 140, 251, 22));
        QFont font;
        font.setPointSize(9);
        cb_choosePoint->setFont(font);
        cb_choosePoint->setCursor(QCursor(Qt::PointingHandCursor));
        pb_saveAs = new QPushButton(centralWidget);
        pb_saveAs->setObjectName("pb_saveAs");
        pb_saveAs->setGeometry(QRect(730, 360, 291, 31));
        pb_saveAs->setCursor(QCursor(Qt::PointingHandCursor));
        pb_clear = new QPushButton(centralWidget);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setGeometry(QRect(730, 320, 291, 31));
        pb_clear->setCursor(QCursor(Qt::PointingHandCursor));
        pb_update = new QPushButton(centralWidget);
        pb_update->setObjectName("pb_update");
        pb_update->setEnabled(true);
        pb_update->setGeometry(QRect(730, 280, 291, 31));
        pb_update->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(760, 170, 251, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        cb_fill = new QCheckBox(centralWidget);
        cb_fill->setObjectName("cb_fill");
        cb_fill->setGeometry(QRect(730, 200, 161, 17));
        cb_fill->setFont(font);
        cb_fill->setCursor(QCursor(Qt::PointingHandCursor));
        cb_showGrid = new QCheckBox(centralWidget);
        cb_showGrid->setObjectName("cb_showGrid");
        cb_showGrid->setGeometry(QRect(730, 230, 181, 21));
        cb_showGrid->setFont(font);
        cb_showGrid->setCursor(QCursor(Qt::PointingHandCursor));
        cb_setZ = new QCheckBox(centralWidget);
        cb_setZ->setObjectName("cb_setZ");
        cb_setZ->setGeometry(QRect(730, 80, 131, 17));
        cb_setZ->setFont(font);
        cb_setZ->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(760, 110, 101, 21));
        label_3->setFont(font);
        sb_z = new QDoubleSpinBox(centralWidget);
        sb_z->setObjectName("sb_z");
        sb_z->setEnabled(false);
        sb_z->setGeometry(QRect(880, 110, 91, 25));
        sb_z->setDecimals(1);
        sb_z->setMinimum(0.100000000000000);
        sb_z->setMaximum(99.000000000000000);
        sb_z->setSingleStep(0.100000000000000);
        cb_nAuto = new QCheckBox(centralWidget);
        cb_nAuto->setObjectName("cb_nAuto");
        cb_nAuto->setGeometry(QRect(731, 11, 241, 24));
        cb_nAuto->setFont(font);
        cb_nAuto->setCursor(QCursor(Qt::PointingHandCursor));
        cb_nAuto->setChecked(true);
        cb_nAuto->setTristate(false);
        sb_n = new QSpinBox(centralWidget);
        sb_n->setObjectName("sb_n");
        sb_n->setEnabled(false);
        sb_n->setGeometry(QRect(880, 40, 91, 25));
        sb_n->setMaximum(12);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setEnabled(false);
        label->setGeometry(QRect(750, 40, 91, 21));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        pb_default = new QPushButton(centralWidget);
        pb_default->setObjectName("pb_default");
        pb_default->setGeometry(QRect(730, 690, 291, 31));
        pb_default->setCursor(QCursor(Qt::PointingHandCursor));
        lbl_sampleColor = new QLabel(centralWidget);
        lbl_sampleColor->setObjectName("lbl_sampleColor");
        lbl_sampleColor->setGeometry(QRect(920, 200, 21, 21));
        lbl_sampleColor->setCursor(QCursor(Qt::PointingHandCursor));
        lbl_sampleColor->setFrameShape(QFrame::NoFrame);
        lbl_sampleColor->setScaledContents(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1038, 17));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbGraph->setText(QString());
        cb_choosePoint->setText(QCoreApplication::translate("MainWindow", "Place dots", nullptr));
        pb_saveAs->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pb_update->setText(QCoreApplication::translate("MainWindow", "Renew", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Need to add 3 dots", nullptr));
        cb_fill->setText(QCoreApplication::translate("MainWindow", "Fill the triangle", nullptr));
        cb_showGrid->setText(QCoreApplication::translate("MainWindow", "Print a grid", nullptr));
        cb_setZ->setText(QCoreApplication::translate("MainWindow", "Select Z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Value Z", nullptr));
        cb_nAuto->setText(QCoreApplication::translate("MainWindow", "Automatically choose n value", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Value n", nullptr));
        pb_default->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        lbl_sampleColor->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
