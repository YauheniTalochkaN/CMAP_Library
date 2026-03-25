#pragma once

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
    void SetParticleEnergy(const TString&, Double_t);
};