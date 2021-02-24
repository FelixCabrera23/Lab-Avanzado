/* tarea1ii1_persona.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Esta es una implementación de la clase Persona

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/

#include <iostream>
#include "tarea1ii1_persona.hpp"

/* Inicializacion del atributo de clase. En este
 * caso solo la declaracion es necesaria ya que
 * la inicializacion propiamente la hace el
 * constructor de la clase vector. */

std::vector< persona* > persona::instancias;

/* Constructor por defecto */
persona::persona( )
{
    /* Coloca todos los punteros a cero para
     * indicar que no estan asignados */
    Nombre              = 0;
    Fecha_nacimiento    = 0;
    Lugar_nacimiento    = 0;
    DPI                 = 0;

    /* Cada instancia de clase tiene un puntero
     * que apunta a ella misma llamado "this".
     * Aqui se aniade al vector de punteros instancias
     * la direccion de la clase que se esta creando
     * por la llamada de este constructor. */
    instancias.push_back(this);

}

/* Constructor con argumentos */
persona::persona( std::string    El_Nombre,
                  int            Anio_Nacimiento,
                  int            Mes_Nacimiento,
                  int            Dia_Nacimiento,
                  std::string    Lugar_Origen
            )
{
    /* Se asignan los valores de los argumentos a los
     * atributos respectivos */
    Nombre              = new std::string( El_Nombre );
    Lugar_nacimiento    = new std::string( Lugar_Origen );
    /* El DPI no figura entre los argumentos, por lo
     * que el puntero se asigna a cero para indicar
     * que no esta asignado */
    DPI                 = 0;

    /* El atributo "Fecha_nacimiento" es un puntero
     * a una estructura de tiempo tm de C. Aqui se asignan
     * los datos proporcionados a la estructura. */
    Fecha_nacimiento = new std::tm;
    Fecha_nacimiento->tm_year = Anio_Nacimiento - 1900;
    Fecha_nacimiento->tm_mon = Mes_Nacimiento - 1;
    Fecha_nacimiento->tm_mday = Dia_Nacimiento;

    std::mktime ( Fecha_nacimiento );

    /* Se aniade la direccion de la instancia que esta
     * siendo creada al vector de punteros instancias. */
    instancias.push_back(this);

}

/* Destructor */
persona::~persona()
{
    /* Se remueve del vector de punteros instancias la direccion
     * de la instancia que esta siendo eliminada. Notese
     * el uso del iterador de la clase vector. */
    for( auto n = instancias.begin(); n != instancias.end(); n++ )
        if( *n == this )
        {
            instancias.erase( n );
            break;
        }

    delete Nombre;
    delete Fecha_nacimiento;
    delete Lugar_nacimiento;
    delete DPI;
}

/* Metodo para asignar el DPI (set method)
 * devuelve 0 si se realiza la asignacion;
 * 1 si no. */
int persona::Asignar_DPI( std::string Num_CUI )
{
    if( !DPI )
    {
        DPI = new std::string( Num_CUI );
        return 0;
    }

    std::cout << "El DPI ya fue asignado" << std::endl;
    return 1;
}


/* Metodo para obtener el DPI a una persona (get method)
 * devuelve un string con el numero de DPI */
std::string persona::Obtener_DPI( )
{
    if( DPI )
        return *DPI;
    return "DPI no asignado";
}

/* Metodo que indica a la instacia que debe imprimir su nombre. */
void persona::Decir_Nombre()
{
    if( Nombre )
        std::cout << "Mi nombre es: " << *Nombre << std::endl;
    else
        std::cout << "Nombre no asignado" << std::endl;
}

/* Metodo que indica a la instacia que debe imprimir su edad
 * en anios. */
void persona::Decir_edad()
{
    if( Fecha_nacimiento )
    {
        std::time_t now;
        float Edad;

        std::time(&now);

        /* La funcion difftime devuelve la diferencia de tiempo
         * en segundos. Se convierte a anios. Notese que no sera
         * la edad calendario. */
        Edad = std::difftime(now,std::mktime(Fecha_nacimiento))/31556925.9747;

        std::cout<< "Mi edad es: " << Edad << " anios" << std::endl;
    }
    else
        std::cout << "Fecha de nacimiento no asignada" << std::endl;

}

/* Metodo que indica a la instacia que debe imprimir su lugar de origen. */
void persona::Decir_origen()
{
    if( Lugar_nacimiento )
        std::cout << "Soy de: " << *Lugar_nacimiento << std::endl;
    else
        std::cout << "Lugar de origen no asignado" << std::endl;
}

/* Metodo de clase. Se utiliza el vector de punteros instancias
 * para llamar al metodo Decir_Nombre de todas las instancias. */
void persona::LLamar_Todos()
{
    /* Primero se verifica que existan instancias por medio del
     * tamanio del vector instancias */
    if( instancias.size() != 0 )
        /* Se usa el iterador de la case vector para llamar al
         * metodo Decir_Nombre de cada instancia. */
        for( auto n = instancias.begin(); n != instancias.end(); n++)
            (*n)->Decir_Nombre();
    else
        std::cout << "No hay instancias aun" << std::endl;

}
/***************************************************************/
/* Metodos de tarea  */

/* Metodo para asingar nombre */
int persona::Asignar_Nombre(std::string elNombre)
{
    if( !Nombre)
    {
        Nombre = new std::string(elNombre);
        return 0;
    }

    std::cout << "El nombre no fue asignado" << std::endl;
    return 1;
}


/* Meotod para asingar fecha de nacimiento
 * devuelve 0 si se realiza la asignacion;
 * 1 si no. */
int persona::Asignar_Fecha_Naciemiento(int A, int M, int D)
{
    if ( !Fecha_nacimiento)
    {
        Fecha_nacimiento = new std::tm;
        Fecha_nacimiento->tm_year = A -1900;
        Fecha_nacimiento->tm_mon = M -1;
        Fecha_nacimiento->tm_mday = D;
        return 0;
    }

    std::cout << "La fecha de nacimiento ya fue asignada" << std::endl;
    return 1;
}

/* Metodo para asignar lugar de origen */
int persona::Asignar_Lugar_Origen(std::string Lugar)
{
    if ( !Lugar_nacimiento )
    {
        Lugar_nacimiento = new std::string(Lugar);
        return 0;
    }

    std:: cout << "El lugar no fue asignado" << std::endl;
    return 1;
}

/* METODOS GET */

std::string persona::Obtener_Nombre()
{
    if(Nombre)
      return *Nombre;
    return "Nombre no asignado";
}

int persona::Obtener_Anio_Nacimiento()
{
    if(Fecha_nacimiento)
        return Fecha_nacimiento->tm_year;
    return 0;
}

int persona::Obtener_Mes_Nacimiento()
{
  if(Fecha_nacimiento)
      return Fecha_nacimiento->tm_mon;
  return 0;
}

int persona::Obtener_Dia_Nacimiento()
{
    if(Fecha_nacimiento)
        return Fecha_nacimiento->tm_mday;
    return 0;
}

std::string persona::Obtener_Lugar_Origen()
{
    if(Lugar_nacimiento)
        return(*Lugar_nacimiento);
    return "Lugar de origen no asignado";
}
