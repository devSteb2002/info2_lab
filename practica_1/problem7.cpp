#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void problem7(){
    // Problema 7. En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
    // 1. Ej: 1, 1, 2, 3, 5, 8, ....
    // Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
    // de Fibonacci menores a n.
    // Ej: si se ingresa 10, sería la suma de 2+8 =10
    // Nota: el formato de salida debe ser: El resultado de la suma es: 10


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
