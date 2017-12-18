#include "userdata.h"


UserData::UserData()
{
    size=0;
    first=NULL;
    last=NULL;
}

UserData::UserData(const UserData &copy)
{
    user_list *p=copy.first;
    user_list *p2;
    while (p!=NULL)
    {
        if(p==copy.first)
        {
            first = new user_list;
            first->speed_word=copy.first->speed_word;
            first->speed_char=copy.first->speed_char;
            first->time=copy.first->time;
            first->und_rate=copy.first->und_rate;
            first->next=NULL;
            p2=first;
            p=copy.first->next;
        }
        else
        {
            p2->next=new user_list;
            p2=p2->next;
            p2->speed_word=p->speed_word;
            p2->speed_char=p->speed_char;
            p2->time=p->time;
            p2->und_rate=p->und_rate;
            p2->next=NULL;
            p=p->next;
        }
    }
    last=p2;
    size=copy.size;
}

UserData::~UserData()
{

}

void UserData::pop_all()
{
    user_list*p;
    while (p!=NULL && first!=NULL)
    {
        p=first->next;
        if(p!=NULL)
        {
            delete first;
            first=p->next;
        }
    }
    last=NULL;
    size=0;
}

bool UserData::operator <<(QString filename)
{
    pop_all();
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return false;
    else
    {
        while(!file.atEnd())
        {
            QString temp,temp2,temp3,temp4;
            temp=file.readLine().replace("\r\n","");
            temp2=file.readLine().replace("\r\n","");
            temp3=file.readLine().replace("\r\n","");
            temp4=file.readLine().replace("\r\n","");
            push_back(new user_list(temp.toInt(),temp2.toInt(),temp3.toFloat(),QDateTime::fromString(temp4,"dd:MM:yyyy:HH:mm:ss")));
        }
        file.close();
        return true;
    }
}

bool UserData::operator >>(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    user_list *p = get_first();
    if(p==NULL)return false;
    else
    {
        while (p!=NULL)
        {
            out<<p->speed_char<<endl<<p->speed_word<<endl<<p->und_rate<<endl<<p->time.toString("dd:MM:yyyy:HH:mm:ss")<<endl;
            p=p->next;
        }
        file.close();
        return true;
    }
}
