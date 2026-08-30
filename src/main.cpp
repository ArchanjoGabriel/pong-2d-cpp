#include <iostream>

#include "../include/Ball.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "variables.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

// Paddle general variables
constexpr float  paddle_W = 15;
constexpr float paddle_H = 70;
constexpr float paddle_margin_X = 5;
constexpr float paddle_margin_Y = 5;
constexpr float paddle_VY = 10;

void paddle1Events(sf::RectangleShape &paddle1) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        paddle1.move({0, -(paddle_VY)});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        paddle1.move({0, paddle_VY});
    }

    // Check for collisions between the paddle 1 and the map boundaries
    if (paddle1.getPosition().y <= 0) {
        paddle1.setPosition({paddle1.getPosition().x, paddle_margin_Y});
    }

    if (paddle1.getPosition().y + paddle_H >= BASE_H) {
        paddle1.setPosition({paddle1.getPosition().x, BASE_H-paddle_H-paddle_margin_Y});
    }
}

void paddle2Events(sf::RectangleShape &paddle2) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        paddle2.move({0, -(paddle_VY)});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        paddle2.move({0, paddle_VY});
    }

    // Check for collisions between the paddle 2 and the map boundaries
    if (paddle2.getPosition().y <= 0) {
        paddle2.setPosition({paddle2.getPosition().x, paddle_margin_Y});
    }

    if (paddle2.getPosition().y + paddle_H >= BASE_H) {
        paddle2.setPosition({paddle2.getPosition().x, BASE_H-paddle_H-paddle_margin_Y});
    }
}

int main() {
    std::cout << "Pong Game" << std::endl;

    sf::RenderWindow window(sf::VideoMode({BASE_W, BASE_H}), "PONG");
    window.setFramerateLimit(60);

    // Load sound effects
    const sf::SoundBuffer buffer("../assets/sounds/paddleSound.wav");
    sf::Sound hitSound(buffer);

    Ball ball(BASE_W/2.0, BASE_H/2.0, hitSound);

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

    // Load Font
    const sf::Font font("../assets/fonts/PressStart2P-Regular.ttf");

    sf::Text player1Score(font);
    player1Score.setPosition({(BASE_W/2.0) - (BASE_W/4.0), BASE_H/16.0});
    player1Score.setCharacterSize(30);
    player1Score.setStyle(sf::Text::Bold);
    player1Score.setFillColor(sf::Color::White);

    sf::Text player2Score(font);
    player2Score.setPosition({(BASE_W/2.0) + (BASE_W/4.0), BASE_H/16.0});
    player2Score.setCharacterSize(30);
    player2Score.setStyle(sf::Text::Bold);
    player2Score.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        paddle1Events(paddle1);
        paddle2Events(paddle2);
        ball.checkPaddleCollision(paddle1.getGlobalBounds());
        ball.checkPaddleCollision(paddle2.getGlobalBounds());

        player1Score.setString(std::to_string(player1));
        player2Score.setString(std::to_string(player2));

        window.clear(sf::Color::Black);

        ball.draw(window);

        window.draw(paddle1);
        window.draw(paddle2);

        window.draw(player1Score);
        window.draw(player2Score);

        window.display();
    }
    return 0;
}
