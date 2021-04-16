/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QTableWidget *TableStocks;
    QTableWidget *TableBonds;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_5;
    QGroupBox *groupBox;
    QLabel *label_2;
    QComboBox *ChoosePaper;
    QLabel *label_3;
    QLineEdit *ChooseCount;
    QPushButton *update;
    QPushButton *ClientMenu;
    QPushButton *showGraphic;
    QPushButton *buy;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        TableStocks = new QTableWidget(groupBox_3);
        TableStocks->setObjectName(QString::fromUtf8("TableStocks"));
        TableStocks->setGeometry(QRect(10, 50, 861, 111));
        TableStocks->setTextElideMode(Qt::ElideMiddle);
        TableBonds = new QTableWidget(groupBox_3);
        TableBonds->setObjectName(QString::fromUtf8("TableBonds"));
        TableBonds->setGeometry(QRect(10, 200, 861, 111));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 0, 81, 31));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 0, 111, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(750, 170, 55, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 170, 91, 16));
        label_5->setFont(font);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 320, 939, 336));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 151, 31));
        ChoosePaper = new QComboBox(groupBox);
        ChoosePaper->setObjectName(QString::fromUtf8("ChoosePaper"));
        ChoosePaper->setGeometry(QRect(10, 60, 201, 41));
        ChoosePaper->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 151, 20));
        ChooseCount = new QLineEdit(groupBox);
        ChooseCount->setObjectName(QString::fromUtf8("ChooseCount"));
        ChooseCount->setGeometry(QRect(10, 150, 201, 41));
        update = new QPushButton(groupBox);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(680, 40, 131, 41));
        update->setFont(font);
        ClientMenu = new QPushButton(groupBox);
        ClientMenu->setObjectName(QString::fromUtf8("ClientMenu"));
        ClientMenu->setGeometry(QRect(670, 120, 151, 61));
        showGraphic = new QPushButton(groupBox);
        showGraphic->setObjectName(QString::fromUtf8("showGraphic"));
        showGraphic->setGeometry(QRect(240, 60, 131, 41));
        buy = new QPushButton(groupBox);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(250, 150, 101, 41));

        verticalLayout->addWidget(groupBox_3);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\220\320\272\321\206\320\270\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\321\213\320\275\320\276\320\272", nullptr));
        label_6->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\273\320\270\320\263\320\260\321\206\320\270\320\270", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203\321\216 \320\261\321\203\320\274\320\260\320\263\321\203", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        ChooseCount->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        ClientMenu->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        showGraphic->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        buy->setText(QCoreApplication::translate("MainWindow", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
