#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise2(){
    //Escriba un programa que pida un número N e imprima en pantalla si es par o impar.
    //Ej: si se ingresa 5 se debe imprimir:5 es impar

    int number;
    bool parity;

    do {
        cout << "Ingrese un numero entero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Ingrese un numero valido" << endl;
            continue;
        }

        break;
    } while (true);


    parity = number & 1;

    if (parity == 0) cout << "El numero " << number << " es par" << endl;
    else cout << "El numero " << number << " es impar" << endl;

}
