#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise19(){
    //Ejercicio 19. Escriba un programa que pida un número N e imprima si es o no un número primo.
    //Ej: si se ingresa 7 se debe imprimir:
    //7 es un numero primo.
    //y si se ingresa 8 se debe imprimir:
    //8 NO es un numero primo

    int N, cont = 0;

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

    for (int i = 1; i <= N; i++) if (N % i == 0) cont++;

    if (cont == 2) cout << N << " es un numero primo.";
    else cout << N << " NO " << "es un numero primo";

}
