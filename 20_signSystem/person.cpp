#include "person.h"
#include "ui_person.h"
#include <QSqlQuery>
#include <qDebug>
#include <QTextCharFormat>


person::person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);
    this->setWindowTitle("个人签到信息");
    this->setWindowIcon(QIcon("://cute_128px_1185893_easyicon.net.ico"));
    ui->label->setStyleSheet("color: rgb(95, 95, 95);"
                             "font: 10pt 'Calibri';");
    ui->label_2->setStyleSheet("color: rgb(95, 95, 95);"
                               "font: 10pt 'Calibri';");
    ui->label_3->setStyleSheet("color: rgb(95, 95, 95);"
                               "font: 10pt 'Calibri';");
    ui->calendarWidget->setStyleSheet("color: rgb(95, 95, 95);"
                                      "font: 10pt 'Calibri';");
}

void person::init(QString sno,QString sname)
{
    ui->label->setText("学号:"+sno);
    ui->label_2->setText("姓名:"+sname);

    QSqlQuery q;
    q.exec(QString("select checkTime from checkInfo "
                   "where sno=%1 and date_format(checkTime,'%Y-%m')="
                   "date_format(curdate(),'%Y-%m')").arg(sno));

    ui->label_3->setText("签到次数:"+QString::number(q.size()));

    QTextCharFormat f;
    f.setForeground(Qt::white);
    f.setBackground(Qt::gray);

    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }

}

person::~person()
{
    delete ui;
}
