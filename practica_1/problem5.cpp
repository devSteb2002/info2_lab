#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void problem5(){
    //Problema 5. Escriba un programa que muestre el siguiente patrón en la pantalla:
    //*
    //***
    //*****
    //*******
    //******
    //***
    //*

    //El tamaño del patrón estará determinado un número entero impar que ingrese el usuario. En el
    //    ejemplo mostrado, el tamaño de la gura es 7.

    unsigned int n;

    while (true){
        cout << "Ingrese un numero impar: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese in numero valido." << endl;
            continue;
        }

        bool isOdd = n & 1;

        if (!isOdd){
            cout << n << " no es impar." << endl;
            continue;
        }

        break;
    }

    unsigned int numberOfCaracter = 1;
    unsigned int numberSpaces;

    for (unsigned int i = 0; i < (n / 2) + 1; i++){
        numberSpaces = (n - numberOfCaracter) / 2;

        for (unsigned int j = 0; j < numberSpaces; j++) cout << " ";

        for (unsigned int j = 0; j < numberOfCaracter; j++) cout << "*";

        for (unsigned int j = 0; j < numberSpaces; j++)  cout << " ";

        cout << endl;
        if (numberOfCaracter == n) break;

        numberOfCaracter += 2;
    }

    numberOfCaracter -= 2;

    for (int i = (n / 2); i > 0 ; i--){
        numberSpaces = (n - numberOfCaracter) / 2;

        for (unsigned int j = 0; j < numberSpaces; j++) cout << " ";

        for (unsigned int j = 0; j < numberOfCaracter; j++) cout << "*";

        for (unsigned int j = 0; j < numberSpaces; j++)  cout << " ";

        numberOfCaracter -= 2;
        cout << endl;

        if (numberOfCaracter == n) break;
    }
}
