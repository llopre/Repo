#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    admBase = new AdminDB;

    connect(ui->pbEntrar, SIGNAL(clicked(bool)),this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()),this, SLOT(slot_validarUsuario()));

}

Login::~Login()
{
    delete ui;
}


void Login::slot_validarUsuario(){

    bool usuarioValido=false;

    if(admBase->getDB().isOpen()){
        QSqlQuery *query= new QSqlQuery(admBase->getDB());
        query->exec("SELECT * FROM basePrueba WHERE nombre='"+ui->leNombre->text()+"' AND clave='"+ui->leClave->text()+"'");
        while(query->next()){
            QSqlRecord record= query->record();
            int columnaDelNombre=record.indexOf("nombre");
            int columnaDeClave=record.indexOf("clave");
            qDebug() << "Bienvenido" << query->value(columnaDelNombre).toString() << " " << query->value(columnaDeClave).toString();
            usuarioValido=true;
        }
    }
    if(usuarioValido) {

                this->hide();
               QMessageBox::information(this,"Informacion","Datos correctos");
    }
    else {
        QMessageBox::critical(this,"Sin Permisos", "Datos Incorrectos");
     ui->leClave->setFocus();
     }

 }
