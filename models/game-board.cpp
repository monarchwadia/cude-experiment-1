#ifndef GAME_BOARD_H
#define GAME_BOARD_H 1

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
};

#endif