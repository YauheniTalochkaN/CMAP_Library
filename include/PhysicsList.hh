#pragma once

#include <iostream>
#include <thread>
#include <omp.h>
#include <list>
#include <utility>
#include "TROOT.h"
#include "TGeoManager.h"
#include "TGeoNode.h"
#include "TLine.h"
#include "TMath.h"
#include "TString.h"
#include "TRandom3.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TMatrixD.h"
#include "TVirtualGeoTrack.h"

#include "LinearInterpolation.hh"
#include "MaterialProperties.hh"
#include "Track.hh"
#include "Tensor.hh"

constexpr Double_t const_c = 299792458.0;
constexpr Double_t const_hr = 1.054571817E-34;
constexpr Double_t const_e = 1.60217662E-19;
constexpr Double_t const_me = 9.10938356E-31;
constexpr Double_t const_k = 8.9875517873681764E9;
constexpr Double_t const_kB = 1.380649E-23;
constexpr Double_t const_Ry = 2.179872361103542E-18;
constexpr Double_t unit_J = 1.0;
constexpr Double_t unit_K = 1.0;
constexpr Double_t unit_meV = 1.60217662E-22;
constexpr Double_t unit_eV = 1.60217662E-19;
constexpr Double_t unit_keV = 1.60217662E-16;
constexpr Double_t unit_MeV = 1.60217662E-13;
constexpr Double_t unit_m = 1.0;
constexpr Double_t unit_cm = 1.0E-2;
constexpr Double_t unit_mm = 1.0E-3;
constexpr Double_t unit_mkm = 1.0E-6;
constexpr Double_t unit_nm = 1.0E-9;
constexpr Double_t unit_A = 1.0E-10;
constexpr Double_t unit_s = 1.0;
constexpr Double_t unit_mks = 1.0E-6;
constexpr Double_t unit_ns = 1.0E-9;
constexpr Double_t unit_ps = 1.0E-12;
constexpr Double_t unit_fs = 1.0E-15;
constexpr Double_t unit_V = 1.0;
constexpr Double_t unit_kV = 1.0E3;
constexpr Double_t unit_MV = 1.0E6;
constexpr Double_t unit_T = 1.0;
constexpr Double_t unit_mT = 1.0E-3;
constexpr Double_t unit_mkT = 1.0E-6;

class PhysicsList
{
public:
    PhysicsList();
    ~PhysicsList();
    void UpdateTimeCut();
    void SetEHGlobalTime(Double_t);
    Double_t GetEHGlobalTime();
    void SetTGeoTrack(Track*);
    void SetElectricFieldStrength(const TVector3&);
    TVector3 GetElectricFieldStrength();
    void SetMagneticFieldInduction(const TVector3&);
    TVector3 GetMagneticFieldInduction();
    void DrawTrack(Track*);
    TVector3 RandomTVector3();
    Double_t RandomValue(const LinearInterpolation*, Double_t, Double_t);
    Double_t GetDistanceBetweenTwoTracks(const TVector3&, const TVector3&, const TVector3&, const TVector3&);
    size_t DiscreteRandomValue(const std::vector<Double_t>&);
    TString GetTGeoVolumeAtPoint(const TVector3&);
    Double_t GenerateInelasticScatteringEnergy(Double_t, Double_t, const TString&);
    void GenerateVectorInElasticScattering(Double_t, Double_t, const TVector3&, TVector3&);
    bool GenerateVectorInInelasticScattering(Double_t, Double_t, Double_t, const TVector3&, TVector3&, TVector3&);
    void GenerateVectorInPhononScattering(Double_t, Double_t, Double_t, const TVector3&, TVector3&);
    void ElasticScattering(Track*, const size_t&);
    void PhononScattering(Track*, const size_t&);
    void InelasticScattering(Track*, const size_t&);
    void InelasticHoleScattering(Track*);
    void ElectronHoleInteraction(const std::vector<Track*>&);
    void RadiationDecayOfExciton(Track*);
    void DecayOfCenter(Track*, const TString&, const TString&, Double_t, bool, const LinearInterpolation*);
    void ExcitonDissociation(Track*);
    void CaptureParticleByCenter(Track*, const TString&, const TString&, Double_t);
    void UpdateVelocity(Track*);
    void UpdateMass(Track*);
    Double_t CalculateMomentum(Double_t, Double_t);
    Double_t CalculateVelocity(Double_t, Double_t);
    void ApplySingleTrackProcesses(std::vector<Track>&);
    void WhichProcesse(Track*);
    void ApplyMultiTrackProcesses(std::vector<Track>&);
    void ParticleStep(std::vector<Track>&, const size_t&);
    Track* CreateElectron(const TrackPoint&, const TString& type = "", TString volume_name = "", MaterialProperties* mp = nullptr, bool loc = false);
    Track* CreateHole(const TrackPoint&, const TString& type = "", TString volume_name = "", MaterialProperties* mp = nullptr, bool loc = false);
    Track* CreateExciton(const TrackPoint&, const TString& type = "", TString volume_name = "", MaterialProperties* mp = nullptr, Double_t mex = 2.0*const_me, bool loc = false);
    Track* CreatePhoton(const TrackPoint&, TString volume_name = "", MaterialProperties* mp = nullptr, bool loc = false);
    Track* CreateCenter(const TrackPoint&, const TString&, const TString&, TString volume_name = "", MaterialProperties* mp = nullptr, bool loc = false);

private:
    Double_t TIME_CUT_eh, EH_GLOBAL_TIME;
    TVector3 Electric_Field_Strength, Magnetic_Field_Induction;
};