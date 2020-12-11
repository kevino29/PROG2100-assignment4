//
// Created by Kevin on 12/11/2020.
//

#ifndef _Zombie_H
#define _Zombie_H

#include <string>
#include "Organism.h"
#include "Human.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie(City city, int width, int height);
    ~Zombie() override;

    void setSpecies(string species) override;
    string getSpecies() override;

    void spawn() override;
    void move() override;
    void convert(Organism& organism);
};

#endif //ASSIGNMENT4_ZOMBIE_H
