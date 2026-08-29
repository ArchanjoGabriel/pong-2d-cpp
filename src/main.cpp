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

    // Paddle 2
    sf::RectangleShape paddle2;
    float paddle2_X = BASE_W - paddle_W -paddle_margin_X;
    float paddle2_Y = (BASE_H/2.0) - (paddle_H/2.0);
    paddle2.setPosition({paddle2_X, paddle2_Y});
    paddle2.setSize({paddle_W, paddle_H});
    paddle2.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            paddle1.move({0, -(paddle_VY)});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            paddle1.move({0, paddle_VY});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            paddle2.move({0, -(paddle_VY)});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            paddle2.move({0, paddle_VY});
        }

        window.clear(sf::Color::Black);

        ball.draw(window);

        window.draw(paddle1);
        window.draw(paddle2);

        window.display();
    }
    return 0;
}
