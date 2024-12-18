#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include <iostream>
#include "TROOT.h"
#include "TMath.h"
#include "TVirtualGeoTrack.h"

class PrimaryGeneratorAction
{
  public:
   PrimaryGeneratorAction();
   virtual ~PrimaryGeneratorAction();
   virtual void GeneratePrimaries() = 0;
   void SetParticleEnergy(TString, Double_t);
};

#endif