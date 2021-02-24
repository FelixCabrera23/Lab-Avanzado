/*
 * funciones01.C: Define varias funciones para
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

void Funciones01()
{
    TF1 *Fondo_Cuadratico = new TF1("FC","[0]*x*x+[1]*x+[2]",0,10);
    Fondo_Cuadratico->SetParNames("a","b","c");
    Fondo_Cuadratico->SetParameters(-(4.0/49),(8.0/7),1);
    Fondo_Cuadratico->Draw();
}

void Funciones02()
{
    // void *ptr;
    // if( (ptr = gDirectory->FindObject("FC")) )   delete (TF1*)ptr;

    
    // TF1 *Fondo_Cuadratico = (TF1*)gDirectory->FindObject("FC");

    TF1 *Fondo_Cuadratico = new TF1("FC","[0]*x*x+[1]*x+[2]",0,10);
    Fondo_Cuadratico->SetParNames("a","b","c");
    Fondo_Cuadratico->SetParameters(-(4.0/49),(8.0/7),1);

    TF1 *Lorentziana = new TF1("FL","([0]/TMath::Pi())*([1]/((x-[2])*(x-[2]) + [1]*[1]))",0,10);
    Lorentziana->SetParNames("Amplitud","FWHM","Media");
    Lorentziana->SetParameters(20,1,4);

    TF1 *Funcion = new TF1("Func01","FC + FL",0,10);

    Funcion->Draw();
}