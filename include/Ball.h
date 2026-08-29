#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H
#include <random>

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#endif //PONG_GAME_BALL_H

class Ball {
    sf::CircleShape ball;

    float dy[10] = {-5.0, -4.0, -3.0, -2.0, -1.0, 1.0, 2.0, 3.0, 4.0, 5.0};

    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;

    float x;
    float y;
    float r;

    float vx;
    float vy;

    void move();
    void checkMapBoundaries();
    void resetBallPosition();

public:

    Ball(float x, float y)
        : rng(std::random_device{}()),
          dist(0, 9)
    {
        this->x = x;
        this->y = y;
        r = 10.0;

        vx = 5.0;
        vy = dy[dist(rng)];

        ball.setRadius(r);
        ball.setPosition({x, y});
        ball.setFillColor(sf::Color::White);
        ball.setOrigin({r, r});
    }

    void checkPaddleCollision(const sf::FloatRect &bounds);

    void draw(sf::RenderWindow &window) {
        checkMapBoundaries();
        move();
        window.draw(ball);
    }
};