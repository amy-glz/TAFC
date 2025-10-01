#include "SteppingAction.hh"
#include "RunAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VProcess.hh"

#include <vector>

void SteppingAction::UserSteppingAction(const G4Step* step) {
  const std::vector<const G4Track*>* secs= step -> GetSecondaryInCurrentStep();

  for (const G4Track* trk: *secs){
    G4String     name = trk->GetDefinition()->GetParticleName();
    G4double     ekin = trk->GetKineticEnergy();
    G4ThreeVector pos = trk->GetPosition(); 
    G4ThreeVector mom = trk->GetMomentum();
    G4String     proc = trk->GetCreatorProcess() ?
                        trk->GetCreatorProcess()->GetProcessName() : "Unknown";
    fRunAction->RecordSecondary(name, ekin, pos, mom, proc);
  }

  G4Track* track =step->GetTrack();
  if (track->GetNextVolume()==nullptr){
    track->SetTrackStatus(fStopAndKill);
  }

}

//SteppingAction::SteppingAction() {}

//SteppingAction::~SteppingAction() {}
