#include <iostream>
#include <cmath>
#include "exercises.h"

using namespace std;

//Ejercicio 1. Escriba un programa que pida dos números A y B e imprima en pantalla el residuo
//de la división A/B.
//Ej: si se ingresan 8 y 3 se debe imprimir:
//El residuo de la division 8/3 es: 2
//Nota: Nótese que la palabra división no tiene tílde, esto no es un error tipográco, es debido a que
//no se puede imprimir correctamente tíldes en la terminal. De ahora en adelante todos los ejemplos
//de salidas contendrán el mismo error tipográco

void clearBufferCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


bool validateInput(){

    if (cin.fail()){
        cout << "Por favor ingrese un numero valido. ";
        clearBufferCin();
        return false;
    }

    clearBufferCin();
    return true;
}


void exercise1(){

    float numA;
    float numB;
    bool validFirts = false;


    do {
        if (!validFirts){
            cout << "Ingrese el numerador: " << endl;
            cin >> numA;

            if (!validateInput()) continue;
            validFirts = true;
        }else{

            cout << "Ingrese el denominador: " << endl;
            cin >> numB;

            if (numB == 0.0) {  // 0,0 = 0 and 0,0 = 0
                cout << "Ingrese un valor diferente de 0. " << endl;
                clearBufferCin();
                continue;
            }

            if (!validateInput()) continue;
            break;
        }

    } while (true);

    float remainer = fmod(numA, numB);

    cout << "El residuo de los numeros " << numA << "/" << numB << " es: " << remainer;

}


