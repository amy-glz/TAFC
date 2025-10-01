#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "globals.hh"
#include <G4VUserActionInitialization.hh>
#include "RunAction.hh"
#include "StackingAction.hh"
#include "SteppingAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
  void Build() const override;
};

#endif
