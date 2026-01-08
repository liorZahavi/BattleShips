#include <iostream>
#include "Grid.h"
namespace BattleShips
{
    Grid::Grid()
    {
        for (int row = 0; row < 10; ++row)
        {
            for (int col = 0; col < 10; ++col)
            {
                cells[row][col] = '~'; // איתחול של ריק
            }
        }
    }

    Grid::~Grid() {}

    bool Grid::isTileOccupied(int row, int col) const // TRUE אם התא לא ריק
    {
        return cells[row][col] != '~';
    }
    bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const // בודקת אם אפשר להציב את הספינה שלא יצא מהלוח
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
            return false;

        if (shipSize <= 0 || shipSize > 10)
            return false;

        if (horizontal) // אופקי
            return (row + shipSize - 1) < 10;

        else // אנכי
            return (col + shipSize - 1) < 10;
    }
    bool Grid::tryPlaceShip(int row, int col, int shipSize, bool horizontal, char symbol)
    {
        if (!inBounds(row, col, shipSize, horizontal))
            return false;

        int dr = horizontal ? 0 : 1;
        int dc = horizontal ? 1 : 0;

        for (int i = 0; i < shipSize; ++i)
            if (isTileOccupied(row + i * dr, col + i * dc))
                return false;

        placeShip(row, col, shipSize, horizontal, symbol);
        return true;
    }

    void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) // בודקת שאפשר להציב גבולות ומציבה בפועל
    {
        if (!inBounds(row, col, shipSize, horizontal))
        {
            std::cout << "Error: Out of bounds\n";
            return;
        }
        int dr = horizontal ? 0 : 1;
        int dc = horizontal ? 1 : 0;
        for (int i = 0; i < shipSize; i++)
        {
            if (isTileOccupied(row + i * dr, col + i * dc))
            {
                std::cout << "Error: Cell is occupied\n";
                return;
            }
        }
        for (int j = 0; j < shipSize; j++)
        {
            cells[row + j * dr][col + j * dc] = symbol;
        }
    }
    void Grid::markHit(int row, int col) // מסמנת פגיעה
    {
        cells[row][col] = 'X';
    }
    void Grid::markMiss(int row, int col) // מסמנת החמצה
    {
        cells[row][col] = 'M';
    }
    void Grid::printGrid() const
    {
        std::cout << "   ";
        for (int col = 0; col < 10; ++col)
            std::cout << col+1 << ' ';
        std::cout << "\n";

        for (int row = 0; row < 10; ++row)
        {
            std::cout << row+1 << "  ";
            for (int col = 0; col <10; ++col)
            {
                std::cout << cells[row][col] << ' ';
            }
            std::cout << "\n";
        }
    }
}
