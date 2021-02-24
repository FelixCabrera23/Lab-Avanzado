/* tarea1ii1_simple.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Esta es una implementación de la clase simple

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/
#include <iostream>

#include "tarea1ii1_simple.hpp"

/* El atributo de clase debe ser inicializado como si fuera
 * una variable global. */

int simple::Numero = 0;
int ID = 0;

/* Constructor sin argumentos (defecto) */
simple::simple( )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor SIN argumentos" << std::endl;
    /* Se asigna un valor por defecto al atributo Frase */
    Frase = "No hay";
    /* Se incrementa el valor del atributo de clase. */
    Numero++;

    /* Se llama a numero como el ID */
    ID = Numero;
}

/* Constructor con argumentos */
simple::simple( std::string La_Frase )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor CON argumento" << std::endl;
    /* Se asigna al atributo Frase el valor del argumento */
    Frase = La_Frase;
    /* Se incrementa el valor del atributo de clase. */
    Numero++;

    ID = Numero;
}

/* Destructor */
simple::~simple()
{
    /* Cada vez que se llame este destructor se mostrara este mensaje. */
    std::cout<< "Soy el destructor" << std::endl;
    /* Se decrementa el valor del atributo de clase. */
    Numero--;
}

/* Implementacion del metodo Decir_Frase: Se llama a traves de las
 * instancias de la clase */
void simple::Decir_Frase()
{
    std::cout << "La frase es: " << Frase << std::endl;
}

/* Metodo de clase: indica cuantas instancias van de la clase */
void simple::Cuantos()
{
    std::cout << "Van " << Numero << " instancias de simple" << std::endl;
}

/* Metodo de clase para decir el ID */

void simple::Decir_ID()
{
    std::cout << "Mi ID es:" << ID << std::endl;
}
