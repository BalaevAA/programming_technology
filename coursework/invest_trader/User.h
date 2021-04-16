#pragma once
#include <QString>
/*!
  \brief Класс содержащий данные о пользователе
*/
class User
{

private:
  double profitNow;
  double moneyBox;
  QString firstName;
  QString lastName;
  int numberPapers;

public:
  /*!
      \brief  Конструктор пользователя, приимающий его имя, фамилию, выгоду с купленных бумаг, копилку продаж и кол-во имеющихся бумаг
  */
  User(QString firstName = "Name", QString lastName = "lastName", double profit = 0, double moneyBox = 0, int numberPapers = 0);
	~User();
  /*!
      \brief Метод, возращающий выгоду с купленных бумаг
  */
	double getProfitNow();
  /*!
      \brief Метод, возращающий сумму в копилке продаж
  */
	double getMoneyBox();
  /*!
      \brief Метод, возращающий имя пользователя
  */
  QString getFirstName();
  /*!
      \brief Метод, возращающий фамилию пользователя
  */
  QString getLastName();
  /*!
      \brief Метод, возращающий кол-во купленных бумаг
  */
  int getNumberPapers();
  /*!
      \brief Метод, устанавливающий кол-во бумаг 
  */
	void setProfitNow(double profit);
  /*!
      \brief Метод, добавляющий новую сумму в копилку продаж
  */
	void addToMoneyBox(double sum);
  /*!
      \brief Метод, устанавливающий имя пользователя
  */
  void setFirstName(QString firstName);
  /*!
      \brief Метод, устанавливающий сумму копилки продаж пользователя
  */
  void setMoneyBox(double moneyBox);
  /*!
      \brief Метод, устанавливающий фамилию пользователя
  */
  void setLastName(QString lastName);
  /*!
      \brief Метод, устанавливающий кол-во бумаг пользователя
  */
  void setNumberPapers(int numberPapers);
};

