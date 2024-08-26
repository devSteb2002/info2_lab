#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;


void problem15(){
    // Problema 15. Empezando con el número 1 y moviéndose hacia la izquierda y en sentido horario
    // se genera una espiral de números como la siguiente:
    // 21 22 23 24 25
    // 20 7 8 9 10
    // 19 6 1 2 11
    // 18 5 4 3 12
    // 17 16 15 14 13
    // En el caso de esta espiral de 5x5, la suma de los números en la diagonal es 101.
    // Escriba un programa que reciba un número impar n y calcule la suma de los números en la diagonal
    // de una espiral de nxn.
    // Nota: la salida del programa debe ser:
    // En una espiral de 5x5, la suma es: 101.
    // Otra nota: se le dará una bonicación si imprime la espiral

    int n;

    while (true){
        cout << "Ingrese un numero impar: ";
        cin >> n;

        bool parity = n & 1;

        if (cin.fail() || !parity){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "El numero es invalido." << endl;
            continue;
        }

        break;
    }

    int matrix[n][n];

    // int **matrix = new int *[n]; // crear matriz con filas n

    // //crear un arreglo dentro de cada fila => 5
    // for (int i = 0; i < n; i++){
    //     matrix[i] = new int[n];
    // }

    int row = 0, rowEnd = n;
    int col = 0, colEnd = n;
    int changeNumber = n * n;
    int condition = (n / 2) + 1;

    while (row < condition){

        //llenar fila superior
        for (int i = colEnd - 1; i >= col; i--){
            matrix[row][i] = changeNumber;
            changeNumber--;
        }

        row++;

        //llenar columna izquierda
        for (int i = row; i < rowEnd; i++){
            matrix[i][col] = changeNumber;
            changeNumber--;
        }

        col++;

        //llenar fila inferior
        for (int i = col; i < colEnd; i++){
            matrix[rowEnd - 1][i] = changeNumber;
            changeNumber--;
        }

        rowEnd--;

        //llenar columna derecha
        for (int i = rowEnd - 1; i >= row; i--){
            matrix[i][colEnd - 1] = changeNumber;
            changeNumber--;
        }

        colEnd--;
    }

    //sumar las espirales
    unsigned int positionDiagonalRigth = 0, positioDiagonalLeft = n - 1;
    unsigned int sumDiagonals = 0;

    for (int i = 0; i < n; i++){
        positionDiagonalRigth = i;

        int position1 = matrix[positionDiagonalRigth][positionDiagonalRigth];
        int position2 =  matrix[positioDiagonalLeft][i];

        if (position1 == position2) sumDiagonals += position1;
        else sumDiagonals += position1 + position2;

        positioDiagonalLeft--;
    }


    //imprimir espiral
    unsigned const int nLength = to_string(n * n).length();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            unsigned const int mLength = to_string(matrix[i][j]).length();

            if (mLength < nLength){
                unsigned const int diference = nLength - mLength;
                for (unsigned int c = 0; c < diference; c++) cout << " ";
            }

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "En una espiral " << n << "x" << n << " la suma es: " << sumDiagonals;

    // delete []matrix;

}
