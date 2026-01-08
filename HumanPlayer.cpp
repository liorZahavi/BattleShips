#include "HumanPlayer.h"
#include "Player.h"
#include "Grid.h"
#include "Ship.h"
#include <iostream>
#include "cstring"
namespace BattleShips
{
    void HumanPlayer::placeAllShips()
    {
        Grid *og = this->getGrid();
        for (int i = 0; i < 5; i++)
        {
            Ship *ship = ships[i];
            char sym = getShipSymbol(ships[i]);
            bool placed = false;
            while (!placed)
            {
                int row, col;
                char dir;

                std::cout << "place ship " << ship->getName() << "(row,col,H/V)" << std::endl;
                std::cin >> row >> col >> dir;

                bool horizontal = (dir == 'H' || dir == 'h');
                if (!og->inBounds(row, col, ship->getSize(), horizontal))
                {
                    std::cout << "Invalid placement, try again.\n";
                    continue;
                }
                placed = og->tryPlaceShip(row, col, ship->getSize(), horizontal, sym);

                if (!placed)
                    std::cout << "Invalid placement, try again.\n";
            }
        }
    }
    void HumanPlayer::makeMove(Player *opponent)
    {
        Grid *og = opponent->getGrid();
        int row, col;
        std::cout << "Enter attack placement(row,col): " << std::endl;
        std::cin >> row >> col;
        row--;
        col--;
        char cell = og->getCell(row, col);
        if (cell == 'X' || cell == 'M')
        {
            std::cout << "Already attacked here\n";
            return;
        }
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
std::cout<<"Human board:\n";
        this->getGrid()->printGrid();

        std::cout<<"computer board:\n";
        og->printGrid();
    }
}