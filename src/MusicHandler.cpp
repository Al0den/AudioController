#include "MusicHandler.h"
#include <algorithm>
#include <cstring>

MusicHandler::MusicHandler(size_t numTracks)
    : trackPlayers(numTracks) {}

void MusicHandler::setTrackPlayer(size_t index, std::unique_ptr<TrackPlayer> player) {
    if (index < trackPlayers.size()) {
        trackPlayers[index] = std::move(player);
    }
}

TrackPlayer* MusicHandler::getTrackPlayer(size_t index) const {
    if (index < trackPlayers.size()) {
        return trackPlayers[index].get();
    }
    return nullptr;
}

size_t MusicHandler::getNumTracks() const {
    return trackPlayers.size();
}

void MusicHandler::mix(float* output, size_t len, trackPosition pos) {
    // Zero the output buffer
    std::memset(output, 0, len * sizeof(float));
    // Mix each track
    for (const auto& player : trackPlayers) {
        if (player) {
            std::vector<float> temp(len, 0.0f);
            player->renderToBuffer(pos, len, temp.data(), false);
            for (size_t i = 0; i < len; ++i) {
                output[i] += temp[i];
            }
        }
    }
}
