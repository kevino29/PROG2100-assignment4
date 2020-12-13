//
// Created by Kevin on 12/11/2020.
//

#ifndef ASSIGNMENT4_CITY_H
#define ASSIGNMENT4_CITY_H

#include <string>
#include <iostream>
#include "GameSpecs.h"

using namespace std;

class Organism;

const int GRID_WIDTH = GRIDSIZE;
const int GRID_HEIGHT = GRIDSIZE;

class City
{
protected:
    Organism *grid[GRIDSIZE][GRIDSIZE] = {nullptr};

public:
    City();
    virtual ~City();

    Organism* getOrganism( int x, int y );
    void setOrganism(Organism& organism, int x, int y);

    friend ostream& operator<<(ostream& output, City& city);
};

#endif //ASSIGNMENT4_CITY_H
