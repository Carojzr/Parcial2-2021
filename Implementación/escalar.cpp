#include "escalar.h"
#include <iostream>
#include <QImage>
#include <math.h>
#include <fstream>
Escalar::Escalar()
{

}

QImage *Escalar::redimensionar(QImage *imagen)
{
    //vecino mas cercano
    float Zw = pixel/imagen->width(); // anchoOriginal*factorEscala=anchoEscalado
    float Zh = pixel/imagen->height();
    int w = round(imagen->width()*Zw);// ancho original * factor de escala(zoom)
    int h = round(imagen->height()*Zh);
    int Nptx = 1, Npty = 1;
    float x = 1.0, y = 1.0;

    QImage *redimagen = new QImage(w,h,QImage::Format_RGB888);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            x = j/Zw;
            y = i/Zh;
            Nptx = x;
            Npty = y;
            if((x-Nptx > 0.5) && (Nptx+1 < w)) Nptx+=1; //comprueba si el punto esta mas cerca de x y lo cumple si no se sale de la dimension
            if((y-Npty > 0.5) && (Npty+1 < h)) Npty+=1;
            redimagen->setPixel(j,i,imagen->pixel(Nptx,Npty)); // asigno a la nueva imagen las posiciones de los puntos o pixeles encontrados
        }
    }
    return redimagen;
}
