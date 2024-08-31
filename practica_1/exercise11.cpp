#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise11(){
    //Ejercicio 11. Escriba un programa que pida un número N e imprima en pantalla su tabla de multiplicar hasta 10xN.
    //Ej: si se ingresa 7 se debe imprimir:
    //1x7=7
    //2x7=14
    //3x7=21
    //4x7=28
    //5x7=35
    //6x7=42
    //7x7=49
    //8x7=56
    //9x7=63
    //10x7=70

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

    for (int i = 1; i <= 10; i++){
        int result = n * i;
        cout << i << "x" << n << " = " << result << endl;
    }

}
