#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

void askInputs(int &number, long long &stringOfNumbers);
bool validateInputsNumbers();

void problem_9(){

    int number = 0, lengthString = 0;
    long long stringOfNumber = 0;
    short count = 0, toGetIndex = 0; //count  0 - number para saber cuando dividir, togetNumber, 0 - number posiciones en el array
    string toStringNumbers = "", numberSeparates = "", pars = "";

    askInputs(number, stringOfNumber);

    toStringNumbers = to_string(stringOfNumber); // convertir el numero dado en un string

    while (true){ //llenar el string correctamente
        lengthString = toStringNumbers.length(); //obtener la longitud del string

        if (lengthString % number != 0){ // cuando no se puede dividir correctamente
            toStringNumbers = "0" + toStringNumbers; //concatenar un 0 al principio
        }else break;
    }

    string *numbersSplit = new string[lengthString / number]; // arreglo de string dinamico con #posicion = al numero pro dividir

    for (int i = 0; i <= lengthString; i++){ //iterar sobre cada letra del string

        if (count == number){ // si count es igual al numero por dividr ingreso la cadena al array
            numbersSplit[toGetIndex] = pars;
            toGetIndex++; //aumento la posicion en el array
            pars = ""; // reinicio el string
            count = 0; // reinicio el contador
        }

        pars += toStringNumbers[i];
        count++;
    }

    int sum = 0;
    for (int i = 0; i < (lengthString / number); i++) sum += stoi(numbersSplit[i]);

    delete[] numbersSplit;

    cout << "Original: " << stringOfNumber << ", Suma: " << sum << endl;
}



void askInputs(int &number,long long &stringOfNumbers){ // pedir y validar las entradas del usuario

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
