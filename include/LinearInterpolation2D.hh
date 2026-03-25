#pragma once

#include <iostream>
#include <fstream>
#include "TROOT.h"
#include "TMath.h"
#include "TGraph2D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"

#include "LinearInterpolation.hh"

struct projectionX
{
    Double_t X = 0;
    LinearInterpolation* slice;
    
    projectionX(Double_t data_1, LinearInterpolation* data_2)
    {
        X = data_1;
        slice = data_2;
    }
    
    ~projectionX()
    {
        delete slice;
    }
};

class LinearInterpolation2D
{
public:
    static LinearInterpolation2D* Initialization(const TString&, Double_t, Double_t, Double_t);
    LinearInterpolation2D(std::ifstream*, Double_t, Double_t, Double_t);
    LinearInterpolation2D(const std::vector<projectionX*>&);
    ~LinearInterpolation2D();
    Double_t GetValue(Double_t, Double_t) const;
    LinearInterpolation* GetXProjection(Double_t, bool accumulate = false) const;
    LinearInterpolation* GetYProjection(Double_t) const;
    Double_t GetXmin() const;
    Double_t GetXmax() const;
    Double_t GetYmin() const;
    Double_t GetYmax() const;
    Double_t GetZmin() const;
    Double_t GetZmax() const;

private:
    std::vector<projectionX*> LinInter1DList;
};