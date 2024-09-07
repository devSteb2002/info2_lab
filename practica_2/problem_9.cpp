#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void askInputs(int &number, int &stringOfNumbers);
bool validateInputsNumbers();

void problem_9(){

    int number = 0, stringOfNumber = 0, cont = 0;
    string toStringNumbers = "", numberSeparates = "";

    askInputs(number, stringOfNumber);

    toStringNumbers = to_string(stringOfNumber); // convertir el numero dado en un string

    int arrayNumbers[number];
    int size = number;

    for (int i = toStringNumbers.length(); i >= 0; i--){ // iterar desde la ultima posicion el string con los numeros

        if (cont == number){ // verificar cuando cont sea igual a el numero de division
            arrayNumbers[size - 1] = i; // guardar en el arreglo la posicion en donde se divide
            cont = 0;  // reinicializar variables
            size--;
            numberSeparates = "";
        }

        cont++;
    }

    arrayNumbers[0] = 0; // inicializar la posicion 0 como 0

    for (int i = 0; i < number; i++){ //iterar las cantidad el numero, ya que el array tiene esa misma dimension
        int index = arrayNumbers[i]; //valor en la posicion i; corresponde una poicion en el string
        int toIndex = i + 1; // valor en la posicion i +1; corresponde a la posicion siguiente en el string
        string stringSeparates = "";

        if (toIndex < number){ // si la posicion siguiente es menor que el numero ingresado
            for (int j = index; j < arrayNumbers[toIndex]; j++){ //itero desde la posicion actual, hasta la siguiente en el string
                stringSeparates += toStringNumbers[j];
            }
        }else if (toIndex == number){ // si son iguales
            for (int j = index; j < toStringNumbers.length(); j++){ //iterar desde el index hasta la longitud de la cadena
                stringSeparates += toStringNumbers[j];
            }
        }

        cout << stringSeparates << endl;

        arrayNumbers[i] = stoi(stringSeparates); // cambiar cada posicion en el arreglo por el numero formado en stringSeparates
    }

    int sum = 0;
    for (int i = 0; i < number; i++){ // iterar el array para sumar los numeros
        sum += arrayNumbers[i];
    }

    cout << "La suma es: " << sum << endl;
}



void askInputs(int &number,int &stringOfNumbers){ // pedir y validar las entradas del usuario

    bool validNumber = false;

    while(true){

        if (!validNumber){
            cout << "Ingrese un numero para separar la cadena:" << endl;
            cin >> number;

            if (!validateInputsNumbers()) continue;

            if (number < 0){
                cout << "El numero debe ser positivo." << endl;
                continue;
            }

            validNumber = true;
        }else{
            cout << "Ingrese la cadena de numeros: " << endl;
            cin >> stringOfNumbers;

            if (!validateInputsNumbers()) continue;

            if (stringOfNumbers < 0){
                cout << "La cadena debe ser positiva." << endl;
                continue;
            }

            if (to_string(stringOfNumbers).length() <= number){
                cout << "El numero debe ser mayor al numero en que se quiere dividir." << endl;
                continue;
            }

            break;

        }
    }
}

bool validateInputsNumbers(){ // validar que el cin sea del tipo correcto

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrada invalida, vuelve a intentar." << endl;

        return false;
    }

    return true;
}
