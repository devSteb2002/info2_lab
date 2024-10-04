#ifndef FILE_H
#define FILE_H

#include <iostream>

using namespace std;

//funciones para encriptar
void convertToBits(string text, string &textInBits);
string convertToAssci(string text);
void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, unsigned short nBits = 4);
void encryptBinaryInSecondMethod(string textInBits, string &codifyBits, unsigned short nBits = 4);

//funciones para validar datos
bool isValidNameFile(string &nameFile, bool inFile);

//funciones para desencriptar
string decryptBinaryInFirstMethod(string binary, unsigned short seed = 4);
string decryptBinaryInSecondMethod(string binary, unsigned short seed = 4);

//aplicacion
void aplicationMain();

#endif // FILE_H
