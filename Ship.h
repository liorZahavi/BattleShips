#pragma once

namespace BattleShips
{
    class Ship
    {
    private:
        char *name;
        int size;
        int hitsTaken;

    public:
        Ship(const char *shipName, int shipSize);
        virtual ~Ship();
        int getHitsTaken() const { return hitsTaken; }
        int getSize() const { return size; }
        virtual void takeHit();
        bool isSunk() const;

        Ship(const Ship &) = delete;
        Ship &operator=(const Ship &) = delete;
    };
    class Carrier : public Ship
    {
    public:
        explicit Carrier() : Ship("Carrier", 5) {}
    };
    class Battleship : public Ship
    {
    public:
        explicit Battleship() : Ship("Battleship", 4) {}
    };
    class Cruiser : public Ship
    {
    public:
        explicit Cruiser() : Ship("Cruiser", 3) {}
    };
    class Submarine : public Ship
    {
    public:
        explicit Submarine() : Ship("Submarine", 3) {}
    };
    class Destroyer : public Ship
    {
    public:
        explicit Destroyer() : Ship("Destroyer", 2) {}
    };
}