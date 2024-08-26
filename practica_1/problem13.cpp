#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

bool isPrime(unsigned int number){

    unsigned cont = 0;

    for (int i = 1; i <= number; i++){
        if (number % i == 0) cont++;
    }

    if (cont == 2) return true;

    return false;
}

void problem13(){
    //Problema 13. Escriba un programa que reciba un número y calcule la suma de todos los primos
    //menores que el número ingresado.
    //Ej: Si se recibe 10 el programa debe imprimir 17.
    //Nota: la salida del programa debe ser: El resultado de la suma es: 17.

    int n, sum = 0;

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

    for (int i = 2; i < n; i++){
        if (isPrime(i)){
            sum += i;
        }
    }

    cout << "El resultado de la suma es: " << sum;


}
