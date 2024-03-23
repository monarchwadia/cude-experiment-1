#ifndef VIEW_H
#define VIEW_H 1

#include <iostream>
#include <SDL2/SDL.h>
#include "models/game-board.cpp"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class GameView
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isInitialized = false;

public:
    GameView() = default;
    ~GameView()
    {
        // cleanup
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }

        if (window)
        {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }

    bool init()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return -1;
        }

        window = SDL_CreateWindow("SDL2 Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window)
        {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            return -1;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer)
        {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return -1;
        }

        isInitialized = true;

        return 1;
    }

    bool render(GameBoard *board)
    {
        if (!isInitialized)
        {
            std::cerr << "SdlApp is not initialized. Call init() first before calling render()." << std::endl;
            return -1;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int row = 0; row < board->height; row++)
        {
            for (int col = 0; col < board->width; col++)
            {
                float value = board->grid[row][col];
                SDL_Rect rect = {col * 10, row * 10, 10, 10};
                SDL_SetRenderDrawColor(renderer, 255 * value, 255 * value, 255 * value, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        // SDL_Rect rect = {100, 100, 200, 150};
        // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        return 1;
    }
};

#endif