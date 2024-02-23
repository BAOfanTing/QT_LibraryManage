#include "cell_bookmanger.h"
#include "ui_cell_bookmanger.h"

Cell_BookManger::Cell_BookManger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_BookManger)
{
    ui->setupUi(this);
    //不能编辑表格
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //每次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

Cell_BookManger::~Cell_BookManger()
{
    delete ui;
}
