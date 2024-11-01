#include "File.h"
#include <limits>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdio>

string FILEADMIN = "sudo.bin";
string FILEUSERS = "users.bin";
string FILETEMPORAL = "temp.bin";

void RolAdmin(bool init = true);
void RolUser(string user);

bool validateCin(string const text);
unsigned short validateOption(string text1, string text2, string text3 = "");

string getRol(string &user); //(1 = admin, 0 = user)
bool compareDecrypts(string line, string passIn, unsigned int id, string &user);
bool countCommasAndSemicolon(string text);

void aplicationMain(){ // centro de la aplicacion
    string user = "";
    string rol = getRol(user);

    if (rol == "ADMIN") RolAdmin();
    else if (rol == "USER") RolUser(user);
    else cout << "Fallo en la red, verifica tu conexion a internet" << endl;;

}


string getRol(string &user){ //obtener los roles
    cout << "            SOFTWARE BANCARIO SAS      " << endl;
    cout << "                  Binvenido..." << endl;
    cout << endl;
    cout << "Ingrese sus datos personales a continuacion..." << endl;

    int id;
    string password, line;
    bool validType = false;
    bool askingData = true;

    while (true){
        if (askingData){
            if (!validType){ //verificar datos de la cedula
                cout << "Cedula: ";
                cin >> id;

                if (!validateCin("Cedula invalida, vuelva a intentar")) continue;

                if (id < 0){
                    cout << "No se admiten valores negativos, vuelva a intentar." << endl;
                    continue;
                }

                if (to_string(id).length() < 8 || to_string(id).length() > 10){ //verficar la cantidad correcta de digitos
                    cout << "La cedula debe contener entre 8 y 10 digitos, vuelva a intentar" << endl;
                    continue;
                }

                validType = true;

            }else{ //verificar caracter en contraseña
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Contrasena: ";

                getline(cin, password);

                if (password.find("'") != string::npos ||
                    password.find(",") != string::npos ||
                    password.find(";") != string::npos
                    ){
                    cout << "La contraseña contiene caracteres invalidos (',;) " << endl;
                    continue;
                }

                if (password.find(" ") != string::npos){
                    cout << "La contraseña debe estar sin espacios, vuelva a intentar." << endl;
                    continue;
                }

                if (!password.empty()) askingData = false;

            }

        }else{ //verficiaciones de la cedula y contraseña con la bd

            fstream FileAdmin;
            fstream FileUsers;
            FileAdmin.open(FILEADMIN, ios::out | ios::in |  ios::binary); //modo lectura
            FileUsers.open(FILEUSERS, ios::out | ios::in | ios::binary); //modo lectura

            if (!FileAdmin.is_open()){
                cout << "Fallo conexion a la base de datos." << endl;
                aplicationMain();
                return "";
            }

            getline(FileAdmin, line); // leer la primera linea del archivo
            //verificar si es admin
            if (compareDecrypts(line, password, id, user)) return "ADMIN"; //Cuando es admin

            //verificar con los usuarios
            bool isUser = false;
            while(getline(FileUsers, line)){

                if (line.empty()) continue;
                //verificar si es user
                if (compareDecrypts(line, password, id, user)) isUser = true; //Cuando es user

            }

            FileAdmin.close(); //cerrar archivos
            FileUsers.close();

            if (isUser) return "USER";

            cout << "Cedula y/o contrasena incorrectos, vuelva a intentar" << endl;

            validType = false;
            askingData = true;
        }
    }
}

void RolAdmin(bool init){ // acciones que puede hacer el administrador

    if (init){
        cout << endl;
        cout << "    BIENVENIDO ADMINISTRADOR    ";
        cout << endl;
    }

    unsigned short option = validateOption("Anadir Usuario -> 1", "Cerrar Sesion -> 2");

    if (option == 2){
        aplicationMain();
        return;
    }

      //cuando la option es 1
    cout << "Creacion De Nuevos Usuarios" << endl;

    int id, cash;
    string password = "";
    bool validateId = false, validatePass = false;

    while (true){ //validacion de datos del nuevo usuario

        if (!validateId){ //valida cedula de nuevo usuario
            cout << "Cedula: ";

            cin >> id;

            if (!validateCin("Cedula invalida, vuelva a intentar.")) continue;

            if (id < 0){
                cout << "No se admiten valores negativos, vuelva a intentar." << endl;
                continue;
            }

            if (to_string(id).length() < 8 || to_string(id).length() > 10){
                cout << "La cedula debe contener entre 8 y 10 digitos, vuelva a intentar" << endl;
                continue;
            }

            validateId = true;

        }else{
            if (!validatePass){ // validar contraseña
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Contrasena: ";

                getline(cin, password);

                if (password.find("'") != string::npos){
                    cout << "La contraseña contiene caracteres invalidos (',\", ^) " << endl;
                    continue;
                }

                if (password.find(" ") != string::npos){
                    cout << "La contraseña no debe tener espacios, vuelva a intentar" << endl;
                    continue;
                }

                if (!password.empty()) validatePass = true;

            }else{ // validar saldo
                cout << "Saldo (valor minimo = 10000): ";
                cin >> cash;

                if (!validateCin("Saldo invalido, vuelva a intentar")) continue;

                if (cash < 0){
                    cout << "No se admiten valores negativos, vuelva a intentar." << endl;
                    continue;
                }

                if (cash < 10000){
                    cout << "El saldo minimo debe ser de 10000, vuelva a intentar." << endl;
                    continue;
                }

                break;
            }
        }
    }


    //verificar si el usuario a crear no existe
    fstream FileUser;
    FileUser.open(FILEUSERS, ios::in | ios::binary);

    if (FileUser.is_open()) {
        string lineUsers = "";
        string tempUser;

        while(getline(FileUser, lineUsers)){
            if (lineUsers.empty()) continue;

            if (compareDecrypts(lineUsers, password, id, tempUser)){
                cout << "El usuario ya existe, vuelva a intentar." << endl;
                this_thread::sleep_for(chrono::seconds(3));
                FileUser.close();
                RolAdmin(true);
                return;
            }
        }

        FileUser.close();
    }

    string formatToSaveNewUser = to_string(id) + "," + password + "," + to_string(cash) + ";"; //id,clave,saldo;
    string codifyBits = "", bits = "";
    unsigned short randomNumber = 1 + rand() % 100; // generar nuemero entre 1 a 100
    bool parity = randomNumber & 1;

    convertToBits(formatToSaveNewUser, bits); // convertir a bits el string

    if (parity == 0) encryptBinaryInFirstMethod(bits, codifyBits); //encriptar con la primera format (semilla = 4)
    else encryptBinaryInSecondMethod(bits, codifyBits);

    ofstream FileUsers;
    FileUsers.open(FILEUSERS, ios::out | ios::binary | ios::app); // metodos del archvio

    if (!FileUsers.is_open()){
        cout << "No se pudo conectar con la tabla usuarios, comuniquese con soporte." << endl;
        aplicationMain();
        return;
    }

    FileUsers << codifyBits << endl; // escribir sobre el archvio
    FileUsers.close();

    cout << "Usuario registrado con exito." << endl;
    cout << "-----------------------------" << endl;

    this_thread::sleep_for(chrono::seconds(2));
    RolAdmin(false);
}

void RolUser(string user){

    if (user.empty()){
        cout << "Error en los usuarios" << endl;
        aplicationMain();
        return;
    }

    cout << endl;
    cout << "            BIENVENIDO USUARIO              " << endl;
    cout << "Las operaciones tienen un costo de 1000 COP " << endl;
    cout << endl;

    ofstream File;
    unsigned const short COST = 1000; //Costo al hacer transacciones
    unsigned short option = validateOption("Consultar Saldo -> 1", "Retirar Dinero  -> 2", "Cerrar Sesion   -> 3");

    if (option == 3){ // Cerrar sesion
        aplicationMain();
        return;
    }

    //Obtener dinero de la cuenta
    size_t findSemmiColon = user.find(";");
    size_t findLastComma = user.rfind(",");
    size_t findFirtsComma = user.find(",");
    string formatMoney;
    string id, passMoney, pass;

    if (findSemmiColon != string::npos
        && findLastComma != string::npos
        && findFirtsComma != string::npos
        ){ // string correcto

        id = user.substr(0, findFirtsComma);//obtener id
        passMoney = user.substr(findFirtsComma, findLastComma); // clave,saldo
        pass = passMoney.substr(1, passMoney.rfind(",") - 1); // obtener clave

        string money = user.substr(findLastComma + 1, findSemmiColon);
        for (unsigned short i = 0; i < money.length(); i++) if (money[i] != ';') formatMoney += money[i];
    }

    try {
        int money = stoi(formatMoney);
        int id_ = stoi(id);

        if (option == 1){ // Consultar saldo
            if (money < COST){
                cout << "No tienes suficiente dinero para el costo de la operacion." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                aplicationMain();
                return;
            }

            cout << "Tu saldo es de: " << money << " COP" << endl;
            money -= COST;
        }
        else if (option == 2){
            int cotMoney;

            while (true){
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cotMoney;

                if (!validateCin("Valor invalido, vuelva a intentar")) continue;

                if (cotMoney < 0){
                    cout << "El valor debe ser positivo, vuelva a intentar" << endl;
                    continue;
                }

                if (cotMoney < COST){
                    cout << "El valor minimo para retirar es de 1000 COP" << endl;
                    continue;
                }

                if (cotMoney > money){
                    cout << "Solo puedes retirar valores inferiores o iguales al saldo" << endl;
                    continue;
                }

                if (cotMoney > 4500000){
                    cout << "Solo se pude retirar hasta 4500000 en Cajeros" << endl;
                    continue;
                }

                break;
            }

            money = money - (COST + cotMoney); // restar el dinero a retirar y el valor de transaccion
        }

        //guardar datos sobreescribiendo el archvio
        fstream TempFile;
        fstream FileData;
        TempFile.open(FILETEMPORAL, ios::out | ios::binary | ios::trunc);
        FileData.open(FILEUSERS, ios::in | ios::binary | ios::app);

        if (!TempFile.is_open() || !FileData.is_open()){ // fallo al abrir los archivos
            cout << "Fallo la conexion a la base de datos." << endl;
            aplicationMain();
            return;
        }

        string line = "";
        string formatToSave = "";

        while (getline(FileData, line)){
            string tempUser = "";

            if (line.empty()) continue;

            if (compareDecrypts(line, pass, id_, tempUser)){ //verificar si la linea corresponde al id y contraseña

                formatToSave = to_string(id_) + "," + pass + "," + to_string(money) + ";";

                string codifyBits = "", bits = "";
                unsigned const short randomNumber = 1 + rand() % 100; // generar nuemero entre 1 a 100
                bool parity = randomNumber & 1;

                convertToBits(formatToSave, bits); // convertir a bits el string

                if (parity == 0) encryptBinaryInFirstMethod(bits, codifyBits); //encriptar con la primera format (semilla = 4)
                else encryptBinaryInSecondMethod(bits, codifyBits);

                TempFile << codifyBits << endl;

            }else{
                TempFile << line << endl;
            }
        }

        FileData.close(); // cerrar el archivo de datos
        TempFile.close();

        FileData.open(FILEUSERS, ios::out | ios::binary | ios::trunc);
        TempFile.open(FILETEMPORAL, ios::in | ios::binary);

        while (getline(TempFile, line)){

            if (line.empty()) continue;
            FileData << line << endl;
        }

        FileData.close();
        TempFile.close();

        //por seguridad
        //eliminar el archivo temporal y volver a crearlo
        if (std::remove(FILETEMPORAL.c_str()) != 0){
            cout << "Error al eliminar la tabla temporal." << endl;
        }

        cout << "Transaccion Exitosa." << endl;
        this_thread::sleep_for(chrono::seconds(3)); //esperar tres segundo para volver a preguntar las opciones

        RolUser(formatToSave);
        return;

    } catch (invalid_argument &ex) {
        cout << "Error con el formato del saldo, comuniquese con soporte." << endl;
        return;
    }

}

bool compareDecrypts(string line, string passIn, unsigned int id, string &user){ //Desencriptar por ambos metodos y buscar coincidencias

    string decryptFirstMethod = decryptBinaryInFirstMethod(line);
    string decryptSecondMethod = decryptBinaryInSecondMethod(line);
    string assciFirstMethod = convertToAssci(decryptFirstMethod);
    string assciSecondMethod = convertToAssci(decryptSecondMethod);

    string correctDecryptString = "";

    bool matchPass = false, matchId = false;

    //verificar de codificacion y asignar el texto correcto
    if (countCommasAndSemicolon(assciFirstMethod)) correctDecryptString = assciFirstMethod;
    else if (countCommasAndSemicolon(assciSecondMethod)) correctDecryptString = assciSecondMethod;
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
                user = correctDecryptString;
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

unsigned short validateOption(string text1, string text2, string text3){ // preguntar y validar las dos opciones
    unsigned short option;

    while (true){
        cout << text1 << endl;
        cout << text2 << endl;
        cout << text3 << endl;

        cin >> option;

        if (!validateCin("Tipo de dato invalido, vuelva a intentar")) continue;

        if (text3 != ""){
            if (option > 3 || option < 1){
                cout << "Solo se permiten dos valores (1, 2, 3), vuelva a intentar." << endl;
                continue;
            }
        }else{
            if (option > 2 || option < 1){
                cout << "Solo se permiten dos valores (1, 2), vuelva a intentar." << endl;
                continue;
            }
        }

        break;
    }

    return option;
}

bool validateCin(string const text){

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << text << endl;
        return false;
    }

    return true;
}
