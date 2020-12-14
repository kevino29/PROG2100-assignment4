#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"

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
                    else {
                        // NO HUMANS WERE RECRUITED
                    }
                }
            }
        }
    }
}

void checkZombieConverts(City& city, Zombie convertedZombies[], int convertedHumans) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                if (city.getOrganism(i, j)->getSpecies() == "Zombie" &&
                    ((Zombie*) city.getOrganism(i, j))->isConverting1()) {
                    string dir = ((Zombie*)city.getOrganism(i, j))->convert();
                    Organism* organism = nullptr;

                    if (dir == "NORTH") {
                        convertedZombies[convertedHumans] = Zombie(city, i, j - 1);
                        city.setOrganism(*organism, i, j - 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i, j - 1);
                    }
                    if (dir == "EAST") {
                        convertedZombies[convertedHumans] = Zombie(city, i + 1, j);
                        city.setOrganism(*organism, i + 1, j);
                        city.setOrganism(convertedZombies[convertedHumans++], i + 1, j);
                    }
                    if (dir == "SOUTH") {
                        convertedZombies[convertedHumans] = Zombie(city, i, j + 1);
                        city.setOrganism(*organism, i, j + 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i, j + 1);
                    }
                    if (dir == "WEST") {
                        convertedZombies[convertedHumans] = Zombie(city, i - 1, j);
                        city.setOrganism(*organism, i - 1, j);
                        city.setOrganism(convertedZombies[convertedHumans++], i - 1, j);
                    }
                    if (dir == "NORTHWEST") {
                        convertedZombies[convertedHumans] = Zombie(city, i - 1, j - 1);
                        city.setOrganism(*organism, i - 1, j - 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i - 1, j - 1);
                    }
                    if (dir == "NORTHEAST") {
                        convertedZombies[convertedHumans] = Zombie(city, i + 1, j - 1);
                        city.setOrganism(*organism, i + 1, j - 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i + 1, j - 1);
                    }
                    if (dir == "SOUTHEAST") {
                        convertedZombies[convertedHumans] = Zombie(city, i + 1, j + 1);
                        city.setOrganism(*organism, i + 1, j + 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i + 1, j + 1);
                    }
                    if (dir == "SOUTHWEST") {
                        convertedZombies[convertedHumans] = Zombie(city, i - 1, j + 1);
                        city.setOrganism(*organism, i - 1, j + 1);
                        city.setOrganism(convertedZombies[convertedHumans++], i - 1, j + 1);
                    }
                    else {
                        // NO HUMAN WAS CONVERTED
                    }
                }
            }
        }
    }
}

void checkZombieStarvation(City& city, Human starvedZombies[], int zombiesStarved) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                if (city.getOrganism(i, j)->getSpecies() == "Zombie" &&
                    ((Zombie *) city.getOrganism(i, j))->isStarving1()) {
                    starvedZombies[zombiesStarved] = Human(city, i, j);
                    city.setOrganism(starvedZombies[zombiesStarved++], i, j);
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
    Human starvedZombies[GRIDSIZE*GRIDSIZE];

    int iteration = 0;
    int humansRecruited = 0;
    int humansConverted = 0;
    int zombiesStarved = 0;
    double this_time_d;

    // To randomize each new run
    srand((unsigned) time(0));

    initializeHumans(city, humans);
    initializeZombies(city, zombies);

    cout << "Time Steps: "
         << iteration++ << "        "
         << "Humans: " << city.getHumanCount() << "      "
         << "Zombies: " << city.getZombieCount() << endl
         << city << endl << flush;

    while (iteration <= ITERATIONS) {
        this_time_d = (double)clock()/CLOCKS_PER_SEC;
        if (this_time_d >= PAUSE_SECONDS * iteration) {
            moveEveryone(city);
            checkHumanRecruits(city, recruitedHumans, humansRecruited);
            checkZombieConverts(city, convertedZombies, humansConverted);
            checkZombieStarvation(city, starvedZombies, zombiesStarved);
            cout << "Time Steps: "
                 << iteration++ << "        "
                 << "Humans: " << city.getHumanCount() << "      "
                 << "Zombies: " << city.getZombieCount() << endl
                 << city << endl << flush;
        }

        if (city.getHumanCount() == 0) {
            cout << "The Humans have gone extinct!" << endl;
            break;
        }
        else if (city.getZombieCount() == 0) {
            cout << "The Zombies have gone extinct!" << endl;
            break;
        }
    }
    return 0;
}