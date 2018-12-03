#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level1 : public Level{
    public:
    Level1(int seed);
    ~Level1();
    char getNextBlock() override; //Returns a char
    void noRandom(std::string sequencefile) override;
    void random() override;
};

#endif
