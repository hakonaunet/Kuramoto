// Grid.hpp
#pragma once
#include <vector>
#include "Oscillator.hpp"

#include <omp.h>

enum class Coupling {
    None,
    Nearest4,
    Nearest8,
    DistanceR,
    DistanceR2,
    Uniform
};

class Grid {
public:
    Grid(int rows, int cols, Coupling couplingMethod = Coupling::None);

    void updateGrid();
    std::vector<std::vector<Oscillator>>& getGrid(); // Non-const version
    const std::vector<std::vector<Oscillator>>& getGrid() const; // Const version

private:
    std::vector<std::vector<Oscillator>> grid;
    Coupling currentCoupling = Coupling::None;

    std::vector<Oscillator*> getNeighbors4(int x, int y);
    std::vector<Oscillator*> getNeighbors8(int x, int y);
    
    // Updated signature to use grid positions for distance calculation
    double computeCouplingStrength(int x1, int y1, int x2, int y2, Coupling method);

    double kuramotoSum(int x, int y, Coupling couplingMethod);
};
