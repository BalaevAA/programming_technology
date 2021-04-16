

#pragma once
#include "SecurityPaper.h"
#include <QVector>
#include <QList>

/*!
   \brief Класс описывающий коллекцию всех ценных бумаг
*/

class PaperCollection
{


private:
  QVector <SecurityPaper*> papers;
	int count;

public:
  /*!
    \brief Конструктор по умолчанию
  */
	PaperCollection();
	~PaperCollection();

  /*!
    \brief Метод, возвращающий количество ценных бумаг
  */
	int getCount() const;
  /*!
    \brief Метод, возвращающий экземпляр класса SecurityPaper по имени бумаги
  */
  SecurityPaper getPaper(QString name) const;
  /*!
    \brief Метод, возвращающий экземпляр класса SecurityPaper по индексу бумаги
  */
  SecurityPaper getPaper(int index) const;
  /*!
    \brief Метод, возвращающий цену бумаги по ее имени
  */
  double getPriceByName(QString name)const;
  /*!
    \brief Метод, устанавливающий цену бумаги
  */
  void setPrice(QString name, double sum);
  /*!
    \brief Метод добавляющий бумагу в коллекцию
  */
  void addPaper(SecurityPaper* paper);
  /*!
    \brief Метод удаляющий ценную бумагу из коллекции
  */
	void deletePaper(int n);
};

