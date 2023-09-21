// Grid.hpp
// Grid.hpp
#include <vector>
#include <random>

class Grid {
public:
    Grid(int N) : N(N) {}

    virtual void initialize() = 0;  // Pure virtual function to initialize the grid

    // ... other common methods for dynamics and visualization ...

protected:
    int N;
    std::vector<std::vector<float>> angles;       // 2D matrix for angles
    std::vector<std::vector<float>> frequencies;  // 2D matrix for intrinsic frequencies
};
