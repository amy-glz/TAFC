#ifdef StackingAction_h
#define StackingAction_h 1

#include "G4UserStackingAction.hh"
#include "RunAction.hh"

class StackingAction : public G4UserStackingAction{
public:
  StackingAction(G4Run* Run): fRunAction(Run){}

  G4ClassificationOfNewTrack ClassifyNewTrack(const Track* trk) override {
    if trk -> (GetParentID()>0){
	auto name = trk->GetDefinition()->GetParticleName();
	auto ekin = trk->GetKineticEnery();
	auto pos  = trk->GetPosition();
	auto mom  = trk->GetMomentumDirection();
	auto proc = trk->GetCreatorProcess() ?
	            trk->GetCreatorProcess()->GetProcessName(): "primary";

	fRunAction-> RecordSecondary(name, ekin, pos, mom, proc);
	
      }
    return fUrgent;
  }
  
private:

  RunAction*fRunAction;
};

#endif
