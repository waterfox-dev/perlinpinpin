#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../libs/stb_image_write.h"
#include <vector>

class ImageGenerator {

public: 
    static void generate_image(
        std::vector<std::vector<float>> perlin_value, 
        const char* filename
    ) {
        const int WIDTH = 1000;
        const int HEIGHT = 1000;

        std::vector<unsigned char> pixels(WIDTH * HEIGHT);

        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {
                float value = perlin_value[i][j];
                float normalized = (value + 1.0f) / 2.0f;
                pixels[j * WIDTH + i] = (unsigned char)(normalized * 255);
            }
        }

        stbi_write_png(filename, WIDTH, HEIGHT, 1, pixels.data(), WIDTH);
    }
};