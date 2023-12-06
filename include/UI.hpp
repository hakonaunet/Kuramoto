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
        UI(SharedData& data) : sharedData(data) {}

        void render(); // Implement the UI rendering logic

        std::string getRuntime() const; // Return the simulation time as a string
        std::string getSimulationTime() const; // Return the simulation time as a string

    private:
        SharedData& sharedData;
};