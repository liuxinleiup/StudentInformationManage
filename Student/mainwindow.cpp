#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //调用函数创建且打开数据库
    CreateDatabaseFunc();
    //调用函数创建数据表
    CreateTableFunc();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//创建SQLLite数据库
void MainWindow::CreateDatabaseFunc(){
    //1.添加数据库驱动
    sqldb = QSqlDatabase::addDatabase("QSQLITE");

    //2.设置数据库名称
    sqldb.setDatabaseName("studentmis.db");

    //3.打开此数据库是否成功
    if(sqldb.open()==true){
        QMessageBox::information(0,"正确","恭喜你，数据库打开成功！",QMessageBox::Ok);
    }else{
        QMessageBox::critical(0,"错误","数据库打开失败，请重新检查！",QMessageBox::Ok);
    }

}


//创建数据库表
void MainWindow::CreateTableFunc(){
    QSqlQuery createquery;

    //创建sql语句
    QString strsql=QString("create table student("
                             "id int primary key not null,"
                             "name text not null,"
                             "score real not null)"
                           );
    //执行sql语句
    if(createquery.exec(strsql)==false){
        QMessageBox::critical(0,"失败","数据表创建失败，请重新检查！",QMessageBox::Ok);
    }else{
        QMessageBox::information(0,"成功","恭喜你，数据表创建成功！",QMessageBox::Ok);
    }
}


//执行查询操作
void MainWindow::QueryTableFunc(){


}






//排序
void MainWindow::on_pushButtonSort_clicked()
{

}

//插入
void MainWindow::on_pushButton_INSERT_clicked()
{
    QSqlQuery sqlquery;


    int id=ui->lineEdit_ID->text().toInt();
    //学号
    if(id == 0){
        QMessageBox::critical(this,"失败","提示：输入错误，因为学生的学号不能为0!",QMessageBox::Ok);
        return ;
    }
    //姓名
    QString name=ui->lineEdit_NAME->text();
    if(name == ""){
        QMessageBox::critical(this,"失败","提示：输入错误，因为姓名不能为空!",QMessageBox::Ok);
        return ;
    }
    //分数
    double score=ui->lineEdit_SCORE->text().toDouble();
    if(score>100 || score<0){
        QMessageBox::critical(this,"失败","提示：输入错误，分数范围(0-100)!",QMessageBox::Ok);
        return ;
    }

    //注意student后面一个空格
    QString strs=QString("insert into student "
                         "values(%1,%2,%3)").arg(id).arg(name).arg(score);

    //执行sql语句
    if(sqlquery.exec(strs)==false){
        QMessageBox::critical(0,"失败","向数据表插入失败，请重新检查！",QMessageBox::Ok);
    }else{
        QMessageBox::information(0,"成功","恭喜你，向数据表插入成功！",QMessageBox::Ok);
    }
}

//删除
void MainWindow::on_pushButton_DELETE_clicked()
{

}

//更新
void MainWindow::on_pushButton_UPDATE_clicked()
{

}


void MainWindow::on_pushButton_SEARCH_clicked()
{

}

