#include <iostream>
#include <limits>
#include <unistd.h>
#include "exercises.h"
#include "problems.h"

using namespace std;

bool validateInputMain();
void ExecuteExercise(unsigned int selected);
void executeProblems(int selected);


int main(void)
{

    string arrayExercises[30] ={
        "Residuo de dos numeros.",
        "Numero par o impar",
        "Imprimir el numero mayor",
        "Imprimir el numero menor",
        "Imprimir division con redondeo",
        "Potencia de dos numeros",
        "Suma de todos los enteros hasta un numero",
        "Imprimir factorial",
        "Area y perimetro de un circulo",
        "Multiplos de un numero",
        "Tabla de multiplicar",
        "Todas las potencias hasta el numero",
        "Divisores de un numero",
        "Dos columnas paralelas con numeros",
        "Suma de todos los numeros ingresados",
        "Promedio de todos los numeros ingresados",
        "El mayor de todos los numeros ingresados",
        "Cuadrado perfecto",
        "Si es primo o no",
        "Numero palindromo",
        "Convertir letra a mayuscula y viceversa",
        "Cantidad de segundos en formato hh:mm:ss",
        "Minimo comun multiplo de dos numeros",
        "Imprimir figura de un cuadrado",
        "Cantidad de digitos de N",
        "Triangulo isoceles, escaleno, equilatero",
        "Calculadora",
        "Suma infinita de pi",
        "Adivinar numero de la maquina",
        "Adivinar numero ingresando numeros"
    };

    string arrayProblems[17] = {
        "Vocal o no",
        "Combinacion de billetes para una cantidad dada",
        "Combinacion de dia o mes",
        "Suma de tiempos",
        "Patron",
        "Suma infinita de euler",
        "Serie Fibonacci",
        "Multiplo de dos nuemros menores a c",
        "Suma de digitos elevados asi mismo",
        "Calcular el n-esimo numero primo",
        "Minimo comun multiplo de todos los enteros hasta n",
        "Maximo factor primo",
        "Suma de todos los primos",
        "Palindromo mas grande con numeros de 3 digitos",
        "Espiral",
        "Serie de collatz",
        "Numeros triangulares"
    };


    unsigned int type, selected;
    bool input = false, typeP = false;
    while (!input){
        if (!typeP){

            cout << "=====================================================================" << endl;
            cout << "||                      Practica N-1                               ||" << endl;
            cout << "=====================================================================" << endl;
            cout << "               Contamos con 30 ejercicios y 17 problemas.         " << endl;
            cout << "   Ingrese 1 para ver los ejercicios o 0 para ver los problemas.  " << endl;
            cin >> type;

            if (!validateInputMain()) continue;
            if (type > 1 || type < 0){
                cout << "Numero invalido. " << endl;
                continue;
            }

            typeP = true;
        }

        if (type == 1){ // exercises
            //sleep(0);

            for (int i = 0; i < 30; i++){
                cout << i +1 << " => " << arrayExercises[i] << endl;
            }

            cout << "Ingrese un numero correspondiente a un ejercicio: ";
            cin >> selected;

            if (!validateInputMain()) continue;
            if (selected < 1 || selected > 30){
                cout << "Numero invalido. " << endl;
                continue;
            }
        }else{ // problems
            //sleep(0);
            for (int i = 0; i < 17; i++){
                cout << i + 1 << " => " << arrayProblems[i] << endl;
            }

            cout << "Ingrese un numero correspondiente a un problema: ";
            cin >> selected;

            if (!validateInputMain()) continue;
            if (selected < 1 || selected > 17){
                cout << "Numero invalido. " << endl;
                continue;
            }
        }


        if (type == 1){
            ExecuteExercise(selected);
            sleep(1);
        }else{
            executeProblems(selected);
            sleep(1);
        }


        unsigned int continue_;
        cout << endl;
        while (true){
            cout << "Ingrese 1 para continuar, 0 para salir." << endl;
            cin >> continue_;

            if (!validateInputMain()) continue;
            if (continue_ < 0 || continue_ > 1){
                cout << "Numero invalido. " << endl;
                continue;
            }

            break;
        }

        if (continue_ == 0){
            typeP = false;
        }

        //input = true;
    }


    return 0;
}

bool validateInputMain(){

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero invalido, vuleva a intentar." << endl;
        return false;
    }

    return true;
}


void ExecuteExercise(unsigned int selected){
    switch (selected) {
    case 1:
        exercise1();
        break;
    case 2:
        exercise2();;
        break;
    case 3:
        exercise3();
        break;
    case 4:
        exercise4();
        break;
    case 5:
        exercise5();
        break;
    case 6:
        exercise6();
        break;
    case 7:
        exercise7();
        break;
    case 8:
        exercise8();
        break;
    case 9:
        exercise9();
        break;
    case 10:
        exercise10();
        break;
    case 11:
        exercise11();
        break;
    case 12:
        exercise12();
        break;
    case 13:
        exercise13();
        break;
    case 14:
        exercise14();
        break;
    case 15:
        exercise15();
        break;
    case 16:
        exercise16();
        break;
    case 17:
        exercise17();
        break;
    case 18:
        exercise18();
        break;
    case 19:
        exercise19();
        break;
    case 20:
        exercise20();
        break;
    case 21:
        exercise21();
        break;
    case 22:
        exercise22();
        break;
    case 23:
        exercise23();
        break;
    case 24:
        exercise24();
        break;
    case 25:
        exercise25();
        break;
    case 26:
        exercise26();
        break;
    case 27:
        exercise27();
        break;
    case 28:
        exercise28();
        break;
    case 29:
        exercise29();
        break;
    case 30:
        exercise30();
        break;
    default:
        break;
    }
}


void executeProblems(int selected){
    switch (selected) {
    case 1:
        problem1();
        break;
    case 2:
        problem2();
        break;
    case 3:
        problem3();
        break;
    case 4:
        problem4();
        break;
    case 5:
        problem5();
        break;
    case 6:
        problem6();
        break;
    case 7:
        problem7();
        break;
    case 8:
        problem8();
        break;
    case 9:
        problem9();
        break;
    case 10:
        problem10();
        break;
    case 11:
        problem11();
        break;
    case 12:
        problem12();
        break;
    case 13:
        problem13();
        break;
    case 14:
        problem14();
        break;
    case 15:
        problem15();
        break;
    case 16:
        problem16();
        break;
    case 17:
        problem17();
        break;
    default:
        break;
    }
}
