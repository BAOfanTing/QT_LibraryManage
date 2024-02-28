#include "cell_bookmanger.h"
#include "ui_cell_bookmanger.h"


Cell_BookManger::Cell_BookManger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_BookManger)
{
    ui->setupUi(this);
    // 将数据模型与表格视图关联
    ui->tableView->setModel(&m_model);
    //不能编辑表格
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //每次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

Cell_BookManger::~Cell_BookManger()
{
    delete ui;
}

void Cell_BookManger::initPage(QString strCondition = "")
{
    //获取所有图书
    //查询数据库并显示
    QVector<QStringList> l = sqlmange::getInstance()->getBooks(strCondition);

    //清空之前的数据
    m_model.clear();

    //设置表格列头标签
    m_model.setHorizontalHeaderLabels(QStringList{"图书id","名称","价格","类别1","类别2","类别3","数量","图书封面"});

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

void Cell_BookManger::on_le_search_textChanged(const QString &arg1)
{
    //搜索图书
    //使用字符串拼接来达到模糊搜索
    QString strCond = QString("where name like '%1%' or type1 like '%2%' or type2 like '%3%' or type3 like '%4%'").arg(arg1).arg(arg1).arg(arg1).arg(arg1);
    initPage(strCond);
}


void Cell_BookManger::on_btn_add_clicked()
{
    //添加图书
    Dlg_BookAdd_Update dlg;
    dlg.exec();
    initPage();
}


void Cell_BookManger::on_btn_mod_clicked()
{

    //修改图书
    // 获取当前选中的行号
    int r = ui->tableView->currentIndex().row();

    // 判断是否选中行
    if (r < 0) {
        // 弹出错误提示框
        QMessageBox::information(nullptr, "错误", "没有选中图书");
    }
    else
    {
        QString id = m_model.item(r,0)->text();
        Dlg_BookAdd_Update dlg;
        dlg.setType(id.toInt());
        dlg.exec();
        QMessageBox::information(nullptr, "ok", "修改成功");
    }
    initPage();
}


void Cell_BookManger::on_btn_del_clicked()
{
    //删除图书
    // 获取当前选中的行号
    int r = ui->tableView->currentIndex().row();

    // 判断是否选中行
    if (r < 0) {
        // 弹出错误提示框
        QMessageBox::information(nullptr, "错误", "没有选中图书");
    }
    else
    {
        // 获取选中行的用户ID,text变为QString
        QString id = m_model.item(r, 0)->text();

        // 使用 SQLManange 类删除用户
        sqlmange::getInstance()->DelBook(id);

        // 弹出成功提示框
        QMessageBox::information(nullptr, "成功", "删除成功");

        // 刷新页面
        initPage();
    }
}


void Cell_BookManger::on_btn_return_clicked()
{
    //归还图书
}


void Cell_BookManger::on_btn_borrow_clicked()
{
    //借阅图书
}

