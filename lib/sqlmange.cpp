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

void sqlmange::init()
{
    // 打开数据库
    // 使用 QSQLITE 数据库驱动
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    // 设置数据库名称
    // 数据库文件位于应用程序目录下的 db/book.db 文件
    m_db.setDatabaseName(QCoreApplication::applicationDirPath() + "/db/book.db");

    // 打开数据库
    // 并输出打开结果到调试信息
    qDebug() << m_db.open();
}

bool sqlmange::login(QString strUsername, QString strPassword)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    QString strSql = QString("select * from user where username = '%1' and password = '%2'").arg(strUsername).arg(strPassword);

    // 执行 SQL 查询
    bool ret = q.exec(strSql);

    // 如果查询失败，输出错误信息
    if(!ret)
    {
        qDebug()<<q.lastError().text();
    }

    // 返回查询结果
    return ret;
}

QVector<QStringList> sqlmange::getUsers(QString strCondition)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    // 使用 strCondition 作为查询条件
    QString strSql = QString("select * from user %1").arg(strCondition);

    // 存储查询结果的容器
    QVector<QStringList> vec;


    // 执行 SQL 查询
    bool ret = q.exec(strSql);

    // 如果查询失败，输出错误信息
    if(!ret)
    {
        qDebug()<<q.lastError().text();
    }
    else
    {
        // 获取查询结果的列数
        int iCols = q.record().count();
        // 临时存储每行的查询结果
        QStringList l;

        // 遍历查询结果
        while(q.next())
        {
            // 遍历每一列
            for (int i = 0;i< iCols;i++)
            {
                // 将当前列的值添加到临时列表中
                l<<q.value(i).toString();
            }
            // 将临时列表添加到最终结果容器中
            vec.push_back(l);

            // 清空临时列表
            l.clear();
        }
    }
    // 返回查询结果
    return vec;
}

void sqlmange::DelUser(QString strID)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    QString strSql = QString("delete from user where userid = '%1'").arg(strID);
    // 执行 SQL 查询
    q.exec(strSql);
}


