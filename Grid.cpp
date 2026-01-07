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
    void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) // בודקת שאפשר להציב גבולות ומציבה בפועל
    {
        if (!inBounds(row, col, shipSize, horizontal))
        {
            std::cout << "Error: Out of bounds\n";
            return;
        }
        if (horizontal) // אם הוא אופקי
        {
            for (int i = 0; i < shipSize; i++)
            {
                if (cells[row + i][col] != '~')
                {
                    std::cout << "Error: Cell is occupied\n";
                    return;
                }
                else
                {
                    cells[row + i][col] = symbol;
                }
            }
        }
        else
        {
            for (int i = 0; i < shipSize; i++)
            {
                if (cells[row][col + i] != '~')
                {
                    std::cout << "Error: Cell is occupied\n";
                    return;
                }
                else
                {
                    cells[row][col + i] = symbol;
                }
            }
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
            std::cout << col << ' ';
        std::cout << "\n";

        for (int row = 0; row < 10; ++row)
        {
            std::cout << row << "  ";
            for (int col = 0; col < 10; ++col)
            {
                std::cout << cells[row][col] << ' ';
            }
            std::cout << "\n";
        }
    }
}