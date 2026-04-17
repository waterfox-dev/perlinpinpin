#include "image/ImageGenerator.h"
#include "functions/BasicSmooth.h"
#include "map/PerlinMapGenerator.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Main function for CLI to generate perlin noise 
 * 
 * @param argc the number of args passsed to the CLI
 * @param argv the list of args passed to the CLI
 * @return int the default UNIX like system return code 
 */
int main(int argc, char * argv[]) {

    BasicSmooth smoothing_function;
    PerlinMapGenerator perlin_map_generator;

    ImageGenerator::generate_png_image(perlin_map_generator.generate(smoothing_function), 5000, 5000, "perlin.png", true);
    std::cout << "Image generated \n";
    return 0;
}