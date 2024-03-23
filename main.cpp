#ifndef MAIN_H
#define MAIN_H 1

#include <iostream>
#include <stdio.h>
#include "gpu.cuh"
#include "view.cpp"
#include "game.cpp"

int main()
{
    calculate();

    // game render
    SdlApp app = SdlApp();
    app.init();
    Game game = Game(&app);
    game.loop();
}

#endif