#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void clearCid23();
bool validateInput23();
int calculateMCD(int a, int b);

void exercise23(){
    //Ejercicio 23. Escriba un programa que pida dos números A y B e imprima en pantalla el mínimo
    //común múltiplo entre los dos.
    //Ej: si se ingresan 4 y 6 se debe imprimir:
    //El MCM de 4 y 6 es: 12

    int numberA, numberB;
    bool validNumber = false;


    do{
        if(!validNumber){
            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput23()) continue;

            if (numberA <= 0){
                cout << "El numero debe ser positivo." << endl;
                continue;
            }


            validNumber = true;
        }else{
            cout << "Ingrese el segundo numero: ";
            cin >> numberB;

            if (!validateInput23()) continue;

            if (numberB <= 0){
                cout << "El numero debe ser positivo." << endl;
                continue;
            }

            break;

        }
    } while (true);



    //MCM(a, b) = |a x b| / MCD(a, b)
    int mcd = calculateMCD(numberA, numberB);
    int mcm = (numberA * numberB) / mcd;

    cout << "El MCM de " << numberA << " y " << numberB << " es " << mcm;
}

void clearCid23(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validateInput23(){

    if (cin.fail()){
        clearCid23();
        cout << "Introduzca un numero valido " << endl;
        return false;
    }

    clearCid23();
    return true;
}


int calculateMCD(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


