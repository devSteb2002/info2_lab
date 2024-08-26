#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

bool validateDayAndMonth(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor, ingrese un numero valido" << endl;
        return false;
    }

    return true;
}


void problem3(){
    // Problema 3. Escriba un programa que debe leer un mes y un día de dicho mes para luego decir
    // si esa combinación de mes y día son válidos. El caso más especial es el 29 de febrero, en dicho caso
    // imprimir posiblemente año bisiesto.
    // Nota: el formato de salida debe ser:
    // 14 es un mes invalido.
    // 31/4 es una fecha invalida.
    // 27/4 es una fecha valida.
    // 29/2 es valida en bisiesto.

    unsigned int month, day;
    bool isMonth = false, exit = false;
    unsigned const int listMonthsDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (!exit){
        if (!isMonth){
            cout << "Ingrese un mes: ";
            cin >> month;

            if (!validateDayAndMonth()) continue;

            if (month <= 0 || month > 12){
                cout << "El mes debe ir desde 1 hasta 12." << endl;
                continue;
            }

            isMonth = true;
        }else{
            cout << "Ingrese un dia: ";
            cin >> day;

            if (!validateDayAndMonth()) continue;

            if (day <= 0 || day > 31){
                cout << "Los dias van desde 1 hasta 31." << endl;
                continue;
            }

            exit = true;

        }
    }


    unsigned int getDaysTotal = listMonthsDays[month - 1];

    if (getDaysTotal == day){
        cout << day << "/" << month << " es una fecha valida.";
    }else{
        if (month == 2){  //bisiets
            if ( day == 29) cout << day << "/" << month << " es valida en bisiesto.";
        } else{
            cout << day << "/" << month << " es una fecha invalida.";
        }
    }


}
