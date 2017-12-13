#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <mainwindow.h>
#include <ui_mainwindow.h>

class Textdata //база данный с текстами и тестами к ним
{
public:
    struct text_data
    {
      QString name;//название текста
      QString text;//текст
      QString info;//информация о тексте
      text_data* next;//ссылка на следующий элемент
    };

    Textdata();
    Textdata(const Textdata &copy);

    QString loadtext(QString textname); //загрузить определенный текст
    bool operator << (std::string filename); //загрузить базу данных
    bool test_text(QString textname); //загрузить тесты к тексту
    int get_char_count();
    int get_word_count();

    bool is_empty();//проверка на пустоту
    size_t get_size();//получить размер
    void push_back(QString in_text,QString in_info,QString in_name);//добавить текст
    text_data* get_first();

private:
    size_t database_size;
    text_data* first;
    text_data* last;
};

#endif // TEXTDATA_H
