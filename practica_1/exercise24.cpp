#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise24(){
    //Ejercicio 24. Escriba un programa que pida una número entero e imprima un cuadrado de dicho
    //tamaño, los bordes del cuadrado deben estar hechos con el carácter `+' y el interior debe estar vacío.
    //Ej: si se ingresa 4 se debe imprimir:
    //++++
    //+  +
    //+  +
    //++++

    int N;

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

    for (int i = 0; i < N; i++){
        if (i == 0){
            for (int j = 0; j < N; j++) cout << "+";
            continue;
        }

        cout << endl;

        if (i <= N - 2 && i > 0){
            for (int j = 0; j < N ; j++){
                if (j == 0 || j == N - 1) cout << "+";
                else cout << " ";
            }
        }

        if (i == N - 1)
            for (int j = 0; j < N; j++) cout << "+";
    }
}
