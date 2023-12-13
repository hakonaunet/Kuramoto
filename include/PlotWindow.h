// PlotWindow.h
#pragma once

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class PlotWindow {
public:
    PlotWindow();
    ~PlotWindow();
    void showPlot();
    void update();
    bool isOpen() const;

private:
    sf::RenderWindow window;
    sf::Texture plotTexture;
    sf::Sprite plotSprite;
};