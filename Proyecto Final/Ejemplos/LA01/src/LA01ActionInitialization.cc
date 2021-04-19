/* 
 * LA01ActionInitialization.cc: Implementación para la clase
 * LA01ActionInitialization.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA01ActionInitialization.hh"
#include "LA01PrimaryGeneratorAction.hh"
#include "LA01RunAction.hh"
#include "LA01EventAction.hh"
#include "LA01SteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA01ActionInitialization::LA01ActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA01ActionInitialization::~LA01ActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA01ActionInitialization::BuildForMaster() const
{
  LA01RunAction* runAction = new LA01RunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA01ActionInitialization::Build() const
{
  SetUserAction(new LA01PrimaryGeneratorAction);

  LA01RunAction* runAction = new LA01RunAction;
  SetUserAction(runAction);
  
  LA01EventAction* eventAction = new LA01EventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new LA01SteppingAction(eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
