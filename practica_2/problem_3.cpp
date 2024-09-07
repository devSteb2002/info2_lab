#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void askChains(string &chain1, string &chain2);

void problem_3(){

    string chain1 = "", chain2 = "";
    bool isTrue = true;

    askChains(chain1, chain2); // pedir input

    if (chain1.length() == chain2.length()){ // verficar que tengan la misma cantidad de caracteres
        int lengthStrings = chain1.length();

        for (int i = 0; i < lengthStrings; i++){ // iterar cada posicion en el string
            if (chain1[i] != chain2[i]) isTrue = false; // si se encuentra al menos una que no sea igual retorna falso
        }
    }else isTrue = false;

    cout << ((isTrue) ? "Verdadero" : "Falso") << endl;
}


void askChains(string &chain1, string &chain2){ //pedir dos cadenas y retornarlo por referencia

    cout << "Ingrese la primera cadena. " << endl;
    cin >> chain1;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese la segunda cadena" << endl;
    cin >> chain2;
}
