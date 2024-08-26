#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise8(){
    //Ejercicio 8. Escriba un programa que pida un número N e imprima en pantalla su factorial.
    //Ej: si se ingresa 5: 5!=1*2*3*4*5=120, por lo que se debe imprimir:
    //5!=120

    int n;
    int result = 1;

    do {
        cout << "Introduzca un numero: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelva a intentar." << endl;
            continue;
        }

        break;
    } while(true);

    for (int i = 1; i <= n; i++) result *= i;

    cout << n << "! =" << result;
}
