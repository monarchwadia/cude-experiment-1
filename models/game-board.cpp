#ifndef GAME_BOARD_H
#define GAME_BOARD_H 1

#include <functional> // Include this for std::function
#include <vector>

typedef struct Cell
{
    int row;
    int col;
    float value;
} Cell;

// a type for a struct
class GameBoard
{
public:
    int height;
    int width;
    float **grid;

    GameBoard(int h, int w)
    {
        height = h;
        width = w;
        grid = new float *[height];
        for (int i = 0; i < height; i++)
        {
            grid[i] = new float[width];
            for (int j = 0; j < width; j++)
            {
                grid[i][j] = 0.0;
            }
        }
    }

    ~GameBoard()
    {
        for (int i = 0; i < height; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }

    GameBoard clone()
    {
        GameBoard newBoard = GameBoard(height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                newBoard.grid[i][j] = grid[i][j];
            }
        }
        return newBoard;
    }

    void copy(GameBoard *board)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                grid[i][j] = board->grid[i][j];
            }
        }
    }

    void iterate(std::function<float(int, int, float)> func)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                grid[i][j] = func(i, j, grid[i][j]);
            }
        }
    }

    void iterateWithNeighbours(std::function<float(int, int, float, std::vector<Cell>)> func)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::vector<Cell> neighbours = std::vector<Cell>();

                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        int r = i + k;
                        int c = j + l;
                        if (r >= 0 && r < height && c >= 0 && c < width)
                        {
                            neighbours.push_back(Cell{r, c, grid[r][c]});
                        }
                    }
                }

                grid[i][j] = func(i, j, grid[i][j], neighbours);

                // free the neighbours
                neighbours.clear();
            }
        }
    }

    void randomize()
    {
        iterate([](int row, int col, float value)
                { return (float)rand() / RAND_MAX; });
    }
};

#endif