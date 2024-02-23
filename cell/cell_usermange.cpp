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

  // 设置表格列头标签
  m_model.setHorizontalHeaderLabels(QStringList{"用户ID", "姓名", "年级", "所属学院", "权限", "用户名", "密码"});

  // 创建一行示例用户数据
  QList<QStandardItem *> items;
  items.append(new QStandardItem("1"));
  items.append(new QStandardItem("小明"));
  items.append(new QStandardItem("1年1班"));
  items.append(new QStandardItem("机械学院"));
  items.append(new QStandardItem("学生"));
  items.append(new QStandardItem("xiaoming"));
  items.append(new QStandardItem("123456"));

  // 将示例数据添加至模型
  m_model.appendRow(items);
}

// Cell_Usermange 类析构函数实现
Cell_Usermange::~Cell_Usermange()
{
  // 释放 UI 界面指针
  delete ui;
}
