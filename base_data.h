#ifndef BASE_DATA_H
#define BASE_DATA_H
#include <QString>
#include <QDateTime>

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

  text_data(const text_data &copy) //конструктор копирования
  {
    name=copy.name;
    text=copy.text;
    info=copy.info;
    next=copy.next;
  }
};

struct user_list
{
    int speed_char;
    int speed_word;
    float und_rate;
    //int char_count;
    //int word_count;
    QDateTime time;
    user_list* next;
    //QDateTime class - для хранения даты прочтения

    user_list()//пустой конструктор
    {
    }

    user_list(int in_speed_char,int in_speed_word,float in_und_rate,QDateTime in_time) //конструктор инициализации
    {
         speed_char=in_speed_char;
         speed_word=in_speed_word;
         und_rate=in_und_rate;
         time=in_time;
    }
    user_list(const user_list &copy) //конструктор копирования
    {
      speed_char=copy.speed_char;
      speed_word=copy.speed_word;
      und_rate=copy.und_rate;
      time=copy.time;
      next=copy.next;
    }
};

template <class Class_1>
class Base_data
{
public:
    virtual ~Base_data(){}
    virtual bool operator << (QString filename)=0;

    void push_back(Class_1* in)
    {
        if (is_empty())
        {
            first=new Class_1(*in);
            first->next=NULL;
            last=first;
        }
        else
        {
            Class_1 *p=last;
            p->next=new Class_1(*in);
            p->next->next=NULL;
            last=p->next;
        }
        size++;
    }

    size_t get_size()
    {
        return size;
    }

    bool is_empty()
    {
        return (size==0);
    }

    Class_1 *get_first()
    {
        return first;
    }

protected:
    Class_1* first;
    Class_1* last;
    size_t size;
};

#endif // BASE_DATA_H
