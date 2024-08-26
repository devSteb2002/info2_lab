#include <iostream>
#include "exercises.h"

using namespace std;

void exercise4(){
    //Ejercicio 4. Escriba un programa que pida dos números A y B e imprima en pantalla el menor.
    //Ej: si se ingresan 7 y 3 se debe imprimir:El menor es 3

    float number1, number2;

    cout << "Ingrese el primer numero: ";
    cin >> number1;

    cout << "Ingrese el segundo numero: ";
    cin >> number2;

    if (number1 > number2) cout << "El menor es " << number2;
    else if (number1 < number2) cout << "El menor es " << number1;
    else cout << "Ambos son iguales";
}
