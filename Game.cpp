#include "Game.h"
#include "Player.h"
#include <iostream>
namespace BattleShips
{
    Game::Game(Player *p1, Player *p2) : player1(p1), player2(p2)
    {
        if (!player1 || !player2)
            throw std::invalid_argument("Game received null player");
    }
    void Game::setup()
    {
        player1->placeAllShips();
        player2->placeAllShips();
    }
    void Game::start()
    {
        while (!isGameOver())
        {
            player1->makeMove(player2);
            if (player2->allShipsSunk())
            {
                std::cout << "The winner is:" << player1->GetPlayerName() << std::endl;
                return;
            }
            player2->makeMove(player1);
            if (player1->allShipsSunk())
            {
                std::cout << "The winner is: " << player2->GetPlayerName() << std::endl;
                return;
            }
        }
    }
    bool Game::isGameOver() const
    {
        return (player1->allShipsSunk() || player2->allShipsSunk());
    }
}