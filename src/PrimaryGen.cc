
#include <Randomize.hh>
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen()
{
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
}

PrimaryGen::~PrimaryGen() {
    delete gun;
}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent){
    G4double pX, pY, pZ, R{1*cm};
    do {
        pX = (2*G4UniformRand()-1)*cm;
        pY = (2*G4UniformRand()-1)*cm;
        pZ = (2*G4UniformRand()-1)*cm;
    } while ((pX*pX+pY*pY+pZ*pZ)>R);
    gun->SetParticlePosition(G4ThreeVector(pX,pY-10*cm,pZ));


    G4double X{2*G4UniformRand()-1}, Y{2*G4UniformRand()-1}, Z{2*G4UniformRand()-1};
    G4double l = sqrt(X*X+Y*Y+Z*Z);
    gun->SetParticleMomentum(G4ThreeVector(X/l,Y/l,Z/l));
    gun->SetParticleEnergy(0.662*MeV);
    gun->GeneratePrimaryVertex(anEvent);

}