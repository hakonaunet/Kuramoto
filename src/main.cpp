// main.cpp
#include "Grid.hpp"
#include "OscillatorView.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics.hpp>

#include <ctime>

int main() {
    srand(time(NULL));  // Set seed for random number generator

    int gridWidth = 40, gridHeight = 40;
    int monitorWidth = 1400, monitorHeight = 1400;
    
    // Calculate maximum allowed size for each oscillator based on monitor resolution
    int maxOscillatorWidth = monitorWidth / gridWidth;
    int maxOscillatorHeight = monitorHeight / gridHeight;

    // Use the smaller of the two to ensure oscillators fit on the screen for both width and height
    int oscillatorSize = std::min(maxOscillatorWidth, maxOscillatorHeight);

    sf::RenderWindow window(sf::VideoMode(gridWidth * oscillatorSize, gridHeight * oscillatorSize), "Oscillator Grid");

    Grid grid(gridWidth, gridHeight, Coupling::Uniform);
    OscillatorView view(grid, oscillatorSize);

    sf::Clock clock; // Clock to measure time between frames
    const sf::Time MinFrameTime = sf::microseconds(1000); // minimum time between frames in microseconds

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        view.render(window); // Render the current state of the grid
        window.display();   // Display the rendered frame

        // Ensure minimum frame time
        while (clock.getElapsedTime() < MinFrameTime) {
            sf::sleep(MinFrameTime - clock.getElapsedTime());
        }
        clock.restart(); // Reset the clock for the next frame

        grid.updateGrid(); // Now, update the grid for the next frame
    }

    return 0;
}