#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level0 : public Level{
    std::string file; //Filename of sequence file
    std::string sequence = ""; //String to hold the sequence of characters
    public:
    Level0(std::string file);
    ~Level0();
    char getNextBlock() override; //Returns a char
    void noRandom(std::string sequencefile) override;
    void random() override;
};

#endif

