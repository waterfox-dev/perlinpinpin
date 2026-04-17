#pragma once

/**
 * @brief Biome definitions and related functions for colorization.
 * 
 * @author Clément BARATIN
 */
struct BiomeColor {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

/**
 * @brief Enumerate all possible biomes.
 * 
 * @author Clément BARATIN
 */
enum class Biome {
    DeepWater,
    ShallowWater,
    Reef,
    Shore,
    Plains,
    Forest,
    Hills,
    Mountain,
    Snow,
};

/**
 * @brief Get the biome object based on the normalized perlin value.
 * Modifying the thresholds will change the distribution of the biomes on the generated image.
 * 
 * @param normalized 
 * @return Biome 
 */
inline Biome get_biome(float normalized) {
    if (normalized < 0.32f) {
        return Biome::DeepWater;
    }
    if (normalized < 0.42f) {
        return Biome::ShallowWater;
    }
    if (normalized < 0.45f) {
        return Biome::Reef;
    }
    if (normalized < 0.48f) {
        return Biome::Shore;
    }
    if (normalized < 0.62f) {
        return Biome::Plains;
    }
    if (normalized < 0.78f) {
        return Biome::Forest;
    }
    if (normalized < 0.84f) {
        return Biome::Hills;
    }
    if (normalized < 0.94f) {
        return Biome::Mountain;
    }
    return Biome::Snow;
}

/**
 * @brief Get the color associated with a biome. 
 * The color can be modified based on the normalized perlin value to add more variety to the image.
 * 
 * @param biome the biome for which we want the color.
 * @param normalized the normalized perlin value, used to add variety to the colorization.
 * @return BiomeColor 
 */
inline BiomeColor get_biome_color(Biome biome, float normalized) {
    switch (biome) {
        case Biome::DeepWater:
            return {8, 36, 108};
        case Biome::ShallowWater:
            return {28, 96, 168};
        case Biome::Reef:
            return {72, 170, 200};
        case Biome::Shore:
            return {214, 201, 155};
        case Biome::Plains:
            return {146, 168, 92};
        case Biome::Forest:
            return {52, 110, 56};
        case Biome::Hills:
            return {122, 124, 96};
        case Biome::Mountain:
            return {108, 108, 110};
        case Biome::Snow:
        default:
            if (normalized < 0.93f) {
                return {212, 212, 212};
            }
            return {246, 246, 246};
    }
}