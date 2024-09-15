#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

int askNumberEnter();
void transformInt(int number, string &numberInString);

void problem_5(){

    int number = askNumberEnter(); // pedir el numero
    string numberInString;

    transformInt(number, numberInString); // pedir la conversion de int a string

    cout << "La cadena es: " << numberInString << endl;
}

void transformInt(int number, string &numberInString){ // transformar un int a string y devolverlo por referencia
    numberInString = to_string(number);
}

int askNumberEnter(){ // pedir y validar un numero entero

    int number;

    while(true){
        cout << "Ingrese un numero entero: " << endl;
        cin >> number;

        if (cin.fail()){ // validar que se haya ingresado los datos que son
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, intente otra vez." << endl;
            continue;
        }

        return number; // retornar el numero
    }
}
