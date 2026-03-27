#pragma once

#include <iostream>
#include <fstream>
#include "TROOT.h"
#include "TMath.h"
#include "TGraph2D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"

#include "LinearInterpolation2D.hh"

struct sliceYZ
{
    Double_t X = 0;
    LinearInterpolation2D* surface;
    
    sliceYZ(Double_t data_1, LinearInterpolation2D* data_2)
    {
        X = data_1;
        surface = data_2;
    }
    
    ~sliceYZ()
    {
        delete surface;
    }
};

class LinearInterpolation3D
{
public:
    static LinearInterpolation3D* Initialization(const TString&, Double_t, Double_t, Double_t, Double_t);
    LinearInterpolation3D(std::ifstream*, Double_t, Double_t, Double_t, Double_t);
    ~LinearInterpolation3D();
    Double_t GetValue(Double_t, Double_t, Double_t) const;
    Double_t GetXmin() const;
    Double_t GetXmax() const;

private:
    std::vector<sliceYZ*> LinInter2DList;
};