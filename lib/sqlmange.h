#ifndef SQLMANGE_H
#define SQLMANGE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>

// sqlmange 类声明
class sqlmange
{
public:
    // 构造函数
    sqlmange();

    // 单例模式：获取类唯一实例
    static sqlmange* getInstance();

    //初始化数据库
    void init();

    //登陆
    bool login(QString strUsername ,QString strPassword);

    //获取所有用户
    QVector<QStringList> getUsers(QString strCondition = "");

    //添加用户
    void AddUser(QVector<QStringList>);

    //删除用户
    void DelUser(QString strID);

    //获取所有图书
    QVector<QStringList> getBooks(QString strCondition = "");

    //增加图书
    void AddBook(QVector<QStringList>);

    //修改图书
    void ModBook(QString strID);
    //删除图书
    void DelBook(QString strID);

    //图书归还,谁还的，还的什么书
    QString ReturnBook(QString strUserID, QString strBookID);

    //图书借阅，谁借的，借的什么书
    QString BorrowBook(QString strUserID, QString strBookID);

    //获取借阅记录
    QVector<QStringList> getRecords(QString strCondition = "");

    //清空记录
    QString clearRecord();

private:
    // 私有构造函数，禁止外部直接创建对象
    sqlmange(const sqlmange&) = delete;
    // 私有赋值运算符，禁止外部直接赋值
    sqlmange& operator=(const sqlmange&) = delete;

    // 单例模式：类唯一实例指针
    static sqlmange* instance;

    //实例化数据库
    QSqlDatabase m_db;
};

#endif // SQLMANGE_H
