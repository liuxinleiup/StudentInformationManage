#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QSqlDatabase>//连接和创建
#include <QSqlQuery>   //专用于DML数据库操作语言、DDL数据库定义语言
#include <QSqlQueryModel> //存储结果集
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSort_clicked();

    void on_pushButton_INSERT_clicked();

    void on_pushButton_DELETE_clicked();

    void on_pushButton_UPDATE_clicked();

    void on_pushButton_SEARCH_clicked();



private://自定义函数
    void CreateDatabaseFunc();  //创建SQLite数据库
    void CreateTableFunc();     //创建数据库表
    void QueryTableFunc();      //执行查询操作

    QSqlDatabase sqldb;         //创建数据库和QT链接
    QSqlQueryModel sqlmodel;    //存储结果集



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
