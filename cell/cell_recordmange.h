#ifndef CELL_RECORDMANGE_H
#define CELL_RECORDMANGE_H

#include <QWidget>

namespace Ui {
class Cell_RecordMange;
}

class Cell_RecordMange : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_RecordMange(QWidget *parent = nullptr);
    ~Cell_RecordMange();

private:
    Ui::Cell_RecordMange *ui;
};

#endif // CELL_RECORDMANGE_H
