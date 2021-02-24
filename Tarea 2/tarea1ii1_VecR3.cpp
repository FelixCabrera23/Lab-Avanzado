/* tarea1ii1_VecR3.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Esta es una implementación de la clase VecR2

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

*/

#include <iostream>
#include <cmath>
#include "tarea1ii3_VecR3.hpp"

/* Constructor sin argumentos */

bool VecR3::Esfericas = false;

VecR3::VecR3()
{
    Xcor = 0;
    Ycor = 0;
    Zcor = 0;
}

/* Constructor con argumentos */
VecR3::VecR3(float valor_x, float valor_y, float valor_z)
{
    Xcor = valor_x;
    Ycor = valor_y;
    Zcor = valor_z;
}

/* Destructor */
VecR3::~VecR3()
{}

/* Metodo de asignacion */
/* Como no forma parte de la tarea solamente
 * incluire la asignacion para xyz */

void VecR3::Asignar_xyz(float valor_x, float valor_y, float valor_z)
{
    Xcor = valor_x;
    Ycor = valor_y;
    Zcor = valor_z;
}

/* Metodos GET */

float VecR3::Obtener_x() const
{
    return Xcor;
}

float VecR3::Obtener_y() const
{
    return Ycor;
}

float VecR3::Obtener_z() const
{
    return Zcor;
}

float VecR3::Magnitud() const
{
    return std::sqrt(Xcor*Xcor + Ycor*Ycor + Zcor*Zcor);
}

/* Sobrecarga de operadores */

/* Suma de dos vectores */
VecR3 VecR3::operator+( const VecR3 &avec) const
{
    /* vector temporal */
    VecR3 tmp;

    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;
    tmp.Zcor = this->Zcor + avec.Zcor;

    return tmp;
}

/* producto punto */
float VecR3::operator*( const VecR3 &avec ) const
{
    float tmp;

    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor + this->Zcor*avec.Zcor;

    return tmp;
}

/* resta de un vector */
VecR3 VecR3::operator-( const VecR3 &avec ) const
{
    VecR3 tmp;
    tmp.Xcor = this->Xcor - avec.Xcor;
    tmp.Ycor = this->Ycor - avec.Ycor;
    tmp.Zcor = this->Zcor - avec.Zcor;

    return tmp;
}

/* negación de un vector */
VecR3 VecR3::operator-()
{
    VecR3 tmp;
    tmp.Xcor = -this->Xcor;
    tmp.Ycor = -this->Ycor;
    tmp.Zcor = -this->Zcor;

    return tmp;
}

/* division por escalar */
VecR3 VecR3::operator/( const float &asec ) const
{
    VecR3 tmp;
    tmp.Xcor = this->Xcor/asec;
    tmp.Ycor = this->Ycor/asec;
    tmp.Zcor = this->Zcor/asec;

    return tmp;
}

/* producto cruz */
VecR3 VecR3::operator%( const VecR3 &avec) const
{
    VecR3 tmp;
    tmp.Xcor = this->Ycor*avec.Zcor - this->Zcor*avec.Ycor;
    tmp.Ycor = this->Zcor*avec.Xcor - this->Xcor*avec.Zcor;
    tmp.Zcor = this->Xcor*avec.Ycor - this->Ycor*avec.Xcor;

    return tmp;
}
/* asignacion */
// void VecR3::operator=( VecR3 &avec )
// {
//     this->Asignar_xyz(avec.Xcor,avec.Ycor,avec.Zcor);
// }

/* comparación entre vectores */
bool VecR3::operator==( const VecR3 &avec ) const
{
    bool igual;
    igual = true;
    if (this->Xcor != avec.Xcor)
    {
        igual = false;
    }
    if (this->Ycor != avec.Ycor)
    {
        igual = false;
    }
    if (this->Zcor != avec.Zcor)
    {
        igual = false;
    }

    return igual;
}
/* Mostrar en coordendas esfericas */
void VecR3::Mostrar_esfericas( bool valor )
{
    Esfericas = valor;
}


/* Funciones amigas */

/* sobrecarga para << para usar std out */
std::ostream &operator<<( std::ostream &salida, const VecR3 &avec )
{

    /*Salida polar*/
    if( VecR3::Esfericas )
    {
        float r=0, theta=0, phi=0;
        r = std::sqrt(avec.Xcor*avec.Xcor+avec.Ycor*avec.Ycor);
        phi = std::atan2( avec.Ycor, avec.Xcor );
        theta = std::atan2( r , avec.Zcor );

        salida << "(" << avec.Magnitud() << ", th " << theta << ", phi " << phi <<")";
    }
    /* Salida carteciana */
    else
    {
        salida << "(" << avec.Xcor << ", " << avec.Ycor << ", " << avec.Zcor << ")";
    }

    return salida;
}

/* sobrecarga para el operador * */
VecR3 operator*( const float &aesc, const VecR3 &avec )
{
    VecR3 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;
    tmp.Zcor = aesc*avec.Zcor;

    return tmp;
}
