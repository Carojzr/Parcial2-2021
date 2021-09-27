#include <iostream>
#include <QImage>
#include <math.h>
#include "escalar.h"
#include "rgb.h"


using namespace std;

int main()
{
    Escalar img;
    rgb matr;
    QImage *imagen;
    QImage *imagen2;
    string imgg;
    cout<<"Ingrese la direccion de ubicacion de la imagen a proyectar: ";
    getline(cin, imgg);
    imagen = new QImage(imgg.c_str());
    if(imagen->load(imgg.c_str())){
        cout << "Se cargo exitosamente la imagen" << endl;
        *imagen = imagen->convertToFormat(QImage::Format_RGB888); // formato de 3 canales rojo, verde, azul
        imagen2 =img.redimensionar(imagen);
        imagen2->save("Escalo.jpg");// para ver como se guardo
        matr.Obcolores(imagen2);
        matr.GuardarInfo();
    }
    else{
        cout << "No se pudo cargar la imagen.\nVerifique la direccion ingresada." << endl;
    }
    return 0;
}
