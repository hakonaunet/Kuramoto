// PlotWindow.cpp
#include "PlotWindow.h"

PlotWindow::PlotWindow() : window(sf::VideoMode(800, 600), "Plot Window") {
    ImGui::SFML::Init(window);
    plotTexture.loadFromFile("plot.png");
    plotSprite.setTexture(plotTexture);
}

PlotWindow::~PlotWindow() {
    ImGui::SFML::Shutdown();
}

void PlotWindow::showPlot() {
    ImGui::SFML::Update(window, sf::seconds(1.f/60.f));

    if (ImGui::Begin("Plot")) {
        ImGui::Image(plotSprite);

        if (ImGui::Button("Save plot")) {
            plotTexture.copyToImage().saveToFile("saved_plot.png");
        }

        if (ImGui::Button("Close")) {
            window.close();
        }

        ImGui::End();
    }

    window.clear();
    ImGui::SFML::Render(window);
    window.display();
}

void PlotWindow::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

bool PlotWindow::isOpen() const {
    return window.isOpen();
}