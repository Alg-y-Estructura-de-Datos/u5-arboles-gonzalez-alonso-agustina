/*Ejercicio 5: Gestión de entregas de paquetes
Problema: Trabajas en una empresa de logística y debes gestionar los paquetes que llegan
y se entregan a través de un sistema. Cada paquete tiene un número de seguimiento único.
Tu sistema debe permitir la entrada de nuevos paquetes, la entrega (eliminación) de
paquetes, y la verificación de los que siguen en tránsito.
● Tarea: Inserta los paquetes con los números de seguimiento: 1001, 5002, 3003,
2004, 4500, 7005, 8006.
● Desafío: Los paquetes con los números de seguimiento 2004 y 4500 fueron
entregados, así que elimínalos. Luego, un nuevo paquete con el número 3500 llega
al sistema. Verifica si el paquete con el número 1001 sigue en tránsito e imprime la
lista de paquetes restantes.*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void entrega (ArbolBinario<int>arbol, int id){
    try{
        if (arbol.search(id)){
            arbol.remove(id);
            cout << "Paquete entregado" << endl;
        }
    }
    catch (int e) {
        if (e == 404) {
            cout << "Paquete no encontrado" << endl;
        }
    }
}

void nuevo (ArbolBinario<int>arbol, int id){
    try{
        arbol.put(id);
    }
    catch (int e){
        if( e == 202){
            cout << "No pudo agregarse" << endl;
        }
    }
}

int main () {
    cout << "Ejercicio 5" << endl;

    ArbolBinario<int> arbol;
    int id, opcion;

    arbol.put(1001);
    arbol.put(5002);
    arbol.put(3003);
    arbol.put(2004);
    arbol.put(4500);
    arbol.put(7005);
    arbol.put(8006);

    do {
        cout << "---------MENU-----------" << endl;
        cout << "1. Insertar codigo" << endl;
        cout << "2. Eliminar codigo" << endl;
        cout << "3. Mostrar arbol" << endl;
        cout << "4. Verificar paquetes" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo para agregar" << endl;
                cin >> id;
                nuevo(arbol, id);
                break;
            case 2:
                cout << "Ingrese el codigo del paquete entregado" << endl;
                cin >> id;
                entrega(arbol, id);
                break;
            case 3:
                arbol.print();
                break;
            case 4:
                cout << "Ingrese el numero de paquete que busca" << endl;
                cin >> id;
                if (arbol.search(id)) {
                    cout << "El paquete numero " << id << " esta en transito" << endl;
                }
                break;
            case 5:
                break;
        }
    } while (opcion != 5);

    return 0;
}