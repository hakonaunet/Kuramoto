// SharedData.hpp  

#pragma once
#include <chrono>

#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/RectangleShape.hpp>

#include "Coupling.hpp"

struct SharedData {
    int N;
    float deltaTime;
    int frameCount;
    Coupling coupling;
    float epsilon;
    std::chrono::steady_clock::time_point startTime;
    double simulationTime;
    double updateTime;
    bool isSimulationRunning;
    bool isPaused;

    SharedData() : N(20), deltaTime(0.1), coupling(Coupling::Uniform), epsilon(0.1),
    startTime(std::chrono::steady_clock::now()), simulationTime(0), frameCount(0), updateTime(0),
    isSimulationRunning(false), isPaused(false) {}
};