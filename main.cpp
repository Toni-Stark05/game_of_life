#include "src/game/Game.h"

int main() {
    Game::Game* game = new Game::Game(1280,1024);
    game->GameCycle();
    return 0;
}
