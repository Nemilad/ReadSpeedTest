#ifndef BASE_DATA_H
#define BASE_DATA_H
#include <QString>
struct text_data
{
  QString name;//название текста
  QString text;//текст
  QString info;//информация о тексте
  text_data* next;//ссылка на следующий элемент

  text_data()//пустой конструктор
  {
  }

  text_data(QString in_name,QString in_text,QString in_info) //конструктор инициализации
  {
      text=in_text;
      name=in_name;
      info=in_info;
  }

};
template <class Class_1>
class Base_data
{
public:
    virtual ~Base_data(){}
    virtual void push_back(Class_1* in)=0;
private:
    Class_1* first,last;

};

#endif // BASE_DATA_H
