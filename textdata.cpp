#include "textdata.h"

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
    while(p->name!=textname && p!=NULL)p=p->next;
    if (p!=NULL) return p->text;
    else return "";
}

bool Textdata::operator <<(std::string filename)
{
    std::ifstream file;
    std::string temp;
    text_data temp2;
    file.open(filename);
    if(!file.is_open()) return false;
    else
    {
        while(!file.eof())
        {
            file>>temp;
            if(temp!="")temp2.name=QString::fromStdString(temp);
            file>>temp;
            if(temp!="")temp2.info=QString::fromStdString(temp);
            file>>temp;
            if(temp!="")temp2.text=QString::fromStdString(temp);

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

void Textdata::push_back(Textdata::text_data *in)
{
    if (is_empty())
    {
        first=new text_data;
        first->text=in->text;
        first->info=in->info;
        first->name=in->name;
        first->next=NULL;
        last=first;
    }
    else
    {
        text_data *p=last;
        p->next=new text_data;
        p->next->text=in->text;
        p->next->info=in->info;
        p->next->name=in->name;
        p->next->next=NULL;
        last=p->next;
    }
    database_size++;
}

Textdata::text_data *Textdata::get_first()
{
    return first;
}
