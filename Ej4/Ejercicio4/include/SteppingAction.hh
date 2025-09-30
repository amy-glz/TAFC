#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4Step;
class G4Track;

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(RunAction* run) : fRunAction(run) {};
  ~SteppingAction() override {};
  void UserSteppingAction(const G4Step* step) override{
    auto secs = step->GetSecondaryInCurrentStep();
    for (const auto* trk : *secs) {
      auto name = trk->GetDefinition()->GetParticleName();
      auto ekin = trk->GetKineticEnergy();
      auto pos  = trk->GetPosition();
      auto mom  = trk->GetMomentumDirection();
      auto proc = trk->GetCreatorProcess() ?
                  trk->GetCreatorProcess()->GetProcessName() : "unknown";

      fRunAction->RecordSecondary(name, ekin, pos, mom, proc);
  };

private:
    RunAction*fRunAction;
};

#endif

