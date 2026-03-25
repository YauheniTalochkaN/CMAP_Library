#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <omp.h>
#include "TROOT.h"
#include "TGeoManager.h"
#include "TMath.h"
#include "TVirtualGeoTrack.h"

#include "PhysicsList.hh"

class TrackPropagation
{
public:
    TrackPropagation();
    ~TrackPropagation();
    size_t MoveTracks();
    Track* GetTrack(size_t);
    size_t SizeofTrackList();
    void ClearTrackList();
    void SetNumThreads(size_t);
    size_t GetNumThreads();
    Track* NewTrackGeneration();

private:
    size_t pre_num_tasks;
    size_t NUM_THREADs;
    std::vector<Track> ListOfTracks;
};