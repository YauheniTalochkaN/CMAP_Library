#pragma once

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TMath.h"
#include "TString.h"

#include "LinearInterpolation.hh"

struct shell
{
    TString shell_name = "";
    Double_t shell_energy = 0;
    std::vector<std::tuple<TString, Double_t, LinearInterpolation*>> radiation_transitions;
    std::vector<std::pair<TString, Double_t>> nonradiation_transitions;

    shell(const TString& nam, Double_t energy, const std::tuple<TString, Double_t, LinearInterpolation*>* rad_times = nullptr, 
          size_t num1 = 0, const std::pair<TString, Double_t>* nonrad_times = nullptr, size_t num2 = 0) 
    {
        shell_name = nam;
        shell_energy = energy;

        for (size_t i = 0; i < num1; ++i)
        {
            radiation_transitions.push_back(rad_times[i]);
        }

        for (size_t i = 0; i < num2; ++i)
        {
            nonradiation_transitions.push_back(nonrad_times[i]);
        }
    }

    ~shell()
    {
        for(auto [level, trad, line] : radiation_transitions)
        {
            if(line != nullptr)
            {
                delete line;
            }
        }
    }
};

struct Container_ccr
{
    TString full_particle_name,
            center_name, center_type;
    LinearInterpolation* rate = nullptr;
    
    Container_ccr(const TString& pnam, const TString& cnam, const TString& ctype, LinearInterpolation* crate)
    {
        full_particle_name = pnam;
        center_name = cnam;
        center_type = ctype;
        rate = crate;
    }
    
    ~Container_ccr()
    {
        if(rate != nullptr) delete rate;
    }
};

class CenterProperties
{
public:
    CenterProperties(const TString&);
    ~CenterProperties(); 
    void SetName(const TString&);
    void SetGroundState(const TString&);
    void SetLevel(shell*);
    void SetCaptureRate(Container_ccr*);  
    TString GetName() const;
    TString GetGroundState() const;
    const shell* GetLevel(const TString&) const;
    std::vector<const Container_ccr*> GetCaptureRates(const TString&) const;

private:
    TString Name = "", ground = "";
    std::vector<shell*> Level_List;
    std::vector<Container_ccr*> Capture_Rates;
};