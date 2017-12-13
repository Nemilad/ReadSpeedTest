#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <mainwindow.h>
#include <QTime>

class UserData //сохраненные данные пользователя - контейнер
{
public:
    UserData();
    UserData(const UserData &copy);

    //Методы списка
    void pop_all();//очистить данные пользователя
    void push_back(float _und_rate, float _time,int _char_count, int word_count);
    bool is_empty();
    bool save_data(std::string filename);
    bool load_data(std::string filename);

    void plot();//функция отрисовки графика зависимости скорости от времени чтения
    int get_speed_char();
    int get_speed_word();
private:
    struct list
    {
        int speed_char;
        int speed_word;
        float und_rate;
        int char_count;
        int word_count;
        QTime time;
        list* next;
        //QDateTime class - для хранения даты прочтения
    };
    list* first, last;
    size_t size;
};

#endif // USERDATA_H
