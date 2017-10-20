#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    rut = QFileDialog::getOpenFileName(this, "Abrir", "./", "imagen (*.jpg *.png)");
    if(rut.isEmpty())
    {
        qDebug() << "no hay imagen cargada.... error";
        exit(1);
    }
    image.load(rut);

    connect(ui->pbConvertir, SIGNAL(pressed()), this, SLOT(slot_convetir()));
    connect(ui->pbConvertir1, SIGNAL(pressed()), this, SLOT(slot_convetir1()));
    connect(ui->pbConvertir2, SIGNAL(pressed()), this, SLOT(slot_convetir2()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    image2 = image.scaled(this->width(), this->height());
    painter.drawImage(0, 0, image2);
}

void Widget::slot_convetir()
{
    QPixmap pixMap = this->grab();
    QImage im = pixMap.toImage();

    for (int x=0 ; x<im.width() ; x++)
    {
        for (int y=0 ; y<im.height() ; y++)
        {
            QRgb rgb = im.pixel(x, y);
            QRgb nuevoValorRgb = qRgb(qBlue(rgb), qGreen(rgb), qRed(rgb));
            im.setPixel(x, y, nuevoValorRgb);
        }
    }
    image = im;
    repaint();
}

void Widget::slot_convetir1()
{
    QPixmap pixMap = this->grab();
    QImage im = pixMap.toImage();

    for (int x=0 ; x<im.width() ; x++)
    {
        for (int y=0 ; y<im.height() ; y++)
        {
            QRgb rgb = im.pixel(x, y);
            int bn = (0,1 * qRed(rgb) + 0,1 * qGreen(rgb) + 0,1 * qBlue(rgb));
            QRgb nuevoValorRgb = qRgb( bn, bn, bn);
            im.setPixel(x, y, nuevoValorRgb);
        }
    }
    image = im;
    repaint();
}

void Widget::slot_convetir2()
{
    QPixmap pixMap = this->grab();
    QImage im = pixMap.toImage();

    for (int x=0 ; x<im.width() ; x++)
    {
        for (int y=0 ; y<im.height() ; y++)
        {
            QRgb rgb = im.pixel(x, y);
            QRgb nuevoValorRgb = qRgb(qBlue(rgb) & 0xff , qGreen(rgb) & 0xff, qRed(rgb) & 0xff);
            im.setPixel(x, y, nuevoValorRgb);
        }
    }
    image = im;
    repaint();
}
