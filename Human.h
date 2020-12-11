//
// Created by Kevin on 12/11/2020.
//

#ifndef _Human_H
#define _Human_H

#include <string>
#include "Organism.h"

class Human : public Organism
{
public:
    Human();
    Human( City *city, int width, int height );
    ~Human() override;

    void spawn() override;
    void move() override;
    string getSpecies() override;
};

#endif //ASSIGNMENT4_HUMAN_H
