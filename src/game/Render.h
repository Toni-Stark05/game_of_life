#ifndef GAME_OF_LIFE_RENDER_H
#define GAME_OF_LIFE_RENDER_H

#include "../core/Window.h"
#include "Board.h"
#include "State.h"

namespace Game {
    class Render {
    public:
        static void Draw(Board* board, State state);
        static void DrawLine(Board* board);
    };
}

#endif //GAME_OF_LIFE_RENDER_H
