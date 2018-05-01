#ifndef TEST_WINDOW_H
#define TEST_WINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QButtonGroup>
#include <cstdlib>
#include <ctime>
#include <random>

namespace Ui {
class test_window;
}

class test_window : public QDialog
{
    Q_OBJECT

public:
    explicit test_window(QWidget *parent = 0);
    ~test_window();
    void closeEvent(QCloseEvent *e);
    test_window* get_test_window();
    void update_qst();//Обновление окна

public slots:
    void recieveData(QStringList test_q, QStringList test_a);//Приём данных и передача в форму
    void startTest();//Начало теста

private slots:
    void on_pushButton_next_pressed();
    void on_pushButton_prev_pressed();

signals:
    void result(float und);//Передача результата

private:
    Ui::test_window *ui;
    QButtonGroup butt_num;//Группа кнопок выбора ответа
    int curr_qst_num;     //Номер текущего вопроса
    QStringList qst;      //Все вопросы
    QStringList ans;      //Все варианты ответов
    QStringList ans_var;  //Верные ответы
    QStringList user_ans; //Ответы пользователя
    QString curr_ans[4];  //Текущие варианты ответа

    bool testended;       //Проверка окончания теста
};

#endif // TEST_WINDOW_H
