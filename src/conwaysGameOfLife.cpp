#include "include/conwaysGameOfLife.h"
#include <exception>
#include <random>
#include <functional>
#include <array>
#include <vector>

GameOfLife::GameOfLife(int height, int width) : seed(0), height(height), width(width)
{
    // allocate the universe
    universe = new bool*[height];
    for(int i = 0; i < height; i++)
    {
        universe[i] = new bool[width];
    }

    // init to 0
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            universe[i][j] = false;
        }
    }

    printUniverse();
    std::cout << std::endl;

}

GameOfLife::GameOfLife(int height, int width, int seed) : GameOfLife(height, width)
{
    this->seed = seed;
}

GameOfLife::~GameOfLife()
{
    for(int i = 0; i < height; i++)
    {
        delete[] universe[i];
    }

    delete[] universe;
}

void GameOfLife::placeCell(int x, int y) const
{
    // check bounds
    if(x >= width || x < 0 || y >= height || y < 0)
    {
        throw std::out_of_range("Can't place a cell there brah");
    }

    // add cell
    universe[x][y] = true;

    printUniverse();
    std::cout << std::endl;

    return void();
}

// using so many new standard library functions
// what am i reading dude
void GameOfLife::populateUniverse(int numCells) const
{
    // seed random and set distribution
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> heightDistribution(0, height);
    std::uniform_int_distribution<int> widthDistribution(0, width);

    // create bound numgenerators
    auto randX = std::bind(heightDistribution, generator);
    auto randY = std::bind(widthDistribution, generator);

    // place cells
    for(int i = 0; i < numCells; i++)
    {
        int cellSpawnX = randX();
        int cellSpawnY = randY();

        // if cell is already at that square, try another lolz
        while(universe[cellSpawnY][cellSpawnX])
        {
            cellSpawnX = randX();
            cellSpawnY = randY();
        }

        // set cell to live at this point
        universe[cellSpawnY][cellSpawnX] = true;
    }

    return void();
}

void GameOfLife::printUniverse() const
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(universe[i][j])
            {
                std::cout << "[O]";
            }
            else
            {
                std::cout << "[ ]";
            }
        }

        std::cout << std::endl;
    }
    return void();
}

void GameOfLife::nextGeneration()
{
    // array to hold all changes on the board
    std::vector<std::pair<int,int>> bitSwitches;

    // neighbor helper arrays
    const std::array<signed char, 8> neighborRows = {0, 0, 1, 1, 1, -1, -1, -1};
    const std::array<signed char, 8> neighborCols = {-1, 1, -1, 0, 1, -1, 0, 1};

    // iterate thru universe and count each cells neighbors
    // there HAS TO BE A QUICKER WAY TO DO THIS
    for(int i = 0; i < height*width; i++)
    {
        // index tings
        int row = i / height;
        int col = i % width;

        // number of living neighbors for our cell
        int neighborCount = 0;

        bool cellAlive = universe[row][col];


        for(int k = 0; k < 8; k++)
        {
            // get neighbor index
            int neighborRow = row + neighborRows[k];
            int neighborCol = col + neighborCols[k];

            // check if index is valid
            if(neighborCol >= width || neighborCol < 0 || neighborRow >= height || neighborRow < 0)
            {
                continue;
            }

            // if cell is alive, call jesus and love thy neighbor
            if(universe[neighborRow][neighborCol])
            {
                neighborCount++;
            }
        }

        // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
        if(cellAlive && neighborCount < 2)
        {
            bitSwitches.push_back(std::pair<int,int>(row,col));
            continue;
        }
        // Any live cell with two or three live neighbours lives on to the next generation.
        if(cellAlive && neighborCount <= 3)
        {
            continue;
        }
        // Any live cell with more than three live neighbours dies, as if by overpopulation.
        if(cellAlive && neighborCount > 3)
        {
            bitSwitches.push_back(std::pair<int,int>(row,col));
            continue;
        }
        // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
        if(!cellAlive && neighborCount == 3)
        {
            bitSwitches.push_back(std::pair<int,int>(row,col));
            continue;
        }

    }

    // bring them back to life or kill em based on rules (frankenstein on them hoes)
    for(std::pair<int,int> coords : bitSwitches)
    {
        universe[coords.first][coords.second] = !universe[coords.first][coords.second];
    }

    return void();
}