#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include <vector> 
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
#include "Block.h"

class TBlock : public Block{
    public:
    TBlock(Grid* g, int generatedLevel);
    ~TBlock();
};
#endif
