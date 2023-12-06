// Application.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>

#include "UI.hpp"
#include "SharedData.hpp"
#include "OscillatorView.hpp"
#include "Grid.hpp"

class Application {
public:
    Application();

    void run();

private:
    SharedData sharedData;
    Grid grid;
    UI ui;
};