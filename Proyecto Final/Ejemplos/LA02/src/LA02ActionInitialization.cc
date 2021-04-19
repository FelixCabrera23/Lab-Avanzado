/* 
 * LA02ActionInitialization.cc: Implementación para la clase
 * LA02ActionInitialization.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA02ActionInitialization.hh"
#include "LA02PrimaryGeneratorAction.hh"
#include "LA02RunAction.hh"
#include "LA02EventAction.hh"
#include "LA02SteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02ActionInitialization::LA02ActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02ActionInitialization::~LA02ActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA02ActionInitialization::BuildForMaster() const
{
  LA02RunAction* runAction = new LA02RunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA02ActionInitialization::Build() const
{
  SetUserAction(new LA02PrimaryGeneratorAction);

  LA02RunAction* runAction = new LA02RunAction;
  SetUserAction(runAction);
  
  LA02EventAction* eventAction = new LA02EventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new LA02SteppingAction(eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
