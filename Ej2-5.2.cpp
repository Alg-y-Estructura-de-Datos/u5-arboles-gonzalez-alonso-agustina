/*Ejercicio N°2
Imagina que trabajas en una tienda que vende una variedad de productos. Cada producto tiene un código único que lo identifica y necesitas gestionar el inventario utilizando un árbol AVL para asegurarte de que el sistema esté optimizado y balanceado. Los productos se identifican únicamente por su código, y no hay productos duplicados en el inventario.
Opciones del menú:
1.	Agregar producto: Inserta un nuevo código de producto en el sistema.
2.	Eliminar producto: Elimina un código de producto del sistema.
3.	Buscar producto: Verifica si un código de producto existe en el inventario.
4.	Mostrar inventario: Imprime el árbol AVL de productos para mostrar su estructura balanceada.
5.	Salir: Finaliza el programa.
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

int main(){
    cout << "Ejercicio 2.2" << endl;

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