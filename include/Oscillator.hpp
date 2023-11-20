// Oscillator.hpp
#pragma once
#include <cmath>
#include <iostream>

class Oscillator {
private:
    double angle;
    double intrinsicFrequency;

public:
Oscillator() {
    angle = ((double)rand() / RAND_MAX) * 2 * M_PI;

    const double lowestFrequency = 0.95; // Lowest possible intrinsic frequency
    const double highestFrequency = 1.05; // Highest possible intrinsic frequency
    const double scale = 1; // Scale factor for intrinsic frequency

    intrinsicFrequency = (lowestFrequency + ((double)rand() / RAND_MAX) * (highestFrequency - lowestFrequency))*scale;
}

    static constexpr double TWO_PI = 2 * M_PI;

    void update(const double& dtheta) {
        angle += dtheta;
        // Ensure the angle is between [0, 2*PI]
        while(angle > 2 * M_PI) angle -= 2 * M_PI;
        while(angle < 0) angle += 2 * M_PI;
    }

    double getAngle() const { return angle; }
    double getIntrinsicFrequency() const { return intrinsicFrequency; }

    void setAngle(double newAngle) {
        angle = newAngle;
        // Ensure the angle is between [0, 2*PI]
        while(angle > 2 * M_PI) angle -= 2 * M_PI;
        while(angle < 0) angle += 2 * M_PI;
    }
};
