#pragma once

#include "../functions/ISmoothingFunction.h"
#include "NoiseGenerator.h"

#include <cstdlib>

class RandomGenerator : public NoiseGenerator {

/**
 * @brief A simple noise generator that returns a random value for each point.
 * 
 * @see NoiseGenerator
 * @author Clément BARATIN
 */
public:

    /**
     * @brief Generator for a given point a random value between 0 and 1.
     * 
     * @param x the X value of the point.
     * @param y the Y value of the point.
     * @param smoothing_function a smoothing function used to make the noise more regular.
     * @return the value of the point.
     */
    float noise(float x, float y, ISmoothingFunction const &smoothing_function) override {
        return smoothing_function.apply((rand()) / static_cast <float> (RAND_MAX));
    }
};