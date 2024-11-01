#include "file.h"

File::File(Router &router) : router_(router) {

    file_.open("Red.txt", ios::in | ios::out | ios::app);

    if (!file_.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }

    string line;
    while (getline(file_, line)){
        router.formatDataInit(line);
    }

}

unsigned int File::getLastId(){
}
