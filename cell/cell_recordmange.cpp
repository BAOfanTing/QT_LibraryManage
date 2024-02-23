#include "cell_recordmange.h"
#include "ui_cell_recordmange.h"

Cell_RecordMange::Cell_RecordMange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_RecordMange)
{
    ui->setupUi(this);
}

Cell_RecordMange::~Cell_RecordMange()
{
    delete ui;
}
