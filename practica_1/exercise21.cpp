#include <iostream>
#include <string>
#include "exercises.h"

using namespace std;

void exercise21(){
    //Ejercicio 21. Escriba un programa que pida un carácter C, si es una letra la debe convertir de
    //mayúscula a minúscula y viceversa e imprimirla.
    //Ej: si se ingresa B se debe imprimir:
    //Letra convertida: b
    //y si se ingresa k se debe imprimir:
    //Letra convertida: K

    string letters = "";
    const string alfabhet = "abcdefghijqlmnñopqrstuvwxyz";


    while (true){
        cout << "Ingrese una letra: ";
        cin >> letters;

        if (letters.length() > 1){
            cout << "Por favor ingrese un solo caracter." << endl;
            continue;
        }

        break;
    }


    size_t matchLower = alfabhet.find(letters[0]); // lower

    if (matchLower == string::npos){
        const char low = tolower(letters[0]);
        size_t matchUpper = alfabhet.find(low); // upper

        if (matchUpper != string::npos) cout << "Letra convertida: " << low;
        else cout << "El caracter ingresado no pertenece al alfabeto.";

    }else{
        char upp = toupper(letters[0]);
        cout << "Letra convertida: " << upp;
    }



}
