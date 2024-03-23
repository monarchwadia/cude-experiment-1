#include <iostream>
#include <stdio.h>
#include "gpu.cuh"
#include "view.cpp"

// Constants
#define GRID_HEIGHT 2
#define GRID_WIDTH 2

int main()
{

    float grid[GRID_HEIGHT][GRID_WIDTH] = {
        {1.1f, 2.2f},
        {3.3f, 4.4f}};

    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            std::cout << std::to_string(grid[row][col]);
            // tab

            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    printf("Hello World");
    calculate();

    // game render
    SdlApp app = SdlApp();
    bool running = true;
    SDL_Event event;
    app.init();
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        app.render();
    }
}
