#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise17(){
    //Ejercicio 17. Escriba un programa que pida constantemente
    //números hasta que se ingrese el número cero e imprima en pantalla el mayor de todos los números ingresados.
    //Ej: si se ingresan 1, 2, 3, 0 se debe imprimir:
    //El numero mayor fue: 3

    int number, higher;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        higher = (higher > number) ? higher : number;

        if (number == 0) break;

    }

    cout << "El numero mayor fue: " << higher;
}
