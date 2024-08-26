#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise18(){
    //Ejercicio 18. Escriba un programa que pida un número N e imprima si es o no un cuadrado perfecto.
    //Ej: si se ingresa 9 se debe imprimir:
    //9 es un cuadrado perfecto.
    //y si se ingresa 8 se debe imprimir:
    //8 NO es un cuadrado perfecto.


    int N;
    bool isPerfect = false;

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

    for (int i = 1; i < N; i++){
        int pow = i * i;

        if (pow == N){
            isPerfect = true;
        }
    }

    if (isPerfect) cout << N << " es un cuadrado perfecto." << endl;
    else cout << N << " NO es un cuadrado perfecto." << endl;
}
