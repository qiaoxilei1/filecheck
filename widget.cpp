#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QString>
#include <QFileInfo>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    testfunction();
    Lession3lib lib;
    this->setWindowFlags(Qt::FramelessWindowHint);   //去掉界面边框
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();


    shadow->setBlurRadius(10);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);


    ui->shadowWidget->setGraphicsEffect(shadow);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    QPoint y = event->globalPos();  //鼠标相对于桌面坐标
    QPoint x = y - this->z;
    this->move(x);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    this->z = QPoint();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QPoint y = event->globalPos();  //鼠标相对于桌面坐标
    QPoint x = this->geometry().topLeft();   //窗口左上角相对于桌面左上角

    this->z = y - x;    //定值 不变的

}

QStringList Widget::getfiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    for(int i = 0; i<infolist.count();++i)
    {
        QFileInfo info = infolist.at(i);
        if(info.isDir())
        {
            QString subDir = info.absoluteFilePath();
            QStringList files = getfiles(subDir);
            ret.append(files);
        }
        else
        {
            QString fileName = info.absoluteFilePath();
            ret.append(fileName);
        }
    }
    return ret;
}

QByteArray Widget::getfileMd5(const QString &filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
            QByteArray content = file.read(100*1024*1024);
            hash.addData(content);
            qApp->processEvents();
        }
        QByteArray md5 = hash.result().toHex();
        //qDebug() << md5 << " " << md5.toHex();

        file.close();
        return md5;
    }
    return QByteArray();
}

void Widget::on_butclose_clicked()
{
    this->close();
}

void Widget::on_butmax_clicked()
{
    if(this->isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}

void Widget::on_butmin_clicked()
{
    this->showMinimized();
}

void Widget::on_pushButton_clicked()
{
    QFile file("H:/hello.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
            QByteArray content = file.read(100*1024*1024);
            hash.addData(content);
            qApp->processEvents();
        }
        QByteArray md5 = hash.result();
        qDebug() << md5 << " " << md5.toHex();

        file.close();

    }
}

void Widget::on_pushButton_2_clicked()
{
    QStringList files = getfiles("H:/qt/day01/lession3lib");

    for(int i =0;i<files.count();++i)
    {
        QString fileName = files.at(i);
        QByteArray md5 = getfileMd5(fileName);
        qDebug() << "filename:" << fileName << "md5:" << md5;
        fileMd5[md5].append(fileName);
    }
    for(QHash<QByteArray,QStringList>::iterator itr= fileMd5.begin();itr!=fileMd5.end(); ++itr)
    {
        qDebug()<<"Md5:" << itr.key()<< "count:"<<itr.value().count();
        if(itr.value().count()>1)
        {
            qDebug() << "file:" << itr.value();
        }
    }
    //qDebug() << files;
}
