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
            city.setOrganism(humans[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        humans[i].setCity(&city);
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
            city.setOrganism(zombies[i], x, y);
        }
        else {
            i--;
            continue;
        }
    }

    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        zombies[i].setCity(&city);
    }
}

void moveEveryone(Human humans[], Zombie zombies[]) {
    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        zombies[i].move();
    }

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        humans[i].move();
    }
}

int main() {
    City city;
    Human humans[HUMAN_STARTCOUNT];
    Zombie zombies[ZOMBIE_STARTCOUNT];

    // To randomize each new run
    srand((unsigned) time(0));

    initializeHumans(city, humans);
    initializeZombies(city, zombies);

    int iteration = 1;
    double this_time_d;

    while (iteration <= ITERATIONS) {
        this_time_d = (double)clock()/CLOCKS_PER_SEC;
        if (this_time_d >= PAUSE_SECONDS * iteration) {
            cout << (float)clock()/CLOCKS_PER_SEC << endl;
            iteration++;
        }
    }

    cout << city;
    for (int i = 0; i < 10; i++) {
        moveEveryone(humans, zombies);
        cout << city;
    }

//    cout << city;

    return 0;
}