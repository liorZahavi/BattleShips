//yarden shriki 322239526
//lior zahavi 325082071
#pragma once

namespace BattleShips
{
    class Player;
    class Game
    {
    private:
        Player *player1;
        Player *player2;

    public:
        Game(Player *p1, Player *p2);
        void setup();
        void start();
        bool isGameOver() const;
    };
}