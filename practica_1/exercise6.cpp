#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

bool validateInput6();

void exercise6(){
    //Ejercicio 6. Escriba un programa que pida dos números A y B e imprima en pantalla la potencia
    //AB, sin hacer uso de librerías matemáticas.
    //Ej: si se ingresan 5 y 3 se debe imprimir: 5∧3=125

    int numberA, numberB;
    long long result = 1;
    bool validNumber = false;

    do {
        if (!validNumber){
            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput6()) continue;

            validNumber = true;
        }else{
            cout << "Ingrese el segundo numero: ";
            cin >> numberB;

            if (!validateInput6()) continue;

            break;
        }

    } while(true);

    for (int i = 1; i <= numberB; i++) result *= numberA;

    cout << numberA << "^" << numberB << " = " << result;
}


bool validateInput6(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    return true;
}
