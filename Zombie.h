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
    bool isConverting;

public:
    Zombie();
    Zombie(City& city, int x, int y);
    ~Zombie() override;

    void setSpecies(string species) override;
    string getSpecies() override;
    int getConvertCooldown() const;
    void setConvertCooldown(int convertCooldown);
    bool isConverting1() const;
    void setIsConverting(bool isConverting);

    void move() override;
    string convert();
    void starve();
};

#endif //ASSIGNMENT4_ZOMBIE_H
