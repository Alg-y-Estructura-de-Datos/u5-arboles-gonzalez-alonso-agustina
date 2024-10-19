/*Ejercicio 2: Gestión de inventario en una tienda
Problema: En una tienda de electrónica, cada producto tiene un código único y quieres
gestionar el inventario. A medida que entran y salen productos, es necesario mantener el
sistema actualizado.
● Tarea: Inserta los productos con los siguientes códigos: 4001, 2002, 6003, 1500,
3500, 5000, 7000.
● Desafío: Un cliente compró los productos con códigos 2002 y 6003, así que
elimínalos del sistema. Luego, un nuevo producto con el código 2500 llega al
inventario. Imprime el inventario actualizado y verifica si el código 4001 todavía está
en el sistema.*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void inventario(ArbolBinario<int>&arbol){
    try{
        arbol.remove(2002);
        arbol.remove(6003);
    }
    catch(int e){
        if (e == 404){
            cout << "No se encuntra ese codigo" << endl;
        }
    }
    arbol.put(2500);
}


int main() {

    cout << "Ejercicio N° 2" << endl;
    ArbolBinario<int> arbol;

    arbol.put(4001);
    arbol.put(2002);
    arbol.put(6003);
    arbol.put(1500);
    arbol.put(3500);
    arbol.put(5000);
    arbol.put(7000);

    inventario(arbol);
    arbol.print();
    if ( arbol.search(4001)){
        cout << "Si esta el numero" << endl;
    }

    return 0;
}
