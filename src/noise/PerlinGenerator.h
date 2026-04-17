#pragma once

#include "NoiseGenerator.h"
#include "../functions/ISmoothingFunction.h"

#include <cmath>
#include <iostream>

/**
 * @brief Implementation of a noise generator based on Perlin Algorithm 
 * 
 * @see NoiseGenerator
 * @author Clément BARATIN
 */
class PerlinGenerator : public NoiseGenerator {

public:

    int* permutation_table;
    
    // The translation unit for the gradients, to ensure they are unit vectors.
    const float TRANSLATION_UNIT = 1.0f / std::sqrt(2.0f);

    // 8 possible gradients for 2D Perlin Noise
    const float GRADIENT[8][2] = {
        {TRANSLATION_UNIT,TRANSLATION_UNIT},
        {-TRANSLATION_UNIT,TRANSLATION_UNIT},
        {TRANSLATION_UNIT,-TRANSLATION_UNIT},
        {-TRANSLATION_UNIT,-TRANSLATION_UNIT},
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    /**
     * @brief Constructor for the PerlinGenerator.
     * It initializes the permutation table.
     */
    PerlinGenerator() {
        this->permutation_table = this->getPermutationTable();
    }

    /**
     * @brief Destructor for the PerlinGenerator.
     * It deletes the permutation table.
     */
    ~PerlinGenerator() {
        delete[] this->permutation_table;
    }
    
    /**
     * @brief Generator for a given point a Perlin Noise.
     * 
     * @param x the X value of the point.
     * @param y the Y value of the point.
     * @param smoothing_function a smoothing function used to make the noise more regular.
     * @return The Perlin Noise value for the given point.
     */
    float noise(float x, float y, ISmoothingFunction const &smoothing_function) override {
        
        int x0 = static_cast<int>(std::floor(x)) & 255;
        int y0 = static_cast<int>(std::floor(y)) & 255;

        int gradient_index_00 = this->permutation_table[this->permutation_table[x0] + y0] % 8;
        int gradient_index_10 = this->permutation_table[this->permutation_table[x0 + 1] + y0] % 8;
        int gradient_index_01 = this->permutation_table[this->permutation_table[x0] + y0 + 1] % 8;
        int gradient_index_11 = this->permutation_table[this->permutation_table[x0 + 1] + y0 + 1] % 8;

        float dot_00 = this->GRADIENT[gradient_index_00][0] * (x - std::floor(x)) + this->GRADIENT[gradient_index_00][1] * (y - std::floor(y));
        float dot_10 = this->GRADIENT[gradient_index_10][0] * (x - std::floor(x) - 1) + this->GRADIENT[gradient_index_10][1] * (y - std::floor(y));
        float dot_01 = this->GRADIENT[gradient_index_01][0] * (x - std::floor(x)) + this->GRADIENT[gradient_index_01][1] * (y - std::floor(y) - 1);
        float dot_11 = this->GRADIENT[gradient_index_11][0] * (x - std::floor(x) - 1) + this->GRADIENT[gradient_index_11][1] * (y - std::floor(y) - 1);

        float u = smoothing_function.apply(x - std::floor(x));
        float v = smoothing_function.apply(y - std::floor(y));
        float lerp_0 = (1 - u) * dot_00 + u * dot_10;
        float lerp_1 = (1 - u) * dot_01 + u * dot_11;
        return (1 - v) * lerp_0 + v * lerp_1;
    }
};