#include <algorithm>
#include <iostream>
#include "problems.h"

using namespace std;

bool isPalindrome(unsigned int palind){

    string stringPalindrome = to_string(palind);
    string reversePalindrome =  stringPalindrome;

    reverse(reversePalindrome.begin(), reversePalindrome.end());

    return stringPalindrome == reversePalindrome;

}

void problem14(){
    // Problema 14. Un número palíndromo es igual de derecha a izquierda y de izquierda a derecha,
    // Ej: 969. escriba un programa que calcule el número palíndromo más grande que se puede obtener
    // como una multiplicación de números de 3 dígitos.
    //  Ej: una de las posibles respuestas es: 143*777=111111.
    //  Nota: la salida del programa debe ser: 143*777=111111


    unsigned int firstNumber, secondNumber, major = 0;
    unsigned int majorFirstNumber = 0, majorSecondNumber = 0;

    for (unsigned int i = 100; i < 1000; i++){
        firstNumber = i;

        for (unsigned int j = 100; j < 1000; j++){
            secondNumber = j;
            unsigned int mult = firstNumber * secondNumber;

            if (isPalindrome(mult)){
                if (mult > major) {
                    major = mult;
                    majorFirstNumber = firstNumber;
                    majorSecondNumber = secondNumber;
                }
            }
        }
    }

    cout << majorFirstNumber << " * " << majorSecondNumber << " = " << major << endl;

}
