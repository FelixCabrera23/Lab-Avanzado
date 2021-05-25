/* 
 * LA03SteppingAction.hh: Header para la clase
 * LA03SteppingAction.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#ifndef LA03SteppingAction_h
#define LA03SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LA03EventAction;

class G4LogicalVolume;

/// Stepping action class
/// 

class LA03SteppingAction : public G4UserSteppingAction
{
  public:
    LA03SteppingAction(LA03EventAction* eventAction);
    virtual ~LA03SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    LA03EventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
