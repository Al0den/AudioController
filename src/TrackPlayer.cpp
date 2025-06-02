
#include "TrackPlayer.h"
#include <algorithm>
#include <cstring>

TrackPlayer::TrackPlayer(const Track& track)
    : track(track), position(0.0f), volume(1.0f), eq{} {}

void TrackPlayer::setPosition(trackPosition pos) {
    position = pos;
}

trackPosition TrackPlayer::getPosition() const {
    return position;
}

void TrackPlayer::setVolume(float vol) {
    volume = vol;
}

float TrackPlayer::getVolume() const {
    return volume;
}

void TrackPlayer::setEQ(const EQParameters& eqParams) {
    eq = eqParams;
}

EQParameters TrackPlayer::getEQ() const {
    return eq;
}

const Track& TrackPlayer::getTrack() const {
    return track;
}

void TrackPlayer::renderToBuffer(trackPosition pos, size_t len, float* output, bool updatePosition) {
    if (paused || !track.isLoaded()) {
        if (!track.isLoaded()) {
            printf("Warning: Attempted to render from an unloaded track '%s'. Output will be zeros.\n", track.getName().c_str());
        }
        std::memset(output, 0, len * sizeof(float));
        return;
    }
    const auto& samples = track.getSamples();
    unsigned int sampleRate = track.getSampleRate();
    size_t start = static_cast<size_t>(pos.seconds * static_cast<float>(sampleRate));
    size_t available = samples.size() > start ? samples.size() - start : 0;
    size_t toCopy = std::min(len, available);
    if (toCopy > 0) {
        for (size_t i = 0; i < toCopy; ++i) {
            // Simple volume and EQ (not a real EQ, just placeholders)
            output[i] = samples[start + i] * volume;
            // Apply EQ here if needed
        }
    }
    if (toCopy < len) {
        std::memset(output + toCopy, 0, (len - toCopy) * sizeof(float));
    }
    if (updatePosition) {
        position.seconds = pos.seconds + static_cast<float>(len) / static_cast<float>(sampleRate);
    }
}

void TrackPlayer::setPaused(bool p) {
    paused = p;
}

bool TrackPlayer::isPaused() const {
    return paused;
}