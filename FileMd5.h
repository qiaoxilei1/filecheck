#ifndef FILEMD5_H
#define FILEMD5_H

#include <QObject>

class FileMd5 : public QObject
{
    Q_OBJECT
public:
    explicit FileMd5(QObject *parent = 0);

signals:

public slots:
};

#endif // FILEMD5_H