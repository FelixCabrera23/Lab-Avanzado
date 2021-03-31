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

    /* Se obtienen los datos del pulso requerido. El pulso que a
     * obtener se especifica en la linea de comandos. */
    pulseData_v = mi_archivo.GetPulse( cmd_args.GetLArgPulseNumber() );

    /* Se verifica que se hayan obtenido correctamente los datos
     * del pulso. */
    if(!pulseData_v)
        return 1;

    /* Los datos solo contienen la información del voltaje medido
     * a intervalos constantes de tiempo. Para fines de graficar
     * se llena otro vector con los indices de tiempo. Para convertir
     * a tiempo real, solo se debe multiplicar el índice por el inverso
     * de la frecuencia de muestreo. */
    for( int i = 0; i < pulseData_v->size(); i++ )
        pulseData_t->push_back(i*8);

    /* Se grafica utilizando una instancia de TGraph de ROOT */
    TGraph *Pulse = new TGraph( pulseData_v->size(), pulseData_t->data(), pulseData_v->data()); // esta el la grafica normal
	  // TGraph *Pulse = new TGraph( 20, pulseData_t->data(),pulseData_v->data()); // esta es para ver los dobles cortos
    Pulse->SetTitle(";time [ns];Signal [mV]"); // Titulo modificado por FCabrera
    /* Se crea un canvas para alojar la gráfica */
	TCanvas *ShowGraph = new TCanvas("Pulse", "RP aqcuire tools", 600, 400);

    Pulse->Draw("AL");
    ShowGraph->Update();
    /* Se almacena la gráfica en un archivo .pdf cuyo nombre se obtiene
     * de los argumentos de la línea de comando. */
	ShowGraph->SaveAs( cmd_args.GetLArgOutputFile().c_str() ,"pdf");

    return 0;

}
