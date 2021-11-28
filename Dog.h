//
// Created by Sara Larson on 5/2/21.
//

#ifndef SFML_TEMPLATE_DOG_H
#define SFML_TEMPLATE_DOG_H

#include <string>
using namespace std;

class Dog {
public:
    Dog();
    Dog(string userSize, string userGrooming, string userFitness, string userBestTemp, string userPlayfulness);
    string getSize();
    string getGroom();
    string getFit();
    string getTemp();
    string getPlay();
private:
    string _size;
    string _grooming;
    string _fitness;
    string _bestTemp;
    string _playfulness;
};

#endif //SFML_TEMPLATE_DOG_H
