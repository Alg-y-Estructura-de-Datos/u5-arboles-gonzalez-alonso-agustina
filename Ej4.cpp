/*Ejercicio 4: Administración de reservas en un restaurante
Problema: Un restaurante tiene un sistema de reservas donde cada mesa tiene un número
específico. A medida que los clientes reservan o cancelan mesas, el sistema debe
mantenerse actualizado.
● Tarea: Agrega las reservas de las siguientes mesas: 15, 10, 20, 5, 12, 18, 25.
● Desafío: Dos clientes cancelaron sus reservas en las mesas 10 y 20, así que
elimínalas del sistema. Luego, un nuevo cliente reserva la mesa 13. Verifica si la
mesa 12 aún está reservada e imprime la lista actualizada de mesas reservadas.*/\

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void remover (ArbolBinario<int>&arbol, int id){
    try{
        if (arbol.search(id)){
            arbol.remove(id);
            cout << "Reserva cancelada" << endl;
        }
    }catch (int e){
        if (e == 404){
            cout << "No se encuentra esa reserva" << endl;
        }
    }
}
int main (){
    cout << "Ejercicio 4" << endl;

    ArbolBinario<int>arbol;

    arbol.put(15);
    arbol.put(10);
    arbol.put(20);
    arbol.put(5);
    arbol.put(12);
    arbol.put(18);
    arbol.put(25);

    remover(arbol, 10);
    arbol.print();

    return 0;

}