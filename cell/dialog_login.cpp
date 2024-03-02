#include "dialog_login.h"
#include "ui_dialog_login.h"

Dialog_login::Dialog_login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::on_btn_login_clicked()
{
    //1是成功，2是失败，0是退出
    int userid = 0;
    bool ret = sqlmange::getInstance()->login(ui->le_username->text(),ui->le_password->text(),userid);
    if(ret)
    {
        setResult(1);
        this->hide();
    }
    else
    {
        QMessageBox::information(nullptr, "信息", "账号或密码错误");
    }
}


void Dialog_login::on_btn_exit_clicked()
{
    setResult(0);
    this->hide();
}

