#ifndef CELL_BOOKMANGER_H
#define CELL_BOOKMANGER_H

#include <QWidget>

namespace Ui {
class Cell_BookManger;
}

class Cell_BookManger : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookManger(QWidget *parent = nullptr);
    ~Cell_BookManger();

private:
    Ui::Cell_BookManger *ui;
};

#endif // CELL_BOOKMANGER_H
