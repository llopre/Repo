#include "logger.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logger::getInstancia()->iniciar();

    return a.exec();
}
