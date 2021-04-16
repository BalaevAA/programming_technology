/********************************************************************************
** Form generated from reading UI file 'myinvestment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINVESTMENT_H
#define UI_MYINVESTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInvestment
{
public:
    QTableWidget *showInvestment;
    QLabel *label;
    QPushButton *sell;
    QComboBox *chooseInvestments;
    QLineEdit *chooseCount;
    QPushButton *backToCabinet;
    QPushButton *update;

    void setupUi(QDialog *MyInvestment)
    {
        if (MyInvestment->objectName().isEmpty())
            MyInvestment->setObjectName(QString::fromUtf8("MyInvestment"));
        MyInvestment->resize(900, 600);
        showInvestment = new QTableWidget(MyInvestment);
        showInvestment->setObjectName(QString::fromUtf8("showInvestment"));
        showInvestment->setGeometry(QRect(20, 60, 861, 331));
        label = new QLabel(MyInvestment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 20, 151, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        sell = new QPushButton(MyInvestment);
        sell->setObjectName(QString::fromUtf8("sell"));
        sell->setGeometry(QRect(230, 480, 101, 41));
        QFont font1;
        font1.setPointSize(9);
        sell->setFont(font1);
        chooseInvestments = new QComboBox(MyInvestment);
        chooseInvestments->setObjectName(QString::fromUtf8("chooseInvestments"));
        chooseInvestments->setGeometry(QRect(70, 461, 101, 31));
        chooseCount = new QLineEdit(MyInvestment);
        chooseCount->setObjectName(QString::fromUtf8("chooseCount"));
        chooseCount->setGeometry(QRect(70, 510, 101, 31));
        backToCabinet = new QPushButton(MyInvestment);
        backToCabinet->setObjectName(QString::fromUtf8("backToCabinet"));
        backToCabinet->setGeometry(QRect(740, 520, 141, 61));
        backToCabinet->setFont(font);
        update = new QPushButton(MyInvestment);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(410, 480, 101, 41));

        retranslateUi(MyInvestment);

        QMetaObject::connectSlotsByName(MyInvestment);
    } // setupUi

    void retranslateUi(QDialog *MyInvestment)
    {
        MyInvestment->setWindowTitle(QCoreApplication::translate("MyInvestment", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MyInvestment", "\320\222\320\260\321\210\320\270 \320\270\320\275\320\262\320\265\321\201\321\202\320\270\321\206\320\270\320\270", nullptr));
        sell->setText(QCoreApplication::translate("MyInvestment", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214", nullptr));
        chooseCount->setText(QCoreApplication::translate("MyInvestment", "1", nullptr));
        backToCabinet->setText(QCoreApplication::translate("MyInvestment", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        update->setText(QCoreApplication::translate("MyInvestment", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyInvestment: public Ui_MyInvestment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINVESTMENT_H
