#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "SecondaryInfo.hh"
#include "G4SystemOfUnits.hh"

#include <vector>
#include <fstream>
#include <map>

class RunAction : public G4UserRunAction{
public :
  RunAction() = default;
  ~RunAction() override = default;

  void BeginOfRunAction(const G4Run* Run) override{
    fSecondaries.clear();

  };

  void EndOfRunAction(const G4Run* Run) override{
    std::map<G4String,int> typeCount;
    std::ofstream outFile("secondary.csv");
    outFile<< "name,ekin_MeV,posX_mm,posY_mm,posZ_mm,"
	   << "momX,momY,momZ,process\n";
    for (auto& sec : fSecondaries) {
      typeCount[sec.name]++;
      outFile << sec.name << ","
	      << sec.ekin/CLHEP::MeV<< ","
	      << sec.pos.x()/CLHEP::mm << ","
	      << sec.pos.y()/CLHEP::mm << ","
	      << sec.pos.z()/CLHEP::mm << ","
	      << sec.mom.x() << ","
	      << sec.mom.y() << ","
	      << sec.mom.z() << ","
	      << sec.proc << "\n";
    };

    outFile.close();
    
    G4cout << "\n=== Secondary particle summary ===\n";
    for (auto& kv : typeCount) {
      G4cout << kv.first << " : " << kv.second << G4endl;
    };
  };

  void RecordSecondary(const G4String& name, G4double ekin,
		       const G4ThreeVector& pos, const G4ThreeVector& mom,
		       const G4String& proc) {
        fSecondaries.push_back({name, ekin, pos, mom, proc});
  };


private :
  std::vector<SecondaryInfo> fSecondaries;
};

  
#endif
