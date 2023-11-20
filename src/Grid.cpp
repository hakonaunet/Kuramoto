// Grid.cpp
#include "Grid.hpp"
#include <cmath>
#include <random>

Grid::Grid(int rows, int cols, Coupling couplingMethod) 
    : currentCoupling(couplingMethod) {
    for (int i = 0; i < rows; i++) {
        grid.push_back(std::vector<Oscillator>(cols));
    }
}

std::vector<Oscillator*> Grid::getNeighbors4(int x, int y) {
    std::vector<Oscillator*> neighbors;
    if (x > 0) neighbors.push_back(&grid[x - 1][y]);
    if (x < grid.size() - 1) neighbors.push_back(&grid[x + 1][y]);
    if (y > 0) neighbors.push_back(&grid[x][y - 1]);
    if (y < grid[0].size() - 1) neighbors.push_back(&grid[x][y + 1]);
    return neighbors;
}

std::vector<Oscillator*> Grid::getNeighbors8(int x, int y) {
    std::vector<Oscillator*> neighbors = getNeighbors4(x, y);
    if (x > 0 && y > 0) neighbors.push_back(&grid[x - 1][y - 1]);
    if (x > 0 && y < grid[0].size() - 1) neighbors.push_back(&grid[x - 1][y + 1]);
    if (x < grid.size() - 1 && y > 0) neighbors.push_back(&grid[x + 1][y - 1]);
    if (x < grid.size() - 1 && y < grid[0].size() - 1) neighbors.push_back(&grid[x + 1][y + 1]);
    return neighbors;
}

double Grid::computeCouplingStrength(int x1, int y1, int x2, int y2, Coupling method) {
    double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));

    switch (method) {
        case Coupling::DistanceR:
            return (distance == 0) ? 0 : 1.0 / distance;

        case Coupling::DistanceR2:
            return (distance == 0) ? 0 : 1.0 / (distance * distance);

        case Coupling::None:
        case Coupling::Nearest4:
        case Coupling::Nearest8:
        case Coupling::Uniform:
            return 1.0; // Adjust as needed

        default:
            return 1.0;
    }
}

// Function to compute the Kuramoto model's sum term for different coupling methods
double Grid::kuramotoSum(int x, int y, Coupling couplingMethod) {
    double sum = 0.0;
    int N = grid.size() * grid[0].size(); // Total number of oscillators

    switch (couplingMethod) {
        case Coupling::None:
            // No coupling
            break;

        case Coupling::Nearest4: {
            auto neighbors = getNeighbors4(x, y);
            for (Oscillator* neighbor : neighbors) {
                sum += sin(neighbor->getAngle() - grid[x][y].getAngle());
            }
            break;
        }

        case Coupling::Nearest8: {
            auto neighbors = getNeighbors8(x, y);
            for (Oscillator* neighbor : neighbors) {
                sum += sin(neighbor->getAngle() - grid[x][y].getAngle());
            }
            break;
        }

        case Coupling::DistanceR:
        case Coupling::DistanceR2:
            // Implement distance-based coupling logic
            // ...

        case Coupling::Uniform:
            for (const auto& row : grid) {
                for (const Oscillator& osc : row) {
                    sum += sin(osc.getAngle() - grid[x][y].getAngle());
                }
            }
            break;

        default:
            // Default behavior or error handling
            break;
    }

    return sum / (couplingMethod == Coupling::Uniform ? N : 1);
}

// Function to update the grid using RK4
void Grid::updateGrid() {
    double K = 1.0; // Set the coupling strength
    double dt = 0.05; // Time step

    #pragma omp parallel for collapse(2) // Parallelize both x and y loops
    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid[0].size(); y++) {
            Oscillator& osc = grid[x][y];
            double theta = osc.getAngle();
            double omega = osc.getIntrinsicFrequency();

            // RK4 integration
            double k1 = dt * (omega + K * kuramotoSum(x, y, currentCoupling));
            double k2 = dt * (omega + K * kuramotoSum(x, y, currentCoupling) + 0.5 * k1);
            double k3 = dt * (omega + K * kuramotoSum(x, y, currentCoupling) + 0.5 * k2);
            double k4 = dt * (omega + K * kuramotoSum(x, y, currentCoupling) + k3);

            osc.setAngle(theta + (k1 + 2 * k2 + 2 * k3 + k4) / 6);
        }
    }
}


std::vector<std::vector<Oscillator>>& Grid::getGrid() {
    return grid;
}

const std::vector<std::vector<Oscillator>>& Grid::getGrid() const {
    return grid;
}