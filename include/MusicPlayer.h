#pragma once
#include "MusicHandler.h"
#include <thread>
#include <atomic>

// Forward declaration for audio library handle (e.g., PortAudio)
struct PaStream;

class MusicPlayer {
public:
    MusicPlayer(MusicHandler& handler, unsigned int sampleRate = 44100);
    ~MusicPlayer();

    void start();
    void stop();
    bool isPlaying() const;

private:
    void audioThreadFunc();
    MusicHandler& handler;
    std::thread audioThread;
    std::atomic<bool> running{false};
    unsigned int sampleRate;
    PaStream* stream = nullptr;
};
