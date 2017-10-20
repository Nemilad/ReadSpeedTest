#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <iostream>
#include <mainwindow.h>
#include <ui_mainwindow.h>

class Textdata //база данный с текстами и тестами к ним
{
public:
    Textdata();
    Textdata(const Textdata &copy);

    void loadtext(int textnumber);
    bool loadtext_file(std::string filename);
    void test_text(int textnumber);

    int get_char_count();
    int get_word_count();

private:
    size_t database_size;
};

#endif // TEXTDATA_H
