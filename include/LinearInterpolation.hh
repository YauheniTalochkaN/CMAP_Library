#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "TROOT.h"
#include "TMath.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TFile.h"
#include "TCanvas.h"

class LinearInterpolation
{
public:
    LinearInterpolation(const Double_t*, const Double_t*, size_t);
    LinearInterpolation(const std::vector<Double_t>&, const std::vector<Double_t>&);
    static LinearInterpolation* Initialization(const TString&, Double_t, Double_t);
    LinearInterpolation(std::ifstream*, Double_t, Double_t);
    ~LinearInterpolation();
    Double_t GetValue(Double_t) const;
    LinearInterpolation* Accumulate() const;
    Double_t GetXmin() const;
    Double_t GetXmax() const;
    Double_t GetYmin() const;
    Double_t GetYmax() const;
    size_t GetNBins() const;
    const Double_t* GetXMass() const;
    const Double_t* GetYMass() const;

private:
    Double_t *MASSXX;
    Double_t *MASSYY;
    size_t    NUMBINS;
    Double_t  YMIN;
    Double_t  YMAX;
};