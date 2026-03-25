#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <chrono>
#include "TString.h"
#include "TProfile.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TSystem.h"
#include <TError.h>

#include "RunAction.hh"
#include "WorldConstruction.hh"
#include "TrackPropagation.hh"
#include "PrimaryGeneratorAction.hh"
#include "PhysicsList.hh"

#define geo_size_factor 1E12
#define geo_time_factor 1E18

struct InitialParticleEnergy
{
    TString name;
    Double_t energy;

    InitialParticleEnergy(const TString& nam, Double_t ek)
    {
        name = nam;
        energy = ek;
    }
};

class RunManager
{
public:
    ~RunManager();
    static RunManager* getInstance();
    void ReadParam(const TString&);
    void Initialization();
    void Launch();
    void SaveGeom(const TString&);
    void SetInitialParticleEnergy();
    void SetWorldConstruction(WorldConstruction*);
    void SetRunAction(RunAction*);
    void SetPrimaryGeneratorAction(PrimaryGeneratorAction*);
    void SetTrackPropagation(TrackPropagation*);
    void SetPhysicsList(PhysicsList*);
    void SetTGeoManager(TGeoManager*);
    WorldConstruction* GetWorldConstruction();
    RunAction* GetRunAction();
    PrimaryGeneratorAction* GetPrimaryGeneratorAction();
    TrackPropagation* GetTrackPropagation();
    PhysicsList* GetPhysicsList();
    TGeoManager* GetTGeoManager();
    void SetVisible(bool);
    void SetNumBeams(size_t);
    bool GetVisible();
    size_t GetNumBeams();
    size_t GetGlobalIter();

private:
    RunManager();
    static RunManager* instance;
    RunAction* Run_Action;
    WorldConstruction* Detector_Construction;
    TrackPropagation* Track_Propagation;
    PrimaryGeneratorAction* Primary_GeneratorAction;
    PhysicsList* Physics_List;
    TGeoManager* geometry;
    bool VISIBLE;
    size_t NUM_BEAMs;
    size_t Global_Iter;
    std::vector<InitialParticleEnergy*> List_Of_Initial_Particle_Energy;
    const std::unordered_map<std::string, double> units_map;
};