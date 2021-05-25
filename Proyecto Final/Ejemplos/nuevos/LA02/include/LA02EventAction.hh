/* 
 * LA02EventAction.hh: Header para la clase
 * LA02EventAction.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */


#ifndef LA02EventAction_h
#define LA02EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class LA02RunAction;

/// Event action class
///

class LA02EventAction : public G4UserEventAction
{
  public:
    LA02EventAction(LA02RunAction* runAction);
    virtual ~LA02EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }

  private:
    LA02RunAction* fRunAction;
    G4double     fEdep;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
