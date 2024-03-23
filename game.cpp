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
                    board[row][col] = 0.0;
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
        const int target_fps = 60;
        const int target_frame_time = 1000 / target_fps;
        int frame_start, frame_time;

        bool running = true;
        SDL_Event event;
        while (running)
        {
            frame_start = SDL_GetTicks();

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            update();
            app->render((float *)board, GRID_HEIGHT, GRID_WIDTH);

            frame_time = SDL_GetTicks() - frame_start;
            if (frame_time < target_frame_time)
            {
                SDL_Delay(target_frame_time - frame_time);
            }
        }

        return 1;
    }
};

#endif