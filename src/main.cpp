#include <iostream>

#include "../include/Ball.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {
    std::cout << "Pong Game" << std::endl;

    constexpr int BASE_W = 800;
    constexpr int BASE_H = 600;

    sf::RenderWindow window(sf::VideoMode({BASE_W, BASE_H}), "PONG");
    window.setFramerateLimit(60);

    Ball ball({BASE_W/2.0, BASE_H/2.0});

    // Paddle general variables
    float paddle_W = 15;
    float paddle_H = 70;
    float paddle_margin_X = 5;
    float paddle_margin_Y = 5;
    float paddle_VY = 10;

    // Paddle 1
    sf::RectangleShape paddle1;
    float paddle1_X = paddle_margin_X;
    float paddle1_Y = (BASE_H/2.0) - (paddle_H/2.0);
    paddle1.setPosition({paddle1_X, paddle1_Y});
    paddle1.setSize({paddle_W, paddle_H});
    paddle1.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        ball.draw(window);

        window.draw(paddle1);

        window.display();
    }
    return 0;
}
