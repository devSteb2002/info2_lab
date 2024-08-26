#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise22(){
    //Ejercicio 22. Escriba un programa que pida una cantidad entera de segundos y la imprima en
    //formato horas:minutos:segundos.
    //Ej: si se ingresa 7777 se debe imprimir:
    //2:9:37

    int seconds, hours = 0, minuts = 0, restSeconds = 0;

    while (true){
        cout << "Ingrese los segundos: ";
        cin >> seconds;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        break;
    }


    hours = seconds / 3600;
    restSeconds = seconds - (hours * 3600);
    minuts = (60 * restSeconds) / 3600;
    restSeconds = restSeconds - ((minuts * 3600) / 60);


    cout << hours << ":" << minuts << ":" << restSeconds;

}
