//yarden shriki 322239526
//lior zahavi 325082071
#pragma once
#include "Player.h"
namespace BattleShips
{
    class HumanPlayer : public Player
    {
    public:
        explicit HumanPlayer(const char *name) : Player(name) {}
        void placeAllShips() override;
        void makeMove(Player *opponent) override;
    };
}