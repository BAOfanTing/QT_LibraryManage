#include "cell_recordmange.h"
#include "ui_cell_recordmange.h"

Cell_RecordMange::Cell_RecordMange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_RecordMange)
{
    ui->setupUi(this);
    // 将数据模型与表格视图关联
    ui->tableView->setModel(&m_model);
    //不能编辑表格
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //每次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

Cell_RecordMange::~Cell_RecordMange()
{
    delete ui;
}

void Cell_RecordMange::on_le_search_textChanged(const QString &arg1)
{

}


void Cell_RecordMange::on_btn_del_clicked()
{

}

void Cell_RecordMange::initPage(QString strCondition = "")
{
    //获取所有图书
    //查询数据库并显示
    QVector<QStringList> l = sqlmange::getInstance()->getRecords(strCondition);

    //清空之前的数据
    m_model.clear();

    //设置表格列头标签
    m_model.setHorizontalHeaderLabels(QStringList{"图书id","用户id","价格","开始时间","结束时间","记录"});

    for(int i = 0;i<l.size();i++)
    {
        //创建一个新的行
        QList<QStandardItem *> items;
        //遍历每一列
        for(int j = 0;j<l[i].size();j++)
        {
            //创建一个新的单元格并设置文本格式
            items.append(new QStandardItem(l[i][j]));
        }
        //将行添加到表格模型中
        m_model.appendRow(items);
    }
}

