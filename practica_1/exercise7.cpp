#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise7(){
    //Ejercicio 7. Escriba un programa que pida un número N e imprima en pantalla la suma de todos
    //los números entre 0 y N (incluyéndose el mismo).
    //Ej: si se ingresa 5: 1+2+3+4+5=15, por lo que se debe imprimir:
    //La sumatoria desde 0 hasta 5 es: 15

    int n;
    int result = 0;

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

    for (int i = 0; i <= n; i++) result += i;

    cout << "La sumatoria desde 0 hasta " << n << " es: " << result;
}
