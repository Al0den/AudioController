#pragma once
#include <vector>
#include <string>

struct trackPosition {
    float seconds;
    trackPosition(float s = 0.0f) : seconds(s) {}
};

class Track {

public:
    Track(const std::string& name, const std::vector<float>& samples, unsigned int sampleRate);
    Track(const std::string& filePath);
    Track(const std::string& name); // Unloaded samples

    const std::string& getName() const;
    const std::vector<float>& getSamples() const;
    size_t getLength() const;
    unsigned int getSampleRate() const;
    bool isLoaded() const;

private:
    std::string name;
    std::vector<float> samples;
    unsigned int sampleRate;
    bool loaded = true;
};
