#include "File.h"
#include <algorithm>
#include <cctype>
#include <bitset> // manejo y convesion de numeros a bits

using namespace std;

//funciones de encriptacion
void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, unsigned short nBits);
void encryptBinaryInSecondMethod(string textInBits, string &codifyBits, unsigned short nBits);

//funciones secundarias para manejo de datos
void convertToBits(string text, string &textInBits);
string convertToAssci(string text);
string* splitArray(unsigned short nBits, string textInBits);
void appendToArray(string newElement, unsigned short size, string *&array);

//funciones para validar
bool isValidNameFile(string &nameFile, bool inFile);

//funciones para desencriptar
string decryptBinaryInFirstMethod(string binary, unsigned short seed);
string decryptBinaryInSecondMethod(string binary, unsigned short seed);

unsigned short SIZEARRAY = 0;

//==============================================
//Funciones de encriptacion

void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, unsigned short nBits){ // codificacion del primer metodo
    SIZEARRAY = 0;

    string *arrayOfBinary = splitArray(nBits, textInBits); //separar en nbits y posiciones en un array
    string arrayCodify[SIZEARRAY]; // definimos nuevo arreglo del tamaño del anterior

    //cambiar cada bit del primer bloque
    string firstBlock = arrayOfBinary[0];
    string codifyFirstBlock = "";
    unsigned short tempSeed = nBits;

    for (unsigned short i = 0; i < nBits; i++){
        char element = firstBlock[i];

        if (element == '0') codifyFirstBlock += '1';
        else codifyFirstBlock += '0';
    }

    arrayCodify[0] = codifyFirstBlock;

       //encriptacion de los demas elementos

    for (unsigned short i = 1; i < SIZEARRAY; i++){
        string blockBefore = arrayOfBinary[i - 1]; // posicion anterior
        string actualBlock = arrayOfBinary[i]; // posicion actual

        if (actualBlock.length() != nBits) tempSeed = actualBlock.length();

        unsigned short countZeros = 0, countOnes = 0;

        for (unsigned short j = 0; j < nBits; j++){ // iterar el bloque anterior
            char bit = blockBefore[j];

            if (bit == '0') countZeros++; //contar cantidad de ceros y de unos
            else countOnes++;
        }

        //verificacion de las condiciones
        string codifyBlock = "", newBlockBits = "";
        unsigned short nBitsCodify = 1; //1 => se invierte cada bit
        unsigned short countBits = 0;

        if (countZeros > countOnes) nBitsCodify = 2;     //si hay mayor cantidad de ceros que de unos se invierte cada dos bits
        else if (countOnes > countZeros) nBitsCodify = 3; // cada tres bits

        for (unsigned short j = 0; j < tempSeed; j++){

            if (countBits == nBitsCodify - 1){ // cuando encuentre el bit cada n posiciones invierte valors

                if (actualBlock[j] == '0') newBlockBits += '1';
                else newBlockBits += '0';

                countBits = 0;
                continue;
            }

            newBlockBits += actualBlock[j];
            countBits++;
           }

           arrayCodify[i] = newBlockBits;
       }

    for (int i = 0; i < SIZEARRAY; i++) codifyBits +=  arrayCodify[i]; //juntar en uns tring todo

    delete[] arrayOfBinary;
}


void encryptBinaryInSecondMethod(string textInBits, string &codifyBits, unsigned short nBits){ //segundo metodo de encriptacion
    SIZEARRAY = 0;

    string *arrayOfBinary = splitArray(nBits, textInBits); //separar en nbits en posiciones en un array
    string arrayCodify[SIZEARRAY];
    unsigned short tempSeed = nBits;

    try {

        for(unsigned short i = 0; i < SIZEARRAY; i++){ // iterar sobre el array
            string block = arrayOfBinary[i];

            if (block.length() != nBits) tempSeed = block.length(); // cuando el bloque no contenga los nbits de la semilla

            arrayCodify[i] = block;
            arrayCodify[i][0] = block[tempSeed - 1]; //agreagamos el ultimo elemento al principio

            for (unsigned short j = 1; j < tempSeed; j++)
                arrayCodify[i][j] = block[j - 1]; // intercambiamos posiciones evitando los extremos
        }

    } catch (exception &ex) {
        delete[] arrayOfBinary;
        cout << "Error en el segundo metodo de encriptacion";
    }

    for (int i = 0; i < SIZEARRAY; i++) codifyBits += arrayCodify[i]; //juntar en uns tring todo

    delete[] arrayOfBinary;

}

//funciones para desencriptar
string decryptBinaryInSecondMethod(string binary, unsigned short seed){ // segundo metodo de desencriptacion
    //NOTA: parecido a la encriptacion
    //pero aqui se mueve de derecha a izquierda

    SIZEARRAY = 0;

    string *arrayOfBinary = splitArray(seed, binary);
    string arrayCodify[SIZEARRAY];
    string response = "";
    unsigned short tempSeed = seed;


    try{

        for (unsigned short i = 0; i < SIZEARRAY; i++){
            string block = arrayOfBinary[i];

            if (block.length() != seed) tempSeed = block.length();

            arrayCodify[i] = block;
            arrayCodify[i][tempSeed - 1] = block[0];  //movemos el primer elemento al final

            for (unsigned short j = 0; j < tempSeed - 1; j++){
                arrayCodify[i][j] = block[j + 1];
            }
        }


        for (int i = 0; i < SIZEARRAY; i++) response += arrayCodify[i];
        delete[] arrayOfBinary;
        return response;

    }catch (invalid_argument &ex){
        delete[] arrayOfBinary;
        cout << "error" ;
        return response;
    }
}



string decryptBinaryInFirstMethod(string binary, unsigned short seed){ //primer metodo de desencriptacion
    //NOTA: es parecido a la forma de encriptacion
    //pero varia en la manipulacion del arreglo inicial y el arreglo secundario

    SIZEARRAY = 0;

    string *arrayBinary = splitArray(seed, binary);
    string arrayDecodify[SIZEARRAY];
    unsigned short seedTemp = seed;

    //editar primer bloque
    for (unsigned short i = 0; i < seed; i++){
        if (arrayBinary[0][i] == '0') arrayBinary[0][i] = '1';
        else arrayBinary[0][i] = '0';
    }

    arrayDecodify[0] = arrayBinary[0];

    //editar los demas bloques en base en el primero
    for (unsigned short i = 1; i < SIZEARRAY; i++){

        string actualBlock = arrayBinary[i];
        string beffBlock = arrayBinary[i - 1];

        if (actualBlock.length() != seed){
            seedTemp = actualBlock.length();
        }

        //contar cantidad de unos y ceros
        unsigned short numberOfCeros = 0, numberOfOnes = 0;
        for (unsigned short j = 0; j < seed; j++){
            if (arrayDecodify[i - 1][j] == '0') numberOfCeros++;
            else numberOfOnes++;
        }

        //condicion segun el numero de ceros y unos

        unsigned short coditionsOnesOrCeros = 1, contBits = 0;
        string stringDecodify = "";

        if (numberOfCeros > numberOfOnes) coditionsOnesOrCeros = 2;
        else if ( numberOfOnes > numberOfCeros) coditionsOnesOrCeros = 3;

        for (unsigned short j = 0; j < seedTemp; j++){

            if (contBits == (coditionsOnesOrCeros - 1)){
                if (actualBlock[j] == '0') stringDecodify += '1';
                else stringDecodify += '0';

                contBits = 0;
                continue;
            }

            stringDecodify += actualBlock[j];
            contBits++;
        }


        arrayDecodify[i] = stringDecodify;
    }

    string res = "";
    for (int i = 0; i < SIZEARRAY; i++) res += arrayDecodify[i];

    delete[] arrayBinary;
    return res;
}


//funciones de validacion
bool isValidNameFile(string &nameFile, bool inFile){ // validar el nombre del archivo

    string restrictCaracter[] = { // caracteres no validos en el nombre de un archivo
        "<", ">" , ":",
        "“" , "|", "?",
        "*", "/", "'"
    };

    unsigned short length = nameFile.length();

    //validar que tenga alguna extension
    size_t extensionIndex = nameFile.find('.'); // encontrar la posicion del .

    if (extensionIndex == string::npos){
        cout << "No se encontro extension del archivo" << endl;
        return false;
    }

    string extension = nameFile.substr(extensionIndex, length - 1);
    string name = nameFile.substr(0, extensionIndex);


    if (name.empty()){  //validar que tenga un nombre
        cout << "Debe tener un nombre el archivo, vuelva a intentar." << endl;
        return false;
    }

    //verificar que la extension sea la correcta
    if (!inFile){ // se pregunta por el txt
        if (extension != ".txt"){
            cout << "La extension debe ser .txt, vuelva a intentar." << endl;
            return false;
        }
    }else{ // bin
        if (extension != ".bin"){
            cout << "La extension debe ser .bin, vuelva a intentar." << endl;
            return false;
        }
    }

    //vericiar que el nombre no tenga los caracters
    for (unsigned short i = 0; i < 9; i++){ // iteramos sobre el arreglo de caracteres invalidos
        size_t findedResctric = nameFile.find(restrictCaracter[i]);

        if (findedResctric != string::npos){
            cout << "Los caracteres < , >, :, “, |, ?, *, /, no son permitidos en el nombre, vuelva a intentar" << endl;
            return false;
        }
    }

    for (unsigned short i = 0; i < length; i++){     //eliminar los espacios en blanco
        if (nameFile[i] == ' ') nameFile.erase(i, 1);
    }

    return true;
}


//=========================
//funciones secundarias para manejo de datos

void convertToBits(string text, string &textInBits){ // convertir texto a binario
    unsigned short length = text.length();
    string tempString = "";

    for (unsigned short i = 0; i < length; i++){ //iterar sobre cada caracter
        char letter = text[i];

        if (!isdigit(letter)){  // si no es un numero
            bitset<8> bits(static_cast<short>(letter)); // encontra el valor en ascci de la letra y convertirlo a binario
            tempString += bits.to_string();

        }else{
            bitset<8> bits(letter); // convertir el digito a binario
            tempString += bits.to_string();
        }
    }

    textInBits = tempString;
}

string convertToAssci(string text){ // funcion para convertir el codigo binario a ascci

    SIZEARRAY = 0;

    unsigned const byte = 8;
    string *arrayBinary = splitArray(byte, text); // separar nbits en posiciones en un array
    string textDecrypt = "";

    for (int i = 0; i < SIZEARRAY; i++){
        try {
            if (!arrayBinary[i].empty()){
                char carater = static_cast<char>(bitset<8>(arrayBinary[i]).to_ullong()); // convertir los 8bits a su respectivo valo en ascci
                textDecrypt += carater;
            }

        } catch (const invalid_argument e) {
            cout <<  "eerror " << e.what() << endl;
            break;
        }
    }

    delete[] arrayBinary;
    return textDecrypt;
}


string* splitArray(unsigned short nBits, string textInBits){ //agregar grupos de bits al arreglo y regresar la referencia
    unsigned short countBits = 1, size = 0;
    unsigned short lengthBits = textInBits.length();
    string splitBinaryTemp = "";
    string *arrayBits = nullptr;

    for (int i = 0; i < lengthBits; i++){ //iterar sobre cada bit

        splitBinaryTemp += textInBits[i];

        if (countBits == nBits){ //contar cada nbits

            appendToArray(splitBinaryTemp, size, arrayBits); //agregar esos nbits a un arreglo

            splitBinaryTemp = ""; //reinicializar valores
            countBits = 0;
            size++;
        }

        countBits++;
    }

    if (!splitBinaryTemp.empty()) appendToArray(splitBinaryTemp, size, arrayBits);

    return arrayBits; // retornar la referencia del arreglo de bits
}

void appendToArray(string newElement, unsigned short size, string *&array){ // agregar un nuevo elemento a un arreglo

    string *tempArray = new string[size + 1];

    SIZEARRAY = size + 1;

    for (int i = 0; i < size; i++)
        tempArray[i] = array[i];


    tempArray[size] = newElement;
    delete[] array;

    array = tempArray;
}


