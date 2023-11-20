// OscillatorView.cpp
#include "OscillatorView.hpp"

OscillatorView::OscillatorView(const Grid& grid, int size)
    : grid_(grid), size_(size) {}

void OscillatorView::render(sf::RenderWindow& window) {
    const auto& gridData = grid_.getGrid();
    sf::RectangleShape rectangle(sf::Vector2f(size_, size_));
    for (size_t i = 0; i < gridData.size(); ++i) {
        for (size_t j = 0; j < gridData[i].size(); ++j) {
            rectangle.setFillColor(angleToColor(gridData[i][j].getAngle()));
            rectangle.setPosition(j * size_, i * size_);
            window.draw(rectangle);
        }
    }
}