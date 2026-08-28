#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#endif //PONG_GAME_BALL_H

class Ball {
    sf::CircleShape ball;

    float x;
    float y;
    float r;

    float vx;
    float vy;

public:

    Ball(float x, float y) {
        this->x = x;
        this->y = y;
        r = 10.0;

        vx = 5.0;
        vy = 0.0;

        ball.setRadius(r);
        ball.setPosition({x, y});
        ball.setFillColor(sf::Color::White);
        ball.setOrigin({r, r});
    }

    void draw(sf::RenderWindow &window) {
        window.draw(ball);
    }
};