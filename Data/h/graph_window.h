#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QWidget>
#include <qcustomplot.h>
#include <userdata.h>
#include <basedata.h>
#include <QString>
#include <QVector>

namespace Ui {
class graph_window;
}

class graph_window : public QWidget
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = 0);
    ~graph_window();
    void plot_xy(QString name);//Построение графика

public slots:
    void recieveData(UserData* in_data);//Приём данных и передача в форму

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::graph_window *ui;
    UserData* data;
    QVector<double> x, y;
    //Установка значений для графика
    void set_xy(user_list *in_p, char value);
};

#endif // GRAPH_WINDOW_H
