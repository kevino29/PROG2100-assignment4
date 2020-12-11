#include <iostream>
#include <random>
#include <ctime>
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "GameSpecs.h"

using namespace std;

int generateRandomInt(int max) {
//    random_device dev;
//    mt19937 rng(dev());
//    uniform_int_distribution<mt19937::result_type> distribution(min, max);
//    return distribution(rng);

    return rand() % max;
}

void initializeHumans(City& city, Human humans[]) {
    int x;
    int y;

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        x = generateRandomInt(GRID_WIDTH);
        y = generateRandomInt(GRID_HEIGHT);

        if (city.getOrganism(x, y) == nullptr) {
            humans[i] = Human(city, x, y);
            city.setOrganism(&humans[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        humans[i].setCity(city);
    }
}

void initializeZombies(City& city, Zombie zombies[]) {
    int x;
    int y;

    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        x = generateRandomInt(GRID_WIDTH);
        y = generateRandomInt(GRID_HEIGHT);

        if (city.getOrganism(x, y) == nullptr) {
            zombies[i] = Zombie(city, x, y);
            city.setOrganism(&zombies[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        zombies[i].setCity(city);
    }
}

int main() {
    City city;
    Human humans[HUMAN_STARTCOUNT];
    Zombie zombies[ZOMBIE_STARTCOUNT];

    srand((unsigned) time(0));

    initializeHumans(city, humans);
    initializeZombies(city, zombies);

    cout << city;

    return 0;
}
