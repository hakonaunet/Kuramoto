#include "Grid.hpp"
#include "OscillatorView.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <../imgui/imgui.h>
#include <../imgui-sfml/imgui-SFML.h>

#include <ctime>

int main() {
    srand(time(NULL)); // Set seed for random number generator

    int gridWidth = 40, gridHeight = 40;
    int uiWidth = 200; // Width of the UI column
    int monitorWidth = 1400 + uiWidth, monitorHeight = 1400;

    // Calculate maximum allowed size for each oscillator based on monitor resolution
    int maxOscillatorWidth = (monitorWidth - uiWidth) / gridWidth;
    int maxOscillatorHeight = monitorHeight / gridHeight;
    int oscillatorSize = std::min(maxOscillatorWidth, maxOscillatorHeight);

    sf::RenderWindow window(sf::VideoMode(monitorWidth, monitorHeight), "Oscillator Grid");
    ImGui::SFML::Init(window); // Initialize ImGui with SFML

    Grid grid(gridWidth, gridHeight, Coupling::Uniform);
    OscillatorView view(grid, oscillatorSize);

    sf::Clock clock; // Clock to measure time between frames
    sf::Clock deltaClock; // Clock for tracking the time between ImGui frames

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            ImGui::SFML::ProcessEvent(event); // Pass the event to ImGui
        }

        ImGui::SFML::Update(window, deltaClock.restart()); // Update ImGui

        // ImGui UI code goes here
        ImGui::Begin("Simulation Control");
        if (ImGui::Button("Run Simulation")) {
            // Add logic to run simulation
        }
        // Additional controls can be added here
        ImGui::End();

        window.clear();
        view.render(window); // Render the current state of the grid

        ImGui::SFML::Render(window); // Render ImGui over SFML

        window.display(); // Display the rendered frame

        // Ensure minimum frame time
        while (clock.getElapsedTime() < sf::microseconds(1000)) {
            sf::sleep(sf::microseconds(1000) - clock.getElapsedTime());
        }
        clock.restart(); // Reset the clock for the next frame

        grid.updateGrid(); // Update the grid for the next frame
    }

    ImGui::SFML::Shutdown(); // Shutdown ImGui properly
    return 0;
}