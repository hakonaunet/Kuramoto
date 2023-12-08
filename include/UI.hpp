// UI.hpp

#pragma once

#include <chrono>
#include <iomanip>
#include <sstream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "SharedData.hpp"
#include "Coupling.hpp"

class UI {
    public:
        UI(SharedData& data) : sharedData(data) {
            auto lastUpdateTime = std::chrono::high_resolution_clock::now();
            totalPauseTime = std::chrono::duration<float>::zero();
        }

        void render(); // Implement the UI rendering logic

        std::string getRuntime() const; // Return the simulation time as a string
        std::string getSimulationTime() const; // Return the simulation time as a string

        std::chrono::steady_clock::time_point pauseStartTime;
        std::chrono::duration<float> totalPauseTime;
        void pause();
        void resume();

    private:
        SharedData& sharedData;
        // Member variables to handle UI update frequency
        std::chrono::time_point<std::chrono::high_resolution_clock> lastUpdateTime;
        const int minUpdateInterval = 200000; // Minimum time between UI updates in milliseconds
};