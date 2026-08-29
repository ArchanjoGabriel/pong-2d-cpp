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
    }

    if (ball.getPosition().x + r >= BASE_W) {
        player1++;
        resetBallPosition();
    }
}

void Ball::resetBallPosition() {
    ball.setPosition({BASE_W/2.0, BASE_H/2.0});
}
