#ifndef DLG_REGISTER_H
#define DLG_REGISTER_H

#include <QDialog>
#include <QMessageBox>
#include "lib/sqlmange.h"

namespace Ui {
class dlg_register;
}

class dlg_register : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_register(QWidget *parent = nullptr);
    ~dlg_register();

private slots:
    void on_btn_register_clicked();

    void on_btn_login_clicked();

private:
    Ui::dlg_register *ui;

    QString str_nickname;
    QString str_grade;
    QString str_department;
    QString str_Username;
    QString str_Password;
};

#endif // DLG_REGISTER_H
