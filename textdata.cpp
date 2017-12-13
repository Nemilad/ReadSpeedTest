#include "textdata.h"
#include <qfile.h>
Textdata::Textdata()
{
    database_size=0;
    first=NULL;
    last=NULL;
}

Textdata::Textdata(const Textdata &copy)
{
    text_data *p=copy.first;
    text_data *p2;
    while (p!=NULL)
    {
        if(p==copy.first)
        {
            first = new text_data;
            first->text=copy.first->text;
            first->info=copy.first->info;
            first->name=copy.first->name;
            first->next=NULL;
            p2=first;
            p=copy.first->next;
        }
        else
        {
            p2->next=new text_data;
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

QString Textdata::loadtext(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->name!=textname)
        p=p->next;
    if (p!=NULL) return p->text;
    else return "";
}

bool Textdata::operator <<(std::string filename)
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
            push_back(temp3,temp2,temp);
        }
        file.close();
        return true;
    }
}

bool Textdata::is_empty()
{
    return (database_size==0);
}

size_t Textdata::get_size()
{
    return database_size;
}

void Textdata::push_back(QString in_text,QString in_info,QString in_name)
{
    if (is_empty())
    {
        first=new text_data;
        first->text=in_text;
        first->info=in_info;
        first->name=in_name;
        first->next=NULL;
        last=first;
    }
    else
    {
        text_data *p=last;
        p->next=new text_data;
        p->next->text=in_text;
        p->next->info=in_info;
        p->next->name=in_name;
        p->next->next=NULL;
        last=p->next;
    }
    database_size++;
}

Textdata::text_data *Textdata::get_first()
{
    return first;
}
