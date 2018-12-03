#include "ZBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

ZBlock::ZBlock(Grid* g, int generatedLevel):Block(g, 'Z', generatedLevel){
    std::vector<GridCell*>tmp;
    tmp.emplace_back(g->getGridCell(0,2));
    tmp.emplace_back(g->getGridCell(1,2));
    tmp.emplace_back(g->getGridCell(1,3));
    tmp.emplace_back(g->getGridCell(2,3));
    for(auto i : tmp){
        if(i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

ZBlock::~ZBlock(){}