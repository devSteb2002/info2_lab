#include "File.h"
#include <limits>
#include <fstream>


string FILEADMIN = "sudo.bin";
string FILEUSERS = "users.bin";
unsigned short methodDecrypt = 0;

void RolAdmin();
void RolUser();

bool validateCin();

string getRol(); //(1 = admin, 0 = user)
bool compareDecrypts(string line, string passIn, unsigned int id);
bool countCommasAndSemicolon(string text);

void aplicationMain(){ // centro de la aplicacion
   string rol = getRol();

    if (rol == "ADMIN") RolAdmin();
    else if (rol == "USER") RolUser();;

}


string getRol(){ //obtener los roles
    cout << "            SOFTWARE BANCARIO SAS      " << endl;
    cout << "                  Binvenido..." << endl;
    cout << endl;
    cout << "Ingrese sus datos personales a continuacion..." << endl;

    unsigned int id;
    string password, line;
    bool validType = false;
    bool askingData = true;

    while (true){
        if (askingData){
            if (!validType){ //verificar datos de la cedula
                cout << "Cedula: ";
                cin >> id;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Cedula invalida, vuelva a intentar" << endl;
                    continue;
                }

                if (to_string(id).length() < 8 || to_string(id).length() > 10){ //verficar la cantidad correcta de digitos
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "La cedula debe contener 10 digitos, vuelva a intentar" << endl;
                    continue;
                }

                validType = true;
            }else{ //verificar caracter en contraseña
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Contrasena: ";

                getline(cin, password);

                if (password.find("'") != string::npos){
                    cout << "La contraseña contiene caracteres invalidos (',\", ^) " << endl;
                    continue;
                }

                if (!password.empty()) askingData = false;

            }
        }else{

            //PRIMERO: VERFICAR SI ES ADMIN
            fstream FileAdmin; //abrir en modo lectura
            FileAdmin.open(FILEADMIN, ios::in | ios::binary);

            if (!FileAdmin.is_open()){
                cout << "Fallo conexion a la tabla admin" << endl;
                return "";
            }

            getline(FileAdmin, line); // leer la primera linea del archivo
            FileAdmin.close();
            if (compareDecrypts(line, password, id)){ //si es admin
                cout << "Perfil: Administrador" << endl;
                return "ADMIN";
            }

            //verificar con los usuarios
            fstream FileUsers;
            FileUsers.open(FILEUSERS, ios::in | ios::binary);

            if (!FileUsers.is_open()){
                cout << "Fallo la conexion a la tabla users" << endl;
                return "";
            }

            bool isUser = false;
            while(getline(FileUsers, line)){

                if (line.empty()) continue;

                if (compareDecrypts(line, password, id)){
                    cout << "Perfil: Usuario." << endl;
                    isUser = true;
                }
            }

            FileUsers.close();

            if (isUser) return "USER";

            cout << "Cedula y/o contrasena incorrectos, vuelva a intentar" << endl;

            validType = false;
            askingData = true;
        }
    }
}

void RolAdmin(){ // acciones que puede hacer el administrador
    cout << endl;
    cout << "    BIENVENIDO ADMINISTRADOR    ";
    cout << endl;

    unsigned short option;

    while (true){
        cout << "Anadir Usuario -> 1" << endl;
        cout << "Cerrar Sesion -> 2" << endl;

        cin >> option;

        if (!validateCin()) continue;

        if (option > 2 || option < 1){
            cout << "Solo se permiten dos valores (1, 2), vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    if (option == 2){
        getRol();
        methodDecrypt = 0;
        return;
    }

    cout << "Creacion De Nuevos Usuarios" << endl;
    //cuando la option es 1
    int id;
    bool validateId = false;
    while (true){

        if (!validateId){
            cout << "Cedula: ";

            cin >> id;

            if (!validateCin()) continue;

            if (to_string(id).length() < 8 || to_string(id).length() > 10){
                cout << "Rango de cedula invalido" << endl;
            }

        }

    }



    cout << methodDecrypt << endl;

}

void RolUser(){

}

bool compareDecrypts(string line, string passIn, unsigned int id){ //Desencriptar por ambos metodos y buscar coincidencias

    string decryptFirstMethod = decryptBinaryInFirstMethod(line);
    string decryptSecondMethod = decryptBinaryInSecondMethod(line);

    string assciFirstMethod = convertToAssci(decryptFirstMethod);
    string assciSecondMethod = convertToAssci(decryptSecondMethod);

    string correctDecryptString = "";

    unsigned short vMethod = 0;
    bool matchPass = false, matchId = false;

    //verificar de codificacion y asignar el texto correcto
    if (countCommasAndSemicolon(assciFirstMethod)) {
        correctDecryptString = assciFirstMethod;
        vMethod = 1;
    }else if (countCommasAndSemicolon(assciSecondMethod)){
        correctDecryptString = assciSecondMethod;
        vMethod = 2;
    }
    else return false;

    //buscar la ultima aparicion de la coma
    size_t lastIndexComma = correctDecryptString.rfind(",");
    size_t firstIndexComma = correctDecryptString.find(",");

    if (lastIndexComma != string::npos && firstIndexComma != string::npos){

        string password_ = "";

        if (firstIndexComma == lastIndexComma){  // formato cedula, clave;

            password_ = correctDecryptString.substr(lastIndexComma, (correctDecryptString.length()));
            password_.erase(password_.find(","), 1); // limpiar de comas la contraseña
            password_.erase(password_.find(";"), 1); // limpiar de punto y coma """"""

        }else{ //formato cedula,clave,saldo;
            password_ = correctDecryptString.substr(firstIndexComma, lastIndexComma);
            password_ = password_.substr(1, password_.rfind(",") - 1);
        }

        if (password_.compare(passIn) == 0) matchPass = true; // las contraseñas coinciden
        else return false;

        string id_ = correctDecryptString.substr(0, firstIndexComma);

        try {
            if (id_ == to_string(id)) matchId = true;
            else return false;

            if (matchPass && matchId) { //cuando se cumple las dos condiciones
                methodDecrypt = vMethod;
                return true;
            }

        } catch (const invalid_argument& e) {
            cout << "Fallo la conversion de la cedula" << endl;
        }
    }

    return false;
}


bool countCommasAndSemicolon(string text){ // funcion que cuenta las comas y el punto y coma

    unsigned short numberOfCommas = 0, numberOfSemicolon = 0;

    for (unsigned short i = 0; i < text.length(); i++){
        const char character = text[i];
        if (character == ',') numberOfCommas++;
        if (character == ';') numberOfSemicolon++;
    }

    if (numberOfCommas == 1 || numberOfCommas == 2){ //cumple las comas
        if (numberOfSemicolon == 1){ //cumple el punto y coma
            //se desencripto correctamente
            return true;
        }
    }

    return false;
}

bool validateCin(){

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Dato invalido, vuelva a intentar." << endl;
        return false;
    }

    return true;
}
