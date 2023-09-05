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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QTextBrowser *textBrowser_3;
    QLabel *label_5;
    QTextBrowser *textBrowser_2;
    QLabel *label_6;
    QTextBrowser *textBrowser_4;
    QLabel *label_7;
    QTextBrowser *textBrowser_5;
    QLabel *label_8;
    QTextBrowser *textBrowser_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(360, 334);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 1, 1, 2);

        label = new QLabel(frame);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 6, 1, 1);

        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");

        gridLayout_2->addWidget(textBrowser, 0, 7, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 1, 1, 2);

        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 1, 3, 1, 3);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 2, 1, 1, 1);

        textBrowser_3 = new QTextBrowser(frame);
        textBrowser_3->setObjectName("textBrowser_3");

        gridLayout_2->addWidget(textBrowser_3, 2, 2, 1, 3);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 5, 1, 1);

        textBrowser_2 = new QTextBrowser(frame);
        textBrowser_2->setObjectName("textBrowser_2");

        gridLayout_2->addWidget(textBrowser_2, 2, 6, 1, 2);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");

        gridLayout_2->addWidget(textBrowser_4, 3, 1, 1, 2);

        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 3, 3, 1, 1);

        textBrowser_5 = new QTextBrowser(frame);
        textBrowser_5->setObjectName("textBrowser_5");

        gridLayout_2->addWidget(textBrowser_5, 3, 4, 1, 2);

        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 3, 6, 1, 1);

        textBrowser_6 = new QTextBrowser(frame);
        textBrowser_6->setObjectName("textBrowser_6");

        gridLayout_2->addWidget(textBrowser_6, 3, 7, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 360, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "NEURONA", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "VOLTAJE", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "R: ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "G:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "B:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
