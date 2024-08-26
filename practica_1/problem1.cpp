#include <iostream>
#include "problems.h"

using namespace std;

void problem1(){
    // Problema 1. Escriba un programa que identique si un carácter ingresado es una vocal, una consonante o ninguna de las 2 e imprima un mensaje según el caso.
    // Nota: el formato de salida debe ser:
    //no es una letra.
    //a es una vocal.
    //C es una consonante.

    const string alfhabet = "abcdefghijqlmnñopqrstuvwxyz";
    const string vowels = "aeiou";
    char caracter;

    cout << "Ingresa un caracter: ";
    cin >> caracter;

    char lowerCaracter = tolower(caracter);
    size_t inAlphabet = alfhabet.find(lowerCaracter);

    if (inAlphabet == string::npos){
        cout << "No es una letra." << endl;
    }else{
        size_t inVowels = vowels.find(lowerCaracter);

        if (inVowels != string::npos){
            cout << caracter <<  " es una vocal." << endl;
        }else{
            cout <<  caracter << " es una consonante." << endl;
        }
    }
}
