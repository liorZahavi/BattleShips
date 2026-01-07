#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    BattleShips::Player *HumanPlayer = new BattleShips::HumanPlayer("Human");
    BattleShips::Player *AiPlayer = new BattleShips::AiPlayer("Computer");
    BattleShips::Game game(HumanPlayer, AiPlayer);
    game.setup();
    game.start();
    delete HumanPlayer;
    delete AiPlayer;
    return 0;
}
