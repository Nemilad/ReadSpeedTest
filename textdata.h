#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <basedata.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <qfile.h>

int get_char_count(QString text);//Получить кол-во символов в тексте
int get_word_count(QString text);//Получить кол-во слов в тексте

//База данных с текстами и тестами к ним
class Textdata:public BaseData<text_data>
{
public:

    Textdata();
    Textdata(const Textdata &copy);
    //Методы класса
    QString loadtext(QString textname);     //Найти определенный текст
    QString loadtextinfo(QString textname); //Найти информацию о текте
    bool operator << (QString filename);    //Загрузить базу данных
    QStringList test_qst(QString textname); //Загрузить вопросы к тексту
    QStringList test_ans(QString textname); //Загрузить ответы к тексту
};

#endif // TEXTDATA_H
