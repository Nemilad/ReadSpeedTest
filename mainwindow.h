#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <textdata.h>
#include <userdata.h>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void load_text_base(Textdata base, int base_index);

private slots:
    void on_pushButton_start_pressed();
    void on_pushButton_stop_pressed();
    void update_time();
private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QTime* time;
};

#endif // MAINWINDOW_H
