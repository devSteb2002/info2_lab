#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void getInput(int &n);
int sumDividers(int number);
void addElementeArray(int*& array, int rows, int newElement);

void problem_17(){

    int number = 0, sumFriendly = 0, row = 0;
    int* array = nullptr;

    getInput(number); //obtener entrada


    for (int i = 1; i < number; i++){ //buscar en todos los numero menores al dado
        int sumFriendly_ = sumDividers(i); // obtener la suma de los amigables
        if (sumFriendly_ != 0){
            addElementeArray(array, row, sumFriendly_); //añadir un elemento al nuevo array
            row++;
        }
    }

    for (int i = 1; i <= row; i++){
        if (array[i - 1] == array[i]){ //sumar los valores del array que no esten repetidos
            sumFriendly += array[i];
        }
    }

    cout << "El resultado de la suma es: " << sumFriendly << "  " << endl;

    delete[] array; //limiar de la memoria el array
}

void addElementeArray(int*& array, int rows, int newElement){ // añadir un nuevo elemento a un arreglo (array) array por referencia
    // para editar el original desde esta funcion

    int* newArray = new int[rows + 1]; // reservar espacio para un arreglo

    for (int i = 0; i < rows; i++){ //llenar el arreglo reservado con todos los elementos del parametor (array)
        newArray[i] = array[i];
    }

    newArray[rows] = newElement; // añadir el nuevo elemento en la ultima posicion
    delete[] array; // limpiar de la memoria el array del parametro
    array = newArray; // darle a array la direccion de memoria del newArray
}

int sumDividers(int number){ // encontrar si son amigables

    int firstFriendly = 0, secondFriendly = 0;

    for (int i = 1; i < number; i++){ // encontrar los divisores del primer numero y sumarlos
        if (number % i == 0) firstFriendly += i;
    }

    for (int i = 1; i < firstFriendly; i++){ // encontrar los divisores de la suma del primer numero y sumarlos
        if (firstFriendly % i == 0) secondFriendly += i;
    }

    if (secondFriendly == number && firstFriendly != secondFriendly){ // comparar si el paramtero es igual al segundo numero
         return firstFriendly + secondFriendly; // sumar los dos numeros amigables
    }

    return 0;
}


void getInput(int &n){ //obtener el input pasando de referencia la n para editar lo que haya en la direccion de memoria

    while(true){
        cout << "Ingrese un numero entero. " << endl;
        cin >> n;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            cout << "Numero invalido, ingrese otro. " << endl;
            continue;
        }

        break;
    }
}


