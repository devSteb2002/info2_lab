#include <iostream>
#include "problems.h"

using namespace std;

bool validateTime(string time);
string validateInputs(string text);
int convertTimeToSecond(string time);

void problem4(){
    // Problema 4. Escriba un programa para leer dos números enteros con el siguiente signicado: el
    //valor del primer número representa una hora del día en un reloj de 24 horas, de modo que 1245
    //representa las doce y cuarenta y cinco de la tarde. El segundo entero representa un tiempo de duración de la misma manera, por lo que 345 representa tres horas y 45 minutos. El programa debe
    //sumar esta duración primer número, y el resultado será impreso en la misma notación, en este caso
    //1630, que es el tiempo de 3 horas y 45 minutos después de 12:45.
    //Nota: el formato de salida debe ser: La hora es 1630.
    //Otra nota: se debe imprimir un mensaje como el siguiente cuando uno de los datos ingresados en
    //inválido: 1560 es un tiempo invalido.

    string hours, timeLapse;

    hours = validateInputs("primer");
    timeLapse = validateInputs("segundo");

    unsigned int firstTime = convertTimeToSecond(hours);
    unsigned int secondTime = convertTimeToSecond(timeLapse);

    unsigned int totalTime = firstTime + secondTime;
    unsigned int totatHours = totalTime / 3600;
    unsigned int totalminutes = (totalTime % 3600) / 60;

    cout << "La hora es: " << totatHours << ":" << totalminutes;
}

bool validateTime(string time){
    try {
        stoi(time);
    } catch (invalid_argument) {
        cout << "Por favor ingrese un numero valido." << endl;
        return false;
    }

    return true;
}

string validateInputs(string text){
    string time = "";

    while (true){
        cout << "Ingrese el " <<  text << " numero con 4 digitos: ";
        cin >> time;

        if (!validateTime(time)) continue;

        if (time.length() < 2 || time.length() > 4){
            cout << "El valor ingresado no debe ser menor de 2 y mayor de 4 digitos." << endl;
            continue;
        }

        time = time.length() == 2 ? (time + "00") : time;
        time = time.length() == 3 ? ("0" + time) : time;

        if (time[2] >= '6'){
            cout << time << " es un tiempo invalido." << endl;
            continue;
        }

        return time;
    }
}


int convertTimeToSecond(string time){

    int hour = stoi(time.substr(0,2));
    int minuts = stoi(time.substr(2,4));
    int totalSeconds = (hour * 3600) +  (minuts * 60);

    return totalSeconds;
}

