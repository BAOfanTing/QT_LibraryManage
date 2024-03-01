#ifndef CELL_BOOKMANGER_H
#define CELL_BOOKMANGER_H

#include <QWidget>
#include <QWidget>
#include <QStandardItemModel>
#include "lib/sqlmange.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include "cell/dlg_bookadd_update.h"
#include "cell/dlg_book_bor.h"


namespace Ui {
class Cell_BookManger;
}

class Cell_BookManger : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookManger(QWidget *parent = nullptr);
    ~Cell_BookManger();

    //初始化界面
    void initPage(QString strCondition);

private slots:
    void on_le_search_textChanged(const QString &arg1);

    void on_btn_add_clicked();

    void on_btn_mod_clicked();

    void on_btn_del_clicked();

    void on_btn_borrow_clicked();

private:
    Ui::Cell_BookManger *ui;

    // 用户信息数据模型
    QStandardItemModel m_model;
};

#endif // CELL_BOOKMANGER_H
