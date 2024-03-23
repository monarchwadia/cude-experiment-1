#include <iostream>
#include <SDL2/SDL.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

int render()
{
}

class SdlApp
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isInitialized = false;

public:
    SdlApp() = default;
    ~SdlApp()
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
    }

    bool render()
    {
        if (!isInitialized)
        {
            std::cerr << "SdlApp is not initialized. Call init() first before calling render()." << std::endl;
            return -1;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect rect = {100, 100, 200, 150};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }
};