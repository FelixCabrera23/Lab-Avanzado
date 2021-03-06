/*
 * LA01RunAction.hh: Header para la clase
 * LA01RunAction.
 *
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 *
 * Héctor Pérez
 * abril 2021
 *
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 */

#ifndef LA01RunAction_h
#define LA01RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

class G4Run;

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.

class LA01RunAction : public G4UserRunAction
{
  public:
    LA01RunAction();
    virtual ~LA01RunAction();

    // virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

    void AddEdep (G4double edep);

  private:
    G4Accumulable<G4double> fEdep;
    G4Accumulable<G4double> fDistance;
};

#endif
