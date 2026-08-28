#include <iostream>

#include "../include/Ball.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {
    std::cout << "Pong Game" << std::endl;

    constexpr int BASE_W = 800;
    constexpr int BASE_H = 600;

    sf::RenderWindow window(sf::VideoMode({BASE_W, BASE_H}), "PONG");
    window.setFramerateLimit(60);

    Ball ball({BASE_W/2.0, BASE_H/2.0});
    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        ball.draw(window);

        window.display();
    }
    return 0;
}
