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
    //搜索记录
    //使用字符串拼接来达到模糊搜索
    QString strCond = QString("where userid like '%1%' or bookid like '%2%'").arg(arg1).arg(arg1);
    initPage(strCond);
}


void Cell_RecordMange::on_btn_del_clicked()
{
    sqlmange::getInstance()->clearRecord();
    QMessageBox::information(nullptr, "信息", "清除成功");
    initPage("");
}

void Cell_RecordMange::initPage(QString strCondition = "")
{
    //获取所有图书
    //查询数据库并显示
    QVector<QStringList> l = sqlmange::getInstance()->getRecords(strCondition);

    //清空之前的数据
    m_model.clear();

    //设置表格列头标签
    m_model.setHorizontalHeaderLabels(QStringList{"id","图书id","用户id","开始时间","结束时间","记录"});

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


void Cell_RecordMange::on_btn_return_clicked()
{
    //借阅图书
    // 获取当前选中的行号
    int r = ui->tableView->currentIndex().row();

    // 判断是否选中行
    if (r < 0) {
        // 弹出错误提示框
        QMessageBox::information(nullptr, "错误", "没有选中图书");
    }
    else
    {
        // 获取选中行的图书ID,text变为QString
        QString id = m_model.item(r, 0)->text();

        //执行借阅
        Dlg_book_bor dlg;

        //传入bookid
        dlg.setBookID(id.toInt());
        dlg.setType(true);
        int ret = dlg.exec();

        // 弹出成功提示框
        QMessageBox::information(nullptr, "信息", ret?"归还成功":"归还失败，账号或者密码错误");

        // 刷新页面
        initPage();
    }
}

