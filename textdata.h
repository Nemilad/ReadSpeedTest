#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <iostream>
#include <fstream>
#include <mainwindow.h>
#include <ui_mainwindow.h>

class Textdata //база данный с текстами и тестами к ним
{
public:
    Textdata();
    Textdata(const Textdata &copy);

    void loadtext(int textnumber); //загрузить определенный текст
    bool loadtext_file(std::string filename); //загрузить базу данных
    void test_text(int textnumber); //загрузить тесты к тексту
    int get_char_count();
    int get_word_count();

private:
    size_t database_size;
};

#endif // TEXTDATA_H
