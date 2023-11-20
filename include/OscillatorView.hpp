// OscillatorView.hpp
#ifndef OSCILLATOR_VIEW_HPP
#define OSCILLATOR_VIEW_HPP

#include "Grid.hpp"
#include "Utils.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class OscillatorView {
public:
    OscillatorView(const Grid& grid, int size);
    void render(sf::RenderWindow& window);

private:
    const Grid& grid_;
    int size_;
};

#endif