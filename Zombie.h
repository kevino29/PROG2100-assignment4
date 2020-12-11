//
// Created by Kevin on 12/11/2020.
//

#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie( City *city, int width, int height );
    virtual ~Zombie();

    void move();
};

#endif //ASSIGNMENT4_ZOMBIE_H
