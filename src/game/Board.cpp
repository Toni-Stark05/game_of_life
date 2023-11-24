#include "Board.h"

Game::Board::Board(int w_size, int h_size): W_SIZE{w_size}, H_SIZE{h_size}, m_CellSize{w_size / GRID_WIDTH, h_size / GRID_HEIGHT}  {
    int gridSize = GRID_WIDTH * GRID_HEIGHT;
    std::vector<Cell> temp(gridSize, Cell::Dead);
    this->display_Board = temp;
    this->edit_Board = temp;
}

void Game::Board::ToggleClickedCell(Coord coords)
{
    int ClickedCell = (floor(coords.x / m_CellSize.x)) + GRID_WIDTH * (floor(coords.y / m_CellSize.y));
    edit_Board[ClickedCell] = edit_Board[ClickedCell] == Cell::Dead ? Cell::New : Cell::Dead;
}

void Game::Board::Clear()
{
    std::fill(this->display_Board.begin(), this->display_Board.end(), Cell::Dead);
    std::fill(this->edit_Board.begin(), this->edit_Board.end(), Cell::Dead);
}

void Game::Board::EditToGame() {
    std::replace_if(this->edit_Board.begin(), this->edit_Board.end(), [](Cell i) {
        return i == Cell::New;
    }, Cell::Alive);

    this->display_Board = this->edit_Board;
}

void Game::Board::GameToEdit() {
    this->edit_Board = this->display_Board;
}

