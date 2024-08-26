#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise10(){
    //Ejercicio 10. Escriba un programa que pida un número N e imprima en pantalla todos los múltiplos de dicho número entre 1 y 100.
    //Ej: si se ingresa 33 se debe imprimir:
    //Multiplos de 33 menores que 100:
    //33
    //66
    //99

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

    for (int i = 1; i <= 100; i++){
        if (i % n == 0){
            cout << i << endl;
        }
    }

}
