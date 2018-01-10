#ifndef TEST_WINDOW_H
#define TEST_WINDOW_H

#include <QDialog>
#include <QButtonGroup>
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
    test_window* get_test_window();

    void update_qst();

public slots:
    void recieveData(QStringList test_q, QStringList test_a);//приём данных и передача в форму
    void startTest();//начало теста

private slots:
    void on_pushButton_next_pressed();

    void on_pushButton_prev_pressed();

signals:
    void result(float und);

private:
    Ui::test_window *ui;
    QButtonGroup butt_num;//группа кнопок выбора ответа
    int curr_qst_num;//номер текущего вопроса
    QStringList qst;//все вопросы
    QStringList ans;//все варианты ответов
    QStringList ans_var;//верные ответы
    QStringList user_ans;//ответы пользователя
    QString curr_ans[4];//текущие варианты ответа
};

#endif // TEST_WINDOW_H
