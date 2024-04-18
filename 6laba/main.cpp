#include <SFML/Graphics.hpp>
#include "source.hpp"
#include "Game.hpp"

int main()
{
    pa::Game game(1920, 1080, "Game");
    if (!game.Setup(5)) {
        return -1;
    }

    game.Life();

    return 0;
}