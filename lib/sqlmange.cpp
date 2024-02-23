#include "sqlmange.h"

// sqlmange 类唯一实例指针初始化
sqlmange* sqlmange::instance = nullptr;

// sqlmange 类构造函数实现
sqlmange::sqlmange() {}

// sqlmange 类获取实例函数实现
// 如果实例不存在，则创建新实例并赋值给 instance 指针
// 然后返回 instance 指针
sqlmange* sqlmange::getInstance()
{
    if (nullptr == instance) {
        instance = new sqlmange();
    }
    return instance;
}

// sqlmange 类测试函数实现
// 输出 "test" 到调试信息
void sqlmange::test()
{
    qDebug() << "test";
}
