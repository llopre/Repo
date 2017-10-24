#include "widget.h"
#include <QApplication>
#include "login.h"
#include"admindb.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AdminDB admindb;

    if(admindb.conectar("../Ejercicio-26/baseprueba")){
        qDebug()<< "Conexion exitosa";

    }
    else{
        qDebug()<< "Sin conexion";
    }

    return a.exec();
}
