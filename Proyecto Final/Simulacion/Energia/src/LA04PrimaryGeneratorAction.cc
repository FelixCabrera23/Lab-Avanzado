/*
 * LA04PrimaryGeneratorAction.cc: Implementación para la clase
 * LA04PrimaryGeneratorAction.
 *
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 *
 * Héctor Pérez
 * abril 2021
 *
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#include "LA04PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "Randomize.hh"

#include <cmath>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA04PrimaryGeneratorAction::LA04PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="gamma");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(150.*keV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA04PrimaryGeneratorAction::~LA04PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LA04PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of ecah event
  //

  // G4double x0 = 0;
  // G4double y0 = 0;

  /* Punto de lanzamiento aleatorio
   *
   * El punto de lanzamiento está sobre un cuadrado
   * de tamaño sizeXY pero a un z constante */
  // G4double sizeXY = 10*cm;
  // G4double x0 = sizeXY * (G4UniformRand()-0.5);
  // G4double y0 = sizeXY * (G4UniformRand()-0.5);
  // G4double z0 = -55*cm;

  // // Generando numeros aleatorios en un cilindro de radio 15 mm y altura 1 mm
  // G4double r = 15*mm;
  // G4double h = 1*mm;
  // G4double ang = 360*(G4UniformRand());
  //
  // G4double x0 = r*std::cos(ang);
  // G4double y0 = r*std::sin(ang);
  // G4double z0 = h*(G4UniformRand() -0.5);
  //
  // fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  //
  // /* Dirección aleatoria */
  //
  // G4double theta = twopi * G4UniformRand();
  // G4double phi = pi * G4UniformRand();
  //
  // fParticleGun->SetParticleMomentumDirection(G4ThreeVector( std::sin(theta)*std::cos(phi), std::sin(theta)*std::sin(phi), std::cos(theta)));

  // Dirección fija para Eficiencia en Energia

  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,1.));

  // Dejar este descomentado si la energia no es aleatoria
  fParticleGun->GeneratePrimaryVertex(anEvent);

  // Energia aleatoria

  // G4double RanEng = 100 + G4UniformRand()*1400;

  // fParticleGun->SetParticleEnergy(RanEng*keV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
