#include <iostream>
#include "problems.h"

using namespace std;

unsigned int countStars(int** arr, int rows, int cols);
bool isStart(int** arr, int i, int j);

void problem_13(){

    int galaxyNGC[6][8] = { //definir el arreglo bidimensional original de la galaxia (estatico)
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 0, 7, 12, 6, 9, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    int** ptrGalayNGC = new int*[6]; // definir un arreglo bidimensional de punteros, reservando 6 posiciones

    for (int i = 0; i < 6; i++){
        ptrGalayNGC[i] = new int[8]; // en cada posicion reservar 8 posiciones de memoria

        for (int j = 0; j < 8; j++){ // iterar las columnas de la matriz
            ptrGalayNGC[i][j] = galaxyNGC[i][j]; // dar el valor de la matriz statica a la matriz dinamica
        }
    }


    unsigned int starsFinded = countStars(ptrGalayNGC, 6, 8); // contar las estrellas (matriz dinamica, filas, columnas)

    cout << "El numero de estrellas encontradas es: " << starsFinded << endl;


    // limpiar de la memoria la matriz de punteros creada previamente
    for (int i = 0; i < 6; i++){
        delete[] ptrGalayNGC[i];
    }

    delete[] ptrGalayNGC;

    // for (int i = 1; i < 6 - 1; ++i) {
    //     for (int j = 1; j < 8 - 1; ++j) {
    //         std::cout << ptrGalayNGC[i][j] << " ";
    //     }
    //     std::cout << std::endl;
   // }
}

unsigned int countStars(int** arr, int rows, int cols){ // contar estrellas

    unsigned int numbersOfStars = 0;

    for (int i = 1; i < rows - 1; i++){ // iterar toda la matriz dinamica evitando los bordes
        for (int j = 1; j < cols - 1; j++){
            if (isStart(arr, i, j)){ // verficiacion de la condicion para que sea una estrella
                cout << "Estrella encontrada en la posicion: (" << i << "," << j << ") = " << *(*(arr + i) + j) << endl;
                numbersOfStars++;
            }
        }
    }

    return numbersOfStars; // retornar el numero de estrellas
}

bool isStart(int** arr, int i, int j){ // verificar si es una estrella (matriz dinamica, posicion i, posicion j)

    int sum = arr[i][j] +
              arr[i][j - 1] +
              arr[i][j + 1] +
              arr[i - 1][j] +
              arr[i + 1][j];


    return (sum / 5.0) > 6;
}
