#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <vector>
#include <cmath>
#include <algorithm>

namespace Game {
    enum class Cell
    {
        Dead,
        Alive,
        New,
    };

    typedef struct {
        int x;
        int y;
    } Coord;

    class Board {
    public:
        Board(int w_size, int h_size);
        ~Board();
        void ToggleClickedCell(Coord coords);
        void Clear();
        void EditToGame();
        void GameToEdit();
        Coord GetCellSize() { return m_CellSize; }
        Cell ReadCell(int Index) { return edit_Board[Index]; }


        static constexpr int GRID_WIDTH = 80;
        static constexpr int GRID_HEIGHT = 60;

        std::vector<Cell> display_Board;
        std::vector<Cell> edit_Board;
    private:
        const int W_SIZE;
        const int H_SIZE;

        const Coord m_CellSize;
    };
}

#endif //GAME_OF_LIFE_BOARD_H
