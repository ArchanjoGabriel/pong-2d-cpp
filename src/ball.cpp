#include "Ball.h"
#include "variables.h"

void Ball::move() {
    ball.move({vx, vy});
}

void Ball::checkMapBoundaries() {
    if (ball.getPosition().y - r <= 0) {
        vy *= -1;
    }

    if (ball.getPosition().y + r >= BASE_H) {
        vy *= -1;
    }

    if (ball.getPosition().x - r <= 0) {
        player2++;
        resetBallPosition();
        CURRENT_STATE = WAITING;
        vy = dy[dist(rng)];
        clock.start();
    }

    if (ball.getPosition().x + r >= BASE_W) {
        player1++;
        resetBallPosition();
        CURRENT_STATE = WAITING;
        vy = dy[dist(rng)];
        clock.start();
    }
}

void Ball::checkPaddleCollision(const sf::FloatRect &bounds) {
    if (bounds.findIntersection(ball.getGlobalBounds())) {
        vx *= -1;
    }
}

void Ball::resetBallPosition() {
    ball.setPosition({BASE_W/2.0, BASE_H/2.0});
}

void Ball::draw(sf::RenderWindow &window) {
    if (clock.getElapsedTime().asSeconds() > WAITING_TIME) {
        clock.reset();
        CURRENT_STATE = MOVING;
    }

    if (CURRENT_STATE == WAITING) {
        window.draw(ball);
    }
    else if (CURRENT_STATE == MOVING) {
        checkMapBoundaries();
        move();
        window.draw(ball);
    }
}
