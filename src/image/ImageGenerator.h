#pragma once

#include "Biome.h"
#include "../libs/stb_image_write.h"
#include <vector>

/**
 * @brief Generate an image based on a Perlin Map
 * 
 * @see PerlinGenerator
 * @author Clément BARATIN
 */
class ImageGenerator {

public: 

    /**
     * @brief Generate a png image based on a perlin noise. 
     * 
     * @param perlin_value the perlin noise array.
     * @param width the width of the image.
     * @param height the height of the image.
     * @param filename the filename of the png image.
     * @param colorize whether to colorize the image based on the perlin value (biome-like) or to use a grayscale representation.
     */
    static void generate_png_image(
        std::vector<std::vector<float>> perlin_value,
        int width, 
        int height,
        const char* filename, 
        bool colorize = false
    ) {

        const int channels = 3;
        std::vector<unsigned char> pixels(width * height * channels);

        for (int i = 0; i < width; i++)
        {

            for (int j = 0; j < height; j++)
            {
                float value = perlin_value[i][j];
                float normalized = (value + 1.0f) * 0.5f; 

                if (normalized < 0.0f) normalized = 0.0f;
                if (normalized > 1.0f) normalized = 1.0f;

                if (colorize)
                {
                    const Biome biome = get_biome(normalized);
                    const BiomeColor color = get_biome_color(biome, normalized);
                    ImageGenerator::set_pixel(pixels, width, i, j, color.r, color.g, color.b);
                }
                else
                {
                    unsigned char v = static_cast<unsigned char>(normalized * 255.0f);
                    ImageGenerator::set_pixel(pixels, width, i, j, v, v, v);
                }
            }
        }

        stbi_write_png(filename, width, height, channels, pixels.data(), width * channels);
    }

    static void set_pixel(std::vector<unsigned char>& pixels, int width, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
        const int channels = 3;
        const int idx = (y * width + x) * channels;
        pixels[idx + 0] = r;
        pixels[idx + 1] = g;
        pixels[idx + 2] = b;
    }
};