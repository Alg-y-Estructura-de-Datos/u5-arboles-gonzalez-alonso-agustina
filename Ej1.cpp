/*Ejercicio 1: Organización de una biblioteca
Problema: Estás organizando una biblioteca familiar. Cada libro tiene un número único de
identificación (ID) y quieres organizar los libros en un sistema que te permita agregarlos,
eliminarlos y buscarlos fácilmente.
● Tarea: Inserta los libros con los siguientes IDs en el sistema de gestión (árbol): 101,
52, 198, 36, 75, 150, 200.
● Desafío: Busca el libro con el ID 75 y verifica si está en la biblioteca. Luego elimina
el libro con el ID 52 porque fue prestado. Imprime la estructura del sistema después
de la eliminación.*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void funcionBuscar (ArbolBinario<int>&arbol){
    try {
        int libro = arbol.search(75);
        cout << "EL libro se encuentra en la bibloteca " << libro << endl;
    }
    catch (int e){
        if (e == 404){
            cout << "El libro no se encuentra en la bibloteca" << endl;
        }
    }
    arbol.remove(52);
}

int main() {

    cout << "Ejercicio N° 1" << endl;
    ArbolBinario<int>arbol;

    arbol.put(101);
    arbol.put(52);
    arbol.put(198);
    arbol.put(36);
    arbol.put(75);
    arbol.put(150);
    arbol.put(200);

    funcionBuscar(arbol);
    arbol.print();

    return 0;
}
