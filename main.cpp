#ifndef MAIN_H
#define MAIN_H 1

#include <iostream>
#include <stdio.h>
#include "gpu.cuh"
#include "game-view.cpp"
#include "game-manager.cpp"

int main()
{
    calculate();

    // game render
    GameView app = GameView();
    app.init();
    Game game = Game(&app);
    game.loop();
}

#endif