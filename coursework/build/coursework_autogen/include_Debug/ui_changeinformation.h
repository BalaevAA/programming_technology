/********************************************************************************
** Form generated from reading UI file 'changeinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFORMATION_H
#define UI_CHANGEINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangeInformation
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *nameEdit;
    QLineEdit *lastNameEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Change;

    void setupUi(QDialog *ChangeInformation)
    {
        if (ChangeInformation->objectName().isEmpty())
            ChangeInformation->setObjectName(QString::fromUtf8("ChangeInformation"));
        ChangeInformation->resize(319, 223);
        verticalLayout_3 = new QVBoxLayout(ChangeInformation);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(ChangeInformation);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_3->addWidget(label, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(ChangeInformation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        label_3 = new QLabel(ChangeInformation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nameEdit = new QLineEdit(ChangeInformation);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout->addWidget(nameEdit);

        lastNameEdit = new QLineEdit(ChangeInformation);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        verticalLayout->addWidget(lastNameEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        Change = new QPushButton(ChangeInformation);
        Change->setObjectName(QString::fromUtf8("Change"));
        Change->setFont(font);

        verticalLayout_3->addWidget(Change);


        retranslateUi(ChangeInformation);

        QMetaObject::connectSlotsByName(ChangeInformation);
    } // setupUi

    void retranslateUi(QDialog *ChangeInformation)
    {
        ChangeInformation->setWindowTitle(QCoreApplication::translate("ChangeInformation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangeInformation", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\222\320\260\321\210\320\265 \320\270\320\274\321\217 \320\270 \321\204\320\260\320\274\320\270\320\273\320\270\321\216", nullptr));
        label_2->setText(QCoreApplication::translate("ChangeInformation", "\320\230\320\274\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeInformation", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        Change->setText(QCoreApplication::translate("ChangeInformation", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInformation: public Ui_ChangeInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFORMATION_H
