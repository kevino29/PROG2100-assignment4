//
// Created by Kevin on 12/11/2020.
//

#ifndef ASSIGNMENT4_ORGANISM_H
#define ASSIGNMENT4_ORGANISM_H

#include <iostream>
#include <string>
#include "City.h"

using namespace std;

class City;

class Organism
{
protected:
    string species;
    int x;
    int y;
    int width;
    int height;
    bool moved;
    City city;

    enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
    Organism();
    Organism(City city, int width, int height);
    virtual ~Organism();

    virtual void spawn() = 0;
    virtual void move() = 0;

    virtual void setSpecies(string species) = 0;
    virtual string getSpecies() = 0;
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    int getRandomInt(int min, int max);
    bool isTurn();
    void endTurn();

    friend ostream& operator<<(ostream &output, Organism *organism);
};

#endif //ASSIGNMENT4_ORGANISM_H
