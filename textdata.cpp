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
            p2=p2->next;
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

QString Textdata::loadtextinfo(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->name!=textname)
        p=p->next;
    if (p!=NULL) return p->info;
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
            temp.replace("\r\n","");
            temp2=file.readLine();
            temp2.replace("\r\n","");
            temp3=file.readLine();
            temp3.replace("\r\n","");
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


int get_char_count(QString text)
{
    QString temp=text;
    temp.remove(" ");
    return temp.length();
}

int get_word_count(QString text)
{

    return text.count(' ')+1;
}
