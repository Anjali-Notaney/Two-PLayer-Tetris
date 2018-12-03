#include "LBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

LBlock::LBlock(Grid* g, int generatedLevel):Block(g, 'L', generatedLevel){
    std::vector<GridCell*>tmp;
    tmp.emplace_back(g->getGridCell(0,3));
    tmp.emplace_back(g->getGridCell(1,3));
    tmp.emplace_back(g->getGridCell(2,3));
    tmp.emplace_back(g->getGridCell(2,2));
    for(auto i : tmp){
        if(i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

LBlock::~LBlock(){}