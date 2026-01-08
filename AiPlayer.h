#pragma once
#include "Player.h"
namespace BattleShips
{
    class AiPlayer : public Player
    {
    private:
    int getRandomCoordinate() const;    
    public:
        explicit AiPlayer(const char *name) : Player(name) {}
        void placeAllShips() override;
        void makeMove(Player *opponent) override;
    };
}