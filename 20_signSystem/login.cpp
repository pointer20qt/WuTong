#include "login.h"
#include "ui_login.h"
#include <QPushButton>
#include "Widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "register.h"


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("签到系统");
    this->setWindowIcon(QIcon("://cute_128px_1185893_easyicon.net.ico"));
    ui->pushButton->setStyleSheet("width: 75px;"
                                   "height: 25px;"
                                   "background-color: rgb(211, 211, 211);");
    ui->pushButton_2->setStyleSheet("width: 75px;"
                                    "height: 25px;"
                                    "background-color: rgb(211, 211, 211);");
    ui->label->setStyleSheet("color: rgb(95, 95, 95);"
                             "font: 10pt 'Calibri';");
    ui->label_2->setStyleSheet("color: rgb(95, 95, 95);"
                             "font: 10pt 'Calibri';");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("student");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open())
    {
        qDebug()<<"打开数据库成功";
    }
    else
    {
        qDebug()<<"打开数据库失败";
    }


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString sname=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();

    QSqlQuery q;

    q.exec(QString("select * from stuInfo where sname='%1'").arg(sname));
    q.next();
    if(q.size()>0)
    {
        q.exec(QString("select * from stuInfo where sname='%1' and pwd='%2'").arg(sname).arg(pwd));
        if(q.size()>0)
        {
            Widget *w=new Widget(NULL,sname);
            w->show();
            this->close();

        }
        else
        {
            QMessageBox::warning(this,"warning","密码不正确");
        }
    }
    else
    {
        QMessageBox::warning(this,"warning","用户不存在");
    }

}

void Login::on_pushButton_2_clicked()
{
    Register *r= new Register();
    r->show();
    this->close();
}
