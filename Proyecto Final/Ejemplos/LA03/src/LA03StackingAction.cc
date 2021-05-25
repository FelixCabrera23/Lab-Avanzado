/* 
 * LA03StackingAction.cc: Implementación para la clase
 * LA03StackingAction.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA03StackingAction.hh"
#include "LA03EventAction.hh"
#include "LA03DetectorConstruction.hh"

#include "G4VProcess.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4ios.hh"
#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


LA03StackingAction::LA03StackingAction(LA03EventAction* eventAction)
  : G4UserStackingAction(),
  EventAction(eventAction)
{}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA03StackingAction::~LA03StackingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ClassificationOfNewTrack
LA03StackingAction::ClassifyNewTrack(const G4Track * aTrack)
{
  
    if( aTrack->GetParentID() > 0 )
    {
        G4cout << "ID: "  << aTrack->GetTrackID()
            << " Parent ID: " << aTrack->GetParentID()
            << " Particle: " << aTrack->GetDefinition()->GetParticleName()
            << " Creation process: " << aTrack->GetCreatorProcess()->GetProcessName()
            << " Creation volumen: " << aTrack->GetVolume()->GetName()
           << G4endl;
    } 
       
  return fUrgent;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA03StackingAction::NewStage()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA03StackingAction::PrepareNewEvent()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


