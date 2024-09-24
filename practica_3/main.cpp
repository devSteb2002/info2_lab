#include "File.h"


using namespace std;

int main()
{

    string nameFile = "sudo.txt";
    string textInBits = "";
    string codifyBits = "";

    convertToBits("AbCd", textInBits); // (texto, textiInBITS => por referencia)

    short nBits = 4;

    encryptBinaryInFirstMethod(textInBits, codifyBits, nBits);


}
