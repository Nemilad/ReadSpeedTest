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

void graph_window::set_xy(user_list *in_p,char value)
{
    x.clear();
    y.clear();
    user_list *p=in_p;
    int count=0;
    x.append(0);
    y.append(0);
    while (p!=NULL)
    {
       x.append(count+1);
       switch (value) {
       case 'w':
           y.append(p->speed_word);
           break;
       case 'c':
           y.append(p->speed_char);
           break;
       case 'u':
           y.append(p->und_rate);
           break;
       default:
           break;
       }

       p=p->next;
       count++;
    }
    switch (value) {
    case 'w':
        plot_xy("Слова в минуту");
        break;
    case 'c':
        plot_xy("Символы в минуту");
        break;
    case 'u':
        plot_xy("Коэф. понимания");
        break;
    default:
        break;
    }
}

void graph_window::plot_xy(QString name)
{
    ui->widget_graph->clearGraphs();
    ui->widget_graph->addGraph();
    ui->widget_graph->graph(0)->setData(x,y);
    ui->widget_graph->xAxis->setLabel("Порядковый номер тестирования");
    ui->widget_graph->yAxis->setLabel(name);
    ui->widget_graph->xAxis->setRange(0, x.size()-1);
    ui->widget_graph->yAxis->setRange(0, *std::max_element(y.begin(),y.end()));
    QSharedPointer<QCPAxisTickerFixed> fixedTicker(new QCPAxisTickerFixed);
    ui->widget_graph->xAxis->setTicker(fixedTicker);
    fixedTicker->setTickStep(1.0);
    ui->widget_graph->replot();
}

void graph_window::recieveData(UserData* in_data)
{
    data=in_data;
    ui->comboBox->setCurrentIndex(0);
    set_xy(in_data->get_first(),'w');
}

void graph_window::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        set_xy(data->get_first(),'w');
        break;
    case 1:
        set_xy(data->get_first(),'c');
        break;
    case 2:
        set_xy(data->get_first(),'u');
        break;
    default:
        break;
    }
}
