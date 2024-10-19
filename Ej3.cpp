/*Ejercicio 3: Sistema de inscripción en un gimnasio
Problema: Estás diseñando un sistema de inscripción para un gimnasio, donde cada socio
tiene un número de socio único. El sistema debe permitir la inscripción de nuevos socios, la
eliminación de socios que se dan de baja, y la búsqueda de socios activos.
● Tarea: Inscribe a los socios con los siguientes números de socio: 500, 250, 750, 100,
300, 600, 800.
● Desafío: Un socio con el número 250 se da de baja, así que elimínalo. Luego,
verifica si los socios con los números 300 y 750 aún están activos. Imprime la lista
de socios actualizada.
*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void remover (ArbolBinario<int>&arbol){

    try{
        arbol.remove(250);
    }
    catch (int e){
        if (e == 404){
            cout << "No se encuentra" << endl;
        }
    }
}

void buscar (ArbolBinario<int>&arbol, int id){
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

int main() {

    cout << "Ejercicio N° 3" << endl;

    ArbolBinario<int>arbol;

    arbol.put(500);
    arbol.put(250);
    arbol.put(750);
    arbol.put(100);
    arbol.put(300);
    arbol.put(600);
    arbol.put(800);

    remover(arbol);
    buscar(arbol, 300);
    buscar (arbol, 750);
    arbol.print();

    return 0;
}
