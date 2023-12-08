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

        if (!sharedData.isPaused && grid != nullptr) {
            grid->updateGrid();
        }
    }

    ImGui::SFML::Shutdown();
}