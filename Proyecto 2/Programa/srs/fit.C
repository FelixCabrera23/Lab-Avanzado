/* Script para hacer fit a los datos de la vida media del muon */

#include "TGraph.h"
#include "TCanvas.h"
/* Para hacer histogramas */
#include "TH1D.h"
/* Para guardar histogramas */
#include "TFile.h"
#include "TF1.h"

void Fit_muon()
{
  TFile *aFile = new TFile("histo_sum.root"); // Llamamos el archivo que necesitamos
  TH1D *aHist; // Definimos el puntero al histograma
  aHist = (TH1D*)aFile->Get("Datos"); // Cargamos el puntero con el contenido dentro del archivo.
  aHist->SetXTitle("tiempo [ns]"); // Le ponemos etiqueta al eje X
  aHist->SetYTitle("coincidencias");
  TF1 *expn = new TF1("expn", "[0]*TMath::Exp(-x/[1])+[2]",0,9000);
  expn->SetParNames("A","T","C");
  expn->SetParameters(1000,2000,5);
  aHist->Fit(expn);

  // Estos son los resultados para que los ponga en la grafica
  TFitResultPtr resultados = aHist->Fit("expn","QS");

  // estos los pone en pantalla
  resultados->Print("V");

  // Aqui sacamos la información importante de las matrices y resultados anteriores
  std::cout<< "Chi2/NDF: " << resultados->Chi2()/resultados->Ndf() << std::endl;
  std::cout<< "T: " << resultados->Parameter(1) << std::endl;
  std::cout<< "error en T: " << resultados->ParError(1) << std::endl;

}
