//
// Created by Kevin on 12/11/2020.
//

#ifndef _Human_H
#define _Human_H

#include <string>
#include "Organism.h"

class Human : public Organism
{
private:
    int recruitCountdown;
    bool isRecruiting;

public:
    Human();
    Human(City& city, int x, int y );
    ~Human() override;

    void setSpecies(string species) override;
    string getSpecies() override;
    bool isRecruiting1() const;

    void move() override;
    string recruit();
};

#endif //ASSIGNMENT4_HUMAN_H
