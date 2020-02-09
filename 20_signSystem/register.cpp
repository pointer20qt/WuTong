#include "register.h"
#include "ui_register.h"
#include <QSqlQuery>
#include "login.h"
#include <QMessageBox>
#include <QDebug>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("用户信息注册");
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
    ui->label_3->setStyleSheet("color: rgb(95, 95, 95);"
                               "font: 10pt 'Calibri';");
    ui->label_4->setStyleSheet("color: rgb(95, 95, 95);"
                               "font: 10pt 'Calibri';");
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    QString rname=ui->lineEdit->text();
    QString rpwd=ui->lineEdit_2->text();
    QString rpwd2=ui->lineEdit_3->text();
    QString rclass=ui->lineEdit_4->text();
    QSqlQuery q1;
    q1.exec(QString("select * from stuInfo where sname='%1'").arg(rname));
    if(q1.size()!=0)
    {
        QMessageBox::warning(this,"warning","用户名已存在");
    }
    else
    {
        if(rpwd!=rpwd2)
        {
            QMessageBox::warning(this,"warning","输入两次密码不一致");
        }
        else
        {
            QSqlQuery q;
            qDebug()<<q.exec(QString("insert into stuInfo(sname,pwd,class)values('%1','%2','%3')").arg(rname).arg(rpwd).arg(rclass));
            QMessageBox::information(this,"information","注册成功");
            Login *l =new Login();
            l->show();
            this->close();
        }
    }

}

void Register::on_pushButton_2_clicked()
{
    Login *l1 =new Login();
    l1->show();
    this->close();
}
