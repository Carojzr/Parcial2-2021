#include "rgb.h"
#include <iostream>
#include <QImage>
#include <math.h>
#include <fstream>
using namespace std;
rgb::rgb()
{

}

void rgb::Obcolores(QImage *imagen) // funcion para obtener los valores de cada pixel
{

    for(int fila = 0; fila < imagen->height(); fila++){ // recorre matriz
        for(int columna = 0; columna < imagen->width(); columna++){
            colorR= imagen->pixelColor(columna,fila).red();
            colorG= imagen->pixelColor(columna,fila).green();
            colorB= imagen->pixelColor(columna,fila).blue();
            if((colorR==0) && (colorG ==0)&&(colorB==0)){ // Para evitar conflictos en tinkercad color negro
                colorR=1;
                colorG=1;
                colorB=1;
            }
            if((colorR==255) && (colorG ==255)&&(colorB==255)){ // Para evitar conflictos en tinkercad color blanco
                colorR=254;
                colorG=254;
                colorB=254;
            }

            matriz[0][fila][columna] = colorR;
            matriz[1][fila][columna] = colorG;
            matriz[2][fila][columna] = colorB;
        }

    }
//    for (int j = 0; j < 3; j++){   // imprime matriz en consola
//        for(int i = 0; i < imagen->height(); i++){
//            for(int m = 0; m < imagen->width(); m++){
//                cout<<matriz[j][i][m]<<ends;
//            }
//          cout<<endl;
//       }
//    }

}

void rgb::GuardarInfo()  // funcion para guardar en txt informacion

{
    ofstream archivo;
    archivo.open("Matriz Colores.txt", ios::out); // Abre el archivo o lo crea si no existe

    //Para recorrer la matriz
    archivo << "{" << endl; //abre llaves
    for(int fila = 0; fila < 3; fila++){  //fila, columna, datos
        archivo << "{" << endl; // cada fila entre llaves
        for(int col = 0; col < leds; col++){ // se cierran con llaves
            archivo << "{";
            for(int dato = 0; dato < leds; dato++){
                archivo << matriz[fila][col][dato]; //separados con ,
                if(dato < leds-1) archivo << ",";
            }
            if(col < leds-1) archivo << "},"; //Longitud para saber si es la ultima columna y no cerrarla
            else archivo << "}";
        }
        archivo << endl;
        if(fila < 2) archivo << "}," << endl;
        else archivo << "}" << endl;
    }

    archivo << "};";//cierra llaves
    //Se cierra el archivo luego de trabajar con el
    archivo.close();
}
