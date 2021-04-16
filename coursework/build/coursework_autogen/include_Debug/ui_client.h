/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QPushButton *myInvestment;
    QPushButton *backToMarket;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *Name;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *Profit;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QLabel *moneyBox;
    QGroupBox *groupBox_5;
    QPushButton *informationChanged;
    QPushButton *update;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(900, 600);
        horizontalLayout = new QHBoxLayout(Client);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_4 = new QGroupBox(Client);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        myInvestment = new QPushButton(groupBox_4);
        myInvestment->setObjectName(QString::fromUtf8("myInvestment"));
        myInvestment->setGeometry(QRect(250, 40, 151, 81));
        QFont font;
        font.setPointSize(9);
        myInvestment->setFont(font);
        backToMarket = new QPushButton(groupBox_4);
        backToMarket->setObjectName(QString::fromUtf8("backToMarket"));
        backToMarket->setGeometry(QRect(260, 170, 131, 71));
        QFont font1;
        font1.setPointSize(10);
        backToMarket->setFont(font1);

        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Client);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        Name = new QLabel(groupBox);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(530, 30, 191, 31));
        Name->setFont(font1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 281, 71));
        label->setFont(font1);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Client);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 0, 291, 71));
        label_2->setFont(font1);
        Profit = new QLabel(groupBox_2);
        Profit->setObjectName(QString::fromUtf8("Profit"));
        Profit->setGeometry(QRect(540, 20, 211, 41));
        Profit->setFont(font1);

        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Client);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 20, 211, 41));
        label_3->setFont(font1);
        moneyBox = new QLabel(groupBox_3);
        moneyBox->setObjectName(QString::fromUtf8("moneyBox"));
        moneyBox->setGeometry(QRect(540, 30, 201, 41));
        moneyBox->setFont(font1);

        verticalLayout->addWidget(groupBox_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        groupBox_5 = new QGroupBox(Client);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        informationChanged = new QPushButton(groupBox_5);
        informationChanged->setObjectName(QString::fromUtf8("informationChanged"));
        informationChanged->setGeometry(QRect(30, 110, 261, 41));
        informationChanged->setFont(font1);
        update = new QPushButton(groupBox_5);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(330, 110, 93, 41));
        update->setFont(font1);

        gridLayout->addWidget(groupBox_5, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Dialog", nullptr));
        groupBox_4->setTitle(QString());
        myInvestment->setText(QCoreApplication::translate("Client", "\320\234\320\276\320\270 \320\270\320\275\320\262\320\265\321\201\321\202\320\270\321\206\320\270\320\270", nullptr));
        backToMarket->setText(QCoreApplication::translate("Client", "\320\240\321\213\320\275\320\276\320\272", nullptr));
        groupBox->setTitle(QString());
        Name->setText(QCoreApplication::translate("Client", "\320\270\320\274\321\217", nullptr));
        label->setText(QCoreApplication::translate("Client", "\320\230\320\234\320\257 \320\244\320\220\320\234\320\230\320\233\320\230\320\257 \320\237\320\236\320\233\320\254\320\227\320\236\320\222\320\220\320\242\320\225\320\233\320\257", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("Client", "\320\222\320\253\320\223\320\236\320\224\320\220 \320\241 \320\241\320\236\320\222\320\225\320\240\320\250\320\225\320\235\320\235\320\253\320\245 \320\241\320\224\320\225\320\233\320\236\320\232", nullptr));
        Profit->setText(QCoreApplication::translate("Client", "0", nullptr));
        groupBox_3->setTitle(QString());
        label_3->setText(QCoreApplication::translate("Client", "\320\232\320\236\320\237\320\230\320\233\320\232\320\220 \320\237\320\240\320\236\320\224\320\220\320\226", nullptr));
        moneyBox->setText(QCoreApplication::translate("Client", "0", nullptr));
        groupBox_5->setTitle(QString());
        informationChanged->setText(QCoreApplication::translate("Client", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        update->setText(QCoreApplication::translate("Client", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
