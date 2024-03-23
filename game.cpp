#ifndef GAME_H
#define GAME_H 1

#include <iostream>
#include <SDL2/SDL.h>
#include "view.cpp"

// Constants
#define GRID_HEIGHT 2
#define GRID_WIDTH 2

class Game
{

public:
    float board[GRID_HEIGHT][GRID_WIDTH] = {};
    SdlApp *app;

public:
    Game(SdlApp *_app)
    {
        app = _app;
        for (int row = 0; row < GRID_HEIGHT; row++)
        {
            for (int col = 0; col < GRID_WIDTH; col++)
            {
                board[row][col] = (float)(row + col);
            }
        }
    }
    ~Game() = default;

    int update()
    {
        for (int row = 0; row < GRID_HEIGHT; row++)
        {
            for (int col = 0; col < GRID_WIDTH; col++)
            {
                if (board[row][col] >= 1.0)
                {
                    board[row][col] = 1.0;
                }
                else
                {
                    board[row][col] += 0.001;
                }
            }
        }
        return 0;
    }

    bool loop()
    {
        bool running = true;
        SDL_Event event;
        while (running)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            app->render();
        }

        return 1;
    }
};

#endif