#include "mainwindow.h"
#include "ui_mainwindow.h"

Textdata<text_data> base1,base2,base3,base4,base5;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer;
    if (!(base1<<("Database1.txt")) || !(base2<<("Database2.txt")) || !(base3<<("Database3.txt")) || !(base4<<("Database4.txt")) || !(base5<<("Database5.txt")))
        QMessageBox::critical(this,"Ошибка","Не найден файл базы данных.\nПроверьте файлы базы данных и перезапустите прогамму");
    else
    {
        load_text_base(base1,0);
        load_text_base(base2,1);
        load_text_base(base3,2);
        load_text_base(base4,3);
        load_text_base(base5,4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_text_base(Textdata<text_data> base,int base_index)
{
    text_data* p = base.get_first();
    QTreeWidgetItem* temp;
    while (p!=NULL)
    {
        temp=new QTreeWidgetItem;
        temp->setText(0,p->name);
        ui->treeWidget->topLevelItem(base_index)->addChild(temp);
        p=p->next;
    }
}

void MainWindow::on_pushButton_start_pressed()
{
    if(ui->treeWidget->currentItem()->childCount()==0)
    {
        delete time;
        delete timer;
        time=new QTime(0,0,0,0); //обнуление времени
        timer=new QTimer;
        ui->time_label->setText(time->toString("HH:mm:ss"));
        if (ui->treeWidget->currentItem()->parent()->text(0)=="Тексты 1 уровня") ui->textBrowser->setText(base1.loadtext(ui->treeWidget->currentItem()->text(0)));
        if (ui->treeWidget->currentItem()->parent()->text(0)=="Тексты 2 уровня") ui->textBrowser->setText(base2.loadtext(ui->treeWidget->currentItem()->text(0)));
        if (ui->treeWidget->currentItem()->parent()->text(0)=="Тексты 3 уровня") ui->textBrowser->setText(base3.loadtext(ui->treeWidget->currentItem()->text(0)));
        if (ui->treeWidget->currentItem()->parent()->text(0)=="Тексты 4 уровня") ui->textBrowser->setText(base4.loadtext(ui->treeWidget->currentItem()->text(0)));
        if (ui->treeWidget->currentItem()->parent()->text(0)=="Тексты 5 уровня") ui->textBrowser->setText(base5.loadtext(ui->treeWidget->currentItem()->text(0)));
        ui->treeWidget->setEnabled(false);
        connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
        timer->start(1000);
    }
}

void MainWindow::on_pushButton_stop_pressed()
{
    timer->stop();
    ui->textBrowser->setText("");
    ui->treeWidget->setEnabled(true);
}

void MainWindow::update_time()
{
    time=new QTime (time->addSecs(1));
    ui->time_label->setText(time->toString("HH:mm:ss"));
}
