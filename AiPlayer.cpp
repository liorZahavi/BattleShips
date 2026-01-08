#include <iostream>
#include "AiPlayer.h"
#include "Player.h"
#include "Ship.h"
#include "Grid.h"
#include "cstring"

namespace BattleShips
{
    int AiPlayer::getRandomCoordinate() const
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
                if (!placed)
                    std::cout << "Invalid placement, try again.\n";
            }
        }
    }
    void AiPlayer::makeMove(Player *opponent)
    {
        Grid *og = opponent->getGrid();

    int row, col;
    char cell;
    do
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        cell = og->getCell(row, col);
    } while (cell == 'X' || cell == 'M');

    if (cell == 'C' || cell == 'B' || cell == 'R' || cell == 'S' || cell == 'D')
    {
        opponent->registerHit(cell);
        og->markHit(row, col);
        std::cout << "Hit!\n";
    }
    else
    {
        og->markMiss(row, col);
        std::cout << "miss!\n";
    }

    this->getGrid()->printGrid();
    og->printGrid();
    }

}