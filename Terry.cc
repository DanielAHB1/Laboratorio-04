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
void MostrarAdelante(const ListaDoble &lista);
void MostrarAtras(const ListaDoble &lista);
Paquete* BuscarID(ListaDoble &lista, int id);
void eliminarID(ListaDoble &lista, int id);

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
        cout << "8. Mostrar cantidad de paquetes\n";
        cout << "9. Salir\n";
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
            MostrarAdelante(milista);
            break;
        case 4:
             MostrarAtras(milista);
            break;

        case 5:
            cout << "------------------------------------\n";
            cout << "Ingrese ID a buscar: ";
            cin >> id;
            {
                Paquete* encontrado = BuscarID(milista, id);
                if (encontrado) {
                    cout << "Paquete encontrado:\n";
                    cout << "ID: " << encontrado->id << "\n";
                    cout << "Peso: " << encontrado->peso << "\n";                   
                }
                else{
                    cout << "No se encontro un paquete con ID: " << id << "\n";
                }
            }
            cout << "------------------------------------\n";
            break;

        case 6:
            cout << "------------------------------------\n";
            cout << "ELIMINAR PAQUETE POR ID\n";
            cout << "Ingrese ID a eliminar: ";
            cin >> id;
            eliminarID(milista, id);
            cout << "------------------------------------\n";
            break;
        case 7:

            break;
        case 8:
            cout << "------------------------------------\n";
            cout << "CANTIDAD DE PAQUETES"<< endl;
            if (milista.contador == 0)
            {
                cout << "La lista esta vacia"<< endl;
            }
            else {
                cout << "Total de paquetes: " << milista.contador << endl;
            }
            cout << "------------------------------------\n";

            break;
        case 9:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 9);

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

// Funcion para mostrar los paquetes desde el inicio
void MostrarAdelante(const ListaDoble &lista)
{
    Paquete *actual = lista.cabeza;
    if (actual == nullptr)
    {
        cout << "La lista esta vacia.\n";
        return;
    }
     cout << "------------------------------------\n";
    cout << "Paquetes en la lista (desde el inicio):\n";
    while (actual != nullptr)
    {
        cout << "ID: " << actual->id << ", Nombre: " << actual->nombre << ", Peso: " << actual->peso << endl;
         cout << "------------------------------------\n";
        actual = actual->siguiente;
    }
}


// Funcion para mostrar los paquetes desde el final
void MostrarAtras(const ListaDoble &lista)
{
    Paquete *actual = lista.cola;
    if (actual == nullptr)
    {
        cout << "La lista esta vacia.\n";
        return;
    }
     cout << "------------------------------------\n";
    cout << "Paquetes en la lista (desde el final):\n";
    while (actual != nullptr)
    {
        cout << "ID: " << actual->id << ", Nombre: " << actual->nombre << ", Peso: " << actual->peso << endl;
         cout << "------------------------------------\n";
        actual = actual->anterior;
    }
}

//Funcion para encontrar el id
Paquete* BuscarID(ListaDoble &lista, int id)
{
    Paquete *actual = lista.cabeza;
    while (actual != nullptr)
    {
        if (actual->id == id)
        return actual;
        actual = actual->siguiente;
    }
    return nullptr;
    
}

void eliminarID(ListaDoble &lista, int id)
{
    if (lista.cabeza == nullptr)
    {
        cout << "La lista esta vacia, nada que eliminar"<< endl; 
        return ;
    }

    Paquete *actual = lista.cabeza;

    //Buscar nodo con ID
    while (actual != nullptr && actual-> id != id)
    {
        actual = actual->siguiente;
    }
    
    if (actual == nullptr)
    {
        cout << "No se encontro un paquete con ID " << id << endl;
        return ;
    }

    if (lista.cabeza == lista.cola)
    {
        delete actual;
        lista.cabeza = nullptr;
        lista.cola = nullptr;
    }
    else if (actual == lista.cabeza)
    {
        lista.cabeza = actual-> siguiente;
        lista.cabeza->anterior = nullptr;
        delete actual;
    }
    else if (actual == lista.cola)
    {
        lista.cola = actual->anterior;
        lista.cola->siguiente = nullptr;
        delete actual;
    }
    else
    {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        delete actual;
    }

    lista.contador--;
    cout << "Paquete con ID " << id << " Eliminado correctamente" << endl;
}