#include "cell_usermange.h"
#include "ui_cell_usermange.h"

Cell_Usermange::Cell_Usermange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_Usermange)
{
    ui->setupUi(this);
}

Cell_Usermange::~Cell_Usermange()
{
    delete ui;
}
