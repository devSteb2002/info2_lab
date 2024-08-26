#include <iostream>
#include "exercises.h"

using namespace std;

void exercise14(){
    //Ejercicio 14. Escriba un programa que imprima dos columnas paralelas, una con los números del
    //1 al 50 y otra con los números del 50 al 1.
    //Ej: las primeras lineas a imprimir serían:
    //1 50
    //2 49
    //3 48

    unsigned int colLeft = 1;
    unsigned int colRigth = 50;

    for (int i = 0; i < 50; i++){
        cout << colLeft << "   " << colRigth << endl;
        colLeft++;
        colRigth--;
    }
}
