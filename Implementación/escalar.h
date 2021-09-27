#ifndef ESCALAR_H
#define ESCALAR_H
#include <iostream>
#include <QImage>
#include <math.h>

class Escalar
{
public:
    Escalar();
    QImage *redimensionar(QImage *imagen);
    float pixel = 12;

    QRgb combinar(QRgb r1, QRgb r2){
        return qRgb((qRed(r1)+qRed(r2))/2, (qGreen(r1)+qGreen(r2))/2, (qBlue(r1)+qBlue(r2))/2);
    }
};
#endif // ESCALAR_H
