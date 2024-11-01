#include <iostream>
#include "router.h"
#include "file.h"
#include <limits>

using namespace std;

void menu();
void addRouter();
void removeRouter();
void updateTable();
void costBetweenTwoRouters();

static Router router;
static File file(router);

int main()
{

    //Modelamiento de una red de routes
    menu();

    return 0;
}


void menu(){

    cout << "---------------------------------------" << endl;
    cout << "|            RED DE ROUTERS            |" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Agregar un router." << endl;
    cout << "2. Eliminar un router." << endl;
    cout << "3. Actualizar tabla de routers." << endl;
    cout << "4. Costo de envio entre dos routers. " << endl;
    cout << "5. Camino mas eficiente entre dos routers." << endl;
    cout << "6. Generar redes aleatorias. " << endl;

    unsigned short option;
    while (true){
        cout << "Digite una opcion: ";
        cin >> option;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo de dato invalido, vuelva a intentar." << endl;
            continue;
        }

        if (option < 1 || option > 6){
            cout << "Esta opcion no existe, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    switch (option) {
    case 1:
        addRouter();
        break;
    case 2:
        removeRouter();
        break;
    case 3:
        updateTable();
        break;
    case 4:
        costBetweenTwoRouters();
        break;
    default:
        break;
    }

}


void addRouter(){

    cout << "--------------------------------" << endl;
    cout << "|          ANADIR ROUTER       |" << endl;
    cout << "--------------------------------" << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    while (true){
        cout << "Ingrese el codigo del nuevo router." << endl;
        getline(cin, input);

        if (router.verifyIFexistRouter(input)){
            cout << "Este codigo de router ya existe, vuelva a intentar." << endl;

            continue;
        }

        break;
    }

    router.setId(input);
    router.addRouter();

    cout << "Router añadido exitosamente." << endl;
    menu();
}

void removeRouter(){

    cout << "--------------------------------" << endl;
    cout << "|       LISTA DE ROUTERS        |" << endl;
    cout << "--------------------------------" << endl;

    cout << "Al eliminar un router se eliminaran todos sus enlaces." << endl;
    cout << "1. Continuar." << endl;
    cout << "2. Salir" << endl;

    unsigned short option;
    while(true){

        cin >> option;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo de dato invalido, vuelva a intentar." << endl;
            continue;
        }

        if (option < 1 || option > 2){
            cout << "Esta opcion no se encuentra, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    if (option == 2) {
        menu();
        return;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    while (true){
        cout << "Ingrese el codigo del router a eliminar." << endl;
        getline(cin, input);

        if (!router.verifyIFexistRouter(input)){
            cout << "Este codigo de router no existe, vuelva a intentar." << endl;
            continue;
        }

        break;
    }

    router.setId(input);
    router.removeRouter();

    cout << "Router eliminado satisfactoriamente." << endl;
    menu();
}


void updateTable(){

    router.showTableOfRouters();

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string originRouter, detinyRouter;
    bool validRouter = false;
    while (true){
        if (!validRouter)
        {
            cout << "Ingrese el router origen: ";

            getline(cin, originRouter);

            if (!router.verifyIFexistRouter(originRouter)){
                cout << "Este router no existe, vuelva a intentar." << endl;
                continue;
            }

            validRouter = true;
        }else
        {
            cout << "Ingrese el router de destion: ";
            getline(cin, detinyRouter);

            if (!router.verifyIFexistRouter(detinyRouter)){
                cout << "Este router no existe, vuelva a intentar." << endl;
                continue;
            }

            if (originRouter == detinyRouter){
                cout << "Ingrese un router de destino diferente al de origen." << endl;
                continue;
            }

            break;
        }
    }


    int cost;
    while (true){
        cout << "Ingrese el costo del enlace: ";
        cin >> cost;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo de dato invalido, vuelva a intentar." << endl;
            continue;
        }

        if (cost < 0){
            cout << "El costo debe ser positivo, vuelva a intentar" << endl;
            continue;
        }

        break;
    }

    router.setCost(cost);

    if (router.addCostBetween(originRouter, detinyRouter)){
        cout << "Enlace creado correctamente." << endl;
    }else
        cout << "El enlace no se pudo crear" << endl;

    router.showTableOfRouters();
}

void costBetweenTwoRouters(){

    cout << "----------------------------------------------" << endl;
    cout << "|       COSTO DE ENVIO ENTRE DOS ROUTERS      |" << endl;
    cout << "----------------------------------------------" << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ORouter, DRouter;
    bool continueToNextRouter = false;

    router.showRouters();

    while (true){
        if (!continueToNextRouter)
        {
            cout << "Digite el codigo del router de origen: ";
            getline(cin, ORouter);

            if (!router.verifyIFexistRouter(ORouter)){
                cout << "Router no existe, vuelva a intentar." << endl;
                continue;
            }

            continueToNextRouter = true;
        }
        else
        {
            cout << "Digite el codigo del router de destion: ";
            getline(cin, DRouter);

            if (!router.verifyIFexistRouter(DRouter)){
                cout << "Router no existe, vuelva a intentar." << endl;
                continue;
            }

            break;
        }
    }


    router.costBetwennToRouters(ORouter, DRouter);

}
