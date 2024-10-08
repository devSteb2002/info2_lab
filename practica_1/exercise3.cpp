#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

bool valiadateFloat();

void exercise3(){
    //Ejercicio 3. Escriba un programa que pida dos números A y B e imprima en pantalla el mayor.
    //Ej: si se ingresan 7 y 3 se debe imprimir: El mayor es 7

    float number1, number2;
    bool validFirst = false;

    do{
        if (!validFirst){
            cout << "Ingrese el primer numero: ";
            cin >> number1;

            if (!valiadateFloat()) continue;

            validFirst = true;
        }else{
            cout << "Ingrese el segundo numero: ";
            cin >> number2;

            if (!valiadateFloat()) continue;

            break;
        }

    } while(true);


    if (number1 > number2) cout << "El mayor es " << number1;
    else if (number1 < number2) cout << "El mayor es " << number2;
    else cout << "Ambos son iguales";
}


bool valiadateFloat(){
    if (cin.fail()){
        cout << "Numero invalido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    return true;
}
