#ifndef MYINVESTMENT_H
#define MYINVESTMENT_H

#include <QDialog>
#include "BoughtCollection.h"
#include "User.h"

namespace Ui {
class MyInvestment;
}
/*!
 \brief Класс содержащий данные о купленных бумагах пользователя
*/
class MyInvestment : public QDialog
{
  Q_OBJECT

public:
  BoughtCollection *investments;
  User* user;
  PaperCollection* papers;
  /*!
    \brief Конструктор класса, принимающий родительский класс, купленные бумаги, информацию о пользователе и существующих бумагах
  */
  explicit MyInvestment(QWidget *parent = nullptr, BoughtCollection *investments = nullptr, User* user = nullptr, PaperCollection* papers = nullptr);
  ~MyInvestment();

private slots:
  /*!
    \brief Метод, осуществляющий продажу ценной бумаги при нажатии на кнопку "Продать"
  */
  void on_sell_clicked();
  /*!
    \brief Метод, позволяющий вернуться к окну "Личный кабинет", при нажатии на одноименную кнопку
  */
  void on_backToCabinet_clicked();
  /*!
    \brief Метод обновляющий данные об инвестициях пользователя, при нажатии на кнопку "Обновить"
  */
  void on_update_clicked();

private:
  Ui::MyInvestment *ui;
};

#endif // MYINVESTMENT_H
