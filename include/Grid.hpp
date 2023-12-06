// Grid.hpp
#pragma once
#include <vector>
#include <cmath>
#include <random>

#include "Oscillator.hpp"
#include "SharedData.hpp"
#include "Coupling.hpp"

#include <omp.h>

class Grid {
public:
    Grid(SharedData& data);

    void updateGrid();
    std::vector<std::vector<Oscillator>>& getGrid(); // Non-const version
    const std::vector<std::vector<Oscillator>>& getGrid() const; // Const version

private:
    SharedData& sharedData;
    
    std::vector<std::vector<Oscillator>> grid;

    std::vector<Oscillator*> getNeighbors4(int x, int y);
    std::vector<Oscillator*> getNeighbors8(int x, int y);
    
    // Updated signature to use grid positions for distance calculation
    double computeCouplingStrength(int x1, int y1, int x2, int y2, Coupling method);

    double kuramotoSum(int x, int y, Coupling couplingMethod);
};