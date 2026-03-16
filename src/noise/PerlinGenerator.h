#include "NoiseGenerator.h"

#include <cmath>
#include <iostream>

class PerlinGenerator : public NoiseGenerator {

public:

    int* permutation_table;

    const float TRANSLATION_UNIT = 1.0 / sqrt(2); 
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
     * Constructor for the PerlinGenerator.
     * It initializes the permutation table.
     */
    PerlinGenerator() {
        this->permutation_table = this->getPermutationTable();
    }
    
    /**
     * Generator for a given point a Perlin Noise.
     * 
     * @param x the X value of the point.
     * @param y the Y value of the point.
     */
    float noise(float x, float y) {
        
        int x0 = (int)floor(x) & 255;
        int y0 = (int)floor(y) & 255;

        int gradient_index_00 = this->permutation_table[this->permutation_table[x0] + y0] % 8;
        int gradient_index_10 = this->permutation_table[this->permutation_table[x0 + 1] + y0] % 8;
        int gradient_index_01 = this->permutation_table[this->permutation_table[x0] + y0 + 1] % 8;
        int gradient_index_11 = this->permutation_table[this->permutation_table[x0 + 1] + y0 + 1] % 8;

        float dot_00 = this->GRADIENT[gradient_index_00][0] * (x - floor(x)) + this->GRADIENT[gradient_index_00][1] * (y - floor(y));
        float dot_10 = this->GRADIENT[gradient_index_10][0] * (x - floor(x) - 1) + this->GRADIENT[gradient_index_10][1] * (y - floor(y));
        float dot_01 = this->GRADIENT[gradient_index_01][0] * (x - floor(x)) + this->GRADIENT[gradient_index_01][1] * (y - floor(y) - 1);
        float dot_11 = this->GRADIENT[gradient_index_11][0] * (x - floor(x) - 1) + this->GRADIENT[gradient_index_11][1] * (y - floor(y) - 1);

        auto fade = [](float t) {
            return t * t * t * (t * (t * 6 - 15) + 10);
        };
        float u = fade(x - floor(x));
        float v = fade(y - floor(y));
        float lerp_0 = (1 - u) * dot_00 + u * dot_10;
        float lerp_1 = (1 - u) * dot_01 + u * dot_11;
        return (1 - v) * lerp_0 + v * lerp_1;
    }
};