#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise25(){
    //Ejercicio 25. Escriba un programa que pida un número N e imprima en pantalla la cantidad de
    //dígitos de N.
    //Ej: si se ingresa 1234  se debe imprimir:
    //1234 tiene 4 digitos.

    int N, numberOfDigits;
    string digits;


    while (true){
        cout << "Ingrese un numero: ";
        cin >> N;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        break;
    }


    digits = to_string(N);
    numberOfDigits = digits.length();

    cout << "El numero " << N << " tiene " << numberOfDigits << " digitos.";

}
