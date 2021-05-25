/* 
 * LA02DetectorConstruction.cc: Implementación para la clase
 * LA02DetectorConstrucion.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA02DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02DetectorConstruction::LA02DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02DetectorConstruction::~LA02DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* LA02DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
   
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  //
  G4double world_sizeX = 2*m;
  G4double world_sizeY = 2*m;
  G4double world_sizeZ = 2*m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeX, 0.5*world_sizeY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
 
 
  //     
  // Target
  //  
  G4ThreeVector pos = G4ThreeVector(0, 0, 55*cm);
        
  G4double target_sizeX = 20*cm;
  G4double target_sizeY = 20*cm;
  G4double target_sizeZ = 20*cm;
  G4Material* target_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4Box* solidTarget =    
    new G4Box("Target",                       //its name
       0.5*target_sizeX, 0.5*target_sizeY, 0.5*target_sizeZ);
                      
  G4LogicalVolume* logicTarget =                         
    new G4LogicalVolume(solidTarget,         //its solid
                        target_mat,          //its material
                        "Target");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    pos,                    //at position
                    logicTarget,             //its logical volume
                    "Target",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  
                
  // Set Target as scoring volume
  //
  fScoringVolume = logicTarget;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
