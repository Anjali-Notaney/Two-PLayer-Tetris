#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class JBlock : public Block {
    public:
    JBlock(Grid* g, int generatedLevel);
    ~JBlock();
};

#endif
