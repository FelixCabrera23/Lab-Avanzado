/* tarea1ii3_VecR3.hpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Definicion de la clase VecR3

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/

#ifndef __VECR3_HPP__
#define __VECR3_HPP__

#include <iostream>
#include <string>

/* Clase VecR3: Vectores en R3 en forma cartesiana. */

class VecR3
{
private:
    /* coordenadas */
    float Xcor;
    float Ycor;
    float Zcor;

    /* Atributo de clase: indica si el despliegue es en cartecianas
     * o esfericas */
    static bool Esfericas;

public:

    /* Constructor sin argumentos */
    VecR3();
    /* Constructor con argumentos */
    VecR3( float valor_x, float valor_y, float valor_z);
    /* Destructor */
    ~VecR3();

    /* Metodos de asignacion */

    /* asigna coordenadas */
    void Asignar_xyz(float valor_x, float valor_y, float valor_z);

    /* Metodos de obtencion */

    /* Obtiene la coordenada x */
    float Obtener_x() const;
    /* Obtiene la coordenada y */
    float Obtener_y() const;
    /* Obtiene la coordenada z */
    float Obtener_z() const;

    /* Otros metodos */

    float Magnitud() const;

    /* Sobrecarga */

    /* Suma de vectores */
    VecR3 operator+( const VecR3 & ) const;

    /* Producto punto */
    float operator*( const VecR3 & ) const;

    /* resta de vector */
    VecR3 operator-( const VecR3 & ) const;

    /* negación de un vector */
    VecR3 operator-( );

    /* division por escalar */
    VecR3 operator/( const float & ) const;

    /* producto cruz */
    VecR3 operator%( const VecR3 & ) const;

    /* asignacion = */
    // void operator=( VecR3 & );
    // El operador nativo ya cumple el requisito

    /* verificar igualdad */
    bool operator==( const VecR3 & ) const;

    /* Mostrar esfericas */
    static void Mostrar_esfericas( bool valor );

    /* Funciones amigas */

    /* Despliega vector con cout */
    friend std::ostream &operator<<( std::ostream &, const VecR3 & );
    /* Multipica un flotante por un vector */
    friend VecR3 operator*( const float &, const VecR3 & );


};
#endif /* __VECR3_HPP__ */
