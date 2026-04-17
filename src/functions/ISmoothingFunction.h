#pragma once

/**
 * @brief Interface to define a smoothing function.
 * 
 * @author Clément BARATIN
 */
class ISmoothingFunction
{
    
public:
    virtual ~ISmoothingFunction() = default;
    /**
     * @brief Apply the smoothing function to a given value.
     * 
     * @param x The input value to be smoothed.
     * @return The smoothed output value.
     */
    virtual float apply(float x) const = 0;
};