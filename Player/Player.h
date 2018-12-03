#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"
#include "../XWindow/XWindow.h"

class Player{
    // xWindow *window;
    protected:
    int score;
    Grid *grid;
    Level *level;
<<<<<<< HEAD
    Block *nextBlock;
    Block *currBlock;
    Xwindow *window;

=======
    char nextBlock;
    Block *currBlock = nullptr;
    bool playerId;
    static bool playerOnePlaying;
    bool heavyLevel;
    
>>>>>>> master
    public:
    virtual ~Player() = 0;
    Player(Grid* grid, Level *level, bool id);
    Player();
    virtual std::vector<GridCell>* getRow(int rowNum) = 0;
    virtual void printRow (int rowNum) = 0;
    virtual bool isHeavyLevel() = 0;
    virtual void setHeavyLevel(bool isHeavy) = 0;
    virtual bool getPlayerId() = 0;
    virtual Player* getBasePlayer() = 0;
    bool isPlayerOnePlaying();
    int getGridWidth();
    int getGridHeight();
    virtual int getLevel() = 0;
    virtual int getScore() = 0;
    virtual char getNextBlock() = 0;
    virtual void setNextBlockChar(char c) = 0;
    virtual char getNextBlockChar() = 0;
    virtual void setNextBlock() = 0;
<<<<<<< HEAD
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
    virtual void rotate(std::string direction) = 0;
    virtual int drop() = 0;
    virtual void print() = 0;
    virtual void drawXWindowBoard() = 0;
=======
    virtual void moveLeft(int times) = 0;
    virtual void moveRight(int times) = 0;
    virtual bool moveDown(int times) = 0;
    virtual void rotate(std::string direction, int times) = 0;
    virtual void levelUp(int times) = 0;
    virtual void levelDown(int times) = 0;
    virtual int drop() = 0;
    virtual void noRandom(std::string sequencefile) = 0;
    virtual void random() = 0;
    virtual void replaceBlock(char c) = 0;
<<<<<<< HEAD
    //virtual void print() = 0;
>>>>>>> master
    //virtual void addBlockOnBoard(Block *b) = 0;
=======
>>>>>>> master
};

#endif