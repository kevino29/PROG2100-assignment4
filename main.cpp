#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <windows.h>
#include <conio.h>
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

void moveEveryone(City& city) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                if (city.getOrganism(i, j)->getSpecies() == "Human")
                    city.getOrganism(i, j)->move();
            }
        }
    }

    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                if (city.getOrganism(i, j)->getSpecies() == "Zombie")
                    city.getOrganism(i, j)->move();
            }
        }
    }
}

void checkHumanRecruits(City& city, Human recruitedHumans[], int humansRecruited) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                if (city.getOrganism(i, j)->getSpecies() == "Human" &&
                    ((Human*)city.getOrganism(i, j))->isRecruiting1()) {
                    string dir = ((Human*)city.getOrganism(i, j))->recruit();
                    cout << "Human at " << i << " " << j << " is recruiting to the ";
                    cout << dir << "!" << endl;

                    if (dir == "NORTH") {
                        recruitedHumans[humansRecruited] = Human(city, i, j - 1);
                        city.setOrganism(recruitedHumans[humansRecruited++], i, j - 1);
                    }
                    else if (dir == "SOUTH") {
                        recruitedHumans[humansRecruited] = Human(city, i, j + 1);
                        city.setOrganism(recruitedHumans[humansRecruited++], i, j + 1);
                    }
                    else if (dir == "EAST") {
                        recruitedHumans[humansRecruited] = Human(city, i + 1, j);
                        city.setOrganism(recruitedHumans[humansRecruited++], i + 1, j);
                    }
                    else if (dir == "WEST") {
                        recruitedHumans[humansRecruited] = Human(city, i - 1, j);
                        city.setOrganism(recruitedHumans[humansRecruited++], i - 1, j);
                    }
                }
            }
        }
    }
}

int main() {
    City city;                                  //  These store the
    Human humans[HUMAN_STARTCOUNT];             //  application data
    Zombie zombies[ZOMBIE_STARTCOUNT];          //  in memory.

    Human recruitedHumans[GRIDSIZE*GRIDSIZE];
    Zombie convertedZombies[GRIDSIZE*GRIDSIZE];

    int iteration = 0;
    int humansRecruited = 0;
    int humansConverted = 0;
    double this_time_d;

    // To randomize each new run
    srand((unsigned) time(0));

    initializeHumans(city, humans);
    initializeZombies(city, zombies);

    cout << "Steps: "
         << iteration++ << "        "
         << "Humans: " << city.getHumanCount() << "      "
         << "Zombies: " << city.getZombieCount() << endl
         << city << endl << flush;

    while (iteration <= ITERATIONS) {
        this_time_d = (double)clock()/CLOCKS_PER_SEC;
        if (this_time_d >= PAUSE_SECONDS * iteration) {
            moveEveryone(city);
            checkHumanRecruits(city, recruitedHumans, humansRecruited);
            cout << "Steps: "
                 << iteration++ << "        "
                 << "Humans: " << city.getHumanCount() << "      "
                 << "Zombies: " << city.getZombieCount() << endl
                 << city << endl << flush;
        }
    }

    return 0;
}