//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Human.h"

using namespace std;

Human::Human() {
    this->species = "Human";
    this->moved = false;
    this->recruitCountdown = HUMAN_BREED;
    this->isRecruiting = false;
}

Human::Human(City& city, int x, int y) {
    this->species = "Human";
    this->city = &city;
    this->x = x;
    this->y = y;
    this->moved = false;
    this->recruitCountdown = HUMAN_BREED;
    this->isRecruiting = false;
}

Human::~Human() = default;

void Human::setSpecies(string species) {
    this->species = species;
}

string Human::getSpecies() {
    return this->species;
}

int Human::getRecruitCountdown() const {
    return recruitCountdown;
}

void Human::setRecruitCountdown(int recruitCountdown) {
    Human::recruitCountdown = recruitCountdown;
}

bool Human::isRecruiting1() const {
    return isRecruiting;
}

void Human::setIsRecruiting(bool isRecruiting) {
    Human::isRecruiting = isRecruiting;
}

void Human::move() {
    auto dir = static_cast<cardinal_direction>(rand() % NUM_CARDINAL_DIRECTIONS);
    Organism *organism = nullptr;

    switch(dir) {
        case WEST:
            if (x != 0) {
                if (this->city->getOrganism(this->x - 1, this->y) == nullptr) {
                    this->city->setOrganism(*organism, this->x, this->y);
                    this->x -= 1;
                    moved = true;
                }
            }
            break;
        case NORTH:
            if (y != 0) {
                if (this->city->getOrganism(this->x, this->y - 1) == nullptr) {
                    this->city->setOrganism(*organism, this->x, this->y);
                    this->y -= 1;
                    moved = true;
                }
            }
            break;
        case EAST:
            if (x != (GRID_WIDTH - 1)) {
                if (this->city->getOrganism(this->x + 1, this->y) == nullptr) {
                    this->city->setOrganism(*organism, this->x, this->y);
                    this->x += 1;
                    moved = true;
                }
            }
            break;
        case SOUTH:
            if (y != GRID_HEIGHT - 1) {
                if (this->city->getOrganism(this->x, this->y + 1) == nullptr) {
                    this->city->setOrganism(*organism, this->x, this->y);
                    this->y += 1;
                    moved = true;
                }
            }
            break;
        case NUM_CARDINAL_DIRECTIONS:
            break;
    }
    if (moved) {
        this->city->setOrganism((Organism &) *this, this->x, this->y);
        moved = false;
    }
    if (recruitCountdown > 0) {
        isRecruiting = false;
        recruitCountdown--;

        if (recruitCountdown == 0)
            isRecruiting = true;
    }
    else
        recruit();
}

string Human::recruit() {
    recruitCountdown = HUMAN_BREED;
    isRecruiting = true;

    auto dir = static_cast<cardinal_direction>(rand() % NUM_CARDINAL_DIRECTIONS);

    switch (dir) {
        case NORTH:
            if (y != 0) {
                if (this->city->getOrganism(this->x, this->y - 1) == nullptr) {
                    return "NORTH";
                }
            }
            break;
        case SOUTH:
            if (y != GRID_HEIGHT - 1) {
                if (this->city->getOrganism(this->x, this->y + 1) == nullptr) {
                    return "SOUTH";
                }
            }
            break;
        case EAST:
            if (x != (GRID_WIDTH - 1)) {
                if (this->city->getOrganism(this->x + 1, this->y) == nullptr) {
                    return "EAST";
                }
            }
            break;
        case WEST:
            if (x != 0) {
                if (this->city->getOrganism(this->x - 1, this->y) == nullptr) {
                    return "WEST";
                }
            }
            break;
        case NUM_CARDINAL_DIRECTIONS:
            break;
    }

    recruitCountdown = 0;
    isRecruiting = false;
    return "NONE";
}
