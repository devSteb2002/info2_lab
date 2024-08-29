#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

bool validateInput_pro();
bool isInString(string multiples, int number);

void problem8(){
    /* Problema 8. Escriba un programa que reciba 3 números a, b, c, y calcule la suma de todos los
     múltiplos de a y b que sean menores a c. Tenga en cuenta no sumar 2 veces los múltiplos comunes.
    Ej: para a=3, b=5 y c=10. Se sumarían 3+6+9+5=23
    Para a=5, b=7 y c=36. Se sumarían 5+10+15+20+25+30+35+7+14+21+28 = 210.
     Nota: el formato de salida debe ser:
     m11 + m12 + m13 + . . . + m21 + m22 + m23. . . = sumatoria.
     m11 representa el primer múltiplo de a y así sucesivamente. m21 representa el primer múltiplo de b
    y así sucesivamente*/

    int numberA, numberB, numberC;
    bool validA = false, validB = false;

    do {
        if (!validA){
            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput_pro()) continue;

            validA = true;
        }else{

            if (!validB){
                cout << "Ingrese el segundo numero: ";
                cin >> numberB;

                if (!validateInput_pro()) continue;
                validB = true;
            }else{
                cout << "Ingrese el tercer numero: ";
                cin >> numberC;

                if (!validateInput_pro()) continue;

                break;
            }
        }

    } while(true);

    string comunMultiples = "", multipleA = "", multipleB = "";
    int sum = 0;

    for (int i = 1; i < numberC; i++){

        int multA = numberA * i;
        int multB = numberB * i;

        if (multA < numberC){
            if(!isInString(comunMultiples, multA)){
                comunMultiples += to_string(multA);
                sum += multA;
                multipleA += (to_string(multA) + " + ");
            }
        }

        if (multB < numberC){
            if(!isInString(comunMultiples, multB)){
                comunMultiples += to_string(multB);
                sum += multB;
                multipleB += (to_string(multB) + " + ");
            }
        }
    }

    multipleB.erase(multipleB.length() - 2 , 2);

    cout << multipleA << multipleB << " = " << sum;
}

bool validateInput_pro(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    return true;
}


bool isInString(string multiples, int number){

    size_t finded = multiples.find(to_string(number));

    if (finded != string::npos) return true;
    else return false;
}
