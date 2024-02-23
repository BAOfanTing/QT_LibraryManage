#include "cell_main.h"
#include "ui_cell_main.h"

#include <QPushButton>
#include <QDebug>
Cell_Main::Cell_Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cell_Main)
    , m_bookpage(nullptr)
    , m_userpage(nullptr)
    , m_recordpage(nullptr)
{
    ui->setupUi(this); // 设置 UI 界面
    initPage();
}

Cell_Main::~Cell_Main()
{
    delete ui;
}

// 初始化页面函数实现
void Cell_Main::initPage()
{
    // 创建用户管理、图书管理、记录管理页面对象
    m_userpage = new Cell_Usermange(this);
    m_bookpage = new Cell_BookManger(this);
    m_recordpage = new Cell_RecordMange(this);

    // 将页面添加到层叠窗口部件中
    ui->stackedWidget->addWidget(m_userpage);
    ui->stackedWidget->addWidget(m_bookpage);
    ui->stackedWidget->addWidget(m_recordpage);

    // 设置初始显示第一个页面（用户管理）
    ui->stackedWidget->setCurrentIndex(0);

    // 获取工具栏所有按钮
    auto l = ui->tool->children();

    // 遍历所有按钮
    for (auto it : l) {
        // 判断是否是按钮
        if (it->objectName().contains("btn")) {
            // 将按钮转换为 QPushButton 类型
            QPushButton *btn = static_cast<QPushButton *>(it);

            // 连接按钮点击事件与槽函数
            connect(btn, &QPushButton::clicked, this, &Cell_Main::dealMenu);
        }
    }
}

// 处理菜单栏按钮点击事件函数实现
void Cell_Main::dealMenu()
{
    //调试显示按钮名称
    qDebug()<<sender()->objectName();

    // 获取发送信号的按钮对象
    QPushButton *btn = static_cast<QPushButton *>(sender());

    // 获取按钮对象名称
    auto str = btn->objectName();

    // 根据按钮名称判断要显示的页面
    do {
        if (str == "btn_user") {
            // 显示用户管理页面
            ui->stackedWidget->setCurrentIndex(0);
            break;
        } else if (str == "btn_book") {
            // 显示图书管理页面
            ui->stackedWidget->setCurrentIndex(1);
            break;
        } else if (str == "btn_record") {
            // 显示记录管理页面
            ui->stackedWidget->setCurrentIndex(2);
            break;
        }
    } while (true);
}
