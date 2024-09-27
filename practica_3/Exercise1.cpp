#include "File.h"
#include "exercises.h"
#include <fstream>

void writeOnFile(string nameFile, string text);

void Exercise_1(){

    //ejercicio 1

    string nameFile = "";
    string textInBits = "";
    string codifyBits = "";
    short nBits = 4, method = 1;

    convertToBits("AbCd", textInBits); // (texto, textiInBITS => por referencia)

    //metodo 1
    encryptBinaryInFirstMethod(textInBits, codifyBits, nBits);

    //metodo 2
    //encryptBinaryInSecondMethod(textInBits, codifyBits, nBits);


    //guardar encripatacion en el archivo
    if (method == 1){
        nameFile = "exercise1.bin";
        writeOnFile(nameFile, codifyBits);
    }

}


void writeOnFile(string nameFile, string text){ //escribir en el archivo
    ofstream File;

    try {
        File.open(nameFile, ios::out | ios::app);

        if (File.is_open()){
            File << text << endl;
            File.close();
        }

    } catch (exception &ex) {
        cout << "Error al guardar informacion";
    }

}
