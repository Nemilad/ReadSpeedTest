#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <basedata.h>
#include <QTextStream>
#include <QFile>

//Сохраненные данные пользователя - контейнер
class UserData:public BaseData<user_list>
{
public:
    UserData();
    UserData(const UserData &copy);

    bool operator <<(QString filename);//Чтение файла
    bool operator >>(QString filename);//Запись файла
};

#endif // USERDATA_H
