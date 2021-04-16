#pragma once
#include "Investment.h"
#include "PaperCollection.h"
#include "User.h"

/*!
  \brief Класс описывает коллекцию купленных бумаг
*/
class BoughtCollection
{

private:
  QVector<Investment*> investments;
	int count;
	PaperCollection *papers;
	User *user;


public:
  /*!
    \brief Конструктор принимающий массив бумаг, которые существуют и информацию о пользователе
  */
	BoughtCollection(PaperCollection* papers, User* user);

	~BoughtCollection();

  /*!
    \brief Метод возвращающий количество купленных бумаг
  */
	int getCount() const;

  /*!
    \brief Метод возвращающий экземпляр класса Investment по индексу
  */
  Investment getInvestment(int index) const;

  /*!
    \brief Метод возвращающий экземпляр класса Investment по имени
  */
  Investment getInvestment(QString name) const;

  /*!
    \brief Метод возвращающий количество купленных бумаг по ее имени
  */
  int getNumberInvesments(QString name) const;

  /*!
    \brief Метод удаляющий инвестиции при их продаже по индексу
  */
  void deleteInvestment(int n);

  /*!
    \brief Метод удаляющий инвестиции при их продаже по индексу
  */
  void deleteInvestment(QString name);

  /*!
    \brief Метод заносящий информацию об инвестициях полученную из файла
  */
  void setInvestments(QVector<QStringList> data);
  /*!
    \brief Метод обновл¤ющий данные существующих инвестиций
  */
  void setInvestmentByName(double price, double sum, int number, QString name);
  /*!
    \brief Метод устанавливающий количество ценных бумаг
  */
  void setCountInvestment(int num);
  /*!
    \brief Метод добавляющий инвестиции
  */
	void addInvestment(const Investment& invest);
  /*!
    \brief Метод осуществляющий продажу инвестиции
  */
  void sellInvestment(QString name, int number);
  /*!
    \brief Метод подсчитывающий выгоду с совершенной сделки
  */
	void profit();
  /*!
    \brief Метод проверяющий наличие инвестиции по ее имени
  */
  bool checkHaveInvestmentByName(QString name);
};

