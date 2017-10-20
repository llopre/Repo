#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

// ej 5, 13, 19, 27, 33

/*
    QPixmap pixMap = ui->visor->grab();  // Para llevar el QWidget a QImage
    QImage image = pixMap.toImage();

    for (int x=0 ; x<image.width() ; x++)
    {
    for (int y=0 ; y<image.height() ; y++)
    {
        QRgb rgb = image.pixel(x, y);  // typedef unsigned int QRgb;
        QRgb nuevoValorRgb = qRgb(qRed(rgb), 0, 0);
        image.setPixel(x, y, nuevoValorRgb);

        qGreen(QRgb rgb); // extrae solo el color verde (a nivel de bits)
        QRgb nuevoValorRgb = qRgb(qBlue(rgb), qGreen(rgb), qRed(rgb));
    }
}
ejercicio:
            -clase ventana con qtdesigner
            -en paintevent dibujar una imagen de disco
            -usar scaled para expandir la imagen en toda la ventana
            -colocar pushbutton "convertir"
            -al convertir capturar con grab() y llevar a BGR

ejercicio:
            -acomodar el procesamiento dentro de metodos

            Qimage getescaladegrises(qimage image);
            Qimage convertirRGBaBGR(qimage im);
            Qimage getnegativo(qimage im);

            escala de grises (y=0.3R + 0.3G + 0.3B)
*/
