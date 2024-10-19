/*Ejercicio N°1
Un almacén necesita gestionar su inventario de productos. Cada producto tiene un número único de identificación (ID),
y el sistema debe mantener el inventario organizado para realizar búsquedas rápidas de productos y
permitir actualizaciones del stock.
Utilizar un árbol AVL para almacenar los IDs de los productos. El árbol debe mantenerse balanceado
para garantizar búsquedas rápidas.

Crear un sistema con un menú que permita gestionar las siguientes opciones:
1.	Insertar un código de producto.
2.	Eliminar un código de producto.
3.	Buscar un producto por código.
4.	Imprimir el árbol (mostrando su estructura balanceada).
5.	Salir del programa.
*/

#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void agregar (ArbolBinarioAVL<int>&arbol, int id){
    try{
        arbol.put(id);
    }catch (int e){
        if (e == 200){
            cout << "Numero invalido o numero existente" << endl;
        }
    }
}

void remover (ArbolBinarioAVL<int>&arbol, int cod){
    try{
        if (arbol.search(cod)){
            arbol.remove(cod);
            cout << "Codigo removido" << endl;
        }
    }catch (int e){
        if (e == 404){
            cout << "No se encuentra esa ese codigo" << endl;
        }
    }
}

void buscar (ArbolBinarioAVL<int>&arbol, int id){
    try{
        if (arbol.search(id)){
            cout << "Si se encuentra el numero " << id << endl;
        }
    }
    catch (int e){
        if (e == 404){
            cout << "No se encuentra el numero "<< id << endl;
        }
    }
}

int main (){
    cout << "Ejercicio 1.2" << endl;

    ArbolBinarioAVL<int>arbol;
    int opcion, id;

    do{
        cout << "---------MENU-----------" << endl;
        cout << "1. Insertar codigo" << endl;
        cout << "2. Eliminar codigo" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Mostrar arbol" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo para agregar" << endl;
                cin >> id;
                agregar(arbol,id);
                break;
            case 2:
                cout << "Ingrese el codigo que desea eliminar" << endl;
                cin >> id;
                remover(arbol,id);
                break;
            case 3:
                cout << "Ingrese el codigo que desea buscar" << endl;
                cin >> id;
                buscar(arbol, id);
                break;
            case 4:
                cout << arbol.getBalance();
                arbol.print();
                break;
            case 5:
                break;
        }
    } while (opcion != 5);
}
