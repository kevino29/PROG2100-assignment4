//
// Created by Kevin on 12/11/2020.
//

#ifndef _Zombie_H
#define _Zombie_H

#include <string>
#include "Organism.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie( City *city, int width, int height );
    ~Zombie() override;

    void spawn() override;
    void move() override;
    string getSpecies() override;
};

#endif //ASSIGNMENT4_ZOMBIE_H
