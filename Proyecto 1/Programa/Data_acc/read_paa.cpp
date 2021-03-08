/*
 * read_pas.cpp: Código para lectura de archivos .paa
 * provenientes de la captura de datos de un WCD con la
 * utilidad Pulse Acquire para Red Pitaya.
 *
 * Héctor Pérez, marzo 2021.
 *
 * Para el curso de Laboratorio Avanzado
 * ECFM - USAC
 *
 */

#include <cstdio>
#include <vector>

#include "TGraph.h"
#include "TCanvas.h"

/* Header de la clase paa_file que maneja los archivos .paa */
#include "paa.hpp"

/* Header de la clase largs que maneja los argumentos de línea */
#include "largs.hpp"
/* Para hacer histogramas */
#include "TH1D.h"
/* Para guardar histogramas */
#include "TFile.h"

int main(int argc, char* argv[])
{
    /* Primero se crea una instancia de la clase que hace el
     * "parsing" de los argumentos de línea proporcionados
     * al programa. */
    largs cmd_args(argc,argv);

    /* Si los argumentos de la línea de comandos no son adecuados se
     * interrumpe la ejecución delprograma. */
    if( !cmd_args.Args_Ok() )
        return 1;

    /* Se asocia el archivo de entrada provisto en el argumento
     * de línea con una instancia de la clase paa_file. */
    paa_file mi_archivo( cmd_args.GetLArgInputFile() );

    /* Se verifica si la asociación del archivo fue exitosa,
     * Si no, se sale del programa */
    if(!mi_archivo.Is_Open())
        return 1;

    /* Se crean dos vectores de enteros para almacenar los datos
     * del pulso que se va leer desde el archivo .paa */
    std::vector<int> * pulseData_v;
    std::vector<int> * pulseData_t = new std::vector<int>;

    /**************************************************************************/
    /*        MODIFICACIÓN PARA LEER TODOS LOS PULSOS                         */

    /* Declaramos variables importantes */
    int pc_i, ps_i, tl_i, low, event, t;
    pc_i = mi_archivo.GetPulseEntries();      // Pulsos por archivo
    ps_i = mi_archivo.GetPulseSize();         // Puntos por pulso
    tl_i = cmd_args.GetLArgThreshold();    // Triger

    bool Doble = false;                       // Verifica si hay doble pulso

    std::vector<int> * Double_pls_list = new std::vector<int>;    // Lista de pulsos dobles

    /* Hacemos un ciclo para cada dato */

    for( int i = 0; i < pc_i; i++){
        pulseData_v = mi_archivo.GetPulse(i); // Va tomando los datos de cad pulso
        event = 1;  // Ponemos 0 eventos
        low = 0;    // Ponemos el contador a 0
        /*  Determinamos el tiempo en el que baja la señal   */
        /* Como los puntos antes del triger son 5 */
        /* Este ciclo quita el primer pulso para que solo detectemos el segundo */
        for(int j = 5; j < pulseData_v->size(); j++){
            int temp1;
            temp1 = pulseData_v[0][j];
            if (temp1 > tl_i){
                low = j;
                break;
                }
            }

        /* Hacemos un ciclo dentro del pulso, buscando el segundo pulso */
        for( int k = low; k < pulseData_v->size(); k++){
            int temp;
            temp = pulseData_v->at(k);
            if (temp < tl_i){
                event = event + 1;
                t = (k-5)*8;
                pulseData_t->push_back(t);
                break;
              }
            }
        /* Si hay 2 eventos guardamos el numero del pulso */

        if(event == 2){
            Double_pls_list->push_back(i);
            // std::cout << i << '\n';
            Doble = true;
          }
        }

    std::cout << "Total double pulses " << Double_pls_list->size() << std::endl;
    std::cout << "Trigger used to get double pulses: " << tl_i << std::endl;

    /***** HISTOGRAMA ******/

    TH1D *aHist = new TH1D("Datos","Tiempo de decaimiento del muon",20,0,0);

    for(int i= 0; i < pulseData_t->size(); i++){
        aHist->Fill(pulseData_t->at(i));
        }

    /* Grafica */
    TCanvas *ShowGraph = new TCanvas("Histo", "send send send", 600,400);

    aHist->Draw();
    ShowGraph->Update();

    ShowGraph->SaveAs((cmd_args.GetLArgOutputFile()+".pdf").c_str(),"pdf");

    /* Archivo de ROOT */

    TFile *aFile = new TFile((cmd_args.GetLArgOutputFile()+".root").c_str(), "RECREATE");

    aHist->Write(); // Escribe el archivo de root
    aFile->Close();

    return 0;

}
