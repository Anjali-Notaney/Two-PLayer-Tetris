#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <fstream>

class Level{
    int level = -1; //Level of the subclass
    protected:
    bool isRandom = 1;
    public:
    Level(int level);
    virtual ~Level();
    virtual char getNextBlock() = 0; //Returns a char
    virtual int getScore(int linesCleared); //Returns score based on lines cleared
    virtual void noRandom(std::string sequencefile) = 0;
    virtual void random() = 0;
    int getLevel(); //Returns the current level
};

#endif
