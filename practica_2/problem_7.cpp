#include <iostream>
#include "problems.h"

using namespace std;

string filter(string caracters);
bool isInString(string newString, char caracter);

void problem_7(){

    string caracters = "", stringOutSame = "";

    cout << "Ingrese un texto cualquiera: " << endl; // pedir un input cualquiera
    cin >> caracters;

    stringOutSame = filter(caracters); // filtrar repetidos en el string

    cout << "Original: " << caracters << ", Sin repetidos: " << stringOutSame << endl;
}

string filter(string caracters){ // filtrar los repetidos y eliminarlos

    unsigned int lengthString = caracters.length();
    string newString = "";

    for (unsigned int i = 0; i < lengthString; i++){ //iterar sobre el string
        char caracter = caracters[i]; //cada caracter en el string

        for (unsigned int j = 0; j < lengthString; j++){ //iterar otra vez sobre el string para comparar
            char caracterSearch = caracters[j]; // cada caracter en el string

            if (j != i){ // si las posicion son diferente, para no comparar las mismas posiciones
                if (caracter == caracterSearch){ //si el caracter 1 es igual al 2 quiere decir que hay repetidos
                    if (!isInString(newString, caracterSearch)) // busca si existen en el nuevo string
                        newString += caracter;
                }else{                                       //sino son iguales
                    if (!isInString(newString, caracter))    // busca si existen en el nuevo string
                        newString += caracter;
                }
            }
        }
    }

    return newString; //retornar string
}

bool isInString(string newString, char caracter){ //funcion para verificar si un caracter esta en un string

    size_t findCaracter = newString.find(caracter); // buscar en el string el caracter

    if (findCaracter == string::npos){ //si es igual al valor de npos entonces no existe en el string
         return false;
    }
    return true;;
}
