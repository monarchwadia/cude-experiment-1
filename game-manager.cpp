#ifndef GAME_H
#define GAME_H 1

#include <iostream>
#include <SDL2/SDL.h>
#include "game-view.cpp"
#include "models/game-board.cpp"
#include "logic/logic_interface.cpp"

// Constants
#define GRID_HEIGHT 100
#define GRID_WIDTH 100

class GameManager
{

public:
    GameBoard *board;
    GameView *app;
    LogicInterface *logic;

public:
    GameManager(GameView *_app, LogicInterface *_logic, GameBoard *board) : app(_app), logic(_logic), board(board) {}
    ~GameManager() = default;

    int update()
    {
        return logic->calculate(board);
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

                app->processEvent(&event);
            }

            update();
            app->render(board);

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