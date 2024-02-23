#ifndef SQLMANGE_H
#define SQLMANGE_H

#include <QDebug>

// sqlmange 类声明
class sqlmange
{
public:
    // 构造函数
    sqlmange();

    // 单例模式：获取类唯一实例
    static sqlmange* getInstance();

    // 测试函数
    void test();



private:
    // 私有构造函数，禁止外部直接创建对象
    sqlmange(const sqlmange&) = delete;
    // 私有赋值运算符，禁止外部直接赋值
    sqlmange& operator=(const sqlmange&) = delete;

    // 单例模式：类唯一实例指针
    static sqlmange* instance;
};

#endif // SQLMANGE_H
