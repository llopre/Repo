#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <iostream>
#include <QDebug>
#include "admindb.h"
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlError>
#include<QMessageBox>
#include<QSqlDatabase>
#include <QCryptographicHash>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
    AdminDB *admBase;

private slots:
    void slot_validarUsuario();
};

#endif // LOGIN_H
