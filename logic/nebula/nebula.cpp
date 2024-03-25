#include "../logic_interface.cpp"
#include <cstring>

class NebulaLogic : public LogicInterface
{
public:
    int calculate(GameBoard *board)
    {
        // Temporary board to store the next state
        GameBoard tempBoard = GameBoard(board->height, board->width);

        board->iterateWithNeighbours([&tempBoard](int row, int col, float value, std::vector<Cell> neighbours)
                                     {
            float sum = 0.0f;

            for (int i = 0; i < neighbours.size(); i++)
            {
                sum += neighbours[i].value;
            }

            tempBoard.grid[row][col] = sum;

            return value; });

        board->copy(&tempBoard);

        return 1;
    }
};
