#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <basedata.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <qfile.h>

int get_char_count(QString text);//получить кол-во символов в тексте
int get_word_count(QString text);//получить кол-во слов в тексте

//база данных с текстами и тестами к ним
class Textdata:public BaseData<text_data>
{
public:

    Textdata();
    Textdata(const Textdata &copy);
    //~Textdata();

    QString loadtext(QString textname); //найти определенный текст
    QString loadtextinfo(QString textname); //найти информацию о текте
    bool operator << (QString filename); //загрузить базу данных
    QStringList test_qst(QString textname); //загрузить вопросы к тексту
    QStringList test_ans(QString textname); //загрузить ответы к тексту

private:

};

#endif // TEXTDATA_H
