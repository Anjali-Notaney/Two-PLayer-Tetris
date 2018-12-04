#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class Xwindow;

class Player{
    // xWindow *window;
    protected:
    int score = 0;
    Grid *grid;
    Level *level;
    char nextBlock;
    Block *currBlock = nullptr;
    bool playerId;
    static bool playerOnePlaying;
    bool heavyLevel;

    public:
    virtual ~Player() = 0;
    Player(Grid* grid, Level *level, bool id);
    Player();
    virtual std::vector<GridCell>* getRow(int rowNum) = 0;
    virtual void printRow (int rowNum, Xwindow* window = nullptr) = 0;
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
    virtual void moveLeft(int times) = 0;
    virtual void moveRight(int times) = 0;
    virtual bool moveDown(int times) = 0;
    virtual void rotate(std::string direction, int times) = 0;
    virtual void levelUp(int times, int seed) = 0;
    virtual void levelDown(int times, std::string scriptfile1, std::string scriptfile2, int seed) = 0;
    virtual int drop() = 0;
    virtual void noRandom(std::string sequencefile) = 0;
    virtual void random() = 0;
    virtual void replaceBlock(char c) = 0;

    //virtual void addBlockOnBoard(Block *b) = 0;
};

#endif
