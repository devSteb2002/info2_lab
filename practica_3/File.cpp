#include "File.h"
#include <cctype>
#include <bitset> // manejo y convesion de numeros a bits

using namespace std;

void convertToBits(string text, string &textInBits);
void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, short nBits);
string* splitArray(unsigned short nBits, string textInBits);
void appendToArray(string newElement, unsigned short size, string *&array);

unsigned short SIZEARRAY = 0;

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


void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, unsigned short nBits){ // codificacion del primer metodo
   string *arrayOfBinary = splitArray(nBits, textInBits);
   string arrayCodify[SIZEARRAY]; // definimos nuevo arreglo del tamaño del anterior

   try {
       //cambiar cada bit del primer bloque
       string firstBlock = arrayOfBinary[0];
       string codifyFirstBlock = "";

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

           for (unsigned short j = 0; j < nBits; j++){

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



       for (int i = 0; i < SIZEARRAY; i++){
           cout << arrayCodify[i] << endl;
       }

       codifyBits = "";

   } catch (exception &ex) {
       cout << "error" << endl;
   }
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

    return arrayBits; // retornar la referencia del arreglo de bits
}

void appendToArray(string newElement, unsigned short size, string *&array){ // agregar un nuevo elemento a un arreglo

    string *tempArray = new string[size + 1];

    SIZEARRAY = size + 1;

    for (int i = 0; i < size; i++){
        tempArray[i] = array[i];
    }

    tempArray[size] = newElement;
    delete[] array;

    array = tempArray;
}
