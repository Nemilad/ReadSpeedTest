#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <mainwindow.h>
class UserData
{
public:
    UserData();
    UserData(const UserData &copy);
    list* get_first();
    void pop_front();
    void push_back(float _und_rate, float _time,int _char_count);
    bool is_empty();
    bool save_data(std::string filename);
    bool load_data(std::string filename);
    void plot();
    void get_speed_char();
    void get_speed_word();
private:
    struct list
    {
        int speed_char;
        int speed_word;
        float und_rate;
        int char_count;
        int word_count;
        float time;
        list* next;
    };
    list* first,last;
    size_t size;
};

#endif // USERDATA_H
