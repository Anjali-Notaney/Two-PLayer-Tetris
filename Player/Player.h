#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"
#include "../XWindow/XWindow.h"

class Player{
    int score;
    Grid *grid;
    Level *level;
    Block *nextBlock;
    Block *currBlock;
    Xwindow *window;

    public:
    virtual ~Player() = 0;
    virtual std::vector<GridCell>* getRow(int rowNum) = 0;
    virtual int getLevel() = 0;
    virtual int getScore() = 0;
    virtual char getNextBlock() = 0;
    virtual void setNextBlock() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
    virtual void rotate(std::string direction) = 0;
    virtual int drop() = 0;
    virtual void print() = 0;
    virtual void drawXWindowBoard() = 0;
    //virtual void addBlockOnBoard(Block *b) = 0;
};

#endif