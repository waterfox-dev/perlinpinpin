#include "noise/PerlinGenerator.h"

#include <iostream>

int main() {
    std::cout << "Perlinpinpin is starting" << std::endl;
    PerlinGenerator generator;
    generator.noise(1,1);
    return EXIT_SUCCESS;
}