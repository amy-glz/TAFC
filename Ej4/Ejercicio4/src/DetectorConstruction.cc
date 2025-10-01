//Ejercicio 2 AMY GABRIELA

#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"

G4VPhysicalVolume*DetectorConstruction::Construct(){

  //Obtener el Materiales
  G4NistManager*nist=G4NistManager::Instance();
  G4Material* Vacio      = nist->FindOrBuildMaterial("G4_Galactic");
  G4Material* Aire       = nist->FindOrBuildMaterial("G4_AIR"); 
  G4Material* PhantomMat = nist->FindOrBuildMaterial("G4_WATER");

  //Dimensiones
  G4double worldSize_half   = 200.0 * mm;
  G4double phantomSize_half = 50.0 * mm;
  
  G4ThreeVector woldPos    = G4ThreeVector(0.0,0.0 ,0.0);
  G4ThreeVector PhantomPos = G4ThreeVector(0.0,0.0 ,0.0);

  
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;
  
  //World
  G4Box* WorldBox=new G4Box("World", //Nombre
			    worldSize_half,worldSize_half,worldSize_half);
  
  G4LogicalVolume* WorldLog=new G4LogicalVolume(WorldBox,   //Geometría
						Aire,      //Material
						"World");   //Nombre

  G4VPhysicalVolume* WorldPhys=new G4PVPlacement(nullptr,  // no rotation
					       {},  // at (0,0,0)
					       WorldLog,  // its logical volume
					       "World",  // its name
					       0,  // its mother  volume
					       false,  // no boolean operation
					       0,  // copy number
					       checkOverlaps);
  G4cout << "World half-sizes (mm): " 
       <<worldSize_half/mm << " " << worldSize_half/mm << " " << worldSize_half/mm << G4endl;
  
  G4VisAttributes* visAtr=new G4VisAttributes;
  visAtr->SetVisibility(false);
  WorldLog->SetVisAttributes(visAtr);

  WorldPhys->CheckOverlaps(1000, 0.0, true);

  
  //Fantoma
  G4Box* PhantomBox=new G4Box("Phantom",
			      phantomSize_half,phantomSize_half,phantomSize_half);

  G4LogicalVolume* PhantomLog=new G4LogicalVolume(PhantomBox,
						  PhantomMat,
						  "Phantom");
  
  G4VPhysicalVolume* PhantomPhys=new G4PVPlacement(nullptr,
						  PhantomPos,
						  PhantomLog,
						  "Phantom",
						  WorldLog,
						  false,
						   0,
						  checkOverlaps);

  G4VisAttributes* PhanAtr = new G4VisAttributes(G4Colour::Cyan());
  PhanAtr->SetVisibility(true);
  PhanAtr->SetForceSolid(true);
  PhantomLog->SetVisAttributes(PhanAtr);

  G4cout << "Phantom half-sizes (mm): " 
       << phantomSize_half/mm << " " << phantomSize_half/mm << " " << phantomSize_half/mm << G4endl;
  G4cout << "Phantom center (mm): " << PhantomPos/mm << G4endl;

  
  return WorldPhys;
};

DetectorConstruction::DetectorConstruction() {};

DetectorConstruction::~DetectorConstruction() {};
