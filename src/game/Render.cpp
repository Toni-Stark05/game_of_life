#include "Render.h"

void Game::Render::Draw(Board *board, State state)
{
    Core::Window *window = Core::Window::GetWindow();
    SDL_Renderer* m_Renderer = window->m_Renderer;

    SDL_RenderClear(m_Renderer);

    for (int i = 0; i < Board::GRID_HEIGHT; ++i)
    {
        for (int j = 0; j < Board::GRID_WIDTH; ++j)
        {
            Cell cell = board->ReadCell(j + Board::GRID_WIDTH * i);
            switch (cell) {
                case Cell::Alive:
                    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 140, 255);
                    break;
                case Cell::Dead:
                    SDL_SetRenderDrawColor(m_Renderer, 120, 120, 120, 0);
                    break;
                case Cell::New:
                    SDL_SetRenderDrawColor(m_Renderer, 90, 120, 120, 0);
                    break;
            }

            SDL_Rect rect;
            rect.x = board->GetCellSize().x * j;
            rect.y = board->GetCellSize().y * i;
            rect.w = board->GetCellSize().x;
            rect.h = board->GetCellSize().y;

            SDL_RenderFillRect(m_Renderer, &rect);
        }
    }

    if (state == State::EDIT) {
        Render::DrawLine(board);
    }

    SDL_RenderPresent(m_Renderer);
}

void Game::Render::DrawLine(Board *board)
{
    Core::Window *window = Core::Window::GetWindow();
    SDL_Renderer* m_Renderer = window->m_Renderer;

    SDL_SetRenderDrawColor(m_Renderer, 180, 180, 180, 0);
    for (int i = 0; i < Board::GRID_HEIGHT; ++i)
    {
        if (i != 0)
        {
            SDL_RenderDrawLine(
                    m_Renderer,
                    0,
                    board->GetCellSize().y * i,
                    board->GetCellSize().x * Board::GRID_WIDTH,
                    board->GetCellSize().y * i
            );
        }
    }

    for (int i = 0; i < Board::GRID_WIDTH; ++i)
    {
        if (i != 0)
        {
            SDL_RenderDrawLine(
                    m_Renderer,
                    board->GetCellSize().x * i,
                    0,
                    board->GetCellSize().x * i,
                    board->GetCellSize().y * Board::GRID_HEIGHT
            );
        }
    }

    SDL_RenderPresent(m_Renderer);
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}
