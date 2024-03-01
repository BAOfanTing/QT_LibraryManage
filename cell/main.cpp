#include "cell_main.h"
#include <QApplication>
#include "dialog_login.h"
#include "lib/sqlmange.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 获取 SQLManange 类的单例实例并初始化数据库连接
    sqlmange::getInstance()->init();

    Dialog_login dlg;
    int ret = dlg.exec();

    // 如果对话框返回值为1，则显示主窗口
    if (ret == 1)
    {
        Cell_Main w;
        w.show();
        return a.exec();
    }
    // 如果对话框返回值为0，则退出程序
    else if (ret == 0)
    {
        exit(0);
        return 0;
    }
    return 0;
}
