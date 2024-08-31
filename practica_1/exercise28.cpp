#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void clearBufferCid_();
bool validateInput28();

void exercise28(){
    //Ejercicio 28. Escriba un programa que encuentre el valor aproximado de pi en base a la siguiente
    //suma infnita: π = 4(1 − 1/3 + 1/5 - 1/7 + 1/9...)
    //El usuario debe ingresar el número de elementos usados en la aproximación.
    //Ej: si se ingresa 3 π = 4(1 − 1/3 + 1/5) = 3.46667, por lo que se debe imprimir:
    //pi es aproximadamente: 3.46667

    unsigned int N;
    bool valid = false;

    while(!valid){
        cout << "Ingrese el primer numero: ";
        cin >> N;

        if (!validateInput28()) continue;
        valid = true;
    }

    int cont = 3;
    float operation = 1.0;
    bool signedO = false; //false = -; true = +

    for (int i = 1; i < N; i++){

        if (!signedO){
            operation = operation - (1.0 / cont);
            signedO = true;
        }else{
            operation = operation + (1.0 / cont);
            signedO = false;
        }

        cont += 2;
    }

    float result = 4.0 * operation;

    cout << "pi es aproximadamente: " << result;
}

void clearBufferCid_(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validateInput28(){
    if (cin.fail()){
        clearBufferCid_();
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    clearBufferCid_();
    return true;
}
