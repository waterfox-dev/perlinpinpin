#pragma once

#include "../noise/PerlinGenerator.h"

class PerlinMapGenerator
{

private:
    int octave;
    int width;
    int height;

    float persistence;
    float lacunarity;
    float scale;

    float base_frequency;
    float base_amplitude;

    std::vector<std::vector<float>> perlin_values;

public:
    PerlinMapGenerator(
        int octave = 6,
        float persistence = 0.5f,
        float lacunarity = 2.0f,
        float scale = 3.5f,
        float base_frequency = 1.0f,
        float base_amplitude = 1.0f,
        int width = 5000,
        int height = 5000)
    {
        this->octave = octave;
        this->persistence = persistence;
        this->lacunarity = lacunarity;
        this->scale = scale;
        this->base_frequency = base_frequency;
        this->base_amplitude = base_amplitude;
        this->width = width;
        this->height = height;
        this->perlin_values = std::vector<std::vector<float>>(
            width,
            std::vector<float>(height, 0.0f) // Fill with default value of 0.0f
        );
    }

    std::vector<std::vector<float>> generate(ISmoothingFunction const &smoothing)
    {
        PerlinGenerator generator;
        for (int i = 0; i < octave; i++)
        {
            float frequency = this->base_frequency * std::pow(this->lacunarity, i);
            float amplitude = this-> base_amplitude * std::pow(this->persistence, i);

            for (int x = 0; x < this->width; ++x)
            {
                for (int y = 0; y < height; ++y)
                {
                    float sample_x = (static_cast<float>(x) / static_cast<float>(this->width)) * this->scale * frequency;
                    float sample_y = (static_cast<float>(y) / static_cast<float>(this->height)) * this->scale * frequency;
                    perlin_values[x][y] += generator.noise(sample_x, sample_y, smoothing) * amplitude;
                }
            }
        }

        float max_amplitude = 0.0f;
        for (int i = 0; i < octave; i++)
        {
            max_amplitude += base_amplitude * std::pow(persistence, i);
        }

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                perlin_values[x][y] /= max_amplitude;
            }
        }
        return perlin_values;
    }
};