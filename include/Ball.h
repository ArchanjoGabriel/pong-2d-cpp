#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H
#include <random>

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#endif //PONG_GAME_BALL_H

class Ball {
    sf::CircleShape ball;

    sf::Clock clock;
    const float WAITING_TIME;

    // States
    const int MOVING;
    const int WAITING;
    int CURRENT_STATE;

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
        : WAITING_TIME(2),
          MOVING(0),
          WAITING(1),
          CURRENT_STATE(WAITING),
          rng(std::random_device{}()),
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

        clock.start();
    }

    void checkPaddleCollision(const sf::FloatRect &bounds);
    void draw(sf::RenderWindow &window);
};