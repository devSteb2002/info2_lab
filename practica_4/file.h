#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include "router.h"

using namespace std;

class File
{
public:
    File(Router& router);


    unsigned int getLastId();

private:
    fstream file_;
    Router& router_;
};

#endif // FILE_H
