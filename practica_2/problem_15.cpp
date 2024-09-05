#include <cmath>
#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void askInput(int* rectA_, int* rectB_);
bool verifyInput();
int* interceptionBetRects(int* rectA_, int* rectB_ );

void problem_15(){

    int* rectA = new int[4];
    int* rectB = new int[4];

    askInput(rectA, rectB); // funcion para obtener los datos del usuario

    int* coordinatesInterception = interceptionBetRects(rectA, rectB); //funcion que me retorna un puntero de un arreglo

    if (coordinatesInterception == nullptr){
        cout << "no hay intercepcion";
        return;
    }

    cout << "Rectangulo A: {" << rectA[0] << ", " << rectA[1] << ", " << rectA[2] << ", " << rectA[3] << "}" << endl;
    cout << "Rectangulo B: {" << rectB[0] << ", " << rectB[1] << ", " << rectB[2] << ", " << rectB[3] << "}" << endl;
    cout << "Interseccion C: {" << coordinatesInterception[0] << ", " << coordinatesInterception[1] << ", " << coordinatesInterception[2] << ", " << coordinatesInterception[3] << "}" << endl;


    delete[] rectA;
    delete[] rectB;
    delete[] coordinatesInterception;

}

void askInput(int* rectA_, int* rectB_){

    bool coordinateXValid = false, widthValid = false, isCoordinates = false;
    int coordinateX, coordinateY, high, width;

    char whatRect[2] = {'A', 'B'};
    unsigned short contRect = 0;

    do{
        if (!isCoordinates){ // pedir coordenadas
            if (!coordinateXValid){ // pedir coordenada x
                cout << "Ingrese la coordenada x del rectangulo " << whatRect[contRect] << endl;
                cin >> coordinateX;

                if (!verifyInput()) continue;

                coordinateXValid = true;
                continue;
            }
            else{ // pedir cooredada y
                cout << "Ingrese la coordenada y del rectangulo " << whatRect[contRect] << endl;
                cin >> coordinateY;

                if (!verifyInput()) continue;

                isCoordinates = true;
                continue;
            }
        }else{ // pedir dimensiones del rectangulo (alto y ancho)
            if (!widthValid){ // pedir el alto del rectangulo
                cout << "Ingrese el ancho del rectangulo " << whatRect[contRect] << endl;
                cin >> width;

                if (!verifyInput()) continue;

                widthValid = true;
                continue;
            }else{ // pedir ancho del rectangulo
                cout << "Ingrese el alto del rectangulo " << whatRect[contRect] << endl;
                cin >> high;

                if (!verifyInput()) continue;

            }
        }

        contRect++;

        if (contRect == 1){ //Datos del rectangulo A
            rectA_[0] = coordinateX;
            rectA_[1] = coordinateY;
            rectA_[2] = width;
            rectA_[3] = high;

            isCoordinates = false;
            coordinateXValid = false;
            widthValid = false;
        }
        else{ // datos del rectangulo B
            rectB_[0] = coordinateX;
            rectB_[1] = coordinateY;
            rectB_[2] = width;
            rectB_[3] = high;

            break;
        }

    }while(true);
}


int* interceptionBetRects(int* rectA_, int* rectB_ ){ //funcion para encontrar la interseccion
    int* intercep = new int[4];

    int widthRectA = rectA_[0] + rectA_[2];
    int heigthRectA = rectA_[1] + rectA_[3];
    int widthRectB = rectB_[0] + rectB_[2];
    int heigthRectB = rectB_[1] + rectB_[3];


     if ( // coliciones en x
         (rectB_[0] > rectA_[0] && widthRectB < widthRectA) ||
         (rectB_[0] < rectA_[0] && widthRectB > widthRectA) ||
         (rectB_[0] < rectA_[0] && widthRectB < widthRectA && widthRectB > rectA_[0]) ||
         (rectB_[0] > rectA_[0] && widthRectB > widthRectA && rectB_[0] < widthRectA)
         ){

         if ( // colisiones en y
            (rectB_[1] > rectA_[1] && heigthRectB < heigthRectA) ||
            (rectB_[1] > rectA_[1] && heigthRectB > heigthRectA && rectB_[1] < heigthRectB) ||
            (rectB_[1] < rectA_[1] && heigthRectB > heigthRectA) ||
             (rectB_[1] < rectA_[1] && heigthRectB < heigthRectA && heigthRectA > rectA_[1])
            ){

             int x, y, widthInter = 0, heigthInter = 0;

             if (rectA_[0] < rectB_[0]){
                 x = rectB_[0];
                 y = rectB_[1];

                 widthInter = widthRectA - x;
                 heigthInter = heigthRectA - y;

             }else{
                 x = rectA_[0];
                 y = rectA_[1];

                 widthInter = widthRectB - x;
                 heigthInter = heigthRectB - y;
             }


             intercep[0] = x;
             intercep[1] = y;
             intercep[2] = widthInter;
             intercep[3] = heigthInter;


             return intercep;
         }
     }

     delete[] intercep; // cuando no hay inteseccion;
     return nullptr;
}

bool verifyInput(){ //verficar que la entrada sea correcta
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Dato ingresado no es valido, vuelve a intenar." << endl;
        return false;
    }

    return true;
}
