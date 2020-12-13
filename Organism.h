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
    int turns;
    bool moved;
    City* city;

    enum cardinal_direction {WEST, NORTH, EAST, SOUTH, NUM_CARDINAL_DIRECTIONS};
    enum ordinal_direction {NORTHWEST, NORTHEAST, SOUTHEAST, SOUTHWEST, NUM_ORDINAL_DIRECTIONS};

public:
    Organism();
    Organism(City& city, int width, int height);
    virtual ~Organism();

    virtual void spawn() = 0;
    virtual void move() = 0;

    virtual void setSpecies(string species) = 0;
    virtual string getSpecies() = 0;
    void setX(int x);
    void setY(int y);
    void setTurns(int mTurns);
    int getX() const;
    int getY() const;
    int getTurns() const;
    void setCity(City* mCity);

    int getRandomInt(int min, int max);
    bool isTurn();
    void endTurn();

    friend ostream& operator<<(ostream &output, Organism *organism);
};

#endif //ASSIGNMENT4_ORGANISM_H