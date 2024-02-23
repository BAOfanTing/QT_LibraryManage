#ifndef CELL_MAIN_H
#define CELL_MAIN_H

#include <QMainWindow>
#include "cell_bookmanger.h"  // 图书管理类头文件
#include "cell_usermange.h"   // 用户管理类头文件
#include "cell_recordmange.h" // 记录管理类头文件

// Qt 命名空间开始
QT_BEGIN_NAMESPACE
namespace Ui {
class Cell_Main;
}
QT_END_NAMESPACE

// 主窗口类，继承 QMainWindow
class Cell_Main : public QMainWindow
{
    Q_OBJECT

public:
    // 构造函数，可选父窗口
    Cell_Main(QWidget *parent = nullptr);
    // 析构函数
    ~Cell_Main();
    // 初始化页面
    void initPage();

    void dealMenu();
private:
    // UI 界面指针
    Ui::Cell_Main *ui;
    // 图书管理页面指针
    Cell_BookManger * m_bookpage;
    // 用户管理页面指针
    Cell_Usermange * m_userpage;
    // 记录管理页面指针
    Cell_RecordMange * m_recordpage;

};

#endif // CELL_MAIN_H
