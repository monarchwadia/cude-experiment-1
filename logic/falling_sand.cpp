#include "logic_interface.cpp"
#include <cstring>

class FallingSandLogic : public LogicInterface
{
public:
    int calculate(GameBoard *board)
    {
        // Temporary board to store the next state
        float **tempBoard = new float *[board->height];
        for (int i = 0; i < board->height; i++)
        {
            tempBoard[i] = new float[board->width];
            std::memcpy(tempBoard[i], board->grid[i], board->width * sizeof(float));
        }

        for (int row = 0; row < board->height - 1; row++)
        {
            for (int col = 0; col < board->width; col++)
            {
                if (board->grid[row][col] == 1.0f && board->grid[row + 1][col] == 0.0f)
                {
                    tempBoard[row][col] = 0.0f;
                    tempBoard[row + 1][col] = 1.0f;
                }
            }
        }

        // Update the original board with the next state
        for (int i = 0; i < board->height; i++)
        {
            for (int j = 0; j < board->width; j++)
            {
                board->grid[i][j] = tempBoard[i][j];
            }
        }

        // Cleanup the temporary board
        for (int i = 0; i < board->height; i++)
        {
            delete[] tempBoard[i];
        }
        delete[] tempBoard;

        return 0;
    }
};
