#pragma once

namespace BattleShips
{
    class Ship;
    class Grid;
    class Player
    {
    protected:
        char *playerName;
        Ship *ships[5];
        Grid *grid;

    public:
        Player(const char *name);
        virtual ~Player();
        char *GetPlayerName() { return playerName; }
        Grid *getGrid() { return grid; }

        virtual void placeAllShips() = 0;
        virtual void makeMove(Player *opponent) = 0;
        bool allShipsSunk() const;
        void displayGrid();
    };
}