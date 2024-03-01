#ifndef CELL_RECORDMANGE_H
#define CELL_RECORDMANGE_H

#include <QWidget>
#include <QStandardItemModel>
#include "lib/sqlmange.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "cell/dlg_book_bor.h"

namespace Ui {
class Cell_RecordMange;
}

class Cell_RecordMange : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_RecordMange(QWidget *parent = nullptr);
    ~Cell_RecordMange();

    void initPage(QString strCondition);

private slots:
    void on_le_search_textChanged(const QString &arg1);

    void on_btn_del_clicked();



    void on_btn_return_clicked();

private:
    Ui::Cell_RecordMange *ui;

    // 用户信息数据模型
    QStandardItemModel m_model;
};

#endif // CELL_RECORDMANGE_H
