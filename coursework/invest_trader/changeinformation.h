

#ifndef CHANGEINFORMATION_H
#define CHANGEINFORMATION_H

#include <QDialog>
#include "User.h"

namespace Ui {
class ChangeInformation;
}
/*!
    \brief Класс описывающий изменения данных об имени и фамилии пользователя
*/
class ChangeInformation : public QDialog
{
    Q_OBJECT

public:
    User *user;

    /*!
      \brief  Конструктор принимающий родительский класс и информацию о пользователе
    */
    explicit ChangeInformation(QWidget *parent = nullptr, User* user = nullptr);
    ~ChangeInformation();

private slots:
    void on_Change_clicked();

private:
    Ui::ChangeInformation *ui;
};

#endif // CHANGEINFORMATION_H
