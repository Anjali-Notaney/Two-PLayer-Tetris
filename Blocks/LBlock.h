#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class LBlock : public Block {
    public:
    LBlock(Grid* g, int generatedLevel);
    ~LBlock();
};

#endif

