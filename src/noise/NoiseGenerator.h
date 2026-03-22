#include <numeric>
#include <random>
#include <algorithm>

/**
 * Partially abstract class providing tools to generate a noise.
 * 
 * @see PerlinGenerator
 * @author Clément BARATIN
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
     * Return a permutation table (lenght: 512)
     * 
     * @return int* The permutation table.
     */
    static int* getPermutationTable() {
        int* random_values = NoiseGenerator::getRandomValues(); 
        int* permutation_table = new int[512];

        for(int i = 0; i < 512; i++) {
            permutation_table[i] = random_values[i & 255];
        }

        delete[] random_values;
        return permutation_table;
    }

private:

    /**
     * Generate an array of 256 integers for 1 to 256 randomly ordered.
     * Statically declared.
     * 
     * @return A pointer to the array.
     */
    static int* getRandomValues() {
        int* values = new int[256];

        std::iota(values, values + 256, 1); 

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(values, values + 256, g);

        return values;   
    }
};