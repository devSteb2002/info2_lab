#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

bool validateNumbersInput();

void exercise4(){
    //Ejercicio 4. Escriba un programa que pida dos números A y B e imprima en pantalla el menor.
    //Ej: si se ingresan 7 y 3 se debe imprimir:El menor es 3

    float number1, number2;
    bool validFirstNumber = false;

    while(true){
        if (!validFirstNumber){
            cout << "Ingrese el primer numero: ";
            cin >> number1;

            if (!validateNumbersInput()) continue;

            validFirstNumber = true;
        }else{
            cout << "Ingrese el segundo numero: ";
            cin >> number2;

            if (!validateNumbersInput()) continue;

            break;
        }
    }


    if (number1 > number2) cout << "El menor es " << number2;
    else if (number1 < number2) cout << "El menor es " << number1;
    else cout << "Ambos son iguales";
}


bool validateNumbersInput(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero invalido, intentelo nuevamente. " << endl;
        return false;
    }

    return true;
}
