#include "Game.h"

Game::Game::Game(int w_size, int h_size) {
    this->window = Core::Window::GetWindow(w_size, h_size);
    this->state = State::EDIT;
    this->board = new Board(w_size, h_size);
    this->running = true;
}

Game::Game::~Game() {
    this->window->exit();
    this->running = false;
}

void Game::Game::GameCycle() {
    while (this->running) {
        HandleEvents();
        if(this->state == State::GAME)
        {
            this->board->GameToEdit();
            this->Iteration();
        }

        Render::Draw(this->board, this->state);

        SDL_Delay(100);
    }
}

void Game::Game::Iteration() {
    std::vector<Cell> newBoard(this->board->display_Board);
    std::vector<Cell> lastBoard(this->board->display_Board);

    int GRID_WIDTH = this->board->GRID_WIDTH;
    int GRID_HEIGHT = this->board->GRID_HEIGHT;

    for (int i = 0; i < Board::GRID_HEIGHT; ++i)
    {
        for (int j = 0; j < GRID_WIDTH; ++j)
        {
            if (lastBoard[j + GRID_WIDTH * i] == Cell::Alive)
            {
                if (CountAliveNeighbors({j, i}) < 2 || CountAliveNeighbors({j, i}) > 3)
                {
                    newBoard[j + GRID_WIDTH * i] = Cell::Dead;
                }
            }
            else
            {
                if (CountAliveNeighbors({j, i}) == 3)
                {
                    newBoard[j + GRID_WIDTH * i] = Cell::Alive;
                }
            }
        }
    }

    this->board->display_Board = newBoard;
}

int Game::Game::CountAliveNeighbors(Coord coords) {
    int count = 0;
    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j <2; ++j)
        {
            int absoluteX = coords.x + i;
            int absoluteY = coords.y + j;
            if (absoluteX == -1 || absoluteX == this->board->GRID_WIDTH ||
                absoluteY == -1 || absoluteY == this->board->GRID_HEIGHT ||
                (i == 0 && j == 0))
            {
                continue;
            }

            if (this->board->display_Board[absoluteX + this->board->GRID_WIDTH * absoluteY] == Cell::Alive)
            {
                ++count;
            }
        }
    }

    return count;
}

void Game::Game::HandleEvents()
{
    SDL_Event Event;
    while(SDL_PollEvent(&Event))
    {
        switch(Event.type)
        {
            case SDL_QUIT:
                this->window->exit();
                this->running = false;
                break;

            case SDL_KEYDOWN:
                if (Event.key.keysym.sym == SDLK_SPACE)
                {
                    if(this->state == State::EDIT) {
                        this->board->EditToGame();
                        this->state = State::GAME;
                    } else {
                        this->board->GameToEdit();
                        this->state = State::EDIT;
                    }
                }
                else if (Event.key.keysym.sym == SDLK_c)
                {
                    this->board->Clear();
                } else if (Event.key.keysym.sym == SDLK_ESCAPE) {
                    delete this;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (this->state == State::EDIT)
                {
                    if (Event.button.button == SDL_BUTTON_LEFT)
                    {
                        this->board->ToggleClickedCell({Event.button.x, Event.button.y});
                    }
                }
                break;
        }
    }
}
