#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

int calculateMCD11(int a, int b);

void problem11(){
    // Problema 11. Escriba un programa que reciba un número y calcule el mínimo común múltiplo de
    // todos los números enteros entre 1 y el número ingresado.
    // Ej: Si se recibe 4 el programa debe imprimir 12.
    // Nota: la salida del programa debe ser: El minimo comun multiplo es: 12


    int n;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> n;

        if (cin.fail() || n <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    //MCM(a, b) = |a x b| / MCD(a, b)

    int result = 1;

    for (int i = 1; i <= n; i++){
        int next = i + 1;
        if (next < n + 1){
            result = (result * next) / calculateMCD11(result, next);
        }

    }
    cout << "El minimo comun multiplo es: " << result;
}

int calculateMCD11(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
