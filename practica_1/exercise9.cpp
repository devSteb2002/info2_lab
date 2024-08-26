#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

void exercise9(){
    //Ejercicio 9. Escriba un programa que pida un número N e imprima el perímetro y área de un
    //círculo con radio N. Nota: use 3.1416 como una aproximación de pi.
    //Ej: si se ingresa 1 se debe imprimir:
    //Perimetro: 6.28352
    //Area: 3.1416
    const float PI = 3.1416;
    float n, A, P;

    do{
        cout << "Ingresa un numero: ";
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, vuelve a intentar." << endl;
            continue;
        }

        break;
    } while(true);

    A = PI * (n * n);
    P = 2 * PI * n;

    cout << "Area: " << A << endl;
    cout << "Perimetro: " << P << endl;

}
