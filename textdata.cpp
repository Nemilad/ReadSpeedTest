/*
#include "textdata.h"
#include <qfile.h>

template <class Class_1>
Textdata<Class_1>::Textdata()
{
    database_size=0;
    first=NULL;
    last=NULL;
}
template <class Class_1>
Textdata<Class_1>::Textdata(const Textdata &copy)
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

template <class Class_1>
Textdata<Class_1>::~Textdata()
{

}

template <class Class_1>
QString Textdata<Class_1>::loadtext(QString textname)
{
    Class_1 *p=first;
    while(p!=NULL && p->name!=textname)
        p=p->next;
    if (p!=NULL) return p->text;
    else return "";
}

template <class Class_1>
bool Textdata<Class_1>::operator <<(std::string filename)
{
    QFile file(QString::fromStdString(filename));
    QString temp,temp2,temp3;
    if(!file.open(QIODevice::ReadOnly)) return false;
    else
    {
        while(!file.atEnd())
        {
            temp=file.readLine();
            temp.truncate(temp.length()-1);
            temp.truncate(temp.length()-1);
            temp2=file.readLine();
            temp2.truncate(temp2.length()-1);
            temp2.truncate(temp2.length()-1);
            temp3=file.readLine();
            temp3.truncate(temp3.length()-1);
            temp3.truncate(temp3.length()-1);
            push_back(new Class_1(temp,temp3,temp2));
        }
        file.close();
        return true;
    }
}

template <class Class_1>
bool Textdata<Class_1>::is_empty()
{
    return (database_size==0);
}

template <class Class_1>
size_t Textdata<Class_1>::get_size()
{
    return database_size;
}

template <class Class_1>
void Textdata<Class_1>::push_back(Class_1* in)
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

template <class Class_1>
Class_1 *Textdata<Class_1>::get_first()
{
    return first;
}
*/
