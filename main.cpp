#include <iostream>
#include <random>
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
            Human human = Human(city, x, y);
            humans[i] = human;
            city.setOrganism(&humans[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }
}

void initializeZombies(City& city, Zombie zombies[]) {
    int x;
    int y;

    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        x = generateRandomInt(GRID_WIDTH);
        y = generateRandomInt(GRID_HEIGHT);

        if (city.getOrganism(x, y) == nullptr) {
            Zombie zombie = Zombie(city, x, y);
            zombies[i] = zombie;
            city.setOrganism(&zombies[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }
}

int main() {
    City city;
    Human humans[HUMAN_STARTCOUNT];
    Zombie zombies[ZOMBIE_STARTCOUNT];

    initializeHumans(city, humans);
    initializeZombies(city, zombies);

    cout << city;

    return 0;
}
