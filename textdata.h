#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <base_data.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <qfile.h>


class Textdata:public Base_data<text_data> //база данный с текстами и тестами к ним
{
public:

    Textdata();
    Textdata(const Textdata &copy);
    ~Textdata();

    QString loadtext(QString textname); //загрузить определенный текст
    bool operator << (QString filename); //загрузить базу данных
    bool test_text(QString textname); //загрузить тесты к тексту
    int get_char_count();
    int get_word_count();

    //bool is_empty();//проверка на пустоту
    //size_t get_size();//получить размер
    //void push_back(text_data *in);//добавить текст
    //text_data* get_first();


private:
    //size_t size;
    //Class_1* first;
    //Class_1* last;
};

#endif // TEXTDATA_H
