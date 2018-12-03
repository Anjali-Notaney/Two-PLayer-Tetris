#include "SBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

SBlock::SBlock(Grid* g, int generatedLevel):Block(g, 'S', generatedLevel){
    std::vector<GridCell*>tmp;
    tmp.emplace_back(g->getGridCell(0,3));
    tmp.emplace_back(g->getGridCell(1,3));
    tmp.emplace_back(g->getGridCell(1,2));
    tmp.emplace_back(g->getGridCell(2,2));
    for(auto i : tmp){
        if(i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

SBlock::~SBlock(){}