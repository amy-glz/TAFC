#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "StackingAction.hh"

void ActionInitialization::Build() const
{
  auto runAction = new RunAction();
  SetUserAction(runAction);  
  SetUserAction(new PrimaryGeneratorAction());
  SetUserAction(new SteppingAction(runAction));
  SetUserAction(new StackingAction(runAction));

}

