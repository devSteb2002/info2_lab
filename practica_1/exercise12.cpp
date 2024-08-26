#include <iostream>
#include <limits>
#include <math.h>
#include "exercises.h"

using namespace std;

void exercise12(){
    //Ejercicio 12. Escriba un programa que pida un número N e imprima todas las potencias desde N1
    //hasta N5
    //Ej: si se ingresa 3 se debe imprimir:
    //3∧1=3
    //3∧2=9
    //3∧3=27
    //3∧4=81
    //3∧5=243


    int n;

    do{
        cout << "Ingresa un numero: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelve a intentar." << endl;
            continue;
        }

        break;
    } while(true);

    for (int i = 1; i <= 5; i++){
        int result = pow(n, i);
        cout << n << "^" << i << "=" << result << endl;
    }

}
