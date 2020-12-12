//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include <windows.h>
#include "Organism.h"
#include "City.h"
#include "GameSpecs.h"

using namespace std;

City::City() {

}

City::~City() = default;

Organism* City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism& organism, int x, int y) {
    this->grid[x][y] = &organism;
}

void City::move() {

}

ostream& operator<<(ostream& output, City& city) {
    // COLORIZING CONSOLE TEXT
    // https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < GRID_HEIGHT; i++) {
        SetConsoleTextAttribute(hConsole, GRID_COLOR);
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (j == 0)
                output << "+---+";
            else
                output << "---+";
        }
        output << endl;

        for (int k = 0; k < GRID_WIDTH; k++) {
            if (k == 0) {
                SetConsoleTextAttribute(hConsole, GRID_COLOR);
                output << "| ";

                if (city.grid[k][i] != nullptr) {
                    if ((city.grid[k][i])->getSpecies() == "Human") {
                        SetConsoleTextAttribute(hConsole, HUMAN_COLOR);
                        output << (char)HUMAN_CH;
                    } else {
                        SetConsoleTextAttribute(hConsole, ZOMBIE_COLOR);
                        output << (char)ZOMBIE_CH;
                    }
                }
                else
                    output << (char)SPACE_CH;

                SetConsoleTextAttribute(hConsole, GRID_COLOR);
                output << " |";
            }
            else {
                SetConsoleTextAttribute(hConsole, ZOMBIE_COLOR);
                output << " ";

                if (city.grid[k][i] != nullptr) {
                    if (city.grid[k][i]->getSpecies() == "Human") {
                        SetConsoleTextAttribute(hConsole, HUMAN_COLOR);
                        output << (char)HUMAN_CH;
                    } else {
                        SetConsoleTextAttribute(hConsole, ZOMBIE_COLOR);
                        output << (char)ZOMBIE_CH;
                    }
                }
                else
                    output << (char)SPACE_CH;

                SetConsoleTextAttribute(hConsole, GRID_COLOR);
                output << " |";
            }
        }
        output << endl;

        if (i == GRID_HEIGHT - 1) { // the last row
            SetConsoleTextAttribute(hConsole, GRID_COLOR);
            for (int l = 0; l < GRID_WIDTH; l++) {
                if (l == 0)
                    output << "+---+";
                else
                    output << "---+";
            }
            output << endl;
        }
    }
    return output;
}
