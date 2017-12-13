#include "mainwindow.h"
#include "ui_mainwindow.h"
Textdata base1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer;
    if (!(base1<<("Database1.txt")))
        QMessageBox::critical(this,"Ошибка","Не найден файл базы данных.\nПроверьте файлы базы данных и перезапустите прогамму");
    Textdata::text_data* p = base1.get_first();
    QTreeWidgetItem* temp;
    while (p!=NULL)
    {
        temp=new QTreeWidgetItem;
        temp->setText(0,p->name);
        ui->treeWidget->topLevelItem(0)->addChild(temp);
        p=p->next;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
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
        ui->textBrowser->setText(base1.loadtext(ui->treeWidget->currentItem()->text(0)));
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
