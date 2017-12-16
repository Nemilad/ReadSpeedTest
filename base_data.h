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
            first=new Class_1;
            first->text=in->text;
            first->info=in->info;
            first->name=in->name;
            first->next=NULL;
            last=first;
        }
        else
        {
            Class_1 *p=last;
            p->next=new Class_1;
            p->next->text=in->text;
            p->next->info=in->info;
            p->next->name=in->name;
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
