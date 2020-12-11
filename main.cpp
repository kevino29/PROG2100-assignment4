#include <iostream>
#include <random>
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "GameSpecs.h"

using namespace std;

int getRandomInt (int min, int max) {
    return rand() % max + min;
}

int main() {
//    Human human = Human();
//
//    for (int i = 0; i < 10; i++) {
//        cout << getRandomInt(i, GRIDSIZE) << endl;
//    }

    City city;
    cout << city;

    return 0;
}
