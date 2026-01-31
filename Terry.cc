#include <iostream>
using namespace std;

// Estructura para el paquete
struct Paquete
{
    int id;
    string nombre;
    float peso;
    Paquete *siguiente;
    Paquete *anterior;
};

// La lista doblemente enlazada
struct ListaDoble
{
    Paquete *cabeza = nullptr;
    Paquete *cola = nullptr;
    int contador = 0;
};

// Prototipos de Funciones
void InsertarInicio(ListaDoble &lista, int id, string nombre, float peso);
void InsertarFinal(ListaDoble &lista, int id, string nombre, float peso);

int main()
{

    ListaDoble milista;
    int opcion, idBuscar;
    int id;
    string nombre;
    float peso;
    do
    {
        cout << "Menu de Paquetes\n";
        cout << "1. Insertar paquete al inicio\n";
        cout << "2. Insertar paquete al final\n";
        cout << "3. Mostrar paquetes desde el inicio\n";
        cout << "4. Mostrar paquetes desde el final\n";
        cout << "5. Buscar paquete por ID\n";
        cout << "6. Eliminar paquete por ID\n";
        cout << "7. Editar paquete por ID\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
         cout << "------------------------------------\n";
            cout << "Ingrese ID del paquete: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombre del paquete: ";
            getline(cin, nombre);
            cout << "Ingrese peso del paquete: ";
            cin >> peso;
            InsertarInicio(milista, id, nombre, peso);
            cout << "Paquete insertado al inicio.\n";
            cout << "------------------------------------\n";
            break;
        case 2:
         cout << "------------------------------------\n";
            cout << "Ingrese ID del paquete: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombre del paquete: ";
            getline(cin, nombre);
            cout << "Ingrese peso del paquete: ";
            cin >> peso;
            InsertarFinal(milista, id, nombre, peso);
            cout << "Paquete insertado al final.\n";
            cout << "------------------------------------\n";
            break;
        case 3:
            break;
        case 4:
            break;

        case 5:
            break;

        case 6:
            break;
        case 7:
            break;
        case 8:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 8);

    return 0;
}

// Funcion para insertar un paquete al inicio de la lista
void InsertarInicio(ListaDoble &lista, int id, string nombre, float peso)
{
    Paquete *nuevoPaquete = new Paquete();
    nuevoPaquete->id = id;
    nuevoPaquete->nombre = nombre;
    nuevoPaquete->peso = peso;
    nuevoPaquete->siguiente = lista.cabeza;
    nuevoPaquete->anterior = nullptr;

    if (lista.cabeza != nullptr)
    {
        lista.cabeza->anterior = nuevoPaquete;
    }
    else
    {
        lista.cola = nuevoPaquete;
    }

    lista.cabeza = nuevoPaquete;
    lista.contador++;
}

// Funcion para insertar un paquete al final de la lista
void InsertarFinal(ListaDoble &lista, int id, string nombre, float peso)
{
    Paquete *nuevoPaquete = new Paquete();
    nuevoPaquete->id = id;
    nuevoPaquete->nombre = nombre;
    nuevoPaquete->peso = peso;
    nuevoPaquete->siguiente = nullptr;
    nuevoPaquete->anterior = lista.cola;

    if (lista.cola != nullptr)
    {
        lista.cola->siguiente = nuevoPaquete;
    }
    else
    {
        lista.cabeza = nuevoPaquete;
    }

    lista.cola = nuevoPaquete;
    lista.contador++;
}