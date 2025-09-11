#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    auto particleTable = G4ParticleTable::GetParticleTable();
    auto electron = particleTable->FindParticle("e-");

    fParticleGun->SetParticleDefinition(electron);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    fParticleGun->SetParticleEnergy(6.0*MeV);
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
  //  for (G4int i=0; i<5; i++){
    G4double x = G4RandGauss::shoot(0.*cm, 1.0*mm);  // haz gaussiano en x
    G4double y = G4RandGauss::shoot(0.*cm, 1.0*mm);  // haz gaussiano en y
    G4double z = -10.0*cm; 
    fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
    G4double E = G4RandGauss::shoot(6.*MeV, 0.05*MeV);
    fParticleGun->SetParticleEnergy(E);

    fParticleGun->GeneratePrimaryVertex(anEvent);

    //  }
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}
