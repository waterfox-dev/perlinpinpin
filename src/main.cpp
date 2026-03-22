(#include "noise/PerlinGenerator.h"
#include "image/ImageGenerator.h"

#include <vector>

int main() {
    const int WIDTH = 1000;
    const int HEIGHT = 1000;
    const float SCALE = 0.02f;

    PerlinGenerator generator;
    std::vector<std::vector<float>> perlin_values(
        WIDTH,
        std::vector<float>(HEIGHT, 0.0f)
    );

    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            perlin_values[x][y] = generator.noise(x * SCALE, y * SCALE);
        }
    }

    ImageGenerator::generate_image(perlin_values, "perlin.png");

    return 0;
}