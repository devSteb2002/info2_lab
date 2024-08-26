#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "exercises.h"

using namespace std;

void clearBufferCid30(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validateInput30(){
    if (cin.fail()){
        clearBufferCid30();
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    clearBufferCid30();
    return true;
}

void exercise30(){
    //Ejercicio 30. Escriba un programa que genere un número aleatorio A (entre 0 y 100) y le pida al
    //usuario que lo adivine, el usuario ingresa un número B y el programa le dirá si B es mayor o menor
    //que A, esto se repetirá hasta que el usuario adivine el número, en ese momento el programa le dirá
    //el número de intentos que tardo el usuario en adivinar el número.
    //Nota: para generar el número aleatorio use la función rand() de la librería <cstdlib>, recuerde
    //convertirlo al rango (0,100).

    srand(time(0));

    unsigned int N;
    bool valid = false, exit = false;
    int randomNumber = rand() % 101;
    int trys = 0;

    cout << "=========== Adivina el numero. =============" << endl;

    while (!exit){
        trys++;
        valid = false;

        while(!valid){
            cout << "Ingrese un numero: ";
            cin >> N;

            if (!validateInput30()) continue;
            valid = true;
        }

        if (N > randomNumber){
            cout << endl;
            cout << "El numero " << N << " es mayor." << endl;
        }else if (N < randomNumber){
            cout << endl;
            cout << "El numero " << N << " es menor." << endl;
        }else{
            cout << endl;
            cout << "Felicitaciones, has encontrado el numero." << endl;
            exit = true;
        }

    }

    cout << "El numero de intentos fue: " << trys;
}

