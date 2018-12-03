#ifndef _BLINDDECORATOR_H_
#define _BLINDDECORATOR_H_

#include "Player.h"
#include "EffectsDecorator.h"
#include <vector>
#include <string>

class BlindDecorator: public EffectsDecorator{
    Player *player;
    
    public:
    BlindDecorator(Player *component);
    ~BlindDecorator() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum) override;
    bool getPlayerId() override;
    void setNextBlockChar(char c) override;
    int getLevel() override;
    int getScore() override;
    char getNextBlock() override;
    void setNextBlock() override;
    void moveLeft(int times) override;
    void moveRight(int times) override;
    bool moveDown(int times) override;
    void rotate(std::string direction, int times) override;
    int drop(int times) override;
    char getNextBlockChar() override;
    void levelUp(int times) override;
    void levelDown(int times) override;
    void noRandom(std::string sequencefile) override;
    void random() override;
    void replaceBlock(char c) override;
    //void print() override;
};


#endif