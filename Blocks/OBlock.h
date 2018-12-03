#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class OBlock : public Block{
    public:
    OBlock(Grid* g, int generatedLevel);
    ~OBlock();
};

#endif