/********************************************************************************
** Form generated from reading UI file 'graphics.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_H
#define UI_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graphics
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *Graphics)
    {
        if (Graphics->objectName().isEmpty())
            Graphics->setObjectName(QString::fromUtf8("Graphics"));
        Graphics->resize(900, 600);
        widget = new QWidget(Graphics);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 901, 601));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Graphics);

        QMetaObject::connectSlotsByName(Graphics);
    } // setupUi

    void retranslateUi(QDialog *Graphics)
    {
        Graphics->setWindowTitle(QCoreApplication::translate("Graphics", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graphics: public Ui_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H
