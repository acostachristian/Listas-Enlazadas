/*
12/9/26
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- Octavio Ramírez - 1132995
- José Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que simule una Lista Enlazada Cola (Linked List).
*/

#include <iostream>
#include <limits>
#include <string>
#include <conio.h>
using namespace std;

struct LinkedList {
    int dato;
    LinkedList* next;
};

void insertarLista(LinkedList*& lista, int dato)
{
    LinkedList* nuevoNodo = new LinkedList();
    nuevoNodo->dato = dato;

    LinkedList* nodoActual = lista;
    LinkedList* nodoAnterior = NULL;

    while ((nodoActual != NULL) && (nodoActual->dato < dato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if (lista == nodoActual)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoAnterior->next = nuevoNodo;
    }

    nuevoNodo->next = nodoActual;

    cout << "Se inserto el elemento " << dato << " a la lista.\n";
    _getch();
}

// Busca un dato en la lista y avisa si lo encontró o no
void buscarLista(LinkedList* lista, int dato)
{
    LinkedList* nodoActual = lista;
    bool encontrado = false;

    while (nodoActual != NULL)
    {
        if (nodoActual->dato == dato)
        {
            encontrado = true;
            break;
        }
        nodoActual = nodoActual->next;
    }

    if (encontrado)
    {
        cout << "El elemento " << dato << " SI se encuentra en la lista.\n";
    }
    else
    {
        cout << "El elemento " << dato << " NO se encuentra en la lista.\n";
    }

    _getch();
}

// Elimina un dato de la lista si existe
void eliminarLista(LinkedList*& lista, int dato)
{
    LinkedList* nodoActual = lista;
    LinkedList* nodoAnterior = NULL;

    while ((nodoActual != NULL) && (nodoActual->dato != dato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if (nodoActual == NULL)
    {
        cout << "El elemento " << dato << " no existe en la lista.\n";
    }
    else
    {
        if (lista == nodoActual)
        {
            lista = nodoActual->next;
        }
        else
        {
            nodoAnterior->next = nodoActual->next;
        }

        delete nodoActual;
        cout << "Se elimino el elemento " << dato << " de la lista.\n";
    }

    _getch();
}

//Muestra los datos de la lista y si no hay nada dice que esta vacia
void mostrarLista(LinkedList* lista)
{
    if (lista == NULL)
    {
        cout << "La lista esta vacia.\n";
        _getch();
        return;
    }

    LinkedList* nodoActual = lista;

    cout << "Lista Enlazada: ";
    while (nodoActual != NULL)
    {
        cout << nodoActual->dato;
        if (nodoActual->next != NULL)
        {
            cout << " -> ";
        }
        nodoActual = nodoActual->next;
    }
    cout << "\n";

    _getch();
}

//Restriccion D. Las entradas de datos del usuario deben ser debidamente validas.
//lee si realmente se esta introduciendo un entero
int leerEntero(string mensaje)
{
    int valor;
    cout << mensaje;

    while (!(cin >> valor))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Por favor ingrese un numero entero: ";
    }

    // Limpiamos el resto del buffer por si el usuario escribio texto extra
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return valor;
}

//Menu Principal
int main()
{
    LinkedList* lista = NULL;
    int opcion;
    int dato;

    do
    {
        cout << "      MENU LISTA ENLAZADA (COLA)    \n";
        cout << "1. Insertar \n";
        cout << "2. Buscar \n";
        cout << "3. Eliminar \n";
        cout << "4. Mostrar Lista \n";
        cout << "5. Salir \n";

        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion)
        {
        case 1:
            dato = leerEntero("Ingrese el dato a insertar: ");
            insertarLista(lista, dato);
            break;

        case 2:
            dato = leerEntero("Ingrese el dato a buscar: ");
            buscarLista(lista, dato);
            break;

        case 3:
            dato = leerEntero("Ingrese el dato a eliminar: ");
            eliminarLista(lista, dato);
            break;

        case 4:
            mostrarLista(lista);
            break;

        case 5:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            _getch();
        }

    } while (opcion != 5);

    return 0;
}
