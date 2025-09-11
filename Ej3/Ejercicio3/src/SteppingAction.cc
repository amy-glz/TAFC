#include "SteppingAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"

void SteppingAction::UserSteppingAction(const G4Step* step){
  G4Track* track = step->GetTrack();
  if (track->GetNextVolume()==nullptr){
    track->SetTrackStatus(fStopAndKill);
  }
}

//SteppingAction::SteppingAction() {}

//SteppingAction::~SteppingAction() {}
