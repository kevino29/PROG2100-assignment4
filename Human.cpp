//
// Created by Kevin on 12/11/2020.
//

#include "Human.h"

using namespace std;

Human::Human() {}

Human::Human(City *city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

Human::~Human() = default;

void Human::move() {

}