/*
 * funciones.C: Define varias funciones para
 * mostrar como se utilizan las clases TF1
 * en ROOT.
 * 
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 * 
 * Héctor Pérez, febrero 2021.
 * 
 */

#include "TROOT.h"
#include "TH1D.h"
#include "TF1.h"

Double_t MiFuncion( Double_t x, 
                    Double_t a, 
                    Double_t b, 
                    Double_t c,
                    Double_t An,
                    Double_t gamma,
                    Double_t mu)
{
    return  a*TMath::Power(x,2) + b*x + c
            + (An/TMath::Pi())*(gamma/(TMath::Power(x-mu,2)+TMath::Power(gamma,2)));            
}

void Funciones03()
{
    TF1 *Funcion = new TF1("Func02","MiFuncion(x,[0],[1],[2],[3],[4],[5])",0,10);
    Funcion->SetParNames("a","b","c","Amplitud","FWHM","Media");
    Funcion->SetParameters(-(4.0/49),(8.0/7),1,20,1,4);
    Funcion->Draw();
}
