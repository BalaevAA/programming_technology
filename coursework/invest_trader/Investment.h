#pragma once
#include <string>
#include <ctime>
#include <QString>
/*!
  \brief Класс хранящий информацию об инвестициях
*/
class Investment
{

private:
	double sum;
	int numberPapers;
  double price;
  QString paperName;

public:
  /*!
      \brief Конструктор класса, принимающий сумму, кол-во, цену и имя бумаги инвестиции
  */
  Investment(double sum = 0, int num = 0,double price = 0, QString paperName = " ");
  /*!
    \brief Копирующий конструктор
  */
  Investment(const Investment& other);
	~Investment();
  /*!
      \brief Метод, возращающий сумму инвестиции
  */
	double getSum() const;
  /*!
      \brief Метод, возращающий кол-во купленных бумаг инвестиции
  */
	int getNumberPapers() const;
  /*!
      \brief Метод, возращающий цену бумаг инвестиции
  */
  double getPrice() const;
  /*!
      \brief Метод, возращающий имя бумаг инвестиции
  */
  QString getPaperName() const;
  /*!
      \brief Метод, устанавливающий сумму инвестиции
  */
	void setSum(double sum);
  /*!
      \brief Метод, устанавливающий кол-во бумаг инвестиции
  */
	void setNumberPapers(int num);
  /*!
      \brief Метод, устанавливающий цену бумаги инвестиции
  */
  void setPrice(double priceBuy);
  /*!
      \brief Метод, устанавливающий имя бумаги инвестиции
  */
  void setPaperName(QString paperName);
};

