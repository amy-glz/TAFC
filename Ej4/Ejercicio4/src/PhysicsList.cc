#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
//#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
//#include "G4StepLimiterPhysics.hh"
#include "G4SystemOfUnits.hh"


PhysicsList::PhysicsList() 
  : G4VModularPhysicsList() {
  RegisterPhysics(new G4EmStandardPhysics_option4());   
  RegisterPhysics(new G4DecayPhysics());
  //  RegisterPhysics(new G4StepLimiterPhysics());
}

PhysicsList::~PhysicsList() {}
