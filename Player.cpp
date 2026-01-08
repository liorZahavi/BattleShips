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
        grid = nullptr;
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

    char Player::getShipSymbol(const Ship *ship) const
    {
        const char *n = ship->getName();
        if (std::strcmp(n, "Carrier") == 0)
            return 'C';
        if (std::strcmp(n, "Battleship") == 0)
            return 'B';
        if (std::strcmp(n, "Cruiser") == 0)
            return 'R';
        if (std::strcmp(n, "Submarine") == 0)
            return 'S';
        if (std::strcmp(n, "Destroyer") == 0)
            return 'D';
    }
    int Player::shipIndexBySymbol(char symbol) const
    {
        for (int i = 0; i < 5; i++)
        {
            if (!ships[i])
                continue;
            const char *name = ships[i]->getName();

            if (symbol == 'C' && std::strcmp(name, "Carrier") == 0)
                return i;
            if (symbol == 'B' && std::strcmp(name, "Battleship") == 0)
                return i;
            if (symbol == 'R' && std::strcmp(name, "Cruiser") == 0)
                return i;
            if (symbol == 'S' && std::strcmp(name, "Submarine") == 0)
                return i;
            if (symbol == 'D' && std::strcmp(name, "Destroyer") == 0)
                return i;
        }
        return -1;
    }
    void Player::registerHit(char symbol)
    {
        int idx = shipIndexBySymbol(symbol);
        if (idx != -1)
            ships[idx]->takeHit();
    }

}