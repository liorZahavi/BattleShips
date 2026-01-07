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
            bool placed = false;
            while (!placed)
            {
                int row, col;
                char dir;

                std::cout << "place ship " << ship->getName() << "(row,col,H/V)" << std::endl;
                std::cin >> row >> col >> dir;
                row--;
                col--;
                bool horizontal = (dir == 'H' || dir == 'h');
                if (!og->inBounds(row, col, ship->getSize(), horizontal))
                {
                    std::cout << "Invalid placement, try again.\n";
                    continue;
                }
                og->placeShip(row, col, ship->getSize(), horizontal, 'S');
                placed = true;
            }
        }
    }
    void HumanPlayer::makeMove(Player *opponent)
    {
        int row, col;
        bool valid = false;
        std::cout << "Enter attack placement(row,col): " << std::endl;
        std::cin >> row >> col;
        row--;
        col--;
        Grid *og = opponent->getGrid();
        char cell = og->getCell(row, col);
        if (cell == 'X' || cell == 'M')
        {
            std::cout << "Already attacked here\n";
            return;
        }
        if (cell == 'S')
        {
            og->markHit(row, col);
            std::cout << "hit!\n";
        }
        else
        {
            og->markMiss(row, col);
            std::cout << "miss!\n";
            return;
        }
        valid = true;

        this->getGrid()->printGrid();
        og->printGrid();
    }
}