/* 
 * LA03ActionInitialization.cc: Implementación para la clase
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

#include "LA03ActionInitialization.hh"
#include "LA03PrimaryGeneratorAction.hh"
#include "LA03RunAction.hh"
#include "LA03EventAction.hh"
#include "LA03SteppingAction.hh"
#include "LA03StackingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA03ActionInitialization::LA03ActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA03ActionInitialization::~LA03ActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA03ActionInitialization::BuildForMaster() const
{
  LA03RunAction* runAction = new LA03RunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA03ActionInitialization::Build() const
{
  SetUserAction(new LA03PrimaryGeneratorAction);

  LA03RunAction* runAction = new LA03RunAction;
  SetUserAction(runAction);
  
  LA03EventAction* eventAction = new LA03EventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new LA03SteppingAction(eventAction));
  SetUserAction(new LA03StackingAction(eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
