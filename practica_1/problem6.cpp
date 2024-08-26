#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void problem6(){
    // Problema 6. Escriba un programa que encuentre el valor aproximado del número de euler en base
    // a la siguiente suma innita:
    // e = / !0 + 1/1! + 1/2! + 1 / 3! + ...
    // El usuario debe ingresar el número de elementos usados en la aproximación.
    // Ej: si se ingresa 3 e = 1/0! + 1/1! + 1/2! = 2.5
    // Nota: el formato de salida debe ser: e es aproximadamente: 2.5


    int n;
    double euler = 0.0;

    while (true){
        cout << "Ingrese el numero de elementos: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un numero valido." << endl;
            continue;
        }

        if (n <= 0){
            cout << "El numero debe ser mayor que 0." << endl;
            continue;
        }

        break;
    }

    for (int i = 0; i < n; i++){
        int factorial = 1;

        if (i <= 1) factorial = 1;
        else{
            for (int j = 1; j <= i; j++) factorial *= j;
        }

        euler += 1.0 / factorial;
    }

    cout << "e es aproximadamente: " << euler;
}
