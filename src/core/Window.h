#ifndef GAME_OF_LIFE_WINDOW_H
#define GAME_OF_LIFE_WINDOW_H

#include <SDL2/SDL.h>

namespace Core {
    class Window {
    public:
        int const W_SIZE;
        int const H_SIZE;

        SDL_Renderer* m_Renderer;

        static Window* GetWindow();
        static Window* GetWindow(int w_size, int h_size);

        void exit();

    protected:
        Window(void);
        Window(int w_size, int h_size);
        ~Window();

    private:
        SDL_Window* m_Window;
    };

}

#endif //GAME_OF_LIFE_WINDOW_H
