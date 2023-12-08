// UI.cpp

#include "UI.hpp"

void UI::render() {
    ImGui::Begin("Simulation Controls");

    ImGui::SliderFloat("Delta Time", &sharedData.deltaTime, 0.001f, 1.0f);
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Time step for simulation");
    }
    ImGui::SliderInt("Grid Size", &sharedData.N, 1, 1300);
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Sidelength for the square grid of oscillators");
    }
    ImGui::SliderFloat("Epsilon", &sharedData.epsilon, 0.0f, 1.0f);
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("The width of the uniform distribution (centered around 1.0) of which each oscillator's intrinsic frequency is sampled from");
    }

    // ImGui drop down menu with options from the enum class 'Couplings'
    std::string couplingOptionsStr[] = { "None", "Nearest4", "Nearest8", "DistanceR", "DistanceR2", "Uniform" };
    const char* couplingOptions[sizeof(couplingOptionsStr) / sizeof(std::string)];
    for (int i = 0; i < sizeof(couplingOptionsStr) / sizeof(std::string); ++i) {
        couplingOptions[i] = couplingOptionsStr[i].c_str();
    }

    // ImGui dropdown menu to select coupling option
    if (ImGui::BeginCombo("Coupling", couplingOptions[static_cast<int>(sharedData.coupling)])) {
        for (int i = 0; i < sizeof(couplingOptions) / sizeof(const char*); ++i) {
            bool isSelected = (sharedData.coupling == static_cast<Coupling>(i));
            if (ImGui::Selectable(couplingOptions[i], isSelected)) {
                sharedData.coupling = static_cast<Coupling>(i);
            }
            if (isSelected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    // Checkbox to set a new random seed
    static bool setRandomSeed = false;
    if (ImGui::Checkbox("Set Random Seed", &setRandomSeed)) {
        if (setRandomSeed) {
            srand(time(NULL)); // Set seed for random results
        } else {
            srand(0); // Set a fixed seed for consistent results
        }
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Enable to set a new random seed for random results, or disable to use a fixed seed for consistent results");
    }

    // Button to start the simulation
    if (ImGui::Button("Run Simulation")) {
        // Set flag to start simulation
        sharedData.isSimulationRunning = true;
        // Update simulation parameters based on UI input
    }

    // Button to pause/resume the simulation
    if (!sharedData.isPaused) {
        if (ImGui::Button("Pause Simulation")) {
            pause();
        }
    }
    else {
        if (ImGui::Button("Resume Simulation")) {
            resume();
        }
    }

    // Display runtime information if simulation is running
    if (sharedData.isSimulationRunning) {
        ImGui::Text("Runtime: %s seconds", getRuntime().c_str());
        ImGui::Text("Simulation Time: %s seconds", getSimulationTime().c_str());
        ImGui::Text("Frames Rendered: %d", sharedData.frameCount);
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedTime = now - lastUpdateTime;
        if (elapsedTime.count() > minUpdateInterval) {
            ImGui::Text("Update Time: %f seconds", sharedData.updateTime);
            lastUpdateTime = now;
        }
    }
    ImGui::End();
}

void UI::pause() {
    sharedData.isPaused = true;
    pauseStartTime = std::chrono::steady_clock::now();
}

void UI::resume() {
    sharedData.isPaused = false;
    totalPauseTime += std::chrono::steady_clock::now() - pauseStartTime;
}

std::string UI::getRuntime() const {
    static std::string lastFormattedTime; // Static variable to store the last returned string

    if (sharedData.isPaused) {
        return lastFormattedTime; // Return the last formatted time if simulation is paused
    }

    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> runtime = currentTime - sharedData.startTime - totalPauseTime;

    // Convert runtime to hours, minutes, and seconds
    int hours = int(runtime.count()) / 3600;
    int minutes = (int(runtime.count()) / 60) % 60;
    int seconds = int(runtime.count()) % 60;

    // Format the time
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    lastFormattedTime = ss.str(); // Update the last formatted time

    return lastFormattedTime;
}

std::string UI::getSimulationTime() const {
    // Convert simulation time to hours, minutes, and seconds
    int hours = int(sharedData.simulationTime) / 3600;
    int minutes = (int(sharedData.simulationTime) / 60) % 60;
    int seconds = int(sharedData.simulationTime) % 60;

    // Format the time
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    std::string formattedTime = ss.str();

    return formattedTime;
}