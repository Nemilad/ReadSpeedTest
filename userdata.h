#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <basedata.h>
#include <QTextStream>
#include <QFile>

//сохраненные данные пользователя - контейнер
class UserData:public BaseData<user_list>
{
public:
    UserData();
    UserData(const UserData &copy);
    //~UserData();

    bool operator <<(QString filename);
    bool operator >>(QString filename);

    //int get_speed_char();//скорость чтения в символах

    //int get_speed_word();//скорость чтения в словах


private:

};

#endif // USERDATA_H
