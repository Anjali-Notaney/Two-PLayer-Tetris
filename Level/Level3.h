#ifndef __LEVEL3_H__
#define __LEVEL3_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level3 : public Level{
    public:
    Level3(int seed); //This Level also ads a heavy decorator
    ~Level3();
    std::string sequence;
    std::string file;
    char getNextBlock() override; //Returns a char
    void noRandom(std::string sequencefile) override;
    void random() override;
};

#endif
