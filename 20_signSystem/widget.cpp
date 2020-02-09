#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QDateTime>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "person.h"



Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("签到信息");
    this->setWindowIcon(QIcon("://cute_128px_1185893_easyicon.net.ico"));
    ui->comboBox->setStyleSheet("color: rgb(95, 95, 95);"
                                "background-color: rgb(239, 239, 239);"
                                "font: 10pt 'Calibri';");
    ui->label->setStyleSheet("color: rgb(95, 95, 95);"
                             "font: 10pt 'Calibri';");
    ui->label_2->setStyleSheet("color: rgb(95, 95, 95);"
                               "font: 10pt 'Calibri';");
    ui->lineEdit->setStyleSheet("color: rgb(95, 95, 95);"
                             "font: 10pt 'Calibri';");
    ui->pushButton->setStyleSheet("color: rgb(95, 95, 95);"
                                  "background-color: rgb(226, 226, 226);"
                               "font: 10pt 'Calibri';");
    ui->tableWidget->setStyleSheet("background-color: rgb(239, 239, 239);"
                                   "color: rgb(95, 95, 95);"
                                   "font: 10pt 'Calibri';");
    this->sname=sname;
    dataToTable(QString("select * from stuInfo"));
    displayClass();
    displaySno();

    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        person *p=new person();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });
}
void Widget::dataToTable(QString sql)
{
    qDebug()<<this->sname;
    QSqlQuery q;
    q.exec(QString("select sno from stuInfo where sname='%1'").arg(this->sname));
    q.next();
    QString curSno=q.value(0).toString();
    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());
        int i=0;
        while(q.next())
        {
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();

            QSqlQuery q3;
            q3.exec(QString("select checkTime from checkInfo "
                            "where sno=%1 and date(checkTime)=curdate() "
                            "order by checkTime desc").arg(sno));
            q3.next();
            if(sno!=curSno)
            {
                c->setDisabled(true);
            }
            if(q3.size())
            {
                c->setText("已签到");
                c->setDisabled(true);
                c->setChecked(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));
            }

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(3).toString()));
            ui->tableWidget->setCellWidget(i,3,c);

            connect(c,QCheckBox::clicked,[=](){
                //修改控件本身状态
                c->setText("已签到");
                c->setDisabled(true);

                //向表格中添加签到时间
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));

                //向数据库中插入一条数据

                QSqlQuery q1;
                qDebug()<<q1.exec(QString("insert into checkInfo values(%1,now())").arg(sno));

            });
            i++;
        }
    }
}

void Widget::displayClass()
{
    QSqlQuery q4;
    q4.exec("select distinct class from stuInfo");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
        ui->comboBox->addItem(q4.value(0).toString());
    }

    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
           dataToTable("select * from stuInfo");
        }
        else
        {
           dataToTable(QString("select * from stuInfo where class ='%1'").arg(text));
        }
    });
}

void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","您输入为空");
        }
        else
        {
            dataToTable(QString("select * from stuInfo where sno like '%1'").arg(ui->lineEdit->text()));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
