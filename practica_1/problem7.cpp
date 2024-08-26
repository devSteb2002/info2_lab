#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void problem7(){
    // Problema 6. Escriba un programa que encuentre el valor aproximado del número de euler en base
    // a la siguiente suma innita:
    // e = / !0 + 1/1! + 1/2! + 1 / 3! + ...
    // El usuario debe ingresar el número de elementos usados en la aproximación.
    // Ej: si se ingresa 3 e = 1/0! + 1/1! + 1/2! = 2.5
    // Nota: el formato de salida debe ser: e es aproximadamente: 2.

    int n;

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

    long long number1 = 1, number2 = 1;
    long long sum = 0, sumParity = 0;

    for (int i = 0; i < n; i++){

        sum = number1 + number2;
        number1 = number2;
        number2 = sum;

        if (number1 < n && number1 > 0){
            bool parity = number1 & 1;

            if (!parity){ // is par
                sumParity += number1;
            }
        }
    }

    cout << "El resultado de la suma es: " << sumParity;
}
