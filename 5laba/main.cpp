#include <Circle.hpp>
#include <Game.hpp>
int main()
{
    pa::Game game(1000, 600, "Game");
    game.Setup(7);

    game.LifeCycle();

    return 0;
}