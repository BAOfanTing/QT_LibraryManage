#include "cell_recordmange.h"
#include "ui_cell_recordmange.h"

Cell_RecordMange::Cell_RecordMange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_RecordMange)
{
    ui->setupUi(this);
    //不能编辑表格
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //每次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

Cell_RecordMange::~Cell_RecordMange()
{
    delete ui;
}
