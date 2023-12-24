#include "include/conwaysGameOfLife.h"

// helper function to print menu
void printMenu()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "P - Print Universe" << std::endl;
    std::cout << "N - Move forward in time" << std::endl;
    std::cout << "Q - Quit" << std::endl;
}

// helper function to place a blinker
void placeBlinker(const GameOfLife* game)
{
    game->placeCell(2,1);
    game->placeCell(2,2);
    game->placeCell(2,3);

    return;
}

// helper function to place a toad
void placeToad(const GameOfLife* game)
{
    
    game->placeCell(2,2);
    game->placeCell(2,3);
    game->placeCell(2,4);
    game->placeCell(3,1);
    game->placeCell(3,2);
    game->placeCell(3,3);

    return;
}

int main()
{
    // create game
    auto game = new GameOfLife(6, 6);

    // take a fat blinker
    placeToad(game);
    game->printUniverse();

    // game loop
    printMenu();
    char input;
    std::cin >> input;

    // convert to lower case
    input = std::tolower(input);

    while(input != 'Q')
    {
        // next generation
        if(input == 'N')
        {
            game->nextGeneration();
        }
        // print universe
        else if(input == 'P')
        {
            game->printUniverse();
        }
        // invalid input
        else
        {
            std::cout << "Invalid input" << std::endl;
        }

        // print menu and get input again
        printMenu();
        std::cin >> input;

        // convert to lower case
        input = std::tolower(input);
    }

}
