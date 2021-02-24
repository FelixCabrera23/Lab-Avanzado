/* tarea1ii1_persona.hpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Definicion de la clase persona

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/
#ifndef __PERSONA_HPP__
#define __PERSONA_HPP__

#include <string>
#include <vector>
#include <ctime>

/* Clase persona. Almacena los datos basicos de una persona. */
class persona
{
protected:
    /* Atributos. Notese que se utilizan punteros
     * en lugar de variables. */

    /* Nombre de la persona */
    std::string* Nombre;
    /* Fecha de nacimiento de la persona */
    std::tm*     Fecha_nacimiento;
    /* Lugar de nacimiento de la persona */
    std::string* Lugar_nacimiento;
    /* Numero de DPI de la persona */
    std::string* DPI;

    /* Atributo de clase. Es un vector de punteros a la
     * clase (persona). En este se almacenaran las direcciones
     * de cada instancia de la clase. */
    static std::vector< persona* > instancias;

public:
    /* Metodos */

    /* Constructor por defecto */
    persona();
    /* Constructor con argumentos */
    persona( std::string    El_Nombre,
             int            Anio_Nacimiento,
             int            Mes_Nacimiento,
             int            Dia_Nacimiento,
             std::string    Lugar_Origen
            );

    /* Destructor */
    ~persona();

    /* Metodo para asignar el DPI a una persona (set) */
    int Asignar_DPI( std::string Num_CUI );

    /* Metodo para obtener el DPI a una persona (get) */
    std::string Obtener_DPI( );

    /* Metodo para solicitar que indique el nombre */
    void Decir_Nombre();
    /* Metodo para solicitar que indique la edad */
    void Decir_edad();
    /* Metodo para solicitar que indique el lugar de origen */
    void Decir_origen();

    /* Metodo de clase. Sera utilizado para que todas las instancias
     * de la clase digan su nombre. */
    static void LLamar_Todos();

    /***************************************************************/

    /* Metodos de tarea (SET): */
    int Asignar_Nombre(std::string elNombre);

    int Asignar_Fecha_Naciemiento(int A, int M, int D); // A - año, M - mes, D - dia

    int Asignar_Lugar_Origen(std::string Lugar);

    /* Metodos de tarea (GET): */
    std:: string Obtener_Nombre();

    int Obtener_Anio_Nacimiento();

    int Obtener_Dia_Nacimiento();

    int Obtener_Mes_Nacimiento();

    std::string Obtener_Lugar_Origen();

    /***************************************************************/
};


#endif /* __PERSONA_HPP__ */
