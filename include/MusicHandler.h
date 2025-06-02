#pragma once
#include "TrackPlayer.h"
#include <vector>
#include <memory>

class MusicHandler {
public:
    MusicHandler(size_t numTracks);

    // Add a TrackPlayer at a given index
    void setTrackPlayer(size_t index, std::unique_ptr<TrackPlayer> player);
    TrackPlayer* getTrackPlayer(size_t index) const;
    size_t getNumTracks() const;

    // Mix all tracks into the output buffer
    void mix(float* output, size_t len, trackPosition pos);

private:
    std::vector<std::unique_ptr<TrackPlayer>> trackPlayers;
};
