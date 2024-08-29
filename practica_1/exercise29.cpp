#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "exercises.h"

using namespace std;

bool validateChar(char simbol);

void exercise29(){
    //Ejercicio 29. Escriba un programa que adivine un número A (entre 0 y 100) seleccionado por el
    //usuario (el número NO se ingresa al programa), el programa imprimirá en pantalla un número B y
    //el usuario usará los símbolos `>', `<' y `=' para indicarle al programa si B es mayor, menor o igual
    //que A. El programa imprimira un nuevo número B, con base en simbolo ingresado por el usuario, y
    //repetira el proceso hasta acertar el número seleccionado por usuario.

    srand(time(0));

    char simbol;
    bool valid = false, exit = false;;
    int randomHide = rand() % 101;
    int randomShow = rand() % 101;

    cout << "Halla el numero escondido en base al que te damos." << endl;
    cout << " ||||||||||||||||||||||||||||||||||||||||||||||||| " << endl;
    cout << endl;

    while (!exit){

        cout << "El numero que te damos es: " << randomShow << endl;


        while(!valid){

            cout << "Ingrese >, < o = para encontrar el numero: ";
            cin >> simbol;

            if (!validateChar(simbol)) continue;
            valid = true;
        }

        switch (simbol) {
        case '<':
            if (randomShow < randomHide){
                cout << "Correcto, el numero " << randomShow << " es menor." << endl;
                randomShow = randomShow +  rand() % (randomHide - randomShow + 1);
            }else {
                cout << "Incorrecto, el numero " << randomShow << " no es menor." << endl;
                randomShow = randomHide + rand() % (randomShow - randomHide + 1);
            }

            break;
        case '>':
            if (randomShow > randomHide){
                cout << "Correcto, el numero " << randomShow << " es mayor." << endl;
                randomShow = randomHide + rand() % (randomShow - randomHide + 1);
            }else{
                cout << "Incorrecto, el numero " << randomShow << " no es mayor." << endl;
                randomShow = randomShow + rand() % (randomHide - randomShow + 1);
            }
            break;
        case '=':
            if (randomShow == randomHide){
                cout << "Felicitaciones. encontraste el numero, es. " << randomHide << endl;
                exit = true;
            }else{
                cout << "Incorrecto. los numeros no son iguales" << endl;
                randomShow = rand() % randomHide + 1;
            }
            break;
        default:
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        valid = false;
    }
}

bool validateChar(char simbol){
    if (simbol != '>' && simbol != '<' && simbol != '='){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Simbolo invalido, vuelva a intentar" << endl;
        return false;
    }

    return true;
}

