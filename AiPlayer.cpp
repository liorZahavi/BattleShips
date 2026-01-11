// yarden shriki 322239526
// lior zahavi 325082071
#include <iostream>
#include "AiPlayer.h"
#include "Ship.h"
#include "Grid.h"
#include <iostream>
namespace BattleShips
{
    int AiPlayer::getRandomCoordinate()
    {
        return std::rand() % 10;
    }
    void AiPlayer::placeAllShips()
    {
        Grid *grid_AI = this->getGrid();

        for (int i = 0; i < 5; i++)
        {
            Ship *ship = ships[i];
            char sym = getShipSymbol(ship);

            int shipSize = ship->getSize();

            bool placed = false;
            while (!placed)
            {
                int row = getRandomCoordinate();
                int col = getRandomCoordinate();
                bool horizontal = (std::rand() % 2 == 0);

                if (!grid_AI->inBounds(row, col, shipSize, horizontal))
                {
                    continue;
                }

                placed = grid_AI->tryPlaceShip(row, col, shipSize, horizontal, sym);
            }
        }
    }
    void AiPlayer::makeMove(Player *opponent)
    {
        Grid *grid_AI = opponent->getGrid();

        int row, col;
        char cell;
        do
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            if (row < 0 || row >= 10 || col < 0 || col >= 10)
            {
                std::cout << "Invalid attack position\n";
                return;
            }
            cell = grid_AI->getCell(row, col);
        } while (cell == 'X' || cell == 'M');

        if (cell == 'C' || cell == 'B' || cell == 'R' || cell == 'S' || cell == 'D')
        {
            opponent->registerHit(cell);
            grid_AI->markHit(row, col);
            std::cout << "Hit!\n";
        }
        else
        {
            grid_AI->markMiss(row, col);
            std::cout << "miss!\n";
        }
        std::cout << "computer board:\n";
        this->getGrid()->printGrid();

        std::cout << "Human board:\n";
        grid_AI->printGrid();
    }

}