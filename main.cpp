#include <iostream>
#include <stdio.h>
#include "gpu.cuh"
#define HEIGHT 2
#define WIDTH 2

int main()
{
    float grid[HEIGHT][WIDTH] = {
        {1.1f, 2.2f},
        {3.3f, 4.4f}};

    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            std::cout << std::to_string(grid[row][col]);
            // tab

            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    printf("Hello World");
    calculate();
}
