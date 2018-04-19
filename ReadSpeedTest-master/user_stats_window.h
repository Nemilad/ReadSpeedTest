#ifndef USER_STATS_WINDOW_H
#define USER_STATS_WINDOW_H

#include <QWidget>
#include <userdata.h>
#include <basedata.h>
#include <QString>

namespace Ui {
class User_stats_window;
}

class User_stats_window : public QWidget
{
    Q_OBJECT

public:
    explicit User_stats_window(QWidget *parent = 0);
    ~User_stats_window();

public slots:
    void recieveData(UserData* in_data);//Приём данных и передача в форму

private:
    Ui::User_stats_window *ui;
    UserData* user;
};

#endif // USER_STATS_WINDOW_H
