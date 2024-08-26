#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise15(){
    //Ejercicio 15. Escriba un programa que pida constantemente números hasta que se ingrese el número cero e imprima en pantalla la suma de todos los números ingresados.
    //Ej: si se ingresan 1, 2, 3, 0 se debe imprimir:
    //El resultado de la sumatoria es: 6

    int number;
    int result = 0;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        result += number;

        if (number == 0) break;
    }

    cout << "El resultado de la suma es: " << result;
}
