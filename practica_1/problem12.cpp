#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

int nextPrime(unsigned int number){

    unsigned cont = number;
    while (true){
        unsigned int prime = 0;

        for (unsigned int i = 1; i <= cont + 1; i++){
            if (cont % i == 0) prime++;
        }


        if (prime == 2){
            if (cont > number){
                return cont;
                break;
            }

        }
        cont++;
    }
}

void problem12(){
    //Problema 12. Escriba un programa que calcula el máximo factor primo de un número.
    //Ej: Si se recibe 33 el programa debe imprimir 11.
    //Nota: la salida del programa debe ser: El mayor factor primo de 33 es: 11

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

    unsigned int prime = 2, division = n;


    while (true){

        if (division % prime == 0){
            division = division / prime;
        }else{
            prime = nextPrime(prime);
        }

        if (division == 1) break;

    }

    cout << "El mayor factor primo de " << n << " es " <<  prime;

}
