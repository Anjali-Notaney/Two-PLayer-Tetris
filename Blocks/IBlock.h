#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "Block.h"

class IBlock : public Block{
    public:
    IBlock(Grid* g, int generatedLevel);
    ~IBlock();
};
#endif