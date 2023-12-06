// Application.cpp

#include "Application.hpp"

Application::Application() : ui(sharedData),  grid(sharedData) {
    // Initialize the application
}

void Application::run() {
    sf::Vector2f windowsize(1350, 1350);
    int oscillatorSize = 30;
    sf::RenderWindow window(sf::VideoMode(windowsize.x, windowsize.y), "Kuramoto Simulation");

    // Set the position of the window (example: top-left corner of the screen)
    window.setPosition(sf::Vector2i(2800, 0));
    
    bool ImGui_initialization = ImGui::SFML::Init(window);
    if (!ImGui_initialization) {
        // Handle initialization failure
        std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    }

    sf::Clock deltaClock;
    std::unique_ptr<Grid> grid = nullptr;
    std::unique_ptr<OscillatorView> view = nullptr;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Check if the simulation should be started
        if (sharedData.isSimulationRunning && grid == nullptr) {
            // Create a new Grid object with the current settings
            grid = std::make_unique<Grid>(sharedData);
            // Create a new OscillatorView with the new Grid
            view = std::make_unique<OscillatorView>(*grid, oscillatorSize);
        }

        // Clear the window
        window.clear();

        if (sharedData.isSimulationRunning && grid != nullptr) {
            view->render(window);
        }

        // Start the ImGui frame
        ImGui::SFML::Update(window, deltaClock.restart());
        ui.render();  // Assuming this method encapsulates ImGui render calls

        ImGui::SFML::Render(window);

        // Display the rendered frame
        window.display();

        if (sharedData.isSimulationRunning && grid != nullptr) {
            grid->updateGrid();
        }
    }

    ImGui::SFML::Shutdown();
}
/*
int main() {
    srand(time(NULL)); // Set seed for random number generator

    int gridWidth = 40, gridHeight = 40;
    int monitorWidth = 1300, monitorHeight = 1300;

    // Calculate maximum allowed size for each oscillator based on monitor resolution
    int maxOscillatorWidth = (monitorWidth) / gridWidth;
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
*/