// yarden shriki 322239526
// lior zahavi 325082071
#pragma once

namespace BattleShips
{
    class Grid
    {
    private:
        char cells[10][10];

    public:
        Grid();
        ~Grid();
        bool isTileOccupied(int row, int col) const;
        bool inBounds(int row, int col, int shipSize, bool horizontal) const;
        bool tryPlaceShip(int row, int col, int shipSize, bool horizontal, char symbol);
        void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
        void markHit(int row, int col);
        void markMiss(int row, int col);
        char getCell(int row, int col) const
        {
            if (row < 0 || row >= 10 || col < 0 || col >= 10)
                return '?';
            return cells[row][col];
        };
        void printGrid() const;
    };
}