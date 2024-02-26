#include "cell_usermange.h"
#include "ui_cell_usermange.h"

// Cell_Usermange 类构造函数实现
Cell_Usermange::Cell_Usermange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_Usermange)
{
  // 设置 UI 界面
  ui->setupUi(this);

  // 将数据模型与表格视图关联
  ui->tableView->setModel(&m_model);
  //不能编辑表格
  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  //每次选中一行
  ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  // // 设置表格列头标签
  // m_model.setHorizontalHeaderLabels(QStringList{"用户ID", "姓名", "年级",  "权限","所属学院", "用户名", "密码"});

  // // 创建一行示例用户数据
  // QList<QStandardItem *> items;
  // items.append(new QStandardItem("1"));
  // items.append(new QStandardItem("小明"));
  // items.append(new QStandardItem("1年1班"));
  // items.append(new QStandardItem("机械学院"));
  // items.append(new QStandardItem("学生"));
  // items.append(new QStandardItem("xiaoming"));
  // items.append(new QStandardItem("123456"));

  // // 将示例数据添加至模型
  // m_model.appendRow(items);
}

// Cell_Usermange 类析构函数实现
Cell_Usermange::~Cell_Usermange()
{
  // 释放 UI 界面指针
    delete ui;
}

void Cell_Usermange::initPage(QString strCondition = "")
{
    //查询数据库并且显示
    QVector<QStringList> l = sqlmange::getInstance()->getUsers(strCondition);

    // 清空之前的数据，以便显示新的查询结果
    m_model.clear();

    // 设置表格列头标签
    m_model.setHorizontalHeaderLabels(QStringList{"用户ID", "姓名", "年级", "权限","所属学院", "用户名", "密码"});

    for(int i = 0;i<l.size();i++)
    {
        // 创建一个新的行
        QList<QStandardItem *> items;

        // 遍历每一列
        for(int j = 0;j<l[i].size();j++)
        {
            // 创建一个新的单元格项并设置文本
            items.append(new QStandardItem(l[i][j]));
        }
        // 将行添加到表格模型中
        m_model.appendRow(items);
    }
}



void Cell_Usermange::on_btn_del_clicked()
{
    // 删除用户
    // 获取当前选中的行号
    int r = ui->tableView->currentIndex().row();

    // 判断是否选中行
    if (r < 0) {
        // 弹出错误提示框
        QMessageBox::information(nullptr, "错误", "没有选中用户");
    } else {
        // 获取选中行的用户ID,text变为QString
        QString id = m_model.item(r, 0)->text();

        // 使用 SQLManange 类删除用户
        sqlmange::getInstance()->DelUser(id);

        // 弹出成功提示框
        QMessageBox::information(nullptr, "成功", "删除成功");

        // 刷新页面
        initPage();
    }
}


void Cell_Usermange::on_btn_import_clicked()
{
    //导入用户并显示
    // 打开文件选择对话框
    QString strPath = QFileDialog::getOpenFileName(nullptr,"请输入文件路径");
    if(!strPath.isEmpty())
    {
        // 打开 CSV 文件
        QFile f(strPath);
        f.open(QFile::ReadOnly|QFile::Text);

        // 定义一个用于存储用户数据的容器
        QVector<QStringList> addData;
        while(!f.atEnd())
        {
           // 读取一行数据
            QString str = f.readLine();

            // 将一行数据分割成字符串列表
            QStringList l = str.split(",");

            // 判断列数是否正确
            if (l.size() != 6)
            {
                // 弹出错误提示框
                QMessageBox::information(nullptr, "错误", "导入失败，列数对不上");
                return;
            }

            // 删除字符串末尾的换行符
            l[l.size() - 1].chop(2);

            // 将数据添加到容器中
            addData.push_back(l);
        }

        // 弹出成功提示框
        QMessageBox::information(nullptr, "成功", "导入成功");

        // 使用 SQLManange 类添加用户
        sqlmange::getInstance()->AddUser(addData);

        // 刷新页面
        initPage();

    }
}

void Cell_Usermange::on_le_search_textChanged(const QString &text)
{
    //搜索用户
    //使用字符串拼接来达到模糊搜索
    QString strCond = QString("where username like '%1%' or nickname like '%2%'").arg(text).arg(text);
    initPage(strCond);
}

