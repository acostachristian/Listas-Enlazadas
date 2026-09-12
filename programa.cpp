/*
12/9/26
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- Octavio Ramirez - 1132995
- Jose Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que simule una Lista Enlazada Cola (Linked List).
*/

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct LinkedList {
    int dato;
    LinkedList* next;
};

void insertarLista(LinkedList*& pFrente, int pDato)
{
    LinkedList* nuevoNodo = new LinkedList();
    nuevoNodo->dato = pDato;

    LinkedList* nodoActual = pFrente;
    LinkedList* nodoAnterior = NULL;

    while ((nodoActual != NULL) && (nodoActual->dato < pDato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if (pFrente == nodoActual)
    {
        pFrente = nuevoNodo;
    }
    else
    {
        nodoAnterior->next = nuevoNodo;
    }

    nuevoNodo->next = nodoActual;

    cout << "Se inserto el elemento " << pDato << " a la lista.\n";
    cout << "\nPresione cualquier tecla para continuar...";
    _getch();
}

// Busca un dato en la lista y avisa si lo encontro o no
void buscarLista(LinkedList* pFrente, int pDato)
{
    LinkedList* nodoActual = pFrente;
    bool encontrado = false;

    while ((nodoActual != NULL) && (encontrado == false))
    {
        if (nodoActual->dato == pDato)
        {
            encontrado = true;
        }
        else {
            nodoActual = nodoActual->next;
        }
    }

    if (encontrado)
    {
        cout << "El elemento " << pDato << " SI se encuentra en la lista.\n";
    }
    else
    {
        cout << "El elemento " << pDato << " NO se encuentra en la lista.\n";
    }
    cout << "\nPresione cualquier tecla para continuar...";
    _getch();
}

// Elimina un dato de la lista si existe
void eliminarLista(LinkedList*& pFrente, int pDato)
{
    LinkedList* nodoActual = pFrente;
    LinkedList* nodoAnterior = NULL;

    while ((nodoActual != NULL) && (nodoActual->dato != pDato))
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->next;
    }

    if (nodoActual == NULL)
    {
        cout << "El elemento " << pDato << " no existe en la lista.\n";
    }
    else
    {
        if (pFrente == nodoActual)
        {
            pFrente = nodoActual->next;
        }
        else
        {
            nodoAnterior->next = nodoActual->next;
        }

        delete nodoActual;
        cout << "Se elimino el elemento " << pDato << " de la lista.\n";
    }
    cout << "\nPresione cualquier tecla para continuar...";
    _getch();
}

// Muestra los datos de la lista y si no hay nada dice que esta vacia
void mostrarLista(LinkedList* pFrente)
{
    if (pFrente == NULL)
    {
        cout << "La lista esta vacia.\n";
        cout << "\nPresione cualquier tecla para continuar...";
        _getch();
        return;
    }

    LinkedList* nodoActual = pFrente;

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
    cout << "\nPresione cualquier tecla para continuar...";
    _getch();
}

void limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Restriccion D. Las entradas de datos del usuario deben ser debidamente validas.
// Pide un entero por consola y NO deja continuar hasta que el usuario escriba
// un numero entero valido (sin letras en ninguna parte de la entrada).
// pDato se pasa por referencia para devolver el valor ya validado.
void leerEntero(string mensaje, int& pDato)
{
    string datoString;
    size_t position;
    bool error;

    do
    {
        try
        {
            cout << mensaje;
            cin >> datoString;
            pDato = stoi(datoString, &position);

            if (datoString.length() != position)
            {
                error = true;
                cout << "Entrada invalida, ingrese un numero entero\n" << endl;
            }
            else
            {
                error = false;
            }
        }
        catch (const exception&)
        {
            error = true;
            cout << "Entrada invalida, ingrese un numero entero\n" << endl;
        }
    } while (error);
}

// Menu Principal
int main()
{
    LinkedList* frente = NULL;
    int opcion;
    int dato;

    do
    {
        limpiarConsola();
        cout << "-----";
        cout << "\nMENU LISTA ENLAZADA (COLA)\n";
        cout << "1. Insertar \n";
        cout << "2. Buscar \n";
        cout << "3. Eliminar \n";
        cout << "4. Mostrar Lista \n";
        cout << "5. Salir \n";

        leerEntero("Seleccione una opcion: ", opcion);

        switch (opcion)
        {
        case 1:
            leerEntero("Ingrese el dato a insertar: ", dato);
            insertarLista(frente, dato);
            break;

        case 2:
            leerEntero("Ingrese el dato a buscar: ", dato);
            buscarLista(frente, dato);
            break;

        case 3:
            leerEntero("Ingrese el dato a eliminar: ", dato);
            eliminarLista(frente, dato);
            break;

        case 4:
            mostrarLista(frente);
            break;

        case 5:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            _getch();
            break;
        }
    } while (opcion != 5);

    return 0;
}