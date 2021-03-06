#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <user_stats_window.h>
#include <graph_window.h>
#include <test_window.h>
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <textdata.h>
#include <userdata.h>
#include <QTimer>
#include <QTime>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Загрузка данных из базы
    void load_text_base(Textdata base, int base_index);

signals:
    //Отправка данных пользователя
    void sendData(UserData* out_data);
    //Отправка вопросов
    void sendQst(QStringList test_q,QStringList test_a);
    //Сигнал начала теста
    void startTest();

public slots:
    //Приём результатов теста
    void reciveResult(float und);

private slots:
    void on_pushButton_start_pressed();

    void on_pushButton_stop_pressed();

    void update_time();

    void on_stats_triggered();

    void on_save_user_data_triggered();

    void on_load_user_data_triggered();

    void on_graph_triggered();

    void on_prog_info_triggered();

private:
    Ui::MainWindow *ui;
    User_stats_window stat_form; //Форма статистики
    graph_window graph_form;     //Форма графика
    test_window* test_form;      //Форма теста
    QTimer* timer;               //Таймер
    QTime* time;                 //Время
    user_list curr_user_data;    //Последние данные пользователя
    text_data curr_text_data;    //Последние данные текста
    UserData User;               //Данные пользователя

    bool firststart=true;
};

#endif // MAINWINDOW_H
