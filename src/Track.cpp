// Constructor for unloaded samples

#include "Track.h"
#include <cstdio>
#include <stdexcept>


Track::Track(const std::string& name, const std::vector<float>& samples, unsigned int sampleRate)
    : name(name), samples(samples), sampleRate(sampleRate), loaded(true) {}

Track::Track(const std::string& name)
    : name(name), sampleRate(-1), loaded(false) {}

Track::Track(const std::string& filePath) {
    throw std::runtime_error("Track loading from file is not implemented yet.");
}

const std::string& Track::getName() const {
    return name;
}

const std::vector<float>& Track::getSamples() const {
    if (!loaded) {
        static std::vector<float> empty;
        printf("Warning: Attempted to access samples from an unloaded track '%s'. Returning zeros.\n", name.c_str());
        return empty;
    }
    return samples;
}
bool Track::isLoaded() const {
    return loaded;
}


size_t Track::getLength() const {
    return samples.size();
}

unsigned int Track::getSampleRate() const {
    return sampleRate;
}
