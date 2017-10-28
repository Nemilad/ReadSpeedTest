#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Textdata base1;
    if (!base1.loadtext_file("test.txt"))
        QMessageBox::critical(this,"Ошибка","Не найден файл базы данных.\nПроверьте файлы базы данных и перезапустите прогамму");
}

MainWindow::~MainWindow()
{
    delete ui;
}


