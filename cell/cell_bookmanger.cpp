#include "cell_bookmanger.h"
#include "ui_cell_bookmanger.h"

Cell_BookManger::Cell_BookManger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_BookManger)
{
    ui->setupUi(this);
}

Cell_BookManger::~Cell_BookManger()
{
    delete ui;
}
