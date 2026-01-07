#pragma once
#include "Player.h"
namespace BattleShips
{
    class HumanPlayer : public Player
    {
    public:
        explicit HumanPlayer(const char *name) : Player(name) {}
        void placeAllShips();
        void makeMove(Player *opponent);
    };
}