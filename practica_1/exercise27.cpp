#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void clearBufferCid();
bool validateInput27();
bool validateOperation(char operation);

void exercise27(){
    //Ejercicio 27. Escriba un programa que actúe como una calculadora con operaciones de suma,
    //resta, multiplicación y división, el usuario debe ingresar los operandos y la operación a realizar.
    //Ej: si se ingresan 3, + y 5 se debe imprimir:
    //3+5=8

    float numA, numB;
    char operation;
    bool validA = false, validO = false;

    do {
        if (!validA){
            cout << "Ingrese el primer numero: ";
            cin >> numA;

            if (!validateInput27()) continue;
            validA = true;
        }else{
            if (!validO){
                cout << "Ingrese la operacion: ";
                cin >> operation;

                if (validateOperation(operation)){
                    validO = true;
                }else {
                    cout << "Simbolo de la operacion invalido, vuelva a intentar. " << endl;
                    clearBufferCid();
                    continue;
                }
            }else{
                cout << "Ingrese el segundo numero: ";
                cin >> numB;

                if (!validateInput27()) continue;

                if (numB == 0.0 && operation == '/'){
                    cout << "Error. no se puede dividir por 0." << endl;
                    continue;
                }

                break;
            }
        }
    } while(true);

    float result = 0.0;

    switch (operation) {
    case '+':
        result = numA + numB;
        break;
    case '-':
        result = numA - numB;
        break;
    case '*':
        result = numA * numB;
        break;
    case '/':
        result = numA / numB;
        break;
    default:
        break;
    }
    cout << numA << " " << operation << " " << numB << " = " << result;
}

void clearBufferCid(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validateInput27(){
    if (cin.fail()){
        clearBufferCid();
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    clearBufferCid();
    return true;
}

bool validateOperation(char operation){
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/');
}

