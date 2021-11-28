//
// Created by Sara Larson on 5/2/21.
//

#ifndef SFML_TEMPLATE_BALL_H
#define SFML_TEMPLATE_BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball();
    sf::CircleShape getBall();
    void updatePosition();
    double setXDir(const double x);
    double setYDir(const double y);
    double getXDir();
    double getYDir();
private:
    sf::CircleShape _ball;
    double _xDir;
    double _yDir;
};

#endif //SFML_TEMPLATE_BALL_H
