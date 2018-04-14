

#include <G4Colour.hh>
#include "DetGeometry.hh"
#include "G4VisAttributes.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * mm;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Box *box = new G4Box("box", 4, 4, 4);
    G4LogicalVolume *box_log = new G4LogicalVolume(box, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "logicWorld");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(0, G4ThreeVector(0,0,0), box_log, "box_log", logicWorld, false, 0);

    return physWorld;
}


