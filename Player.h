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
        virtual void placeAllShips() = 0;
        virtual void makeMove(Player *opponent) = 0;
        bool allShipsSunk() const;
        void displayGrid();
        Grid* getGrid() const { return grid; }
        void registerHit(char symbol);
        int shipIndexBySymbol(char symbol) const;
        char getShipSymbol(const Ship *ship) const;

    };
}