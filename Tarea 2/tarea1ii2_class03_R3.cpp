/* tarea1ii2_class03_R3.cpp

* Autor: Félix Cabrera
* ECFM 11/feb/2020
* Tomado de los codigos originales de la clase
* de Laboratorio Avanzado, impartida por Hector Perez
* ECFM-USAC primer semestre 2021

* Esta es una implementación de la clase VecR2

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

* instrucciónes para compilar:
* $ g++ -Wall -pedantic -o tarea1_R3 tarea1ii1_VecR3.cpp tarea1ii2_class03_R3.cpp

* Ejecución:
* ./tarea1_R3

*/

#include <cstdlib>
#include <iostream>
#include "tarea1ii3_VecR3.hpp"

using namespace std;

int main()
{
    VecR3 v1(1,0,0);
    VecR3 v2(0,1,0);
    VecR3 v3(0,3,1);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "Magnitud v3 = " << v3.Magnitud() << endl;

    VecR3 v4;
    v4 = v1 + v2;
    cout << "v4 = v1 + v2 = " << v4 << endl;

    // Prueba de producto punto
    float a;
    a = v4*v3;
    cout << "a = v4*v3 = " << a << endl;

    // Prueba de multiplicacion por escalar
    VecR3 v5;
    v5 = a*v4;
    cout << "v4*a = " << v5 << endl;

    // Prueba de resta
    VecR3 v6;
    v6 = v1 - v2;
    cout << "v1- v2 = =" << v6 << endl;

    // Prueba de negacións
    VecR3 v7;
    v7 = -v6;
    cout << "-v6 = " << v7 << endl;

    // Prueba de division por escalar

    VecR3 v8;
    v8 = v5/a;
    cout << "v5/a = " << v8 << endl;

    // Prueba producto cruz
    VecR3 v9;
    v9 = v1%v2;
    cout << "v1 x v2 = " << v9 << endl;

    // Prueba asignacion
    v1 = v2;
    cout << "v1 = " << v1 << endl;

    // Prueva de igualdad
    cout << "v1 = v2 ? " << (v1 == v2) << endl;
    cout << "v1 = v3 ? " << (v1 == v3) << endl;

    VecR3::Mostrar_esfericas(true);
    cout<< "Mostar en notacion esferica activado" << endl;
    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "v2 = " <<  v2 << endl;
    cout << "v3 = " <<  v3 << endl;
    cout << "v4 = " <<  v4 << endl;

    return 0;
}
