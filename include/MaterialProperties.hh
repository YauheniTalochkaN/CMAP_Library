#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "TROOT.h"
#include "TMath.h"
#include "TString.h"

#include "LinearInterpolation.hh"
#include "LinearInterpolation2D.hh"
#include "CenterProperties.hh"

struct Container
{
    LinearInterpolation* func = nullptr;
    TString full_particle_name = "";
    
    Container(const TString& name, LinearInterpolation* data)
    {
        func = data;
        full_particle_name = name;
    }

    ~Container()
    {
        delete func;
    }
};

struct Container_imfp
{
    LinearInterpolation* imfp = nullptr;
    TString full_particle_name = "";
    LinearInterpolation* els = nullptr;

    Container_imfp(const TString& name, LinearInterpolation* data_1, LinearInterpolation* data_2)
    {
        imfp = data_1;
        full_particle_name = name;
        els = data_2;
    }

    ~Container_imfp()
    {
        delete imfp;
        delete els;
    }
};

struct Container_emfp
{
    LinearInterpolation* ait = nullptr;
    TString full_particle_name = "";
    LinearInterpolation2D* mls = nullptr;

    Container_emfp(const TString& name, LinearInterpolation* data_1, LinearInterpolation2D* data_2)
    {
        ait = data_1;
        full_particle_name = name;
        mls = data_2;
    }

    ~Container_emfp()
    {
        delete ait;
        delete mls;    
    }
};

struct Container_ait
{
    LinearInterpolation* ait = nullptr;
    TString full_particle_name = "";
    LinearInterpolation2D* mls = nullptr;
    LinearInterpolation* displow = nullptr;

    Container_ait(const TString& name, LinearInterpolation* data_1, LinearInterpolation2D* data_2, LinearInterpolation* data_3)
    {
        ait = data_1;
        full_particle_name = name;
        mls = data_2;
        displow = data_3;
    }

    ~Container_ait()
    {
        delete ait;
        delete mls;
        delete displow;
    }
};

struct Container_exadt
{
    LinearInterpolation* ait = nullptr;
    LinearInterpolation2D* des = nullptr;
    
    Container_exadt(LinearInterpolation* data_1, LinearInterpolation2D* data_2)
    {
        ait = data_1;
        des = data_2;
    }
    
    ~Container_exadt()
    {
        delete ait;
        delete des;
    }
};


class MaterialProperties
{
public:
    MaterialProperties();
    ~MaterialProperties();
    void SetBandGap(Double_t);
    void SetDielectricPermittivity(Double_t);
    void SetExcitonBondEnergy(Double_t);
    void SetEffectiveMass(Container*);
    void SetUnitCellVolume(Double_t);
    void SetDensityOfStates(LinearInterpolation*);
    void SetGroupVelocity(Container*);
    void SetInelasticMeanFreePath(Container_imfp*);
    void SetElasticMeanFreePath(Container_emfp*);
    void SetPhononAverageInteractionTime(Container_ait*);
    void SetRadiationDecayTimeOfExciton(LinearInterpolation*);
    void SetElectronHoleRadiationRecombinationTime(LinearInterpolation2D*);
    void SetExcitonDissociationTime(Container_exadt*);
    void SetCenterProperties(CenterProperties*);
    Double_t GetBandGap();
    Double_t GetDielectricPermittivity();
    Double_t GetExcitonBondEnergy();
    Double_t GetUnitCellVolume();
    const LinearInterpolation* GetEffectiveMass(const TString&);
    const LinearInterpolation* GetDensityOfStates();
    const LinearInterpolation* GetCDFOfStates();
    const LinearInterpolation* GetGroupVelocity(const TString&);
    std::vector<const Container_imfp*> GetListOfInelasticMeanFreePath(const TString&);
    std::vector<const Container_emfp*> GetListOfElasticAverageInteractionTime(const TString&);
    std::vector<const Container_ait*> GetListOfPhononAverageInteractionTime(const TString&);
    const LinearInterpolation* GetRadiationDecayTimeOfExciton();
    const LinearInterpolation2D* GetElectronHoleRadiationRecombinationTime();
    const Container_exadt* GetExcitonDissociationTime();
    std::vector<const CenterProperties*> GetCenterList();
    const CenterProperties* GetCenter(const TString&);

private:
    Double_t Band_gap = 0;
    Double_t Unit_Cell_Volume = 0;
    Double_t Dielectric_Permittivity = 1;
    Double_t Exciton_Bond_Energy = 0;
    std::vector<Container*> Effective_Mass;
    LinearInterpolation* Density_Of_States = nullptr;
    LinearInterpolation* CDF_Of_States = nullptr;
    std::vector<Container*> Group_Velocity;
    std::vector<Container_imfp*> Inelastic_Mean_Free_Paths;
    std::vector<Container_emfp*> Elastic_Mean_Free_Path;
    std::vector<Container_ait*> Phonon_Average_Interaction_Time; 
    LinearInterpolation* Radiation_Decay_Time_Of_Exciton = nullptr;
    LinearInterpolation2D* Electron_Hole_Radiation_Recombination_Time = nullptr;
    Container_exadt* Exciton_Dissociation_Time = nullptr;
    std::vector<CenterProperties*> List_Of_Centers;
};