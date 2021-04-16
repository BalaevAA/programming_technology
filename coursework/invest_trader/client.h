#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include "User.h"
#include "BoughtCollection.h"

namespace Ui {
class Client;
}
/*!
  \brief Класс описывает окно "Личный кабинет"
*/
class Client : public QDialog
{
    Q_OBJECT

public:
    User *user;
    BoughtCollection* investments;
    PaperCollection* papers;

    /*!
      \brief  Конструктор принимающий родительский класс, данные о пользователе, информацию о купленных бумагах и о существующих ценных бумагах
    */
    explicit Client(QWidget *parent = nullptr, User* user = nullptr, BoughtCollection* investments = nullptr, PaperCollection* papers = nullptr);
    ~Client();

private slots:

    /*!
      \brief Метод позволяющий вернутьс¤ к окну "Рынок", при нажатии на одноименную кнопку
    */
    void on_backToMarket_clicked();
    /*!
      \brief Метод позволяющий изменить информацию о пользователе(имя и фамилию)
    */
    void on_informationChanged_clicked();
    /*!
      \brief Метод обновляющий данные о пользователе, при нажатии на кнопку "Обновить"
    */
    void on_update_clicked();
    /*!
      \brief Метод позволяющий перейти к окну "Мои инвестиции", при нажатии на одноименную кнопку
    */
    void on_myInvestment_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
