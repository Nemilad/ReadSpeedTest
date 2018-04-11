#ifndef BaseData_H
#define BaseData_H
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <string.h>

struct text_data
{
    QString info;//информация о тексте
    text_data* next;//ссылка на следующий элемент

    //пустой конструктор
    text_data()
    {
    }

    //конструктор инициализации
    text_data(QString in_name,QString in_text,QString in_info,QStringList in_test_q,QStringList in_test_a)
    {
        if(in_text!="")text=in_text;
        if(in_name!="")name=in_name;
        info=in_info;
        test_q=in_test_q;
        test_a=in_test_a;
        //memcpy(test_q,in_test_q,sizeof(test_q));
        //memcpy(test_a,in_test_a,sizeof(test_a));
    }

    //конструктор копирования
    text_data(const text_data &copy)
    {
        name=copy.name;
        text=copy.text;
        info=copy.info;
        next=copy.next;
        test_q=copy.test_q;
        test_a=copy.test_a;
        //memcpy(test_q,copy.test_q,sizeof(test_q));
        //memcpy(test_a,copy.test_a,sizeof(test_a));
    }

    void set_name(QString in_name)
    {
        if(in_name!="")name=in_name;
    }

    void set_text(QString in_text)
    {
        if(in_text!="")text=in_text;
    }

    QString get_text()
    {
        return text;
    }

    QString get_name()
    {
        return name;
    }

    QStringList test_q;//Вопросы
    QStringList test_a;//Варианты ответа
private:
    QString name;//название текста
    QString text;//текст

};

struct user_list
{
    int speed_char;
    int speed_word;
    float und_rate;
    QDateTime time;
    user_list* next;

    user_list()//пустой конструктор
    {
    }
    //конструктор инициализации
    user_list(int in_speed_char,int in_speed_word,float in_und_rate,
              QDateTime in_time)
    {
        speed_char=in_speed_char;
        speed_word=in_speed_word;
        und_rate=in_und_rate;
        time=in_time;
    }
    //конструктор копирования
    user_list(const user_list &copy)
    {
        speed_char=copy.speed_char;
        speed_word=copy.speed_word;
        und_rate=copy.und_rate;
        time=copy.time;
        next=copy.next;
    }

private:

};

template <class Class_1>
class BaseData
{
public:
    ~BaseData()
    {
        Class_1*p;
        while (p!=NULL && first!=NULL)
        {
            p=first->next;
            if(p!=NULL)
            {
                delete first;
                first=p;
            }
        }
        last=NULL;
        size=0;
    }

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

    Class_1 *get_last()
    {
        return last;
    }

    void pop_all()
    {
        Class_1*p;
        while (p!=NULL && first!=NULL)
        {
            p=first->next;
            if(p!=NULL)
            {
                delete first;
                first=p;
            }
        }
        last=NULL;
        size=0;
    }

protected:
    Class_1* first;
    Class_1* last;
    size_t size;
};

#endif // BaseData_H
