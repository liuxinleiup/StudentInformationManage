# 基于C++的QT连接数据库实现学生信息管理系统


      1.设计好界面、连接好数据库

      2.创建数据库和QT链接QSqlDatabase sqldb

      3..调用函数创建且打开数据库CreateDatabaseFunc：创建SQLLite数据库
	        添加数据库驱动
	        设置数据库名称
	        打开此数据库是否成功

      4.调用函数创建数据表CreateTableFunc
	        创建sql语句
	        执行sql语句
		        执行查询操作QueryTableFunc
		        存储结果集QSqlQueryModel sqlmodel  
          
只是实现了插入数据操作，其他操作一样的在此基础上   
