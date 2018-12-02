#ifndef __GAMEPLAYER_H__
#define __GAMEPLAYER_H__

#include "Player.h"
#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class GamePlayer: public Player{
    int score = 0;
    Grid *grid;
    Level *level;
    char nextBlock;
    Block *currBlock = nullptr;
    std::vector<Block*> blocksOnBoard;
    std::pair <std::pair<int, int>, std::pair<int, int>> displayBounds; // defines the space in the window where the display is drawn
    void shiftCellsDown(int y);
    void removeEmptyBlocks();
    void printBlock();
    public:
    Xwindow *window;

    //GamePlayer::GamePlayer(xWindow &w);
    GamePlayer(Grid *grid, Level *level,  Xwindow* window);
    ~GamePlayer();
    std::vector<GridCell>* getRow(int rowNum) override;
    int getLevel() override;
    int getScore() override;
    char getNextBlock() override;
    void setNextBlock() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
    void rotate(std::string direction) override;
    int drop() override;
    void print() override;
    void drawXWindowBoard() override;
    //void addBlockOnBoard(Block *b) override;
};
#endif
