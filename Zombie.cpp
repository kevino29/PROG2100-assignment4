//
// Created by Kevin on 12/11/2020.
//

#include "Zombie.h"

using namespace std;

Zombie::Zombie() {}

Zombie::Zombie(City *city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

Zombie::~Zombie() = default;

void Zombie::move() {

}