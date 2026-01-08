//yarden shriki 322239526
//lior zahavi 325082071
#pragma once
#include "Player.h"
namespace BattleShips
{
    class AiPlayer : public Player
    {
    private:
      int getRandomCoordinate() ;
    public:
        explicit AiPlayer(const char *name) : Player(name) {}
        void placeAllShips() override;
        void makeMove(Player *opponent) override;
    };
}