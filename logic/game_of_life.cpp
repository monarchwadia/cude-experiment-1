#include "logic_interface.cpp"

class GameOfLifeLogic : public LogicInterface
{
public:
    int calculate(GameBoard *board)
    {
        // Temporary board to store the next state
        float **tempBoard = new float *[board->height];
        for (int i = 0; i < board->height; i++)
        {
            tempBoard[i] = new float[board->width];
            for (int j = 0; j < board->width; j++)
            {
                tempBoard[i][j] = board->grid[i][j];
            }
        }

        for (int row = 0; row < board->height; row++)
        {
            for (int col = 0; col < board->width; col++)
            {
                int neighbors = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        if (i == 0 && j == 0)
                        {
                            continue;
                        }
                        int r = row + i;
                        int c = col + j;
                        if (r >= 0 && r < board->height && c >= 0 && c < board->width)
                        {
                            if (board->grid[r][c] > 0.0f)
                            {
                                neighbors += 1;
                            }
                        }
                    }
                }

                // Use tempBoard for storing the next state instead of modifying board->grid directly
                if (board->grid[row][col] == 1.0f)
                {
                    if (neighbors < 2 || neighbors > 3)
                    {
                        tempBoard[row][col] = 0.0f;
                    }
                }
                else
                {
                    if (neighbors == 3)
                    {
                        tempBoard[row][col] = 1.0f;
                    }
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
