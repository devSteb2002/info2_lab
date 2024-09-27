#ifndef FILE_H
#define FILE_H

#include <iostream>

using namespace std;
void convertToBits(string text, string &textInBits);
void encryptBinaryInFirstMethod(string textInBits, string &codifyBits, unsigned short nBits);
void encryptBinaryInSecondMethod(string textInBits, string &codifyBits, unsigned short nBits);

#endif // FILE_H
