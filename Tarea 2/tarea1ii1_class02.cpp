/* tarea1ii1_class02.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Programa de ejemplo para la clase simple

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

* instrucciónes para compilar:
* $ g++ -Wall -pedantic -o tarea1_class02 tarea1ii1_persona.cpp tarea1ii1_class02.cpp

* Ejecución:
* ./tarea1_class02

*/
#include <cstdlib>
#include <iostream>
#include "tarea1ii1_persona.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona.
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    persona Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital");

    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::LLamar_Todos();

    delete Maria;

    persona::LLamar_Todos();


    /*********************************/
    // Comandos de tarea 1.ii.2

    std::cout << "Tarea:" << '\n';

    Fulano.Asignar_Nombre("Armando Casas");
    Fulano.Asignar_Lugar_Origen("Xela");
    Fulano.Asignar_Fecha_Naciemiento(1991,7,12);

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    int A,B,C;
    string D,E;

    A = Fulano.Obtener_Anio_Nacimiento();
    B = Fulano.Obtener_Dia_Nacimiento();
    C = Fulano.Obtener_Mes_Nacimiento();

    D = Fulano.Obtener_Nombre();
    E = Fulano.Obtener_Lugar_Origen();

    std::cout << A << '\n';
    std::cout << B << '\n';
    std::cout << C << '\n';
    std::cout << D << '\n';
    std::cout << E << '\n';

    return 0;
}
