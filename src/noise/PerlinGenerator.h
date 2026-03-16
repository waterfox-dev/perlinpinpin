#include "NoiseGenerator.h"
#include <cmath>

class PerlinGenerator : public NoiseGenerator {

    public:
    /**
     * Generator for a given point a Perlin Noise.
     * 
     * @param x the X value of the point.
     * @param y the Y value of the point.
     */
    float noise(float x, float y) {
        float translation_unit = 1.0 / sqrt(2); 
        float gradient[8][2] = {
            {translation_unit,translation_unit},
            {-translation_unit,translation_unit},
            {translation_unit,-translation_unit},
            {-translation_unit,-translation_unit},
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
    }
};