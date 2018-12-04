#include "IBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
IBlock::IBlock(Grid *g, int generatedLevel): Block(g, 'I',generatedLevel){
    std::vector<GridCell*> tmp;
    tmp.emplace_back(g->getGridCell(0,3));
    tmp.emplace_back(g->getGridCell(1,3));
    tmp.emplace_back(g->getGridCell(2,3));
    tmp.emplace_back(g->getGridCell(3,3));
    for (auto i : tmp){
        if (i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

IBlock::~IBlock(){}


