#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise13(){
    //Ejercicio 13. Escriba un programa que pida un número N e imprima todos los divisores de N.
    //Ej: si se ingresa 4 se debe imprimir:
    //Los divisores de n son:
    //1
    //2
    //4


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

    for (int i = 1; i <= n; i++){
        if (n % i == 0) cout << i << endl;
    }

}
