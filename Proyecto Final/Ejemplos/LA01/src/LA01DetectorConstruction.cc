/*
 * LA01DetectorConstruction.cc: Implementación para la clase
 * LA01DetectorConstrucion.
 *
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 *
 * Héctor Pérez
 * abril 2021
 *
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA01DetectorConstruction.hh"

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

// Para el tubo
#include "G4Tubs.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA01DetectorConstruction::LA01DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA01DetectorConstruction::~LA01DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* LA01DetectorConstruction::Construct()
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


  //  ******** Modificando para hacer un cilindro
  // Descomentar todo lo que esta a continucaión

  G4ThreeVector pos = G4ThreeVector(0, 0, 55*cm);
  G4Material* target_mat = nist->FindOrBuildMaterial("G4_Al");
  // Añadimos una matriz de rotación
  G4RotationMatrix *RotMat = new G4RotationMatrix();
  RotMat -> rotateY(-90*deg);
  // ****** Caja *******

  // G4double target_sizeX = 20*cm;
  // G4double target_sizeY = 20*cm;
  // G4double target_sizeZ = 20*cm;

  // G4Box* solidTarget =
  //   new G4Box("Target",                       //its name
  //      0.5*target_sizeX, 0.5*target_sizeY, 0.5*target_sizeZ);

  // ******* Cilindro **********

  G4double rad_in = 0*cm;
  G4double rad_out = 5*cm;
  G4double h_z = 10*cm;
  G4double ang_o = 0;
  G4double ang_e = 360*deg;

  G4Tubs* solidTarget =
    new G4Tubs ("Target",
        rad_in, rad_out, h_z, ang_o, ang_e);

  // ****** fin del cilindro

  //
  G4LogicalVolume* logicTarget =
     new G4LogicalVolume(solidTarget,         //its solid
                         target_mat,          //its material
                         "Target");           //its name

   new G4PVPlacement(RotMat,                       //no rotation
                     pos,                    //at position
                     logicTarget,             //its logical volume
                     "Target",                //its name
                     logicWorld,                //its mother  volume
                     false,                   //no boolean operation
                     0,                       //copy number
                     checkOverlaps);          //overlaps checking

  // Agua dentro del aluminio

  G4ThreeVector pos2 = G4ThreeVector(0, 0, -1*cm);
  G4Material* target2_mat = nist->FindOrBuildMaterial("G4_WATER");

  G4double rad_in2 = 0*cm;
  G4double rad_out2 = 4.5*cm;
  G4double h_z2 = 9*cm;
  G4double ang_o2 = 0;
  G4double ang_e2 = 360*deg;

  G4Tubs* solidTarget2 =
    new G4Tubs ("Target2",
        rad_in2, rad_out2, h_z2, ang_o2, ang_e2);

          G4LogicalVolume* logicTarget2 =
             new G4LogicalVolume(solidTarget2,         //its solid
                                 target2_mat,          //its material
                                 "Target2");           //its name

           new G4PVPlacement(0,                       //no rotation
                             pos2,                    //at position
                             logicTarget2,             //its logical volume
                             "Target2",                //its name
                             logicTarget,                //its mother  volume
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
