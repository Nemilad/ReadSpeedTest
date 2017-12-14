#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <mainwindow.h>
#include <QTime>

class UserData //сохраненные данные пользователя - контейнер
{
public:
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

    UserData();
    UserData(const UserData &copy);

    //Методы списка
    void pop_all();//очистить данные пользователя
    void push_back(list* in);
    bool is_empty();
    bool save_data(std::string filename);
    bool load_data(std::string filename);
    list* get_first();

    void plot();//функция отрисовки графика зависимости скорости от времени чтения
    int get_speed_char();
    int get_speed_word();
private:
    list* first, last;
    size_t size;
};

#endif // USERDATA_H
