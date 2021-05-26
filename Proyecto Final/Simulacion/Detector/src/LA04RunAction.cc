/*
 * LA04RunAction.cc: Implementación para la clase
 * LA04RunAction.
 *
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 *
 * Héctor Pérez
 * abril 2021
 *
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA04RunAction.hh"
#include "LA04PrimaryGeneratorAction.hh"
#include "LA04DetectorConstruction.hh"
#include "LA04Analysis.hh"
// #include "LA04Run.hh"

#include <fstream>

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA04RunAction::LA04RunAction()
: G4UserRunAction(),
  fEdep(0.),
  fDistance(0.),
  fElectron(0.)
{
  // Register accumulable to the accumulable manager
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->RegisterAccumulable(fEdep);
  accumulableManager->RegisterAccumulable(fDistance);
  accumulableManager->RegisterAccumulable(fElectron);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA04RunAction::~LA04RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA04RunAction::BeginOfRunAction(const G4Run*)
{
  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();

  // Hciendo los histogramas
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
  // Open an output file
  analysisManager->OpenFile("LA04");

// Creating histograms
analysisManager->CreateH1("LA04","Electrons detected", 100, 100.*keV, 1500.*keV);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA04RunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  // Merge accumulables
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Merge();

  G4double edep  = fEdep.GetValue();
  G4double Distance  = fDistance.GetValue();
  // Añadimos los conteos golbales de electrones
  G4double Electrones = fElectron.GetValue();

  // Run conditions
  //  note: There is no primary generator action object for "master"
  //        run manager for multi-threaded mode.
  const LA04PrimaryGeneratorAction* generatorAction
   = static_cast<const LA04PrimaryGeneratorAction*>
     (G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
  G4String runCondition;
  if (generatorAction)
  {
    const G4ParticleGun* particleGun = generatorAction->GetParticleGun();
    runCondition += particleGun->GetParticleDefinition()->GetParticleName();
    runCondition += " of ";
    G4double particleEnergy = particleGun->GetParticleEnergy();
    runCondition += G4BestUnit(particleEnergy,"Energy");
  }

  // Print
  //
  if (IsMaster()) {
    G4cout
     << G4endl
     << "--------------------End of Global Run-----------------------";
  }
  else {
    G4cout
     << G4endl
     << "--------------------End of Local Run------------------------";
  }

  G4cout
     << G4endl
     << " The run consists of " << nofEvents << " "<< runCondition
     << G4endl
     << " Energy deposited per run, in scoring volume : "
     << G4BestUnit(edep,"Energy")
     << " Distance traveled per run, in scoring volume : "
     << G4BestUnit(Distance,"Length")
     << "Electrons detected : "
     << Electrones
     << G4endl
     << "------------------------------------------------------------"
     << G4endl
     << G4endl;

     // Guardando los histogramas

     auto analysisManager = G4AnalysisManager::Instance();
     analysisManager->Write();
     analysisManager->CloseFile();

     // Escribiendo a archivo

     const G4ParticleGun* particleGun = generatorAction->GetParticleGun();
     G4double particleEnergy = particleGun->GetParticleEnergy();

     std::ofstream file;
     file.open("Eficiencia_energia.txt",std::ios::app),
     file << particleGun->GetParticleEnergy()<<","<< G4BestUnit(particleEnergy,"Energy") <<","<<nofEvents << "," << Electrones << std::endl;
     file.close();


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA04RunAction::AddEdep(G4double edep)
{
  fEdep  += edep;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA04RunAction::AddDistance(G4double distance)
{
  fDistance  += distance;
}

// Agregamos la funcion para sumar electrones
void LA04RunAction::AddElectron(G4double electron)
{
  fElectron += electron;
}
