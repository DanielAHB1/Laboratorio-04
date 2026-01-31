#include <iostream>
using namespace std;

struct Paquete {
    int id;
    string nombre;
    float peso;
    Paquete* siguiente;
    Paquete* anterior;
};

struct ListaDoble {
    Paquete* cabeza = nullptr;
    Paquete* cola = nullptr;
    int contador = 0;
};

int main(){

return 0; 
}