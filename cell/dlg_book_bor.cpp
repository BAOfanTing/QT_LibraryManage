#include "dlg_book_bor.h"
#include "ui_dlg_book_bor.h"

Dlg_book_bor::Dlg_book_bor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_book_bor)
{
    ui->setupUi(this);
}

Dlg_book_bor::~Dlg_book_bor()
{
    delete ui;
}

void Dlg_book_bor::setBookID(int id)
{
    m_bookid = id;
    //查询对于id的书本名
    auto l = sqlmange::getInstance()->getBooks(QString("where bookid = %1").arg(m_bookid));

    //显示在label上
    ui->lb_bookname->setText(QString("图书名称： "+l[0][1]));
}

void Dlg_book_bor::setType(bool isReturn)
{
    //设置是归还还是借阅，并显示在页面上
    m_isReturn = isReturn;
    if(m_isReturn)
    {
        ui->btn_ok->setText("归还");
    }
    else
    {
        ui->btn_ok->setText("借阅");
    }
}

void Dlg_book_bor::on_btn_ok_clicked()
{

    // 判断用户名密码是否正确
    do
    {
        // 获取用户名和密码
        QString username = ui->le_username->text();
        QString password = ui->le_password->text();

        // 用户 ID
        int m_userid = 0;

        // 登录验证
        bool ret = sqlmange::getInstance()->login(username, password, m_userid);

        // 登录失败
        if (!ret)
        {
            // 关闭对话框
            this->done(0);

            // 退出循环
            break;
        }
        if(m_isReturn)
        {
            //图书归还
            sqlmange::getInstance()->ReturnBook(QString::number(m_userid), QString::number(m_bookid));
        }
        else
        {
            // 图书借阅
            sqlmange::getInstance()->BorrowBook(QString::number(m_userid), QString::number(m_bookid));
        }

        // 关闭对话框并返回成功状态
        this->done(1);

    } while (false);
}


void Dlg_book_bor::on_btn_cancel_clicked()
{

    this->done(0);
}

