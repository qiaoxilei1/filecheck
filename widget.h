#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Lession3lib.h"
#include <QMap>
#include <QHash>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    QStringList getfiles(const QString &path);
    QByteArray getfileMd5(const QString &filename);
private slots:
    void on_butclose_clicked();

    void on_butmax_clicked();

    void on_butmin_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QPoint z;
    QHash<QByteArray, QStringList> fileMd5;
};
#endif // WIDGET_H
