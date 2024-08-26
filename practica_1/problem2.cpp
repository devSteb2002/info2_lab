#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;


void problem2(){
    //Problema 2. Se necesita un programa que permita determinar la mínima combinación de billetes
    //y monedas para una cantidad de dinero determinada. Los billetes en circulación son de $50.000,
    // //$20.000, $10.000, $5.000, $2.000 y $1.000, y las monedas son de $500, $200, $100 y $50.
    // Hacer un programa que entregue el número de billetes y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas disponibles no se puede lograr la
    // cantidad deseada, el sistema deberá decir lo que resta para lograrla.
    // Ej: si se ingresa 47810, el programa debe imprimir:
    // 50000 : 0
    // 20000: 2
    // 10000 : 0
    // 5000: 1
    // 2000 : 1
    // 1000: 0
    // 500 : 1
    // 200: 1
    // 100 : 1
    // 50: 0
    // Faltante: 10

    int arrayMoney[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cashToEnter;

    while (true){
        cout << "Introduzca la cantidad a retirar: ";
        cin >> cashToEnter;

        if (cin.fail()){
            cout << "Por favor ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break;

    }


    for (int i = 0; i < 10; i++){
        int division = cashToEnter / arrayMoney[i];
        cashToEnter = cashToEnter - (division * arrayMoney[i]);

        cout << arrayMoney[i] << ":" << division << endl;
    }

    cout << "Faltante: " << cashToEnter;

}
