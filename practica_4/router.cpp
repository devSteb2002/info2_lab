#include "router.h"
#include <vector>

Router::Router(){}

void Router::formatDataInit(string unformattedData){ // formatear los datos en entrada para entregarlos en el map
    size_t toPints = unformattedData.find(":");

    if (toPints != string::npos){
        try {
            string key = unformattedData.substr(0, toPints);

            string dataIn = "";
            for (size_t i = toPints + 1; i < unformattedData.length(); i++){
                const char letter = unformattedData[i];

                if (letter == ','){

                    size_t findBar = dataIn.find("-");

                    if (findBar != string::npos){
                        string idIn = dataIn.substr(0, findBar);
                        string cost = dataIn.substr(findBar, dataIn.length() - 1);

                        size_t findComma = idIn.find(",");
                        size_t findBar = cost.find("-");

                        if (findComma != string::npos) idIn.erase(findComma, 1);
                        if (findBar != string::npos) cost.erase(findBar, 1);

                        string keyIn = idIn;
                        int valueIn = stoi(cost);

                        data[key][keyIn] = valueIn;
                    }

                    dataIn = "";
                }

                dataIn += letter;
            }
        } catch (exception& e) {
            cout << "Error" << e.what() << endl;
        }
    }
}

void Router::addRouter(){
    string key = getKey();
    data[key][key] = 0; //asignar nueva clave de clave con valor 0 haciendo referencia a ella misma
}

void Router::removeRouter(){

    string key = getKey();

    for (const auto& keyOut: data) data[keyOut.first].erase(key);

    data.erase(key); // eliminar la clave original
}

bool Router::verifyIFexistRouter(string key){

    for (const auto& keyOut: data)
        if (keyOut.first == key) return true;

    return false;
}

void Router::showRouters(){
    for (const auto& keyOut : data)
        cout << "Codigo: " << keyOut.first << endl;
}

void Router::showTableOfRouters(){


    cout << "--------------------------------------------------------------------" << endl;
    cout << "|                        TABLA DE ROUTERS                           |" << endl;

    for (const auto& outerMap : data){
        cout << "--------------------------------------------------------------------" << endl;
        cout <<  left << "Router: " << outerMap.first << " | ";

        for (const auto& innerMap : outerMap.second){
            cout << left << "    " << innerMap.first << " - " << innerMap.second << "   ";
        }
        cout << endl;
    }

    cout << "--------------------------------------------------------------------" << endl;
}

bool Router::addCostBetween(string key_1, string key_2){

    try {

        data[key_1][key_2] = getCost();
        data[key_2][key_1] = getCost();

        return true;
    } catch (exception& e) {
        cout << "Error" << e.what() << endl;
        return false;
    }
}

int Router::costBetwennToRouters(string key_1, string key_2){

    //verificar si estan directamente conectados
    if (data[key_1].count(key_2) > 0) return data[key_1][key_2];

    vector<string> vectorKey1;
    vector<string> vectorKey2;

    for (const auto& dataOut : data){

        bool foundKey1 = dataOut.second.count(key_1) > 0;
        bool foundKey2 = dataOut.second.count(key_2);

        if (foundKey1 && dataOut.first != key_1) vectorKey1.push_back(dataOut.first);
        if (foundKey2 && dataOut.first != key_2) vectorKey2.push_back(dataOut.first);

    }

    int sum;

    for (size_t i = 0; i < vectorKey1.size(); i++){
        for (size_t j = 0; j < vectorKey2.size(); j++){
            if (data[vectorKey1[i]].count(vectorKey2[j]) > 0){
                cout << "Costo" << data[vectorKey1[i]][vectorKey2[j]] << endl;
            }
        }
    }

    cout << "qui  0 <<" << endl;


    return 0;
}

void Router::searchLinkBTRoutes(string key, string ignore, string &keyEnd){


}

void Router::setId(string key){
    this->id = key;
}

void Router::setCost(int cost){
    this->cost = cost;
}

string Router::getKey() const{
    return this->id;
}

int Router::getCost() const{
    return this->cost;
}
