#include "Player.h"
#include "Ship.h"
#include "Grid.h"
#include <iostream>
#include <cstring>
namespace BattleShips
{
    Player::Player(const char *name) : playerName(nullptr)
    {
        grid = new Grid();
        if (name != nullptr)
        {
            playerName = new char[std::strlen(name) + 1];
            std::strcpy(playerName, name);
        }
        for (int i = 0; i < 5; ++i)
        {
            ships[i] = nullptr;
        }

        ships[0] = new Carrier();
        ships[1] = new Battleship();
        ships[2] = new Cruiser();
        ships[3] = new Submarine();
        ships[4] = new Destroyer();
    }
    Player::~Player()
    {
        delete[] playerName;
        playerName = nullptr;

        for (int i = 0; i < 5; ++i)
        {
            delete ships[i];
            ships[i] = nullptr;
        }
        delete grid;
    }
    bool Player::allShipsSunk() const
    {
        for (int i = 0; i < 5; ++i)
        {
            if (ships[i] == nullptr)
                return false;

            if (!ships[i]->isSunk())
                return false;
        }
        return true;
    }
    void Player::displayGrid()
    {
        grid->printGrid();
    }

}