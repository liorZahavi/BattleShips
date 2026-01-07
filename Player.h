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
        virtual void placeAllShips();
        virtual void makeMove(Player *opponent);
        bool allShipsSunk() const;
        void displayGrid();
    };
}