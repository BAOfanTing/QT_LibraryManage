#ifndef CELL_USERMANGE_H
#define CELL_USERMANGE_H

#include <QWidget>
//#include <QStandardItemModel>

namespace Ui {
class Cell_Usermange;
}

class Cell_Usermange : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_Usermange(QWidget *parent = nullptr);
    ~Cell_Usermange();

private:
    Ui::Cell_Usermange *ui;

    //QStandardItemModel m_model;
};

#endif // CELL_USERMANGE_H
