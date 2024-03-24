#ifndef MAIN_H
#define MAIN_H 1

#include <iostream>
#include <stdio.h>
#include "gpu.cuh"
#include "game-view.cpp"
#include "game-manager.cpp"
#include "logic/game_of_life.cpp"

int main()
{
    // calculate();

    // game render
    GameView gameView = GameView();
    gameView.init();

    GameOfLifeLogic logic = GameOfLifeLogic();
    GameBoard gameBoard = GameBoard(GRID_HEIGHT, GRID_WIDTH);

    // glider pattern on gameboard
    // output the 3 topleft cells 0,0 0,1 and  1,0
    std::cout << "DEBUG" << std::endl;
    // std::cout << gameBoard.grid[0][0] << std::endl;
    // std::cout << gameBoard.grid[0][1] << std::endl;
    // std::cout << gameBoard.grid[1][0] << std::endl;
    // std::cout << gameBoard.grid[1][1] << std::endl;

    gameBoard.grid[10][11] = 1.0f;
    gameBoard.grid[11][12] = 1.0f;
    gameBoard.grid[12][10] = 1.0f;
    gameBoard.grid[12][11] = 1.0f;
    gameBoard.grid[12][12] = 1.0f;

    GameManager gameManager = GameManager(&gameView, &logic, &gameBoard);
    gameManager.loop();
}

#endif