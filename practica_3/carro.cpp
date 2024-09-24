include "carro.h"

Carro::Carro(string marca) {
    this->marca = marca;
}


int Carro::getData() const {
    cout << "la marca es" << this->marca;
    return 0;

}
