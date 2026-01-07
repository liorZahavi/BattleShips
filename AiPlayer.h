#pragma once
#include "Player.h"
namespace BattleShips
{
    class AiPlayer : public Player
    {
    public:
        explicit AiPlayer(const char *name) : Player(name) {}
        void placeAllShips();
        void makeMove(Player *opponent);
    };
}