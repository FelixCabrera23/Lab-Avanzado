/* tarea1ii1_class01.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Programa de ejemplo para la clase simple

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

* instrucciónes para compilar:
* $ g++ -Wall -pedantic -o tarea1_simple tarea1ii1_simple.cpp tarea1ii1_class01.cpp

* Ejecución:
* ./tarea1_simple

*/
#include <cstdlib>
#include <iostream>

#include "tarea1ii1_simple.hpp"

using namespace std;

/* Inicio del programa */
int main()
{
    /* Se crean dos instancias de la clase simple. La
     * primera sin argumentos, el constructor por defecto
     * es llamando. */
    simple primero;
    /* Para la segunda instancia se utilizan argumentos, el
     * constructor con argumentos es llamado. */
    simple segundo("Hoy no es viernes");

    /* Se llama el metodo de clase simple::Cuantos() que
     * nos indica cuantas instancias van de la clase.
     * Notese que su llamada es independiente de las instancias. */
    simple::Cuantos();

    /* Se crea un puntero a un objeto de tipo simple. Esto
     * no llama al constructor ya que lo que se esta creando
     * es un puntero, no una instancia de clase.
     * el puntero se pone con asterisco */
    simple* tercero = 0;

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Se crea una instancia en memoria de la clase simple
     * utilizando new. La ubicacion de esta clase se almacena
     * en el puntero creado anteriormente. Notese que se
     * llama la forma con argumentos. */
    tercero = new simple("Voy de ultimo");

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Se llaman los metodos de los objetos. Estos deben
     * ser llamados desde una instancia e interactuan
     * con los atributos de cada instancia. */
    primero.Decir_Frase();
    segundo.Decir_Frase();
    tercero->Decir_Frase();

    /* Aqui probaremos el metodo ID */
    primero.Decir_ID();
    segundo.Decir_ID();
    tercero->Decir_ID();

    /* Se libera el espacio de memoria creado por new.
     * El destructor es llamado. */
    delete tercero;

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Al finalizar la funcion con el comando return
     * las instancias que aun queden deben ser eliminadas.
     * Los destructores deben ser llamados para cada
     * instancia. */
    return 0;
}
