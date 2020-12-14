//
// Created by Kevin on 12/11/2020.
//

#ifndef _Zombie_H
#define _Zombie_H

#include <string>
#include "Organism.h"

class Zombie : public Organism
{
private:
    int eatCooldown;
    int convertCooldown;
    bool isStarving;
    bool isConverting;

public:
    Zombie();
    Zombie(City& city, int x, int y);
    ~Zombie() override;

    void setSpecies(string species) override;
    string getSpecies() override;
    bool isStarving1() const;
    bool isConverting1() const;

    void move() override;
    string convert();
};

#endif //ASSIGNMENT4_ZOMBIE_H
