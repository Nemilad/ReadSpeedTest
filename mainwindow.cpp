#include "mainwindow.h"
#include "ui_mainwindow.h"

Textdata base1,base2,base3,base4,base5;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer;
    //загрузка баз данных
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
    //Подключение сигналов форм статистики и графика
    connect(this, SIGNAL(sendData(UserData*)), &stat_form, SLOT(recieveData(UserData*)));
    connect(this, SIGNAL(sendData(UserData*)), &graph_form, SLOT(recieveData(UserData*)));
    //установка таймера
    time=new QTime(0,0,0,0);
    timer=new QTimer;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_text_base(Textdata base, int base_index)
{
    text_data* p = base.get_first();
    QTreeWidgetItem* temp;
    while (p!=NULL)
    {
        temp=new QTreeWidgetItem;
        temp->setText(0,p->get_name());
        ui->treeWidget->topLevelItem(base_index)->addChild(temp);
        p=p->next;
    }
}

void MainWindow::reciveResult(float und)
{
    //приём данных из тестовой формы
   test_form->close();
   curr_user_data.und_rate=und;
   curr_user_data.speed_char=curr_user_data.speed_char*curr_user_data.und_rate;//коррекция скорости чтения
   curr_user_data.speed_word=curr_user_data.speed_word*curr_user_data.und_rate;//коррекция скорости чтения
   User.get_last()->und_rate=und;
   User.get_last()->speed_char=curr_user_data.speed_char;//коррекция скорости чтения
   User.get_last()->speed_word=curr_user_data.speed_word;//коррекция скорости чтения
}

void MainWindow::on_pushButton_start_pressed()
{
    //настройка окна тестов
    if(!firststart) delete test_form;
    firststart=false;
    test_form=new test_window;
    connect(this, SIGNAL(sendQst(QStringList,QStringList)), test_form->get_test_window(), SLOT(recieveData(QStringList,QStringList)));
    connect(this,SIGNAL(startTest()),test_form->get_test_window(),SLOT(startTest()));
    connect(test_form->get_test_window(),SIGNAL(result(float)),this,SLOT(reciveResult(float)));

    ui->pushButton_stop->setEnabled(true);
    ui->pushButton_start->setEnabled(false);
    if(ui->treeWidget->currentItem()->childCount()==0)
    {
        delete time;
        delete timer;
        time=new QTime(0,0,0,0); //обнуление времени
        timer=new QTimer;
        ui->time_label->setText(time->toString("HH:mm:ss"));
        QTreeWidgetItem* curitem=ui->treeWidget->currentItem();
        //загрузка из базы данных
        if (curitem->parent()->text(0)=="Тексты 1 уровня")
        {
            curr_text_data.set_name(curitem->text(0));
            curr_text_data.set_text(base1.loadtext(curitem->text(0)));
            curr_text_data.info=base1.loadtextinfo(curitem->text(0));
            emit (sendQst(base1.test_qst(curitem->text(0)),base1.test_ans(curitem->text(0))));
            ui->textBrowser->setText(curr_text_data.get_name()+"\n"
                                     +curr_text_data.info+"\n"
                                     +curr_text_data.get_text());
        }
        if (curitem->parent()->text(0)=="Тексты 2 уровня")
        {
            curr_text_data.set_name(curitem->text(0));
            curr_text_data.set_text(base2.loadtext(curitem->text(0)));
            curr_text_data.info=base2.loadtextinfo(curitem->text(0));
            emit (sendQst(base2.test_qst(curitem->text(0)),base2.test_ans(curitem->text(0))));
            ui->textBrowser->setText(curr_text_data.get_name()+"\n"
                                     +curr_text_data.info+"\n"
                                     +curr_text_data.get_text());
        }
        if (curitem->parent()->text(0)=="Тексты 3 уровня")
        {
            curr_text_data.set_name(curitem->text(0));
            curr_text_data.set_text(base3.loadtext(curitem->text(0)));
            curr_text_data.info=base3.loadtextinfo(curitem->text(0));
            emit (sendQst(base3.test_qst(curitem->text(0)),base3.test_ans(curitem->text(0))));
            ui->textBrowser->setText(curr_text_data.get_name()+"\n"
                                     +curr_text_data.info+"\n"
                                     +curr_text_data.get_text());
        }
        if (curitem->parent()->text(0)=="Тексты 4 уровня")
        {
            curr_text_data.set_name(curitem->text(0));
            curr_text_data.set_text(base4.loadtext(curitem->text(0)));
            curr_text_data.info=base4.loadtextinfo(curitem->text(0));
            emit (sendQst(base4.test_qst(curitem->text(0)),base4.test_ans(curitem->text(0))));
            ui->textBrowser->setText(curr_text_data.get_name()+"\n"
                                     +curr_text_data.info+"\n"
                                     +curr_text_data.get_text());
        }
        if (curitem->parent()->text(0)=="Тексты 5 уровня")
        {
            curr_text_data.set_name(curitem->text(0));
            curr_text_data.set_text(base5.loadtext(curitem->text(0)));
            curr_text_data.info=base5.loadtextinfo(curitem->text(0));
            emit (sendQst(base5.test_qst(curitem->text(0)),base5.test_ans(curitem->text(0))));
            ui->textBrowser->setText(curr_text_data.get_name()+"\n"
                                     +curr_text_data.info+"\n"
                                     +curr_text_data.get_text());
        }
        ui->treeWidget->setEnabled(false);
        connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
        timer->start(1000);
    }
}

void MainWindow::on_pushButton_stop_pressed()
{
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_start->setEnabled(true);
    timer->stop();
    ui->textBrowser->setText("");
    ui->treeWidget->setEnabled(true);

    if (QTime(0, 0, 0).secsTo
            (QTime(time->hour(), time->minute(), time->second()))!=0)
    {
        curr_user_data.speed_char=(
                    get_char_count
                    (curr_text_data.get_text())/((QTime(0, 0, 0).secsTo
                       (QTime
                        (time->hour(), time->minute(), time->second())))))*60;
        curr_user_data.speed_word=(
                    get_word_count
                    (curr_text_data.get_text())/((QTime(0, 0, 0).secsTo
                       (QTime
                        (time->hour(), time->minute(), time->second())))))*60;
    }
    else
    {
        curr_user_data.speed_char=0;
        curr_user_data.speed_word=0;
    }
    curr_user_data.time=QDateTime::currentDateTime();
    curr_user_data.und_rate=0;


    test_form->setWindowModality(Qt::ApplicationModal);//окно теста
    test_form->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    test_form->show();
    emit(startTest());
    User.push_back(new user_list(curr_user_data));//сохранение данных
}

void MainWindow::update_time()
{
    time=new QTime (time->addSecs(1));
    ui->time_label->setText(time->toString("HH:mm:ss"));
}

void MainWindow::on_stats_triggered()
{
    stat_form.setWindowModality(Qt::ApplicationModal);
    stat_form.show();
    emit sendData(new UserData(User));
}

void MainWindow::on_save_user_data_triggered()
{
    User>>QFileDialog::getSaveFileName(this,"save","",tr("*.txt"));
}

void MainWindow::on_load_user_data_triggered()
{
    User<<QFileDialog::getOpenFileName(this,"load","",tr("*.txt"));
}

void MainWindow::on_graph_triggered()
{
    graph_form.setWindowModality(Qt::ApplicationModal);
    graph_form.show();
    emit sendData(new UserData(User));
}
