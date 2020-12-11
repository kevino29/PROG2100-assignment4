//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "City.h"

using namespace std;

City::City() {

}

City::~City() = default;

Organism* City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    this->grid[x][y] = organism;
}

void City::move() {

}

ostream& operator<<(ostream& output, City& city) {
    string terminalGrid = "";

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (j == 0)
                terminalGrid += "+---+";
            else
                terminalGrid += "---+";
        }
        terminalGrid += "\n";

        for (int k = 0; k < GRID_WIDTH; k++) {
            if (k == 0)
                terminalGrid = terminalGrid + "| " + "X" + " |";
            else
                terminalGrid = terminalGrid + " " + "X" + " |";
        }
        terminalGrid += "\n";

        if (i == GRID_HEIGHT - 1) { // the last row
            for (int l = 0; l < GRID_WIDTH; l++) {
                if (l == 0)
                    terminalGrid += "+---+";
                else
                    terminalGrid += "---+";
            }
            terminalGrid += "\n";
        }
    }
    output << terminalGrid;
    return output;
}
