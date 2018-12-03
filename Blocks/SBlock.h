#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class SBlock : public Block {
    public:
    SBlock(Grid* g, int generatedLevel);
    ~SBlock();
};
#endif