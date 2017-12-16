#include "textdata.h"

Textdata::Textdata()
{
    size=0;
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
    size=copy.size;
}

Textdata::~Textdata()
{

}

QString Textdata::loadtext(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->name!=textname)
        p=p->next;
    if (p!=NULL) return p->text;
    else return "";
}

bool Textdata::operator <<(QString filename)
{
    QFile file(filename);
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
            push_back(new text_data(temp,temp3,temp2));
        }
        file.close();
        return true;
    }
}

bool Textdata::test_text(QString textname)
{
    return false;
}

int Textdata::get_char_count()
{
    return 0;
}

int Textdata::get_word_count()
{
    return 0;
}
