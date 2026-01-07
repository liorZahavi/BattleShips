#include "Ship.h"
#include <cstring>
#include <iostream>
namespace BattleShips
{
    Ship::Ship(const char *shipName, int shipSize) : name(nullptr), size(shipSize), hitsTaken(0)
    {
        if (shipName != nullptr)
        {
            name = new char[std::strlen(shipName) + 1];
            std::strcpy(name, shipName);
        }
        else
        {
            name = new char[1];
            name[0] = '\0';
        }
        if (shipSize < 0)
            size = 0;
    }
    Ship::~Ship()
    {
        delete[] name;
        name = nullptr;
    }
    void Ship::takeHit()
    {
        if (hitsTaken >= size)
            return;
        ++hitsTaken;
        std::cout << name << " got hit!" << std::endl;
    }
    bool Ship::isSunk() const
    {
        return hitsTaken >= size;
    }
}