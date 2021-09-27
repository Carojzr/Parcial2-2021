#ifndef RGB_H
#define RGB_H
#include <QImage>
#include <math.h>
#include <fstream>


class rgb
{
private:
int matriz[3][12][12];
int colorR;
int colorG;
int colorB;

public:
    rgb();
    int leds=12;
    void Obcolores(QImage *imagen);
    void GuardarInfo();
};

#endif // RGB_H
