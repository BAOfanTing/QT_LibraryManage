#ifndef CELL_USERMANGE_H
#define CELL_USERMANGE_H

#include <QWidget>
#include <QStandardItemModel>
#include "lib/sqlmange.h"
#include <QMessageBox>

// 命名空间声明
namespace Ui {
class Cell_Usermange;
}

// Cell_Usermange 类声明
class Cell_Usermange : public QWidget
{
    Q_OBJECT

public:
    // 构造函数，接受父窗口指针作为参数
    explicit Cell_Usermange(QWidget *parent = nullptr);

    // 析构函数
    ~Cell_Usermange() override;

    void initPage(QString strCondition);

private slots:


    void on_btn_del_clicked();


    void on_btn_import_clicked();

private:
    // UI 界面指针
    Ui::Cell_Usermange *ui;

    // 用户信息数据模型
    QStandardItemModel m_model;
};

#endif // CELL_USERMANGE_H
