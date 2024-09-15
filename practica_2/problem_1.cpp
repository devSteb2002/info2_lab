#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void askMoney(int &money);
void problem_1(){

    int money;
    unsigned int cash[10] = { // array con el tipo de billetes
        50000, 20000, 10000, 5000, 2000,
        1000, 500, 200, 100, 50
    };


    askMoney(money); // pedir que ingres un numero

    for (int i = 0; i < 10; i++){ // iterar el array
        int quantityCash = money / cash[i]; // dividir el numero ingresado por cada posicion en el array
        money =  money - (quantityCash * cash[i]); //al dinero original restarle la division por el index

        cout << cash[i] << ": " << quantityCash << endl; // imprimir el billete y la cantidad
    }

    cout << "Faltante: " << money << endl; //imprimir el faltante

}

void askMoney(int &money){ // validar input y retornar por referencia

    while(true){
        cout << "Ingrese la cantidad. " << endl;
        cin >> money;

        if (cin.fail()){ // verificar que la entrada si sea int
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido." << endl;
            continue;
        }

        if (money < 0) money = abs(money);

        break;
    }

}
