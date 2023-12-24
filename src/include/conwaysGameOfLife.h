#include <iostream>

/*
Random Recreation of Conway's Game of Life
    - Cells live in 2d bool array universe
    - A cell is "living" at each true index of the array

(taken from wikipedia):
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
*/

class GameOfLife
{
public:
    // generates a universe with seed 0
    GameOfLife(int height, int width);

    // generates universe with seed
    explicit GameOfLife(int height, int width, int seed);

    // deconstructor for the universe
    ~GameOfLife();

    // place a cell into the universe
    void placeCell(int x, int y) const; 

    // randomly place numCells cells into the universe based on seed
    void populateUniverse(int numCells) const; 

    // calculates the next generation of life and updates members
    void nextGeneration(); 

    // prints the current universe of life to the console
    void printUniverse() const; 


private: 

    int seed; // jus for storage
    bool** universe; int height; int width; // universe and dimensions.

};