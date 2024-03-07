#include "dlg_register.h"
#include "ui_dlg_register.h"



dlg_register::dlg_register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_register)
{
    ui->setupUi(this);
}

dlg_register::~dlg_register()
{
    delete ui;
}

void dlg_register::on_btn_register_clicked()
{
    str_nickname = ui->le_nickname->text();
    str_grade = ui->le_grade->text();
    str_Username = ui->le_username->text();
    str_Password = ui->le_password->text();
    str_department = ui->le_department->text();

    int userid = 0;
    //先查询用户名密码是否存在，若若是存在则无法注册
    bool ret = sqlmange::getInstance()->login(str_Username,str_Password,userid);
    if(ret)
    {
        QMessageBox::information(nullptr,"信息","用户已经存在!");
        return ;
    }
    else
    {
        //注册新用户
        sqlmange::getInstance()->RegisterUser(str_nickname,str_grade,str_department,str_Username,str_Password);

        QMessageBox::information(nullptr,"信息","注册成功!");
        return ;
    }
}


void dlg_register::on_btn_login_clicked()
{
    this->hide();
}

