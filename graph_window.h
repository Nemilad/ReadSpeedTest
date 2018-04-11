#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QWidget>

namespace Ui {
class graph_window;
}

class graph_window : public QWidget
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = 0);
    ~graph_window();

private:
    Ui::graph_window *ui;
};

#endif // GRAPH_WINDOW_H
