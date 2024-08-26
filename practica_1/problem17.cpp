#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

int getNumbersOfDivider(int number){
    int count = 0;;
    for (int i = 1; i <= number; i++){
        if (number % i == 0) count++;
    }

    return count;
}

void problem17(){
    // Problema 17. La secuencia de números triangulares se forma al sumar su posición en el arreglo
    // con el valor del número anterior: 1, 1+2=3, 3+3=6, 6+4=10, 10+5=15, 15+6=21, 21+7=28...
    // Si listamos los números triangulares y sus divisores tenemos:
    // 1: 1
    // 3: 1,3
    // 6: 1,2,3,6
    // 10: 1,2,5,10
    // 15: 1,3,5,15
    // 21: 1,3,7,21
    // 28: 1,2,4,7,14,28
    // Se observa que 28 es el primer número triangular que tiene más de 5 divisores. Escriba un programa
    // que reciba un número k y calcule cual es el primer número triangular que tiene más de k divisores.
    // Tip: el enésimo número triangular se puede representar como n*(n+1)/2.
    // Nota: la salida del programa debe ser:
    // El numero es: 28 que tiene 6 divisores.


    unsigned int k, numberN = 1;
    bool iter = true;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> k;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "El numero es invalido." << endl;
            continue;
        }

        break;
    }


    unsigned int numberOfDividers = 0, numberInPosition = 0;
    do {
        numberInPosition  = numberN * (numberN + 1) / 2;
        numberOfDividers = getNumbersOfDivider(numberInPosition);

        if (numberOfDividers > k) iter = false;

        numberN++;
    } while(iter);

    cout << "El numero es: " << numberInPosition << " que tiene " << numberOfDividers << " divisores.";
}
