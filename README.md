# Conways Game of Life 
This is a simple implementation of Conway's Game of Life in C++. The main function provides minimal functionality, but there are several implemented features within the conwaysGameofLife.h header and implementation.

# Functionality
- Creating the Universe: You can create a static GameOfLife universe simply by providing the constructor with the height and width of it. NOTE: This will seed the universe with '0' if you are randomly generating the cells. If you wish to give a custom seed, you must pass the argument to the constructor.
- PlaceCell(x, y): You can place a cell at a given (x,y) coordinate of the universe.
- Populate Universe (beta): You can call the populateUniverse() function to randomly generate a universe full of cells.
- Calculate the Next Generation: By calling the nextGeneration() function, the next generation will be algorithmically created. NOTE: I wrote this function without seeking outside resources, so there may be bugs.
- View the Universe: By calling print, your universe will come to life.

## References
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
