#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <base_data.h>
#include <QTextStream>
#include <QFile>

class UserData:public Base_data<user_list> //сохраненные данные пользователя - контейнер
{
public:
    UserData();
    UserData(const UserData &copy);
    ~UserData();

    void pop_all();//очистить данные пользователя
    bool operator <<(QString filename);
    bool operator >>(QString filename);

    void plot();//метод отрисовки графика зависимости скорости от времени чтения

    int get_speed_char();//скорость чтения в символах

    int get_speed_word();//скорость чтения в словах


private:

};

#endif // USERDATA_H
