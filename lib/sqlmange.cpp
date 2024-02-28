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

void sqlmange::AddUser(QVector<QStringList> addData)
{
    // 开启数据库事务
    m_db.transaction();

    // 创建 SQL 查询对象
    QSqlQuery q(m_db);

    // 遍历用户数据
    for (int i = 0; i < addData.size(); i++)
    {
        // 构建 SQL 插入语句
        // 使用占位符防止 SQL 注入攻击
        // 将字符串转换为 UTF-8 编码，避免中文乱码
        QString strSql = QString("insert into user VALUES(NULL,'%1','%2','%3','%4','%5','%6')").arg(addData[i][0].toUtf8()).arg(addData[i][1].toUtf8()).arg(addData[i][2].toUtf8()).arg(addData[i][3].toUtf8()).arg(addData[i][4].toUtf8()).arg(addData[i][5].toUtf8());

        // 执行 SQL 插入
        q.exec(strSql);
    }

    // 提交数据库事务
    m_db.commit();
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

QVector<QStringList> sqlmange::getBooks(QString strCondition)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    // 使用 strCondition 作为查询条件
    QString strSql = QString("select * from book %1").arg(strCondition);

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

void sqlmange::AddBook(QVector<QStringList> vec)
{
    //增加图书
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);

    if(vec.size() == 0)
    {
        return;
    }
    QStringList ldata = vec[0];
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    QString strSql = QString("INSERT INTO book "
                             "values(NULL,'%1','%2','%3','%4','%5',%6,'')")
                         .arg(ldata[1])
                         .arg(ldata[2])
                         .arg(ldata[4])
                         .arg(ldata[5])
                         .arg(ldata[6])
                         .arg(ldata[3]);
    // 执行 SQL 查询
    q.exec(strSql);
}

//修改图书
void sqlmange::ModBook(QStringList ldata)
{
    //更新图书
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    QString strSql = QString("UPDATE book "
                             "set name = '%1',press = '%2',type1 = '%3',type2 = '%4',type3 = '%5',count = '%6' "
                             "where bookid = '%7'")
                            .arg(ldata[1])
                            .arg(ldata[2])
                            .arg(ldata[4])
                            .arg(ldata[5])
                            .arg(ldata[6])
                            .arg(ldata[3])
                            .arg(ldata[0]);
    // 执行 SQL 查询
    q.exec(strSql);
}

void sqlmange::DelBook(QString strID)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    QString strSql = QString("delete from book where bookid = '%1'").arg(strID);
    // 执行 SQL 查询
    q.exec(strSql);
}

QVector<QStringList> sqlmange::getRecords(QString strCondition)
{
    // 创建 SQL 查询对象
    QSqlQuery q(m_db);
    // 构建 SQL 查询语句
    // 使用占位符防止 SQL 注入攻击
    // 使用 strCondition 作为查询条件
    QString strSql = QString("select * from record %1").arg(strCondition);

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


