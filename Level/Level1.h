#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level1 : public Level{
    public:
    Level1();
    ~Level1();
    char getNextBlock() override; //Returns a char
};

#endif
