//
// Created by Kevin on 12/11/2020.
//

#ifndef ASSIGNMENT4_CITY_H
#define ASSIGNMENT4_CITY_H

#include <string>
#include <iostream>

using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
    Organism *grid[GRID_WIDTH][GRID_HEIGHT];

public:
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );

    void move();

    friend ostream& operator<<( ostream &output, City &city );

};

#endif //ASSIGNMENT4_CITY_H
