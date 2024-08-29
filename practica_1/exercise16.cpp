#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise16(){
    //Ejercicio 16. Escriba un programa que pida constantemente números hasta que se
    //ingrese el número cero e imprima en pantalla el promedio de los números ingresados (excluyendo el cero).
    //Ej: si se ingresan 1, 2, 3, 0 se debe imprimir:
    //El promedio es: 2

    int number, cont = 0;
    float prom = 0.0, result = 0.0;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        if (number == 0) break;

        result += number;
        cont++;

    }

    prom = result / cont;
    cout << "El promedio es: " << prom;
}
