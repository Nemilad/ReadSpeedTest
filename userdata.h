#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <mainwindow.h>
#include <base_data.h>

class UserData:public Base_data<user_list> //сохраненные данные пользователя - контейнер
{
public:
    UserData()
    {
        size=0;
        first=NULL;
        last=NULL;
    }

    UserData(const UserData &copy)
    {
        user_list *p=copy.first;
        user_list *p2;
        while (p!=NULL)
        {
            if(p==copy.first)
            {
                first = new user_list;
                first->speed_word=copy.first->speed_word;
                first->speed_char=copy.first->speed_char;
                first->time=copy.first->time;
                first->und_rate=copy.first->und_rate;
                first->next=NULL;
                p2=first;
                p=copy.first->next;
            }
            else
            {
                p2->next=new user_list;
                p2->speed_word=p->speed_word;
                p2->speed_char=p->speed_char;
                p2->time=p->time;
                p2->und_rate=p->und_rate;
                p2->next=NULL;
                p=p->next;
            }
        }
        last=p2;
        size=copy.size;
    }

    void pop_all()//очистить данные пользователя
    {

    }

    bool operator <<(QString filename)
    {
        QFile file(filename);

        return true;
    }

    bool operator >>(QString filename)
    {
        QFile file(filename);

        return true;
    }

    void plot()//метод отрисовки графика зависимости скорости от времени чтения
    {

    }

    int get_speed_char()//скорость чтения в символах
    {

        return 0;
    }

    int get_speed_word()//скорость чтения в словах
    {

        return 0;
    }

private:
    //user_list* first;
    //user_list* last;
    //size_t size;
};

#endif // USERDATA_H
