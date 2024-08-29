#include <iostream>
#include <limits>
#include "problems.h"

using namespace std;

int counTermsSerieCollatz(int seed);
string drawSerie(int seed);

void problem16(){
    // Problema 16. La serie de Collatz se conforma con la siguiente regla: sea n un elemento de la serie,
    // si n es par, el siguiente elemento es n/2, y si n es impar, el siguiente elemento es 3n+1.
    // Escriba un programa que reciba un número k y calcule cual es el elemento inicial j (semilla), menor
    // que k, que produce la serie más larga y diga cuantos términos m tiene la serie.
    // Tip: la serie termina al llegar a un elemento cuyo valor sea 1.
    // Ej: para la semilla 13: 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
    // Nota: la salida del programa debe ser:
    // La serie mas larga es con la semilla: j, teniendo m terminos.
    // Otra nota: se le dará una bonicación si imprime la serie

    int k;

    while (true){
        cout << "Ingrese un numero: ";
        cin >> k;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "El numero es invalido." << endl;
            continue;
        }

        break;
    }

    unsigned int seed = 0, higherTerms = 0;

    for (int i = 1; i < k; i++){

        unsigned const int termsSerie = counTermsSerieCollatz(i);

        if (termsSerie > higherTerms) {
            higherTerms = termsSerie;
            seed = i;
        }
    }

    cout << "La serie mas larga es con la semilla: " << seed << ", Teniendo " << higherTerms + 1 << " terminos." << endl;
    cout  << seed << drawSerie(seed);
}

int counTermsSerieCollatz(int seed){
    unsigned int changeSeed = seed, countTerms = 0;

    while (changeSeed != 1) {
        if (changeSeed % 2 == 0)  changeSeed /= 2;
        else changeSeed = 3 * changeSeed + 1;
        countTerms++;
    }

    return countTerms;
}

string drawSerie(int seed){
    unsigned int changeSeed = seed;
    string serie = "";

    while (changeSeed != 1) {
        if (changeSeed % 2 == 0)  changeSeed /= 2;
        else changeSeed = 3 * changeSeed + 1;

        serie = serie + ", " + to_string(changeSeed);
    }

    return serie;
}
