/* tarea1.cpp

* Autor: Félix Cabrera
* ECFM 01/feb/2020

* Este programa escribe numeros en Binario

* Compiladores probados:
* gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

* instrucciónes para compilar:
* $ g++ -Wall -pedantic -o tarea1 tarea1.cpp

* Ejecución:
* ./tarea1

*/

#include <bitset>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

  int numero = -1000000;
  std::cout << std::bitset<32>(numero) <<endl;

  return 0;
}
