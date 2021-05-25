/* 
 * LA03ActionInitialization.hh: Header para la clase
 * LA03ActionInitialization.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#ifndef LA03ActionInitialization_h
#define LA03ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class LA03ActionInitialization : public G4VUserActionInitialization
{
  public:
    LA03ActionInitialization();
    virtual ~LA03ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
