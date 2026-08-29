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
}
