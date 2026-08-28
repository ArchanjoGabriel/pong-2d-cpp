#include <iostream>

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {
    std::cout << "Pong Game" << std::endl;

    constexpr int BASE_W = 800;
    constexpr int BASE_H = 600;

    sf::RenderWindow window(sf::VideoMode({BASE_W, BASE_H}), "PONG");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.display();
    }
    return 0;
}
