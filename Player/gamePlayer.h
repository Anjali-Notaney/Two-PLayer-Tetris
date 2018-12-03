#ifndef __GAMEPLAYER_H__
#define __GAMEPLAYER_H__

#include "Player.h"
#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class GamePlayer: public Player{
    std::vector<Block*> blocksOnBoard;
    std::pair <std::pair<int, int>, std::pair<int, int>> displayBounds; // defines the space in the window where the display is drawn
    void shiftCellsDown(int y);
    void removeEmptyBlocks();
    void getBlock(char blockChar);

    public:
    Xwindow *window;

    //GamePlayer::GamePlayer(xWindow &w);

    GamePlayer(Grid *grid, Level *level, bool id);
    ~GamePlayer();
    bool getPlayerId() override;
    Player* getBasePlayer() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    bool isHeavyLevel() override;
    void setHeavyLevel(bool isHeavy) override;
    void printRow (int rowNum) override;
    int getLevel() override;
    int getScore() override;
    char getNextBlock() override;
    void setNextBlockChar(char c) override;
    char getNextBlockChar() override;
    void setNextBlock() override;
    void moveLeft(int times) override;
    void moveRight(int times) override;
    bool moveDown(int times) override;
    void rotate(std::string direction, int times) override;
    void levelUp(int times) override;
    void levelDown(int times) override;
    int drop() override;
    void noRandom(std::string sequencefile) override;
    void random() override;
    void replaceBlock(char c) override;
};
#endif
