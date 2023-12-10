// SharedData.hpp  

#pragma once
#include <chrono>

#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/RectangleShape.hpp>

#include "Coupling.hpp"

struct SharedData {
    int N;
    float deltaTime;
    int iteration;
    Coupling coupling;
    float epsilon;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::duration totalPauseTime;        
    double simulationTime;
    double updateTime;
    bool isSimulationRunning;
    bool isPaused;
    bool startSimulation;
    bool calculateKuramotoOrderParameter;

    SharedData() : N(20), deltaTime(0.1), coupling(Coupling::Uniform), epsilon(0.1),
    updateTime(0), isSimulationRunning(false), isPaused(false), startSimulation(false),
    calculateKuramotoOrderParameter(false) {
    reset();
    }

    void reset() {
        startTime = std::chrono::high_resolution_clock::now();
        totalPauseTime = std::chrono::high_resolution_clock::duration::zero();
        simulationTime = 0;
        iteration = 0;
    }
};