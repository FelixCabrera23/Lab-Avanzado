/* script.C

Este es un ejemplo de script para usar con root

Para correrlo dentro de root:

$ .L script.C
$ Script01Func()

*/

#include "TH1D.h"

void Script01Func()
{
    TH1D *RanHisto = new TH1D("rh", "Histograma de numeros aleatorios", 100, -3, 3);
    RanHisto->FillRandom("gaus",10000);
    RanHisto->Draw();

}
