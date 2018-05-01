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
            first->set_text(copy.first->get_text());
            first->info=copy.first->info;
            first->set_name(copy.first->get_name());
            first->next=NULL;
            p2=first;
            p=copy.first->next;
        }
        else
        {
            p2->next=new text_data;
            p2=p2->next;
            p2->set_text(p->get_text());
            p2->info=p->info;
            p2->set_name(p->get_name());
            p2->next=NULL;
            p=p->next;
        }
    }
    last=p2;
    size=copy.size;
}

QString Textdata::loadtext(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->get_name()!=textname)
        p=p->next;
    if (p!=NULL) return p->get_text();
    else return "";
}

QString Textdata::loadtextinfo(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->get_name()!=textname)
        p=p->next;
    if (p!=NULL) return p->info;
    else return "";
}

bool Textdata::operator <<(QString filename)
{
    QFile file(filename);
    QString temp,temp2,temp3;
    QStringList temp4;
    QStringList temp5;
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
            int qst_num=file.readLine().replace("\r\n","").toInt();
            for(int i=0;i<qst_num;i++)
            {
                temp4<<file.readLine().replace("\r\n","");
                temp5<<file.readLine().replace("\r\n","");
            }

            push_back(new text_data(temp,temp3,temp2,temp4,temp5));
        }
        file.close();
        return true;
    }
}

QStringList Textdata::test_qst(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->get_name()!=textname)
        p=p->next;
    if (p!=NULL)
    {
        return p->test_q;
    }
}

QStringList Textdata::test_ans(QString textname)
{
    text_data *p=first;
    while(p!=NULL && p->get_name()!=textname)
        p=p->next;
    if (p!=NULL)
    {
        return p->test_a;
    }
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
