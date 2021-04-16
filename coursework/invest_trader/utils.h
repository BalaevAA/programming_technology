#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <vector>
#include "PaperCollection.h"
#include "BoughtCollection.h"

/*!
  \brief Класс содержащий методы для упрощения работы
*/
class utils
{
public:
    /*!
      \brief Метод, переводящий строку формата QString в формат StdString
    */
    static std::string qStringStdString(QString string);
    /*!
      \brief Метод, переводящий строку формата StdString в формат QString
    */
    static QString StdStringtoQString(std::string string);
    /*!
      \brief Метод, преобразующий строку полученную из файла в вектор
    */
    static void StrToMassive(const std::string s, std::vector <double>*massive);
    /*!
      \brief Метод, парсящий строки из файла пользователя и сохраняющий их в ветор строк
    */
    static std::vector<std::string> parseStr(std::ifstream& file);
    /*!
      \brief Метод, парсящий строки из файла с данными о измененях цен бумаг и сохраняющий из вектор строк
    */
    static std::vector<std::vector<double>> parseData(std::ifstream& file);
    /*!
      \brief Метод, создающий файл пользователя, если он еще не создан
    */
    static void createUserFile();
    /*!
      \brief Метод, возвращающий данные о пользователе, которые он прочитал из файла, с помощью метода ParseStr
    */
    static std::vector<std::string> getDataFromUserFile();
    /*!
      \brief Метод, возращающий минуту с начала открытия биржи, которая соответсвует индесу в массиве с ценнами на бумаги в эту минуту
    */
    static int whatTimeIndex();
    /*!
      \brief Метод, генерирующий цены на бумаги
    */
    static void newPrice();
    /*!
      \brief Метод, обновляющий информацию о пользователя в файле
    */
    static void addUserDataToFile(QString name, QString lastName, double profit, double moneyBox, int numberPapers);
    /*!
      \brief Метод, создающий файл инвестиций, если он еще не создан
    */
    static void createInvestmentFile();
    /*!
      \brief Метод, добавляющий в файл новую инвестицию
    */
    static void addInvestmentFile(BoughtCollection* investments);
    /*!
      \brief Метод, возвращающий вектор, хранящий информацию о инвестициях
    */
    static QVector<QStringList> getInvestmentsFromFile();
    /*!
      \brief Метод, проверяющий пустой ли файл
    */
    static bool isEmpty(std::ifstream& pFile);
};

#endif // UTILS_H
