#include "Grid.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Grid::Grid(int w, int h) : width(w), height(h), cells(w, std::vector<Cell>(h)) {}

void Grid::initializeRandom() {
    std::srand(std::time(nullptr));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            cells[x][y].setState(std::rand() % 2);
        }
    }
}

void Grid::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    file >> width >> height;
    cells = std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int state;
            file >> state;
            cells[x][y].setState(state == 1);
        }
    }
    file.close();
}

void Grid::update() {
    std::vector<std::vector<Cell>> newCells = cells;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int aliveNeighbors = countAliveNeighbors(x, y);
            if (cells[x][y].getState()) {
                newCells[x][y].setState(aliveNeighbors == 2 || aliveNeighbors == 3);
            } else {
                newCells[x][y].setState(aliveNeighbors == 3);
            }
        }
    }

    cells = newCells;
}

int Grid::countAliveNeighbors(int x, int y) const {
    int count = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignore la cellule elle-même

            int nx = x + dx, ny = y + dy;

            // Vérifie si la cellule voisine est valide et vivante
            if (isValidCell(nx, ny) && cells[nx][ny].getState()) {
                ++count;
            }
        }
    }

    return count;
}

bool Grid::isValidCell(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Grid::operator==(const Grid& other) const {
    if (width != other.width || height != other.height) {
        return false;
    }
    return cells == other.cells;
}
