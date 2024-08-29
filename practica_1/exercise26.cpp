#include <iostream>
#include <limits>
#include "exercises.h"

using namespace std;

bool validateInput26();
bool isTriangle(int a, int b, int c);
bool isEquilateral(int a, int b, int c);
bool isIsoceles(int a, int b, int c);
bool isEcalene(int a, int b, int c);

void exercise26(){
    //Ejercicio 26. Escriba un programa que pida tres números e imprima el tipo de triangulo (isósceles, equilátero, escaleno) que se formaría, si sus lados tienen la longitud denida por los números
    //ingresados. Tenga en cuenta el caso en que los números ingresados no forman un triángulo.
    //Ej: si se ingresan 3, 3 y 5 se debe imprimir:
    //Se forma un triangulo isosceles.
    //y si se ingresan 3, 3 y 6 se debe imprimir:
    //Las longitudes ingresadas no forman un triangulo


    //Desigualdad triangular, los dos lados mas pequeños sumados, deben ser
    //mayor que el lado mas grande

    unsigned int numberA, numberB, numberC;
    bool validA = false, validB = false;

    do {
        if (!validA){
            cout << "Ingrese la primera longitud: ";
            cin >> numberA;

            if (!validateInput26()) continue;

            validA = true;
        }else{

            if (!validB){
                cout << "Ingrese la segunda longitud: ";
                cin >> numberB;

                if (!validateInput26()) continue;
                validB = true;
            }else{
                cout << "Ingrese la tercera longitud: ";
                cin >> numberC;

                if (!validateInput26()) continue;

                break;
            }
        }

    } while(true);

    if (!isTriangle(numberA, numberB, numberC)) cout << "Las longitudes ingresadas no forman un triangulo.";
    else{
        if (isEquilateral(numberA, numberB, numberC)) cout << "Es un triangulo equilatero.";
        else if (isIsoceles(numberA, numberB, numberC)) cout << "Es un triangulo isoceles.";
        else if (isEcalene(numberA, numberB, numberC)) cout << "Es un triangulo escaleno.";
    }
}

bool validateInput26(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero invalido, vuelva a intentar" << endl;
        return false;
    }

    return true;
}

bool isTriangle(int a, int b, int c){
    return (a + b > c) && (a + c > b) && (b + c > a);
}

bool isIsoceles(int a, int b, int c){ // es isoceles cuando tiene dos lados iguales
    return (a == b) || (a == c) || (c == b);
}

bool isEquilateral(int a, int b, int c){
    return (a == b) && (a == c);
}

bool isEcalene(int a, int b, int c){
    return (a != b) && (a != c);
}
