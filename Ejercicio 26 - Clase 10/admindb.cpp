#include "admindb.h"

 AdminDB::~AdminDB(){}

AdminDB::AdminDB(){

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("../Ejercicio 26 - Clase 10/baseprueba");
    db.open();
}


bool AdminDB::conectar(QString nombreBase){

    db.setDatabaseName(nombreBase);
    if(db.open()){
        return true;
    }
    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}
