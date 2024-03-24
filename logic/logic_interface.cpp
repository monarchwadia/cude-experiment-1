#ifndef LOGIC_H
#define LOGIC_H

#include "../models/game-board.cpp"

class LogicInterface
{
public:
    virtual ~LogicInterface(){};
    virtual int calculate(GameBoard *board) = 0;
};

#endif