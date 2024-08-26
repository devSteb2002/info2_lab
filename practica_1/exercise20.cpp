#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise20(){
    //Ejercicio 20. Escriba un programa que pida un número N e imprima si es o no un palíndromo
    //(igual de derecha a izquierda que de izquierda a derecha).
    //Ej: si se ingresa 121 se debe imprimir:
    //121 es un numero palindromo.
    //y si se ingresa 123 se debe imprimir:
    //123 NO es un numero palindromo

    int N;
    string stringNumber;
    string reverNumber = "";

    while (true){
        cout << "Ingrese un numero: ";
        cin >> N;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        break;
    }

    stringNumber = to_string(N);

    for (int i = 1; i <= stringNumber.length(); i++)
        reverNumber += stringNumber[stringNumber.length() - i ];

    if (stringNumber == reverNumber) cout << N << " es palindromo.";
    else cout << N << " NO es palindromo.";

}
