#include <iostream>
#include <limits>
#include <cmath>
#include "exercises.h"

using namespace std;

void clearCid();
bool validateInput5();

void exercise5(){
    //Ejercicio 5. Escriba un programa que pida dos números A y B e imprima en pantalla la división
    //A/B con redondeo.
    //Ej: si se ingresan 8 y 3 se debe imprimir: 8/3=3
    // Si se ingresan 7 y 3 se debe imprimir:7/3=2

    float numberA, numberB, result;
    int prox;
    bool validNumber = false;


    do{
        if(!validNumber){
            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput5()) continue;

            validNumber = true;
        }else{
            cout << "Ingrese el segundo numero: ";
            cin >> numberB;

            if (!validateInput5()) continue;

            if (numberB == 0.0) {
                cout << "El numero debe ser diferente de cero " << endl;
                continue;
            }

            break;

        }
    } while (true);

    result = numberA / numberB;
    prox = round(result);

    cout << numberA << "/" << numberB << " = " << prox;
}

void clearCid(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validateInput5(){

    if (cin.fail()){
        clearCid();
        cout << "Introduzca un numero valido " << endl;
        return false;
    }

    clearCid();
    return true;
}
