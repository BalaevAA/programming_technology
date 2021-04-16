#pragma once
#include <string>
#include "Investment.h"
#include <QString>
/*!
  \brief Класс содержащий информацию об ценных бумагах
*/
class SecurityPaper
{

private:
  QString name;
	double price;

public:
  /*!
    \brief Конструктор класса, принимающий имя бумаги и ее цену
  */
  SecurityPaper(QString name = "Paper", double price = 0);
  /*!
    \brief Копирующий конструктор
  */
  SecurityPaper(SecurityPaper &other);

	~SecurityPaper();
  /*!
    \brief Метод, возвращающий имя бумаги
  */
  QString getName();
  /*!
    \brief Метод, возвращающий цену бумаги
  */
	double getPrice();
  /*!
    \brief Метод, устанавливающий имя бумаги
  */
  void setName(QString name);
  /*!
    \brief Метод, устанавливающий цену бумаги
  */
	void setPrice(double price);
};
