//
// Created by Sara Larson on 5/2/21.
//

#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball() {
    _ball.setRadius(50);
    _ball.setPosition(-100, 350);
    _ball.setFillColor(sf::Color::Red);
}

sf::CircleShape Ball::getBall() {
    return _ball;
}

void Ball::updatePosition() {
    double x = _ball.getPosition().x;
    double y = _ball.getPosition().y;
    _ball.setPosition(getXDir() + x, getYDir() + y);
}

double Ball::getXDir() {
    return _xDir;
}

double Ball::setXDir(const double x) {
    _xDir = x;
}

double Ball::getYDir() {
    return _yDir;
}

double Ball::setYDir(const double y) {
    _yDir = y;
}