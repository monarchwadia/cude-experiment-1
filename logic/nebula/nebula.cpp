#include "../logic_interface.cpp"
#include <cstring>

class NebulaLogic : public LogicInterface
{
public:
    int calculate(GameBoard *board)
    {
        // Temporary board to store the next state
        GameBoard tempBoard = board->clone();

        const int NEIGHBOURHOOD_RADIUS = 1;

        board->iterateWithNeighbours([&tempBoard](int row, int col, float value, std::vector<Cell> neighbours)
                                     {
            float sum = 0.0f;

            for (int i = 0; i < neighbours.size(); i++)
            {
                sum += neighbours[i].value;
            }

            const float INCREASE_SPEED = 0.05f;
            const float DECREASE_SPEED = 0.05f;

            const float LOWER_THRESHOLD = 0.4f;
            const float MIDDLE_THRESHOLD = 0.7f;
            const float UPPER_THRESHOLD = 0.85f;

            if (sum < LOWER_THRESHOLD) {
                tempBoard.grid[row][col] -= DECREASE_SPEED;
            }

            if (sum >= LOWER_THRESHOLD && sum < MIDDLE_THRESHOLD)
            {
                // no change
            }

            if (sum >= MIDDLE_THRESHOLD && sum < UPPER_THRESHOLD)
            {
                tempBoard.grid[row][col] += INCREASE_SPEED;
            }

            if (sum >= UPPER_THRESHOLD)
            {
                tempBoard.grid[row][col] -= DECREASE_SPEED;
            }

            // minmax between 0.0 and 1.0

            if (tempBoard.grid[row][col] < 0.0f)
            {
                tempBoard.grid[row][col] = 0.0f;
            }

            if (tempBoard.grid[row][col] > 1.0f)
            {
                tempBoard.grid[row][col] = 1.0f;
            }

            return value; },
                                     NEIGHBOURHOOD_RADIUS);

        board->copy(&tempBoard);

        return 1;
    }
};
