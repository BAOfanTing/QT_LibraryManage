#ifndef DLG_BOOKADD_UPDATE_H
#define DLG_BOOKADD_UPDATE_H

#include <QDialog>
#include "lib/sqlmange.h"

namespace Ui {
class Dlg_BookAdd_Update;
}

class Dlg_BookAdd_Update : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_BookAdd_Update(QWidget *parent = nullptr);
    ~Dlg_BookAdd_Update();

    void setType(int id);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_BookAdd_Update *ui;

    int m_id = -1;
};

#endif // DLG_BOOKADD_UPDATE_H
