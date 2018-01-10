#include "user_stats_window.h"
#include "ui_user_stats_window.h"

User_stats_window::User_stats_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_stats_window)
{
    ui->setupUi(this);
}

User_stats_window::~User_stats_window()
{
    delete ui;
}

void User_stats_window::recieveData(UserData* in_data)
{
    ui->treeWidget->clear();
    user=in_data;
    user_list* temp=user->get_first();
    while(temp!=NULL)
    {
        QTreeWidgetItem *temp_item=new QTreeWidgetItem;
        temp_item->setText(0,temp->time.toString("dd.MM.yyyy HH:mm:ss"));
        temp_item->setText(1,QString::number(temp->speed_word));
        temp_item->setText(2,QString::number(temp->speed_char));
        temp_item->setText(3,QString::number(temp->und_rate));
        ui->treeWidget->addTopLevelItem(temp_item);
        temp=temp->next;
    }
}
