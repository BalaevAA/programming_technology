/*!
  @mainpage Приложение симулятор трейдера
    
    ⚡приложение являющееся симулятором
      спекуляции на инвестиционной бирже, в котором есть возможность
      покупки ценных бумаг (акций и облигаций) и их последующей продаже.
      Доход вычисляется из разности цен на момент продажи и покупки (купоны
      и дивиденды в этой программе не учитываются).

    📄Приложение выполнено с помощью графической библиотеки Qt и графической библиотеке QCustomPlot

    🔨Основные функции:

        • Автоматическое заполнение ячеек таблицы с ценой акций и облигаций.
        • Построения графика исходя из данных занесенных в файл.
        • Осуществление покупки и продажи ценных бумаг.
        • Внесение данных пользователя (имени и фамилии) с возможностью
        сохранения или изменения этих данных.
        • Подсчет текущего дохода с купленных бумаг
        • Подсчет дохода с продаж

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "PaperCollection.h"
#include "BoughtCollection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
    \brief Класс описывает логику работы основного окна

    Основное окно содержит 2 вкладки: для работы с клиентами и для работы с услугами/тарифами.

*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    User *user;
    PaperCollection *papers;
    BoughtCollection *investments;

    /*!
      Конструктор принимает родительский класс.
    */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


private slots:
    /*!
      \brief Метод для перехода в окно "Графики" и просмотра изменения цен бумаги.
    */
    void on_showGraphic_clicked();


    /*!
      \brief Метод для перехода в окно "Клиент".
    */
    void on_ClientMenu_clicked();


    /*!
      \brief Метод для для обновления данных в таблице при нажатии на кнопку.
    */
    void on_update_clicked();


    /*!
      \brief Метод для покупки ценных бумаг.
    */
    void on_buy_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
