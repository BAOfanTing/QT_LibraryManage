#ifndef CELL_MAIN_H
#define CELL_MAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Cell_Main;
}
QT_END_NAMESPACE

class Cell_Main : public QMainWindow
{
    Q_OBJECT

public:
    Cell_Main(QWidget *parent = nullptr);
    ~Cell_Main();

private:
    Ui::Cell_Main *ui;
};
#endif // CELL_MAIN_H
