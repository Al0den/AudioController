#pragma once
#include "Track.h"

struct EQParameters {
    float low = 0.0f;
    float mid = 0.0f;
    float high = 0.0f;
};

class TrackPlayer {
public:
    TrackPlayer(const Track& track);

    void setPaused(bool p);
    bool isPaused() const;

    void setPosition(trackPosition pos);
    trackPosition getPosition() const;
    void setVolume(float vol);
    float getVolume() const;
    void setEQ(const EQParameters& eq);
    EQParameters getEQ() const;
    const Track& getTrack() const;

    // Callback: paste track music at the given position into output
    void renderToBuffer(trackPosition pos, size_t len, float* output, bool updatePosition = true);

private:
    const Track& track;
    trackPosition position;
    float volume = 1.0f;
    EQParameters eq;
    bool paused = false;
};
