/*
12/9/26
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que simule una Lista Enlazada Cola (Linked List).
*/

#include <iostream>
using namespace std;

struct LinkedList {
int dato;
LinkedList *next;
};

void insertarLista(LinkedList*& lista, int dato)
{
    LinkedList* nuevoNodo = new LinkedList();
    nuevoNodo->dato = dato;

    LinkedList* nodoActual = lista;
    LinkedList* nodoAnterior = NULL;

    while((nodoActual != NULL) && (nodoActual->dato < dato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if(lista == nodoActual)
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
struct LinkedList {
int dato;
LinkedList *next;
};

void insertarLista(LinkedList*& lista, int dato)
{
    LinkedList* nuevoNodo = new LinkedList();
    nuevoNodo->dato = dato;

    LinkedList* nodoActual = lista;
    LinkedList* nodoAnterior = NULL;

    while((nodoActual != NULL) && (nodoActual->dato < dato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if(lista == nodoActual)
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

    while(nodoActual != NULL)
    {
        if(nodoActual->dato == dato)
        {
            encontrado = true;
            break;
        }
        nodoActual = nodoActual->next;
    }

    if(encontrado)
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

    while((nodoActual != NULL) && (nodoActual->dato != dato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if(nodoActual == NULL)
    {
        cout << "El elemento " << dato << " no existe en la lista.\n";
    }
    else
    {
        if(lista == nodoActual)
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

int main()
{
  return 0;
}
