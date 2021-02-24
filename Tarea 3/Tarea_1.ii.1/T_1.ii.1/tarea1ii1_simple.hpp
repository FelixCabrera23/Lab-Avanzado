/* tarea1ii1_simple.hpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Definicion de la clase simple

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/

#ifndef __SIMPLE_HPP__
#define __SIMPLE_HPP__

#include <string>

/* Clase simple: Clase de ejemplo. */
class simple
{
    /* Tanto los atributos como los metodos pueden ser definidos
     * privados o publicos. Generalmete los atributos son privados,
     * esto quiere decir que solo es posible acceder a ellos a
     * traves de los metodos puplicos de la clase. */
private:
    /* Estos son los atributos del objeto (data members)
     * Son diferentes para cada instancia de la clase */

    /* Atributo de cada instancia. */
    std::string Frase;

    /* Atributo de clase: es comun a todas las instancias. */
    static int Numero;

    /* Atributo ID */

    int ID;

public:
    /* Estos son los metodos del objeto (member functions) */

    /* Constructor sin argumentos */
    simple();
    /* Constructor con argumentos */
    simple( std::string La_Frase );
    /* Destructor */
    ~simple();

    /* Metodo para solicitar que imprima la frase.
     * Se llaman a travez de las instancias de la clase */
    void Decir_Frase();

    /* Metodo de clase: Indica cuantas instancias estisteb
     * de la clase. No puede llamarse desde una instancia */
    static void Cuantos( );

    /* Metodo para saber el ID */

    void Decir_ID();

};

#endif /* __SIMPLE_HPP__ */
