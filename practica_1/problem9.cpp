#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;



void problem9(){
    // Problema 9. Escriba un programa que pida un número entero N e imprima el resultado de la suma
    // de todos sus dígitos elevados a sí mismos.
    // Ej: si se ingresa 1223 el resultado sería 1
    // 1 + 2^2 + 2^2 + 3^3 = 36
    // Nota: la salida del programa debe ser: El resultado de la suma es: 36.


    int n;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    string digits = to_string(n);
    int sum = 0;

    for (int i = 0; i < digits.length(); i++){
        int digit = digits[i] - '0';
        int potence = 1;

        for (int j = 0; j < digit; j++) potence *= digit;

        sum += potence;
    }

    cout << "El resultado de la suma es: " << sum;

}
