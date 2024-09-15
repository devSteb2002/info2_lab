#include <iostream>
#include "problems.h"

using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);

void exercise_1(){
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun_b(array, 10);
}

void fun_a(int *px, int *py){
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam){
    int f, l;
    int *b = a;

    for (f = 0, l = tam -1; f < l; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

//Cuál es su dirección en memoria? ¿Cuántos bytes se dedican para almacenar cada elemento de array?
//R/= su direccion de memoria es la primera posicion del arreglo array => se requieren 4 bytes

//Cuál es la dirección y el contenido en memoria del elemento array[3] ?
//La direccion de memoria de la posicion 0 sumada tres bloques de 4 bytes

//Describa el efecto que tiene la función fun_b, sobre el arreglo array
//fun_b esta recorriendo el array de izquierda a derecha y viceversa al mismo tiempo
//llamando asi a la funcion fun_a para que intercambie los valores en esas direcciones de memoria, asi voltea el arreglo
