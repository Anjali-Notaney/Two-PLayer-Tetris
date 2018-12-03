#ifndef _LEVELDECORATOR_H_
#define _LEVELDECORATOR_H_

#include "Player.h"
#include "EffectsDecorator.h"
#include <vector>
#include <string>

class LevelDecorator: public EffectsDecorator{
    Player *player;
    
    public:
    LevelDecorator(Player *component);
    ~LevelDecorator() override;
    Player* getBasePlayer() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum, Xwindow* window = nullptr) override;
    bool getPlayerId() override;
    int getLevel() override;
    int getScore() override;
    void setNextBlockChar(char c) override;
    char getNextBlock() override;
    void setNextBlock() override;
    void moveLeft(int times)override;
    void moveRight(int times)override;
    bool moveDown(int times)override;
    void rotate(std::string direction, int times)override;
    int drop(int times) override;
    char getNextBlockChar() override;
    void levelUp(int times, int seed) override;
    void levelDown(int times, std::string scriptfile1, std::string scriptfile2, int seed) override;
    void noRandom(std::string sequencefile) override;
    void random() override;
    void replaceBlock(char c) override;
    //void print() override;
};

#endif