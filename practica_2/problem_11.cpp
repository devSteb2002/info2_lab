#include <iostream>
#include "problems.h"
#include <limits>
#include <unistd.h>

using namespace std;

void printSits(bool** array, char rows[]);
void clearMemory(bool** &array);
unsigned int initCinema();
unsigned int validateRow(char rows[]);
unsigned int validateCol();
bool validateOptionsCinema(unsigned int option);

void problem_11(){

    unsigned int option;
    bool** arrayCinema = new bool*[15];  // decalaracion del arreglo bidimensional de punteros con las filas y columnas
    char arrayRow[15] = {                // arreglo con las letras de las filas
        'A', 'B', 'C', 'D',
        'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L',
        'M','N','O'
    };

    for (short i = 0; i < 15; i++){     // iterar las filas del arreglo
        arrayCinema[i] = new bool[20];  // reservar un espacio de memoria para las columnas

        for (short j = 0; j < 20; j++) arrayCinema[i][j] = false; // iterar las columnas para inicilizar en false
    }

    bool isInitiCinema = true;


    while(true){

        if (isInitiCinema){
            option = initCinema();
            isInitiCinema = false;
        }

        if (option == 3){
            clearMemory(arrayCinema);
            break;
        }

        unsigned int indexRow = validateRow(arrayRow); // obtner la fila
        unsigned int indexCol = validateCol(); // obtener el asiento

        bool valueSpot = arrayCinema[indexRow][indexCol];

        if (option == 1){ // Reserva
            cout << "Reservacion del asiento: " << arrayRow[indexRow] << "-" << (indexCol + 1) << endl;

            if (valueSpot){ // el asiento ya esta reservado
                cout << "El asiento ya esta reservado, ingrese otro. " << endl;
                continue;
            }

            //cuando el asiento no esta reservado
            arrayCinema[indexRow][indexCol] = true;
            cout << "Asiento Reservado con exito." << endl;
        }
        else if (option == 2){ // cancelar reserva

            if (!valueSpot){ //verificar si el asiento esta ocupado
                 cout << "Este asiento no tiene reserva, ingrese otro." << endl;
                continue;
            }

            arrayCinema[indexRow][indexCol] = false;
            cout << "Reserva eliminada con exito." << endl;
        }

        usleep(1000000);
        isInitiCinema = true;
        printSits(arrayCinema, arrayRow);

    }
}

unsigned int initCinema(){ // pedir datos para reserva o cancelaciones

    unsigned int option;

    cout << endl;
    cout << "  Reservas Cinema  " << endl;
    cout << " ================== " << endl;
    cout << endl;

    cout << "Seleccione una opcion. " << endl;
    cout << "1. Reservar" << endl;
    cout << "2. Cancelaciones " << endl;
    cout << "3. salir" << endl;

    do{ // ciclo para validar que la entra sea correcta
        cout << "Ingrese una opcion." << endl;
        cin >> option;

        if (!validateOptionsCinema(option)) continue; // si es falso la validacion entonces continue en el ciclo
        break;
    }while(true);

    return option;
}

bool validateOptionsCinema(unsigned int option){ // validaciones del input

    if (cin.fail()){ // validar que el dato desde el cin sea correcto
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Numero Invalido. Vuelva a intentar" << endl;
        return false;
    }

    if (option >= 1 && option <= 3) // 1,2, 3 los unicos valores permitidos
        return true;


    cout << "Rango de valores invalidos. " << endl;
    cout << "Valores permitidos: 1, 2, 3." << endl;

    return false;
}

unsigned int validateRow(char rows[]){ // validar el input para las filas A-0

    string caracter;
    unsigned int index;

    while(true){ //validaciones necesarias para las filas
        cout << "Ingrese la fila (A-O)." << endl;
        cin >> caracter;

        if (caracter.length() > 1){
            cout << endl << "Por favor ingrese solo un caracter." << endl;
            continue;
        }

        char toUpperCaracter = toupper(caracter[0]); // convertir caracter a mayusculas
        bool finded = false;

        for (int i = 0; i < 15; i++){ // validar que exista el caracter en el arreglo
            if (rows[i] == toUpperCaracter) {
                finded = true;
                index = i;
                break;
            }
        }

        if (finded) break; // si se encontro termina el ciclo


        cout << "Por favor ingrese una letra dentro del rango." << endl;
        cin.clear();
    }

    return index; // retorna la posicion en la que se encotro el caracter(fila)
}

unsigned int validateCol(){ // validar el numero del asiento ingresado

    unsigned int spot;

    while (true){
        cout << "Ingrese el asiento (1 - 20)." << endl;
        cin >> spot;

        if (cin.fail()){ // validar que se haya ingresado un nuemro
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un asiento valido." << endl;
            continue;
        }

        if (spot >= 1 && spot <= 20) break; // validar el rango del numero

        cout << "Numero de asiento fuera de rango." << endl;
    }

    return (spot - 1); // retornar el indice del asiento
}


void printSits(bool** array, char rows[]){

    cout << "   ";
    for (int j = 0; j < 20; j++) { // imprimir la primera fila del 1 hasta el 20
        string numberCol = to_string(j + 1);

        if (j > 9) numberCol = "" + numberCol + " ";
        else numberCol = " " + numberCol + " ";

        cout << " " << numberCol << " ";
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout <<  " " << rows[i] << " " ; // imprimir la primera columna con letras de la A hasta la O

        for (int j = 0; j < 20; j++) {
            string state = (array[i][j]) ? "+" : "-"; // imprimir valor de la posicion [i][j] en la matriz
            cout << "  " << state << "  ";
        }
        cout  << endl;
    }
}


void clearMemory(bool** &array){
    for (int i = 0; i < 15; i++){
        delete[] array[i];
    }

    delete[] array;
}
