#pragma once 

#include "ISmoothingFunction.h"

/**
 * @brief Implementation of smoothing function using polynomial values.
 * 
 * @see ISmoothingFunction
 * @author Clément BARATIN
 */
class BasicSmooth : public ISmoothingFunction {

public:

    /**
     * @brief Overriding the interface with a polynamial equation 
     * such as f(x) = 6x^5-15x^4+10x^3
     * 
     * @param x the parameter of the function
     * @return the image of the function
     */
    float apply(float x) const override {
        return x * x * x * (x * (x * 6 - 15) + 10);
    }
};