//
// Created by Sara Larson on 5/2/21.
//

#include "Dog.h"

// Default constructor for Dog
Dog::Dog() {
    _size = "Medium";
    _grooming = "Medium";
    _fitness = "Medium";
    _bestTemp = "Mid";
    _playfulness = "Medium";
}

// Parameterized constructor for Dog
Dog::Dog(string userSize, string userGroom, string userFit, string userTemp, string userPlay) {
    _size = userSize;
    _grooming = userGroom;
    _fitness = userFit;
    _bestTemp = userTemp;
    _playfulness = userPlay;
}

string Dog::getSize() {
    return _size;
}

string Dog::getGroom() {
    return _grooming;
}

string Dog::getFit() {
    return _fitness;
}

string Dog::getTemp() {
    return _bestTemp;
}

string Dog::getPlay() {
    return _playfulness;
}