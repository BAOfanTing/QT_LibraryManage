#include "dlg_bookadd_update.h"
#include "ui_dlg_bookadd_update.h"

Dlg_BookAdd_Update::Dlg_BookAdd_Update(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_BookAdd_Update)
{
    ui->setupUi(this);
}

Dlg_BookAdd_Update::~Dlg_BookAdd_Update()
{
    delete ui;
}

// 函数声明：设置书籍ID
void Dlg_BookAdd_Update::setType(int l)
{
    // 将参数l赋值给成员变量m_id
    m_id = l;
}

// 函数声明：确认按钮槽函数
void Dlg_BookAdd_Update::on_btn_ok_clicked()
{
    // 定义一个QStringList用于存储书籍信息
    QStringList l;

    // 将书籍ID转换为QString并添加到l中
    l << QString::number(m_id);

    // 将书名、价格、数量、分类1、分类2、分类3添加到l中
    l << ui->le_name->text();
    l << ui->le_press->text();
    l << ui->le_count->text();
    l << ui->cb1->currentText();
    l << ui->cb2->currentText();
    l << ui->cb3->currentText();
    l << "";
    qDebug()<< l;
    // 判断m_id是否为-1
    if (-1 != m_id) {
        // 更新书籍信息
        sqlmange::getInstance()->ModBook(l);
    } else {
        // 添加新书籍
        QVector<QStringList> vec;
        vec.push_back(l);
        sqlmange::getInstance()->AddBook(vec);
        QMessageBox::information(nullptr, "成功", "添加图书成功");  
    }
    this->hide();

}



void Dlg_BookAdd_Update::on_btn_cancel_clicked()
{
    this->hide();
}

