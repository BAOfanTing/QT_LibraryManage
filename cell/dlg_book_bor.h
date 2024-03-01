#ifndef DLG_BOOK_BOR_H
#define DLG_BOOK_BOR_H

#include <QDialog>
#include "lib/sqlmange.h"

namespace Ui {
class Dlg_book_bor;
}

class Dlg_book_bor : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_book_bor(QWidget *parent = nullptr);
    ~Dlg_book_bor();

    void setBookID(int id);
    void setBookname(int m_bookid);
    void setType(bool isReturn);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_book_bor *ui;
    int m_bookid;
    bool m_isReturn = false;
};

#endif // DLG_BOOK_BOR_H
