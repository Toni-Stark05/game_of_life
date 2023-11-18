//
// Created by tonistark on 11/12/23.
//

#include "Window.h"

using namespace Core;

Window* window_ = nullptr;

Window::Window(void): Window(1280,1024) {}

Window::Window(int w_size, int h_size): W_SIZE{w_size}, H_SIZE{h_size} {
    SDL_assert(SDL_Init(SDL_INIT_VIDEO) >= 0);

    this->m_Window = SDL_CreateWindow(
            "Coursework: game of life",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            this->W_SIZE,
            this->H_SIZE,
            SDL_WINDOW_SHOWN
    );

    SDL_assert(this->m_Window != NULL);

    this->m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_assert(this->m_Renderer != NULL);

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_Renderer);
}

Window::~Window() {
    SDL_DestroyWindow(this->m_Window);
    SDL_DestroyRenderer(this->m_Renderer);
    this->m_Window = NULL;
    this->m_Renderer = NULL;

    SDL_Quit();
}

Window *Window::GetWindow() {
    if(window_ == nullptr){
        window_ = new Window();
    }
    return window_;
}
Window *Window::GetWindow(int w_size, int h_size) {
    if(window_ == nullptr){
        window_ = new Window(w_size, h_size);
    }
    return window_;
}

void Window::exit() {
    Window::~Window();
}