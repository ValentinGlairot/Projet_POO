#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;
    int x;
    int y;

public:
    Cell(int x, int y, bool isAlive = false);
    bool getState() const;
    void setState(bool state);
    int getX() const;
    int getY() const;

    // Add this line:
    bool operator==(const Cell& other) const;
};

#endif // CELL_H
