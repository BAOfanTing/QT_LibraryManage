#include "cell_main.h"
#include "ui_cell_main.h"

Cell_Main::Cell_Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cell_Main)
{
    ui->setupUi(this);
}

Cell_Main::~Cell_Main()
{
    delete ui;
}
