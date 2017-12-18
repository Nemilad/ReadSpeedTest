#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <base_data.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <qfile.h>

int get_char_count(QString text);//получить кол-во символов в тексте
int get_word_count(QString text);//получить кол-во слов в тексте

class Textdata:public Base_data<text_data> //база данный с текстами и тестами к ним
{
public:

    Textdata();
    Textdata(const Textdata &copy);
    ~Textdata();

    QString loadtext(QString textname); //найти определенный текст
    QString loadtextinfo(QString textname); //найти информацию о текте
    bool operator << (QString filename); //загрузить базу данных
    bool test_text(QString textname); //загрузить тесты к тексту


private:

};

#endif // TEXTDATA_H
