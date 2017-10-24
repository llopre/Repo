#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    //explicit AdminDB(QObject *parent = 0);

    AdminDB();
    ~AdminDB();

    bool conectar(QString nombreBase);

    QVector<QStringList>select(QString comando);

    QSqlDatabase getDB();

private:
    QSqlDatabase db;



signals:

public slots:
};

#endif // ADMINDB_H
