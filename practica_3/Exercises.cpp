#include "File.h"
#include "exercises.h"
#include <fstream>
#include <limits>

void readAndWriteFile(bool exercise2 = false);

bool validCin();
void askInfo(unsigned short &method, unsigned short &seed, string exercise = "Ejercicio 1");
void askNamesFiles(string &nameFileInput, string &nameFileOutput);


string nameFileInput = "", nameFileOutput = "";
string textInBits = "", codifyBits = "";
unsigned short method, seed;

void Exercise_1(){

    //ejercicio 1
    askInfo(method, seed); //pedir metodo y semilla por referencia
    askNamesFiles(nameFileInput, nameFileOutput); // pedir nombre de archivos por referencia

    try {
        readAndWriteFile();
        cout << "Dato encriptados y guardados correctamente" << endl;

    } catch (exception &ex) {
        cout << "Error en readAndWrite" << endl;
    }
}


void Exercise_2(){
    askInfo(method, seed, "Ejercicio 2"); //pedir metodo y semilla por referencia
    askNamesFiles(nameFileInput, nameFileOutput); // pedir nombre de archivos por referencia

    try {
        readAndWriteFile(true);
        cout << "Datos desencriptados correctamente" << endl;
    } catch (exception &ex) {
        cout << "Error en readAndWrite" << endl;
    }
}


void readAndWriteFile(bool exercise2){
    string line;

    if (!exercise2){ // ejercicio 1 (encriptar un texto plano)

        fstream File1; //archivo de texto sin encriptar
        fstream FileOut; //archvio de encriptacion

        File1.open(nameFileInput, ios::in | ios::out | ios::app);
        FileOut.open(nameFileOutput, ios::out | ios::binary | ios::trunc);

        if (!File1.is_open() || !FileOut.is_open()){ // verificar que se haya abierto los dos archivos
            cout << "Error al abir los archivos" << endl;
            return;
        }

        while(getline(File1, line)){ //encriptar cada linea del archvio de texto ejercicio 1

            if (line.empty()) continue;

            convertToBits(line, textInBits); //convertir a bit el texto de archivo plano

            if (method == 1) encryptBinaryInFirstMethod(textInBits, codifyBits, seed); //codificar metodo 1
            else encryptBinaryInSecondMethod(textInBits, codifyBits, seed); //codificar metodo 2

            FileOut << codifyBits << endl; // añadir al archivo ya codificado
            codifyBits = ""; //limpiar los datos de referencia
        }

        FileOut.close();
        File1.close();

    }else{ // Ejercicio 2 (desencriptar un archivo)

        fstream FileBinary; // Archivo con los datos encriptados
        ofstream FileText; // Archivo donde se guarda los datos desencriptados

        FileBinary.open(nameFileOutput, ios::in | ios::binary);
        FileText.open(nameFileInput, ios::out | ios::trunc);

        if (!FileBinary.is_open() || !FileText.is_open()){
            cout << "Error al abrir los archvios" << endl;
            return;
        }

        string allBinary = "";

        while(getline(FileBinary, line)){ //ejercico 2 desencriptar

            if (line.empty()) continue;

            string decryptBinary = "", ascci = "";

            if (method == 1) decryptBinary = decryptBinaryInFirstMethod(line, seed); //desencriptar segun el metodo
            else decryptBinary = decryptBinaryInSecondMethod(line, seed);

            ascci = convertToAssci(decryptBinary); // convertir a texto

            FileText << ascci << endl; // copiar en el archivo plano
        }


        FileBinary.close(); //cerrar archivos
        FileText.close();
    }
}


void askInfo(unsigned short &method, unsigned short &seed, string exercise){ // funcion para obtener el metodo y la semilla (ambos ejercicios)

    bool validMethod = false;

    cout << exercise << endl;

    //pedir datos
    while (true){
        if (!validMethod){ //validar metodo
            cout << "Seleccione el metodo de " << (exercise == "Ejercicio 1" ? "encriptacion" : "desencriptacion") << endl;
            cout << "Primer metodo -> 1" << endl;
            cout << "Segundo metodo -> 2" << endl;

            cin >> method;

            if (!validCin()) continue;

            if (method < 1 || method > 2){
                cout << "Solo se adminte el 1 y el 2" << endl;
                continue;
            }

            validMethod = true;
        }else{
            //validar semilla
            cout << "Ingrese la semilla (numero entero 2 - 8)" << endl;
            cin >> seed;

            if (!validCin()) continue;

            if (seed > 8 || seed < 2){
                cout << "El rango de la semilla es de 2 a 8" << endl;
                continue;
            }

            break;
        }
    }
}

void askNamesFiles(string &nameFileInput, string &nameFileOutput){ // funcion para obtener el nombre de los archivos

    bool inFile = false;
    cin.ignore();

    while(true){
        cout << "Ingrese el nombre del archivo txt" << endl;

        getline(cin , nameFileInput);

        if (isValidNameFile(nameFileInput, inFile)){ // funcion que valida el nombre correctamente
            inFile = true;
            break;
        }else cin.clear();
    }

    while (true){ //validar archivo de salida

        cout << "Ingrese el nombre del archvio bin" << endl;

        getline(cin, nameFileOutput);

        if (isValidNameFile(nameFileOutput, inFile)) break;
        else cin.clear();
    }
}


bool validCin(){

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Dato ingresado invalido." << endl;

        return false;
    }

    return true;
}
