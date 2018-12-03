#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class ZBlock : public Block {
    public:
    ZBlock(Grid* g, int generatedLevel);
    ~ZBlock();
};
#endif