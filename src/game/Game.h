#ifndef GAME_OF_LIFE_GAME_H
#define GAME_OF_LIFE_GAME_H

#include "Board.h"
#include "../core/Window.h"
#include "State.h"
#include "Render.h"

namespace Game {

    class Game {
    public:
        Game(int w_size, int h_size);
        ~Game();
        void GameCycle();
    private:
        State state;
        Board* board;
        Core::Window *window;
        bool running;

        void HandleEvents();
        void Iteration();
        int CountAliveNeighbors(Coord coords);
    };
}

#endif //GAME_OF_LIFE_GAME_H
