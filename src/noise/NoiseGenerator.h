#include <numeric>
#include <random>
#include <algorithm>

/**
 * Partially abstract class providing tools to generate a noise.
 * 
 * @see PerlinGenerator
 */
class NoiseGenerator {

public:
    /**
     * Generate a noise for a given points.
     * Abstract to make it modulable for differents noise generator.
     * 
     * @param x the X value of the point.
     * @param y the Y value of the point.
     * @return The noise for a given point.
     */
    virtual float noise(float x, float y) = 0;

protected:
    /**
     * Generate an array of 256 integers for 1 to 256
     * randomly ordered.
     * @return A pointer to the array.
     */
    int* getRandomValues() {
        int* values = new int[256];

        std::iota(values, values + 256, 1); 

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(values, values + 256, g);

        return values;   
    }
};