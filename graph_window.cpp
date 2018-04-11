#include "graph_window.h"
#include "ui_graph_window.h"

graph_window::graph_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graph_window)
{
    ui->setupUi(this);
}

graph_window::~graph_window()
{
    delete ui;
}
