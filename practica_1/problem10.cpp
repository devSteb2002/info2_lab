#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void problem10(){
    // Problema 10. Escriba un programa que reciba un número n e imprima el enésimo número primo.
    // Ej: Si recibe 4 el programa debe imprimir 7.
    // Nota: la salida del programa debe ser: El primo numero 4 es: 7.

    int n;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> n;

        if (cin.fail() || n <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    bool finded = false;
    int numbers = 2, iters = 0;

    while (!finded){
        int cont = 0;
        for (int i = 1; i <= numbers; i++){
            if (numbers % i == 0) cont++;
        }

        if (cont == 2){
            if (iters == n - 1){
                cout << "El primo numero " << n << " es " << numbers << endl;
                finded = true;
            }
            iters++;
        }

        numbers++;
    }

}
