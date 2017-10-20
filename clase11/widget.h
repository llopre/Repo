#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
#include <QCameraViewfinder>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;

    QImage image, image2;
    QString rut;

private slots:
    void slot_convetir();
    void slot_convetir1();
    void slot_convetir2();
};

#endif // WIDGET_H
