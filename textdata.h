#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <base_data.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <qfile.h>
#include <mainwindow.h>
#include <ui_mainwindow.h>

template <class Class_1>
class Textdata:public Base_data<Class_1> //база данный с текстами и тестами к ним
{
public:
    /*
    Textdata();
    Textdata(const Textdata &copy);
    ~Textdata();

    QString loadtext(QString textname); //загрузить определенный текст
    bool operator << (std::string filename); //загрузить базу данных
    bool test_text(QString textname); //загрузить тесты к тексту
    int get_char_count();
    int get_word_count();

    bool is_empty();//проверка на пустоту
    size_t get_size();//получить размер
    void push_back(Class_1 *in);//добавить текст
    Class_1* get_first();
*/
    //template <class Class_1>
    Textdata()
    {
        database_size=0;
        first=NULL;
        last=NULL;
    }
    //template <class Class_1>
    Textdata(const Textdata &copy)
    {
        Class_1 *p=copy.first;
        Class_1 *p2;
        while (p!=NULL)
        {
            if(p==copy.first)
            {
                first = new Class_1;
                first->text=copy.first->text;
                first->info=copy.first->info;
                first->name=copy.first->name;
                first->next=NULL;
                p2=first;
                p=copy.first->next;
            }
            else
            {
                p2->next=new Class_1;
                p2->text=p->text;
                p2->info=p->info;
                p2->name=p->name;
                p2->next=NULL;
                p=p->next;
            }
        }
        last=p2;
        database_size=copy.database_size;
    }

    //template <class Class_1>
    ~Textdata()
    {}

    //template <class Class_1>
    QString loadtext(QString textname)
    {
        Class_1 *p=first;
        while(p!=NULL && p->name!=textname)
            p=p->next;
        if (p!=NULL) return p->text;
        else return "";
    }

    //template <class Class_1>
    bool operator <<(std::string filename)
    {
        QFile file(QString::fromStdString(filename));
        QString temp,temp2,temp3;
        if(!file.open(QIODevice::ReadOnly)) return false;
        else
        {
            while(!file.atEnd())
            {
                temp=file.readLine();
                temp.replace("\r\n","");
                temp2=file.readLine();
                temp2.replace("\r\n","");
                temp3=file.readLine();
                temp3.replace("\r\n","");
                push_back(new Class_1(temp,temp3,temp2));
            }
            file.close();
            return true;
        }
    }

    //template <class Class_1>
    bool is_empty()
    {
        return (database_size==0);
    }

    //template <class Class_1>
    size_t get_size()
    {
        return database_size;
    }

    //template <class Class_1>
    void push_back(Class_1* in)
    {
        if (is_empty())
        {
            first=new Class_1;
            first->text=in->text;
            first->info=in->info;
            first->name=in->name;
            first->next=NULL;
            last=first;
        }
        else
        {
            Class_1 *p=last;
            p->next=new Class_1;
            p->next->text=in->text;
            p->next->info=in->info;
            p->next->name=in->name;
            p->next->next=NULL;
            last=p->next;
        }
        database_size++;
    }

    //template <class Class_1>
    Class_1 *get_first()
    {
        return first;
    }

private:
    size_t database_size;
    Class_1* first;
    Class_1* last;
};

#endif // TEXTDATA_H
